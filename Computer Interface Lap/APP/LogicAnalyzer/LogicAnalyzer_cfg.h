/*
 * LogicAnalyzer_pri.h
 *
 * Created: 03/12/2022 07:45:13 PM
 *  Author: 20109
 */ 


#ifndef LOGICANALYZER_CFG_H_
#define LOGICANALYZER_CFG_H_


#define	LOGIC_CHANNELS_PORT		PORTA_ID
typedef enum{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7
};

/*
*	Sample number
*	Options:
*	1- SAMPLE_25
*	2- SAMPLE_50
*	3- SAMPLE_75
*	4- SAMPLE_100
*	5- SAMPLE_125
*	6- SMAPLE_150
*	7- SAMPLE_200
*/
#define SAMPLE_NUMBER	SAMPLE_25

/*
*	Sampling frequency
*	Options:
*	1- FREQ_1KHZ
*	2- FREQ_4KHZ
*	3_ FREQ_8KHZ
*	4_ FREQ_16KHZ
*	5_ FREQ_32KHZ
*/
#define SAMPLE_FREQ		FREQ_4KHZ



#endif /* LOGICANALYZER_PRI_H_ */