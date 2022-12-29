/*
 * Smart Home.c
 *
 * Created: 26/12/2022 05:58:27 PM
 * Author : 20109
 */ 


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/


#include "APPSYS/APPSYS.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/HC/HC_int.h"

#include <avr/delay.h>

int main(void)
{
	Mcu_Init();
	System_Start();

	//DIO_vSetPinDir(PORTD_ID, PIN4_ID, DIR_OUTPUT);
//	LCD_vInit();
//	LCD_vDispStr("HELLO WORLD!");

    while (1) 
    {	
		System_WakeUp();
	}
}




