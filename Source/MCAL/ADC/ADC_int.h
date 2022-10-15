/*
 * ADC_int.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

void ADC_vInit(void);
u16 ADC_u16ReadDigitalDataSync(u8 A_u8AdcChannel);
void ADC_vReadDigitalDataAsync(FUNC_PTR_Iu16_OV A_PTR_FUNC, u8 A_u8AdcChannel);

#endif /* MCAL_ADC_ADC_INT_H_ */
