/*
 * ADC_prg.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Dell
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "../DIO/DIO_int.h"

#include "ADC_reg.h"
#include "ADC_pri.h"
#include "ADC_cfg.h"
#include "ADC_int.h"
FUNC_PTR_Iu16_OV G_vISRptr;
void ADC_vInit(void)
{
    /*Set Reference REFS1 REFS0 AVCC with external capcitor 0 1 */
    SET_BIT(ADMUX, REFS0);
    CLR_BIT(ADMUX, REFS1);
    /*Enable ADC*/
    SET_BIT(ADCSRA, ADEN);
    /*Set ADLAR to right adjustment set it to 0*/
    CLR_BIT(ADMUX, ADLAR);
    /* Set prescaler to 128 */
    ADCSRA = (ADCSRA & MASK_PRESCALER_VALUE) | PRESCALER_MODE;
    /*if we use auto trigger set it*/
}
u16 ADC_u16ReadDigitalDataSync(u8 A_u8AdcChannel)
{
    /*SELECT THE CHANNEL*/
    ADMUX = (ADMUX & 0xE0) | A_u8AdcChannel;
    /*START CONVERSION*/
    SET_BIT(ADCSRA, ADSC);
    /*Wait for conversion to end*/
    while (READ_BIT(ADCSRA, ADIF) == 0)
    {
        /*Wait*/
    }
    SET_BIT(ADCSRA, ADIF);

    return ADCW;
}
void ADC_vReadDigitalDataAsync(FUNC_PTR_Iu16_OV A_PTR_FUNC, u8 A_u8AdcChannel)
{
    /*SELECT THE CHANNEL*/
    ADMUX = (ADMUX & 0xE0) | A_u8AdcChannel;
    /*Enable Interrupt*/
    SET_BIT(ADCSRA, ADIE);
    /*Assign Function*/
    G_vISRptr = A_PTR_FUNC;
    /*START CONVERSION*/
    SET_BIT(ADCSRA, ADSC);
}

void __vector_16(void)
{

    G_vISRptr(ADCW);
    /*Disable The ADC Interrupt*/
    CLR_BIT(ADCSRA, ADIE);
}
