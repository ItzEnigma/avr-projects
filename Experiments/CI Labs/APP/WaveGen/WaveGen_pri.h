/*
 * WaveGen_pri.h
 *
 * Created: 26/11/2022 06:45:27 PM
 *  Author: 20109
 */ 


#ifndef WAVEGEN_PRI_H_
#define WAVEGEN_PRI_H_

typedef struct Wave_st* WavePtr_t;

#define WAVEGEN_PORT	PORTB_ID

#define SINEWAVE_ID		0
#define TRIANGEWAVE_ID	1
#define SQUAREWAVE_ID	2
#define STAIRCASE_ID	3


static void displaySineWave(u8 A_u8Freq, u8 A_u8Amp);
static void displaySquareWave(u8 A_u8Freq, u8 A_u8Amp);
static void displayTriangleWave(u8 A_u8Freq, u8 A_u8Amp);
static void displayStaircaseWave(u8 A_u8Freq, u8 A_u8Amp);
static void dataHandler(u8 A_u8Data);

#endif /* WAVEGEN_PRI_H_ */