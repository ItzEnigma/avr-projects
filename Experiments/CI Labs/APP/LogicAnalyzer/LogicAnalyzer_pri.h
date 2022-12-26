/*
 * LogicAnalyzer_pri.h
 *
 * Created: 03/12/2022 07:48:29 PM
 *  Author: Taqi
 */ 


#ifndef LOGICANALYZER_PRI_H_
#define LOGICANALYZER_PRI_H_

#define GO_SIGNAL	'K'

/************************************************************************/
/*						Number of Samples                               */
/************************************************************************/
#define SAMPLE_25		25
#define SAMPLE_50		50
#define SAMPLE_75		75
#define SAMPLE_100		100
#define SAMPLE_125		125
#define SMAPLE_150		150
#define SAMPLE_200		200


/************************************************************************/
/*						Sampling frequency                              */
/************************************************************************/
#define FREQ_1KHZ		1
#define FREQ_4KHZ		4
#define FREQ_8KHZ		8
#define FREQ_16KHZ		16
#define FREQ_32KHZ		32



typedef enum{
	SAMPLING, SENDING
}state_t;

#define IDLE	'S'
#define MONITOR  'D'

static void dataHandler(u8 A_u8Data);
static void sampling(u8 A_u8SampleNum);
static void toHex(u8 A_u8Data);

#endif /* LOGICANALYZER_PRI_H_ */