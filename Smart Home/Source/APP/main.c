/*
 * Smart Home.c
 *
 * Created: 26/12/2022 05:58:27 PM
 * Author : 20109
 */ 

#define		_HOME_LOCKED			100
#define		_HOME_UNLOCKED			101
#define		_HOME_KEYPAD_STATE		102


#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/TEMPS/TEMPS_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KeyPad/KeyPad_int.h"
#include "../HAL/LDR/LDR_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/TIM0/TIM0_int.h"
#include <avr/delay.h>

void startKeypad();
void Timer0Elapsed_KeyOFF();

u16 channelsValues[2] = {0};

u8 Home_State = _HOME_LOCKED;

void DisplayOverLCD()
{
	channelsValues[0] = TEMPS_ConvertValue(channelsValues[0]);	/* Getting Temp Value */
	channelsValues[1] = LDR_ConvertValue(channelsValues[1]);	/* Getting LDR Value */
	LCD_vSetPosition(ROW0_ID, COL0_ID);
	LCD_vDispNum(channelsValues[0]);
	LCD_vSetPosition(ROW1_ID, COL0_ID);
	LCD_vDispNum(channelsValues[1]);
	LCD_vSetPosition(ROW1_ID, COL6_ID);
}

int main(void)
{
	DIO_vSetPinDir(PORTD_ID, PIN7_ID, DIR_OUTPUT);
	TEMPS_vInit();
	LCD_vInit();
	KeyPad_vInit();
	GIE_vEnableGlobaLInt();
	TIM0_vInit();
	EXTI_vInitINT0();
	EXTI_vReg_Func(startKeypad, INT0_ID);
	DIO_vSetPinDir(PORTB_ID, PIN7_ID, DIR_OUTPUT);
	u8 channels[2] = {ADC0_ID, ADC1_ID};
	ADC_stChain chain = { channels, channelsValues, 2, &DisplayOverLCD };
	
	u8 L_u8Char;
    while (1) 
    {	
		if (Home_State == _HOME_KEYPAD_STATE)
		{
			L_u8Char = KeyPad_u8GetPressedKey();
			if(L_u8Char != NO_PRESSED_KEY)
			{
				
				TIM0_vDelayMilli(8000, 0, &Timer0Elapsed_KeyOFF);
				LCD_vDispChar(L_u8Char);
			}
		}
		else if(Home_State == _HOME_UNLOCKED)
		{
			ADC_StartChain(&chain);
			_delay_ms(500);
		}
		else;	/* What State ??? */
    }
}

void startKeypad(){
	DIO_vSetPinVal(PORTB_ID, PIN7_ID, VAL_HIGH);
	Home_State = _HOME_KEYPAD_STATE;
	TIM0_vTurnOn();
	TIM0_vDelayMilli(8000, 0, &Timer0Elapsed_KeyOFF);
}

void Timer0Elapsed_KeyOFF()
{
	DIO_vSetPinVal(PORTB_ID, PIN7_ID, VAL_LOW);
	Home_State = _HOME_LOCKED;	/* To be Handled */
	TIM0_vTurnOff();
}

