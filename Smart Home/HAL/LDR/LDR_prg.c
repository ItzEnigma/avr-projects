/*
 * LDR_prg.c
 *
 *  Created on: 12 Sep 2022
 *      Author: 20109
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "LDR_cfg.h"
#include "LDR_int.h"

void LDR_vInit(){
	ADC_vInit();
}

/*LDR resistance decreases by increasing the light intensity*/
u16 LDR_u8GetValue(){
	u16 L_u8DigitalVal = ADC_u16ReadDigitalSync(LDR_CHANNEL);

	u32 L_u8AnalogVal = ( (L_u8DigitalVal * 5000UL) / 1023 ); /*in mV*/
	/* EQN: LDR = R * (VCC/AnalogVal - 1). R is connected to 5K*/
	return (5 * ((5000UL/L_u8AnalogVal) - 1)) ;
}
