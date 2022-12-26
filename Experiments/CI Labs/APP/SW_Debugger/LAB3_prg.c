/*
 * LAB3_prg.c
 *
 * Created: 28/10/2022 11:21:04 PM
 *  Author: 20109
 */ 
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "../../MCAL/UART/UART_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/EXI/EXI_int.h"
#include "LAB3_int.h"
#include "LAB3_pri.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <avr/delay.h>
#include <avr/boot.h>

void LAB3_vInit(){
	UART_vInit();
	UART_u8GetDataAsync(dataHandler);
	GIE_vSetGlobalInterrupt();
	DIO_vSetPinDir(PORTA_ID, PIN7_ID, DIR_OUTPUT);
}

static u8 EEPROM_read(u16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}

static void EEPROM_write(u16 uiAddress, u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

void LAB3_vUpdate(){
	u16 L_u16Address = 0;
	u8 L_u08Data = 0;
	u8 L_u08FirstChar = 0;
	u8 L_u08SecondChar = 0;
	/*check if a command is received*/
	if(!G_u8IsBufferReady){
		
		/* Getting Address */
		for ( int i=0 ; (G_u8Buffer[ADDRESS_INDEX+i] != '^') ; i++ )
		{
			if (G_u8Buffer[ADDRESS_INDEX+i] > 0x40)		/* It's character */
			{
				L_u16Address  |= ((G_u8Buffer[ADDRESS_INDEX+i] - 0x37) << (12-(4*i)));
			}
			else								/* It's a number */
			{
				L_u16Address  |= ((G_u8Buffer[ADDRESS_INDEX+i] - 0x30) << (12-(4*i)));
			}
		}
		
		/* RAM TYPE */
		if		(G_u8Buffer[MEMTYPE_INDEX] == RAM_TYPE)
		{
			
		/* READ OPERATION */	
			if		(G_u8Buffer[R_W_INDEX] == READ_OP)
			{
				L_u08Data = _MEM(L_u16Address);
				L_u08FirstChar = L_u08Data & 0x0F;
				L_u08SecondChar = (L_u08Data & 0xF0) >> 4;
				switch(L_u08FirstChar){			/* Parsing the higher ASCII values for first char */
					case 10: L_u08FirstChar = 'A'; break;
					case 11: L_u08FirstChar = 'B'; break;
					case 12: L_u08FirstChar = 'C'; break;
					case 13: L_u08FirstChar = 'D'; break;
					case 14: L_u08FirstChar = 'E'; break;
					case 15: L_u08FirstChar = 'F'; break;
					default: L_u08FirstChar += '0'; break;
				}
				switch(L_u08SecondChar){		/* Parsing the higher ASCII values for second char */
					case 10: L_u08SecondChar = 'A'; break;
					case 11: L_u08SecondChar = 'B'; break;
					case 12: L_u08SecondChar = 'C'; break;
					case 13: L_u08SecondChar = 'D'; break;
					case 14: L_u08SecondChar = 'E'; break;
					case 15: L_u08SecondChar = 'F'; break;
					default: L_u08SecondChar += '0'; break;
				}
			/* Resetting Buffer in Back-end */
				UART_vSendData('-');
				UART_vSendData('+');
				UART_vSendData(L_u08SecondChar);
				UART_vSendData(L_u08FirstChar);
				UART_vSendData('+');
				L_u16Address = 0;
			}
		/* WRITE OPERATION */
			else if (G_u8Buffer[R_W_INDEX] == WRITE_OP)
			{
				if (G_u8Buffer[VALUE_INDEX] > 0x40)
					L_u08Data |= (G_u8Buffer[VALUE_INDEX] - 0x37) << 4;
				else
					L_u08Data |= (G_u8Buffer[VALUE_INDEX] - 0x30) << 4;
				if (G_u8Buffer[VALUE_INDEX+1] > 0x40)
					L_u08Data |= G_u8Buffer[VALUE_INDEX+1] - 0x37;
				else
					L_u08Data |= G_u8Buffer[VALUE_INDEX+1] - 0x30;
				_MEM(L_u16Address) = L_u08Data;
				L_u08Data = 0;
				DIO_vTogPinVal(PORTA_ID, PIN7_ID);
			}
			else;	/* MISRA RULE */
			G_u8IsBufferReady = 1;
		}
		
		/* ROM TYPE */
		else if (G_u8Buffer[MEMTYPE_INDEX] == ROM_TYPE)
		{
		/* READ OPERATION */
			if		(G_u8Buffer[R_W_INDEX] == READ_OP)
			{
				L_u08Data = EEPROM_read(L_u16Address);	/* Reading EEPROM Data */
				
				L_u08FirstChar = L_u08Data & 0x0F;
				L_u08SecondChar = (L_u08Data & 0xF0) >> 4;
				switch(L_u08FirstChar){			/* Parsing the higher ASCII values for first char */
					case 10: L_u08FirstChar = 'A'; break;
					case 11: L_u08FirstChar = 'B'; break;
					case 12: L_u08FirstChar = 'C'; break;
					case 13: L_u08FirstChar = 'D'; break;
					case 14: L_u08FirstChar = 'E'; break;
					case 15: L_u08FirstChar = 'F'; break;
					default: L_u08FirstChar += '0'; break;
				}
				switch(L_u08SecondChar){		/* Parsing the higher ASCII values for second char */
					case 10: L_u08SecondChar = 'A'; break;
					case 11: L_u08SecondChar = 'B'; break;
					case 12: L_u08SecondChar = 'C'; break;
					case 13: L_u08SecondChar = 'D'; break;
					case 14: L_u08SecondChar = 'E'; break;
					case 15: L_u08SecondChar = 'F'; break;
					default: L_u08SecondChar += '0'; break;
				}
				/* Resetting Buffer in Back-end */
				UART_vSendData('-');
				UART_vSendData('+');
				UART_vSendData(L_u08SecondChar);
				UART_vSendData(L_u08FirstChar);
				UART_vSendData('+');
				L_u16Address = 0;
			}
			else
			{
				if (G_u8Buffer[VALUE_INDEX] > 0x40)
					L_u08Data |= (G_u8Buffer[VALUE_INDEX] - 0x37) << 4;
				else
					L_u08Data |= (G_u8Buffer[VALUE_INDEX] - 0x30) << 4;
				if (G_u8Buffer[VALUE_INDEX+1] > 0x40)
					L_u08Data |= G_u8Buffer[VALUE_INDEX+1] - 0x37;
				else
					L_u08Data |= G_u8Buffer[VALUE_INDEX+1] - 0x30;
				EEPROM_write(L_u16Address, L_u08Data);
				L_u08Data = 0;
				L_u16Address = 0;
				DIO_vTogPinVal(PORTA_ID, PIN7_ID);
			}
			G_u8IsBufferReady = 1;
		}
		else;	/* MISRA RULE */
			
	} else {/*If the command is not ready*/
	}
}

static void dataHandler(u8 A_u8Data){
	static u8 L_u8Index = 0;
	static u8 L_u8Flag = 0;
/*
		# ==> RAM 
		$ ==> ROM
		READ:   #r(ABCD)^(AB);
		WRITE:  #w(ABCD)^(AB)
*/

	DIO_vTogPinVal(PORTA_ID, PIN7_ID);

	/*Ignore white spaces*/
	if		(A_u8Data == '#' &&  !L_u8Flag)	/* RAM */
		L_u8Flag = 1;
	else if (A_u8Data == '$' &&  !L_u8Flag)	/* ROM */
		L_u8Flag = 1;
	/* Storing Data */
		if ((A_u8Data != ' ' && L_u8Flag && G_u8IsBufferReady))
			G_u8Buffer[L_u8Index++] = A_u8Data;
		if (G_u8Buffer[L_u8Index-1] == ';') {
			L_u8Flag = 0;
			G_u8IsBufferReady = 0;
			L_u8Index = 0;
	}
}

