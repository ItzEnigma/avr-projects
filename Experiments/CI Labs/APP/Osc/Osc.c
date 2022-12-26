/*
 * Osc.c
 *
 * Created: 12/8/2022 8:20:26 PM
 *  Author: hosam
 */ 


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/TIMER/TIMER_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "../../MCAL/ADC/ADC_reg.h"
#include "avr/delay.h"

#include "Osc.h"
#include "Osc_pri.h"


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

u8 currentState = SAMPLING;
static u8 gGUI_currentState;
static u8  gAnalog_samples[_SAMPLES_NUM];
static u16 gTime_snap[_SAMPLES_NUM];

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/* Custom ADC Initialization */
void ADC_customInit(void)
{
	ADMUX =0b01100000;// PA0 -> ADC0, ADLAR=1(8-bit)
	ADCSRA |= ((1<<ADEN) | (1<<ADSC) | (1<<ADPS1)); // ADC prescaler at 4
}

u8 ADC_sample(void)
{
	u8 ADCvalue =0;
	ADCSRA |= (1<< ADSC);
	while(!(ADCSRA & (1<<ADIF)));// waiting for ADIF,conversion complete
	ADCvalue = ADCH;
	return ADCvalue;
}


void Osc_Init(void)
{
	UART_vInit();
	GIE_vSetGlobalInterrupt();
	ADC_customInit();
	TIMER_vInit(TIMER1);
	UART_u8GetDataAsync( UART_ReceiveHander );
}

void Osc_Main(void)
{
	static volatile u8 i_sample = 0;
	
	switch(currentState)
	{
		case SAMPLING:
		{
			/* One Sample (Storing the sample value & and time stamp) */
			gAnalog_samples[i_sample] = ADC_sample();
			gTime_snap[i_sample] = TIMER_u16GetTCNT1W();
			
			/* Increment variable to get next sample */
			i_sample++;
			
			if (i_sample >= _SAMPLES_NUM)
				currentState = SENDING;
			else;
				/* Do Nothing */
				
			break;
		}
		case SENDING:
		{
			static u8 i = 0 ;

			/* Sending Frame /
			/ Frame: #(byte sample value)(2-bytes sample timestamp); */
			if(i == 0){
				UART_vSendData('~');	/*Start frame*/
				UART_vSendData('+'); 
				UART_vSendData('-');	/*Clear GUI buffer*/
			}
			
			toHex(gAnalog_samples[i]);	/*Send the sample*/
			UART_vSendData('+');
			UART_vSendData('-');	    /*Clear GUI buffer*/
				
			toHex(gTime_snap[i] >> 8);	/*Send time stamp*/
			toHex(gTime_snap[i] & 0x00FF);
			UART_vSendData('+');
			UART_vSendData('-');	    /*Clear GUI buffer*/
			
			i++;
			
			if(i == _SAMPLES_NUM) {
				UART_vSendData('Q');	/*End frame*/
				UART_vSendData('+'); 
				UART_vSendData('-');	/*Clear GUI buffer*/
				i = 0;
				
				switch(gGUI_currentState)
				{
					case CONTINUOUS:
					{
						currentState = SAMPLING;
						i_sample = 0;
						TIMER_vSetPreLoad(TIMER1, 0);
						break;
					}
					default: currentState = IDLE; gGUI_currentState = STOP; break;
				}
			}
			break;
		}	
		case IDLE:
		{
			if(gGUI_currentState == STOP);
				/* Do Nothing */
			else if (gGUI_currentState == DISCONTINUOUS)
			{
				currentState = SAMPLING;
				i_sample = 0;
				TIMER_vSetPreLoad(TIMER1, 0);
			}
			else; /* MISRA RULES */
			break;
		}
		
		default: { /* MISRA RULES */ }
	}
}

static void UART_ReceiveHander(u8 Rx_Data)
{
	static u8 L_u8Index = 0;
	static u8 L_u8Flag = 0;
		
	if(Rx_Data == ';'){
		L_u8Flag = 0;
		L_u8Index = 0;
	}
	if(L_u8Flag){
		gGUI_currentState = Rx_Data;
		UART_vSendData('R');
		UART_vSendData('+');
		UART_vSendData('-');
	}
	if(Rx_Data == '#'){
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