/*
 * Smart Home.c
 *
 * Created: 26/12/2022 05:58:27 PM
 * Author : 20109
 */ 
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/TEMPS/TEMPS_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KeyPad/KeyPad_int.h"
#include "../HAL/LDR/LDR_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include <avr/delay.h>

void startKeypad();


int main(void)
{
	TEMPS_vInit();
	LCD_vInit();
	KeyPad_vInit();
	GIE_vEnableGlobaLInt();
	EXTI_vInitINT0();
	EXTI_vReg_Func(startKeypad, INT0_ID);
	DIO_vSetPinDir(PORTB_ID, PIN7_ID, DIR_OUTPUT);
	
	u8 L_u8Char;
    while (1) 
    {	
		LCD_vSetPosition(ROW0_ID, COL0_ID);
		LCD_vDispNum(TEMPS_u8GetTemp());
		LCD_vSetPosition(ROW1_ID, COL0_ID);
		LCD_vDispNum(LDR_u16GetValue());
		L_u8Char = KeyPad_u8GetPressedKey();
	
		LCD_vSetPosition(ROW1_ID, COL6_ID);
		if(L_u8Char != NO_PRESSED_KEY)
			LCD_vDispChar(L_u8Char);
		
		_delay_ms(500);
    }
}

void startKeypad(){
	DIO_vTogPin(PORTB_ID, PIN7_ID);
}

