/*
 * AVR-COTS-Application.c
 *
 * Created: 10/14/2022 1:09:46 PM
 * Author : hosam
 */ 

#include "../MCAL/DIO/Dio.h"



int main(void)
{
	DIO_Init(&Port_strPortConfig);
	UART_Init();
	
    /* Replace with your application code */
    while (1) 
    {
		u16 x = 0x0F;		u08 *y;
		DIO_WritePort(PORT_B, 0xff);
		DIO_WriteChannel(PORT_A, PIN0, HIGH);
		if(!DIO_ReadChannel(PORT_C, PIN0))	DIO_ToggleChannel(PORT_A, PIN2);
		UART_ReceiveByte(y);
		UART_TransmitByte(*y);

    }
}

