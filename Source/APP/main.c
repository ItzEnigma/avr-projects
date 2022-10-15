/*
 * main.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */
#include "../lib/std_types.h"
#include "../lib/bit_map.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIMER/TIMER_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXI/EXI_int.h"
#include <avr/delay.h>

#define PWM_SIGNAL 25

void incSpeed(void);
void decSpeed(void);
void changeDir(void);

volatile s8 G_s8Pwm = PWM_SIGNAL;
u8 G_u8IsClkWise = 0;

int main()
{
	GIE_vSetGlobalInterrupt();

	EXI_vINT0_Init();
	EXI_vINT1_Init();
	EXI_vINT2_Init();

	EXI_vRegFunc(&incSpeed, INT0_FUNC);
	EXI_vRegFunc(decSpeed, 	INT1_FUNC);
	EXI_vRegFunc(&changeDir, INT2_FUNC);

	DIO_vSetPinDir(PORTC_ID, PIN0_ID, DIR_OUTPUT);
	DIO_vSetPinDir(PORTC_ID, PIN1_ID, DIR_OUTPUT);

	DIO_vSetPinVal(PORTC_ID, PIN0_ID, HIGH);
	DIO_vSetPinVal(PORTC_ID, PIN1_ID, LOW);

	TIMER_vInit(TIMER0);
	TIMER_vPWMSignal(TIMER0, PWM_SIGNAL);


	while (1)
	{

	}
}


void incSpeed(void){
	G_s8Pwm += 5;
	if(G_s8Pwm>100)
		G_s8Pwm = 100;
	TIMER_vPWMSignal(TIMER0, G_s8Pwm);
	_delay_ms(20);
}

void decSpeed(void){
	G_s8Pwm -= 5;
	if(G_s8Pwm < 5)
		G_s8Pwm = 5;
	TIMER_vPWMSignal(TIMER0, G_s8Pwm);
	_delay_ms(20);
}

void changeDir(void){
	TOG_BIT(G_u8IsClkWise, 0);
	if(G_u8IsClkWise){
		DIO_vSetPinVal(PORTC_ID, PIN0_ID, LOW);
		DIO_vSetPinVal(PORTC_ID, PIN1_ID, HIGH);
	} else {
		DIO_vSetPinVal(PORTC_ID, PIN0_ID, HIGH);
		DIO_vSetPinVal(PORTC_ID, PIN1_ID, LOW);
	}
	_delay_ms(20);
}
