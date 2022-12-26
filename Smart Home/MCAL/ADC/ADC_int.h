/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: LCD	 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 31 Aug 2022	 	**************/
/*********************************************************/
#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_
/*
 *
 * Error enum that will be in the STD_TYPES
 *
 * typedef enum {
 *     error_ok,
 *     error_ADC,
 *     error_Timer,
 *     etc.....
 * }errorState_t;
 *
 *
 * */
typedef enum {
	ADC0_ID,
	ADC1_ID,
	ADC2_ID,
	ADC3_ID,
	ADC4_ID,
	ADC5_ID,
	ADC6_ID,
	ADC7_ID
};

void ADC_vInit();
void ADC_vSetPreScale(u8 A_u8PreScaleVal);
void ADC_vTurnOff();
void ADC_vReadDigitalAsync(ptr_func_Iu16_Ov ptr, u8 A_u8ADCId);
u16 ADC_u16ReadDigitalSync(u8 A_u8ADCId);

#endif /* MCAL_ADC_ADC_INT_H_ */
