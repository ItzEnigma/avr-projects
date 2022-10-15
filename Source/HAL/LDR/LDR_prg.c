/*
 * LDR_prg.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "LDR_pri.h"
#include "LDR_cfg.h"
#include "LDR_int.h"

void LDR_vInit(){
	 ADC_vInit();
}
f32 LDR_f32GetLuxValue(){
	u16 L_u16DigitalReading;
	f32 L_f32OutputVolt, L_f32LuxValue,L_f32LdrResValue;
	L_u16DigitalReading =ADC_u16ReadDigitalDataSync(ADC0);
	L_f32OutputVolt = L_u16DigitalReading * REFERENCE_VOLTAGE / TWO_POWER_ADC_RESOLUTION;
	L_f32LdrResValue =  (RES_KO * INPUT_VOLT - RES_KO * L_f32OutputVolt) / 	L_f32OutputVolt;
	L_f32LuxValue = 500.0/ (L_f32LdrResValue/1000);
	return (L_f32LuxValue);
}
