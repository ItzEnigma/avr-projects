/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Dell
 */

#define F_CPU 8000000UL
#include "../LIB/std_types.h"
#include "../LIB/bit_map.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIMER/TIMER_int.h"
#include "../MCAL/TIMER/TIMER_reg.h"
#include "../MCAL/TIMER/TIMER_cfg.h"
#include "../MCAL/TIMER/TIMER_pri.h"

#include "../MCAL/EXI/EXI_int.h"
#include "../MCAL/GIE/GIE_int.h"

#include "../HAL/LED/LED_int.h"
#include "../HAL/SWITCHES/SWITCHES_int.h"
#include "../HAL/SSD/SSD_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/SERVO/SERVO_int.h"
#include <avr/delay.h>

volatile u32 G_u32Counts_Read1 = 0, G_u32Counts_Read2 = 0, G_u32Counts_Read3 = 0;
volatile u8 Flag = 0;
volatile u16 PeriodTime = 0, DutyCycle = 0, TimeOn = 0;
volatile u16 G_u16Cov = 0;
void ICU_HW();
void TIM1_OVF();

int mainICU()
{
	/* INIT LCD */
	LCD_vInit();
	LCD_vDisplayString("Start");

	/* Enable Global Interrupt */
	GIE_vSetGlobalInterrupt();
	/* SWT PWM to 25 Duty Cycle This Sets OCR0 to 64 */
	TIMER_vPWMSignal(TIMER0, 35);
	/* Init Timer 0 */
	TIMER_vInit(TIMER0);
	/* ******************************* */

	/* Enanle ICU TIMER 1 */
	TIMER_vsetCallBackFunctionIcuTIMER1(&ICU_HW);
	TIMER_vsetCallBackFunctionOvfTIMER1(&TIM1_OVF);
	TIMER_vCongfigureICU();
	TIMER_vSetTriggeringICU(RISING);

	while (1)
	{
		if (Flag == 1)
		{
			DutyCycle = (TimeOn * 1.0 / PeriodTime) * 100;
			LCD_vSetPostion(ROW0, COLUMN0);
			LCD_vDisplayString("TimePeriod:");
			LCD_vDisplayNumInteger(PeriodTime);
			LCD_vDisplayString("us");
			LCD_vSetPostion(ROW1, COLUMN0);
			LCD_vDisplayString("DutyCycle : ");
			LCD_vDisplayNumInteger(DutyCycle);
			LCD_vDisplayString("%");
			Flag = 0;
		}
		else
		{
			// do nothing
		}
	}
	return 0;
}
void ICU_HW(void)
{
	static u8 counter = 0;
	counter++;
	if (counter == 2)
	{
		G_u32Counts_Read1 = TIMER_u16GetICU() + (G_u16Cov * 65536);
	}
	else if (counter == 3)
	{
		G_u32Counts_Read2 = TIMER_u16GetICU() + (G_u16Cov * 65536);
		PeriodTime = G_u32Counts_Read2 - G_u32Counts_Read1;
		/* SET TRTIGGER TO Falling EDGE */
		TIMER_vSetTriggeringICU(FALLING);
	}
	else if (counter == 4)
	{
		G_u32Counts_Read3 = TIMER_u16GetICU() + (G_u16Cov * 65536);
		TimeOn = G_u32Counts_Read3 - G_u32Counts_Read2;
		TIMER_vDisableIntICU();
		Flag = 1;
	}
	else
	{
		// DO Nothing
	}
}
void TIM1_OVF()
{
	G_u16Cov++;
}
/* SERVO */

/*
int main()
{
	SERVO_vInit();

	while (1)
	{
		SERVO_vMoveToInitialAngle();
		_delay_ms(1000);
		SERVO_vMoveToAngle(45);
		_delay_ms(1000);
		SERVO_vMoveToAngle(90);
		_delay_ms(1000);
		SERVO_vMoveToAngle(135);
		_delay_ms(1000);
		SERVO_vMoveToAngle(180);
		_delay_ms(1000);
	}
	return 0;
}
 */
