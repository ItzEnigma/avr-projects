/*
 * LED_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "LED_cfg.h"
#include "LED_int.h"

#include "../../MCAL/DIO/DIO_int.h"

void LED_vInit(u8 A_u8LedNo)
{
	switch (A_u8LedNo)
	{
	case LED0:
		DIO_vSetPinDir(LED0_PORT, LED0_PIN, DIR_OUTPUT);
		break;
	case LED1:
		DIO_vSetPinDir(LED1_PORT, LED1_PIN, DIR_OUTPUT);
		break;
	case LED2:
		DIO_vSetPinDir(LED2_PORT, LED2_PIN, DIR_OUTPUT);
		break;
	case LED3:
		DIO_vSetPinDir(LED3_PORT, LED3_PIN, DIR_OUTPUT);
		break;
	case LED4:
		DIO_vSetPinDir(LED4_PORT, LED4_PIN, DIR_OUTPUT);
		break;
	case LED5:
		DIO_vSetPinDir(LED5_PORT, LED5_PIN, DIR_OUTPUT);
		break;
	case LED6:
		DIO_vSetPinDir(LED6_PORT, LED6_PIN, DIR_OUTPUT);
		break;
	case LED7:
		DIO_vSetPinDir(LED7_PORT, LED7_PIN, DIR_OUTPUT);
		break;
	}
}
void LED_vTurnOn(u8 A_u8LedNo)
{
	switch (A_u8LedNo)
	{
	case LED0:
		DIO_vSetPinVal(LED0_PORT, LED0_PIN, HIGH);
		break;
	case LED1:
		DIO_vSetPinVal(LED1_PORT, LED1_PIN, HIGH);
		break;
	case LED2:
		DIO_vSetPinVal(LED2_PORT, LED2_PIN, HIGH);
		break;
	case LED3:
		DIO_vSetPinVal(LED3_PORT, LED3_PIN, HIGH);
		break;
	case LED4:
		DIO_vSetPinVal(LED4_PORT, LED4_PIN, HIGH);
		break;
	case LED5:
		DIO_vSetPinVal(LED5_PORT, LED5_PIN, HIGH);
		break;
	case LED6:
		DIO_vSetPinVal(LED6_PORT, LED6_PIN, HIGH);
		break;
	case LED7:
		DIO_vSetPinVal(LED7_PORT, LED7_PIN, HIGH);
		break;
	}
}
void LED_vTurnOff(u8 A_u8LedNo)
{
	switch (A_u8LedNo)
	{
	case LED0:
		DIO_vSetPinVal(LED0_PORT, LED0_PIN, LOW);
		break;
	case LED1:
		DIO_vSetPinVal(LED1_PORT, LED1_PIN, LOW);
		break;
	case LED2:
		DIO_vSetPinVal(LED2_PORT, LED2_PIN, LOW);
		break;
	case LED3:
		DIO_vSetPinVal(LED3_PORT, LED3_PIN, LOW);
		break;
	case LED4:
		DIO_vSetPinVal(LED4_PORT, LED4_PIN, LOW);
		break;
	case LED5:
		DIO_vSetPinVal(LED5_PORT, LED5_PIN, LOW);
		break;
	case LED6:
		DIO_vSetPinVal(LED6_PORT, LED6_PIN, LOW);
		break;
	case LED7:
		DIO_vSetPinVal(LED7_PORT, LED7_PIN, LOW);
		break;
	}
}
