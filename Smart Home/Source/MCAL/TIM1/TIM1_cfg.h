/*
 * TIM0_cfg.h
 *
 *  Created on: 3 Oct 2022
 *      Author: 20109
 */

#ifndef MCAL_TIM0_TIM0_CFG_H_
#define MCAL_TIM0_TIM0_CFG_H_


/**************   TIMER1_config   **************/


/* WaveForm generation Mode
 *
 * Options:
 * 1- TIMER1_WGM_NORMAL_MODE
 * 2- TIMER1_WGM_PWM_PHASE_CORRECT_8BIT_MODE
 * 3- TIMER1_WGM_PWM_PHASE_CORRECT_9BIT_MODE
 * 4- TIMER1_WGM_PWM_PHASE_CORRECT_10BIT_MODE
 * 5- TIMER1_WGM_CTC_MODE
 * 6- TIMER1_WGM_FAST_PWM_8BIT_MODE
 * 7- TIMER1_WGM_FAST_PWM_9BIT_MODE
 * 8- TIMER1_WGM_FAST_PWM_10BIT_MODE
 * 9- TIMER1_WGM_PWM_PHASE_CORRECT_TOP_ICR1
 * 10-TIMER1_WGM_PWM_PHASE_CORRECT_TOP_OCR1A
 * 11-TIMER1_WGM_CTC_TOP_ICR1
 * 12-TIMER1_WGM_FAST_PWM_TOP_ICR1
 * 13-TIMER1_WGM_FAST_PWM_TOP_OCR1A
 * */
#define TIMER1_WGM_MODE TIMER1_WGM_FAST_PWM_8BIT_MODE



/* Compare Match Output Mode (OC1x Pin)	CTC
 *
 * Options:
 * 1- TIMER1_OC1x_DISCONNECT
 * 2- TIMER1_TOG_OC1x
 * 3- TIMER1_CLR_OC1x
 * 4- TIMER1_SET_OC1x
 * */
#define TIMER1_OC1A_MODE TIMER1_OC1x_DISCONNECT
#define TIMER1_OC1B_MODE TIMER1_OC1x_DISCONNECT



/* Clock select
 *
 * Options:
 * 1- TIMER1_PRESCALER_NO_CLK
 * 2- TIMER1_PRESCALER_NO_PRESCALE
 * 3- TIMER1_PRESCALER_8
 * 4- TIMER1_PRESCALER_32
 * 5- TIMER1_PRESCALER_64
 * 6- TIMER1_PRESCALER_128
 * 7- TIMER1_PRESCALER_256
 * 8- TIMER1_PRESCALER_1024
 * */
#define TIMER1_CLK_SELECT TIMER1_PRESCALER_1024


/* Timers state
 *
 * Options:
 * 1- TIMER_ENABLE
 * 2- TIMER_DISABLE
 * */
#define TIMER1_STATE TIMER_ENABLE



/* interrupt state
 *
 * Options:
 * 1- INT_ENABLE
 * 2- INT_DISABLE
 * */
#define TIMER1_OVF_INT_STATE	INT_DISABLE
#define TIMER1_OCF1A_INT_STATE	INT_DISABLE
#define TIMER1_OCF1B_INT_STATE	INT_DISABLE
#define TIMER1_ICF1_INT_STATE	INT_DISABLE


/* TIMER1 PWM mode
 *
 * Options:
 * 1- PWM_NON_INVERTING
 * 2- PWM_INVERTING
 * 3- PWM_OFF
 * Note:
 * PWM_NON_INVERTING means the Duty cycle is directly proportional to OCR1x
 * PWM_INVERTING means the Duty cycle is inversely proportional to OCR1x
 * */
#define TIMER1_OC1A_PWM_MODE PWM_NON_INVERTING
#define TIMER1_OC1B_PWM_MODE PWM_NON_INVERTING


/* TIMER1 FCPU frequency
 *
 *	Options:
 *	user specify the frequency
 * */
#define TIMER1_InputFreq 8000000UL


/* OC1x Pin Configuration */
#define OC1A_PORT PORTD_ID
#define OC1A_PIN  PIN5_ID
#define OC1B_PORT PORTD_ID
#define OC1B_PIN  PIN4_ID

#endif /* MCAL_TIM0_TIM0_CFG_H_ */
