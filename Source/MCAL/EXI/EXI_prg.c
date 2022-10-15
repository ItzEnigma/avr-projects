/*
 * EXI_prg.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Dell
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"
#include "../DIO/DIO_int.h"

#include "EXI_reg.h"
#include "EXI_int.h"
#include "EXI_cfg.h"
#include "EXI_pri.h"

static void (*G_vISRptr0)(void);
static void (*G_vISRptr1)(void);
static void (*G_vISRptr2)(void);
void EXI_vINT0_Init(void)
{
    /*Configure INT0 PIN as INPUT , Turn on pull up*/
    DIO_vSetPinDir(INT0_PORT, INT0_PIN, DIR_INPUT);
    DIO_vSetPinVal(INT0_PORT, INT0_PIN, HIGH);
    /*Enable INT0*/
    SET_BIT(GICR, INT0);
    /*configure INT0 Mode as The Mode Configured in CFG File*/
    MCUCR = (MCUCR & 0xFC) | (INT0_MODE << ISC00);
}
void EXI_vINT1_Init(void)
{
    /*Configure INT1 PIN as INPUT , Turn on pull up*/
    DIO_vSetPinDir(INT1_PORT, INT1_PIN, DIR_INPUT);
    DIO_vSetPinVal(INT1_PORT, INT1_PIN, HIGH);
    /*Enable INT1*/
    SET_BIT(GICR, INT1);
    /*configure INT1 Mode as The Mode Configured in CFG File*/
    MCUCR = (MCUCR & 0xF3) | (INT1_MODE << ISC10);
}
void EXI_vINT2_Init(void)
{
    /*Configure INT2 PIN as INPUT , Turn on pull up*/
    DIO_vSetPinDir(INT2_PORT, INT2_PIN, DIR_INPUT);
    DIO_vSetPinVal(INT2_PORT, INT2_PIN, HIGH);
    /*Enable INT2*/
    SET_BIT(GICR, INT2);
    /*configure INT2 Mode as The Mode Configured in CFG File*/
    MCUCSR = (MCUCSR & 0xBF) | (INT2_MODE << ISC2);
}
void EXI_vRegFunc(void (*ISR_PTR)(void), u8 A_u8INT)
{
    switch (A_u8INT)
    {
    case INT0_FUNC:
        G_vISRptr0 = ISR_PTR;
        break;
    case INT1_FUNC:
        G_vISRptr1 = ISR_PTR;
        break;
    case INT2_FUNC:
        G_vISRptr2 = ISR_PTR;
        break;
    default:
        break;
    }
}
void __vector_1(void)
{
    G_vISRptr0();
}
void __vector_2(void)
{
    G_vISRptr1();
}
void __vector_3(void)
{
    G_vISRptr2();
}