/*
 * WaveGen.c
 *
 * Created: 26/11/2022 06:44:38 PM
 *  Author: 20109
 */ 

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/TIMER/TIMER_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "WaveGen_pri.h"
#include "WaveGen_int.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

u8 G_u8Buffer[3] = {100, 100, 100};
u8 sine_value[] = {128,150,171, 192, 218, 226,238, 248, 254, 255, 254, 248,238,226,210,192,171, 150, 128, 105,84,64,45,29,17,7,1,0,1,7,17,29,45,64,84,105,128};
	
void WaveGen_vInit(){
	UART_vInit();
	GIE_vSetGlobalInterrupt();
	TIMER_vInit(TIMER2);
	TIMER_vPWMSignal(TIMER2, 20);
	UART_u8GetDataAsync(dataHandler);
	DIO_vSetPortDir(WAVEGEN_PORT, 0xFF);
}

static void displaySineWave(u8 A_u8Freq, u8 A_u8Amp){
	for(u8 i=0; i<36; i++){
		DIO_vSetPortVal(WAVEGEN_PORT, sine_value[i]);
		_delay_us(5);
	}
}
static void displaySquareWave(u8 A_u8Freq, u8 A_u8Amp){
	u16 L_u8Freq = (u16)( 500.0 / (A_u8Freq * 1.0));
	DIO_vSetPortVal(WAVEGEN_PORT, 0x00);
	_delay_us(L_u8Freq);
	DIO_vSetPortVal(WAVEGEN_PORT, 0xFF);
	_delay_us(L_u8Freq);
}
static void displayTriangleWave(u8 A_u8Freq, u8 A_u8Amp){
	for(u8 i=0; i<256; i++){
		DIO_vSetPortVal(WAVEGEN_PORT, i);
		_delay_us(1);
	}
	for(u8 i=255; i>=0; i--){
		DIO_vSetPortVal(WAVEGEN_PORT, i);
		_delay_us(1);
	}
}

static void displayStaircaseWave(u8 A_u8Freq, u8 A_u8Amp){
	DIO_vSetPortVal(WAVEGEN_PORT, 0x00);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0x33);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0x66);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0x99);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0xCC);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0xFF);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0xCC);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0x99);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0x66);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0x66);
	_delay_us(100);
	DIO_vSetPortVal(WAVEGEN_PORT, 0x33);
	_delay_us(100);
}

static void stopWave(){
	DIO_vSetPortVal(WAVEGEN_PORT, 0x00);
}

/*Max freq 0-255 KHZ*/
/* # WAVE_ID FREQ	AMP $ */

void WaveGen_vUpdate(){
	displayTriangleWave(1,2);
	/*
	switch(G_u8Buffer[0]){
		case SINEWAVE_ID:		displaySignWave(G_u8Buffer[1], G_u8Buffer[2]); break;
		case TRIANGEWAVE_ID:	displayTriangleWave(G_u8Buffer[1], G_u8Buffer[2]); break;
		case SQUAREWAVE_ID:		displaySquareWave(G_u8Buffer[1], G_u8Buffer[2]); break;
		case STAIRCASE_ID:		displayStaircaseWave(G_u8Buffer[1], G_u8Buffer[2]); break;
		default:				stopWave(G_u8Buffer[1], G_u8Buffer[2]); break;
	}
	*/
}

static void dataHandler(u8 A_u8Data){
	static u8 L_u8Index = 0;
	static u8 L_u8Flag = 0;
	
	if(A_u8Data == '$'){
		L_u8Flag = 0;
		L_u8Index = 0;
	}
	if(L_u8Flag){
		G_u8Buffer[L_u8Index++] = A_u8Data;
	}
	if(A_u8Data == '#'){
		L_u8Flag = 1;
	} 
}