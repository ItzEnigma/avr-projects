/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: LCD	 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date:  12 Sep 2022	 	**************/
/*********************************************************/
#ifndef HAL_LDR_LDR_INT_H_
#define HAL_LDR_LDR_INT_H_

void LDR_vInit();
u16 LDR_u16GetValue();

u16 LDR_ConvertValue(u16);

#endif /* HAL_LDR_LDR_INT_H_ */
