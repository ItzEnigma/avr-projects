/*
 * ADC_pri.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_PRI_H_
#define MCAL_ADC_ADC_PRI_H_

#define DIV_FACT_2 0
#define DIV_FACT_4 2
#define DIV_FACT_8 3
#define DIV_FACT_16 4
#define DIV_FACT_32 5
#define DIV_FACT_64 6
#define DIV_FACT_128 7

#define MASK_PRESCALER_VALUE 0xF8
#define MASK_CHANNEL_VALUE 0xE0
void __vector_16(void) __attribute__((signal));

#endif /* MCAL_ADC_ADC_PRI_H_ */
