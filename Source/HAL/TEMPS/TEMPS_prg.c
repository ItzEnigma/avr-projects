/*
 * TEMPS_prg.c
 *
 *  Created on: Sep 4, 2022
 *      Author: Dell
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "TEMPS_pri.h"
#include "TEMPS_cfg.h"
#include "TEMPS_int.h"


void TEMPS_vInit()
{
    ADC_vInit();
}

f32 TEMPS_f32GetTemp()
{
    u16 L_u16ReadingDigital;
    f32 L_u16ReadingAnalogue;
    f32 L_f32Temp;
    L_u16ReadingDigital = ADC_u16ReadDigitalDataSync(TEMP_SENSOR_PIN);
    L_u16ReadingAnalogue = (L_u16ReadingDigital * REFERENCE_VOLTAGE) / TWO_POWER_ADC_RESOLUTION;
    L_f32Temp = L_u16ReadingAnalogue / 10;
    return L_f32Temp;
}
