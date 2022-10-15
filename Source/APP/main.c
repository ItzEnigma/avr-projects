/*
 * AVR-COTS-Application.c
 *
 * Created: 10/14/2022 1:09:46 PM
 * Author : hosam
 */ 

#include "main.h"


int main(void)
{
	Mcu_Init();
	
	/* Replace with your application code */
	while (1)
	{
		u16 x = 0x0F;		u08 *y;
		
		DIO_WriteChannel(PORT_A, PIN0, HIGH);
		if(!DIO_ReadChannel(PORT_C, PIN0))	DIO_ToggleChannel(PORT_A, PIN2);
		for(int i= 0 ; i<1000 ; i++);
		UART_ReceiveByte(y);
		UART_TransmitByte(*y);

	}
}

