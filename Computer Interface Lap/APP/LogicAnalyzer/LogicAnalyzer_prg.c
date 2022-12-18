/*
 * LogicAnalyzer.c
 *
 * Created: 03/12/2022 07:44:06 PM
 *  Author: TaqiEldeen
 */ 
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/TIMER/TIMER_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "LogicAnalyzer_pri.h"
#include "LogicAnalyzer_int.h"
#include "LogicAnalyzer_cfg.h"
#define F_CPU 8000000UL
#include <avr/delay.h>


static u8 G_u8LogicBuffer[SAMPLE_NUMBER];
static u16 G_u16TimeStamp[SAMPLE_NUMBER];
static u8 G_u8UARTBuffer = IDLE;
static u16 G_u8SamplePeriod = 0;	/*In micro-second*/

static void monitor(){
	u8 L_u8SampleNum = 0;	/*Keep track of current sample*/
	u8 L_u8InitialLogicVal = DIO_u8GetPortVal(LOGIC_CHANNELS_PORT);		/*get the initial */
	TIMER_vSetPreLoad(TIMER1, 0);		/*Reset timer*/
	DIO_vSetPinDir(PORTC_ID, PIN0_ID, DIR_OUTPUT);

	while(L_u8SampleNum < SAMPLE_NUMBER) {	
 		while(DIO_u8GetPortVal(LOGIC_CHANNELS_PORT) == L_u8InitialLogicVal){	/*Wait for pin state change (MONITOR)*/
 		}
 		L_u8InitialLogicVal = DIO_u8GetPortVal(LOGIC_CHANNELS_PORT);
		sampling(L_u8SampleNum);	/*Sampling*/
		DIO_vTogPinVal(PORTC_ID, PIN0_ID);

		//for(u16 i=0; i<G_u8SamplePeriod; i++)	/*Take sample at sampling rate*/
		//	_delay_us(1);
		
		L_u8SampleNum++;	/*Next sample*/
	}
	G_u8UARTBuffer = SENDING;	/*Start sending to PC*/
}

static void sampling(u8 A_u8SampleNum){
	G_u8LogicBuffer[A_u8SampleNum] = DIO_u8GetPortVal(LOGIC_CHANNELS_PORT);		/*Save the current sample (SAMPLING)*/
	G_u16TimeStamp[A_u8SampleNum] = TIMER_u16GetTCNT1W();					/*Save current time stamp for this sample*/

}

static void sending(){
	UART_vSendData('L');/*Start char*/
	UART_vSendData('+');
	UART_vSendData('-');
	for (u8 i=0; i < SAMPLE_NUMBER; i++)
	{
		toHex(G_u8LogicBuffer[i]); /*pin state*/
		UART_vSendData('+');
		UART_vSendData('-');
		toHex(G_u16TimeStamp[i] >> 8); /*Time stamp higher byte*/
		toHex(G_u16TimeStamp[i]); /*Time stamp lower byte*/
		UART_vSendData('Q');	/*End frame*/
		UART_vSendData('+');
		UART_vSendData('-');	/*End char*/
	}
	G_u8UARTBuffer = IDLE;
}

void LogicAnalyzer_vInit(){
	UART_vInit();				/*Init UART*/
	GIE_vSetGlobalInterrupt();
	DIO_vSetPortDir(LOGIC_CHANNELS_PORT, 0x00);	/*Make channels input*/
	DIO_vSetPortVal(LOGIC_CHANNELS_PORT, PORT_HIGH);
	TIMER_vInit(TIMER1);		/*Init timer in normal mode with 1024 prescaler (128u * 1024) to keep track of time passed*/
	UART_u8GetDataAsync(dataHandler);
}


void LogicAnalyzer_vUpdate(){	/*The main loop*/
	switch (G_u8UARTBuffer)
	{
		case IDLE:  break;
		case MONITOR: monitor(); break;
		case SENDING: sending(); break;
	}
}


static void dataHandler(u8 A_u8Data){
	static u8 L_u8Index = 0;
	static u8 L_u8Flag = 0;
	
	if(A_u8Data == ';'){
		L_u8Flag = 0;
		L_u8Index = 0;
	}
	if(L_u8Flag){
		G_u8UARTBuffer = A_u8Data;
		if(G_u8UARTBuffer == IDLE){
			UART_vSendData('R');
			UART_vSendData('+');
			UART_vSendData('-'); 
		}
	}
	if(A_u8Data == '#'){
		L_u8Flag = 1;
	}
}

static void toHex(u8 A_u8Data){
	u8 L_u08FirstChar = A_u8Data & 0x0F;
	u8 L_u08SecondChar = (A_u8Data & 0xF0) >> 4;
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
	UART_vSendData(L_u08SecondChar);
	UART_vSendData(L_u08FirstChar);
}