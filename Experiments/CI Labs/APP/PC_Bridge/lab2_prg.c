/*
 * lab2_prg.c
 *
 * Created: 10/21/2022 11:06:40 PM
 *  Author: john
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "../../MCAL/TIMER/TIMER_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/EXI/EXI_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/TEMPS/TEMPS_int.h"
#include "lab2_int.h"


void sendCharA(){
	UART_vSendData('A');
}

void sendCharZ(){
	UART_vSendData('Z');
}

void controller(u8 data){
	if(data=='#')
		DIO_vSetPinVal(PORTA_ID,PIN0_ID,HIGH);
	else if(data == '$')
		DIO_vSetPinVal(PORTA_ID,PIN0_ID,LOW);	
		else{
			TIMER_vPWMSignal(TIMER0,(data-48)*10);
		}
}

void lab2_vSetup(){
	//UART
	UART_vInit();
	UART_u8GetDataAsync(controller);
	
	//GIE
	GIE_vSetGlobalInterrupt();
	
	//EXI
	EXI_vINT0_Init();
	EXI_vINT1_Init();
	EXI_vRegFunc(sendCharA,INT0_FUNC);
	EXI_vRegFunc(sendCharZ,INT1_FUNC);
	
	//DIO
	DIO_vSetPinDir(PORTA_ID,PIN0_ID,DIR_OUTPUT);
	
	//TIMER
	TIMER_vInit(TIMER0);
	
	//TEMPS
	TEMPS_vInit();
}

void lab2_vloop(){
	
	static f32 tempData = 0;
	tempData = TEMPS_f32GetTemp();
	u32 u32Value = (u32)tempData;
	u8 Data_S[20];
	sprintf(Data_S,"%i",u32Value);
	UART_vSendData('#');
	UART_vSendString(Data_S);
	UART_vSendData('$');
}
