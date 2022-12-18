/*
 * Osc_pri.h
 *
 * Created: 12/8/2022 8:22:21 PM
 *  Author: hosam
 */ 


#ifndef OSC_PRI_H_
#define OSC_PRI_H_

#define _SAMPLES_NUM 250

/* Oscilloscope States */
typedef enum{
	SAMPLING, SENDING, IDLE
} states_t;

#define CONTINUOUS		'C'
#define DISCONTINUOUS	'D'
#define STOP			'S'

static void UART_ReceiveHander(u8);
static void toHex(u8 A_u8Data);

#endif /* OSC_PRI_H_ */