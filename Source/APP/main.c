/*
 * main.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */
#include "../lib/std_types.h"
#include "../lib/bit_map.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../RTOS_STACK/TMU/RTOS_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/EEPROM/EEPROM_int.h"
#include <avr/delay.h>
void TASK_1()
{
	DIO_vTogPinVal(PORTA_ID, PIN3_ID);
}
void TASK_2()
{
	DIO_vTogPinVal(PORTA_ID, PIN4_ID);
}
void TASK_3()
{
	DIO_vTogPinVal(PORTA_ID, PIN5_ID);
}
int main()
{
	DIO_vSetPinDir(PORTA_ID, PIN3_ID, DIR_OUTPUT);
	DIO_vSetPinDir(PORTA_ID, PIN4_ID, DIR_OUTPUT);
	DIO_vSetPinDir(PORTA_ID, PIN5_ID, DIR_OUTPUT);

	RTOS_vStartSchedular();
	RTOS_vInit();
	RTOS_vCreateTask(0, 1, TASK_1);
	RTOS_vCreateTask(1, 2, TASK_2);
	RTOS_vCreateTask(2, 3, TASK_3);
	while (1)
	{
	}
}
