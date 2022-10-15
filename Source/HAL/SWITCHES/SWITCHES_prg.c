/*
 * SWITCHES_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "SWITCHES_pri.h"
#include "SWITCHES_cfg.h"
#include "SWITCHES_int.h"

void SWT_vInit(u8 A_u8SwtID)
{
    switch (A_u8SwtID)
    {
    case SWT0:
        DIO_vSetPinDir(SWT0_PORT, SWT0_PIN, DIR_INPUT);
        break;
    case SWT1:
        DIO_vSetPinDir(SWT1_PORT, SWT1_PIN, DIR_INPUT);
        break;
    case SWT2:
        DIO_vSetPinDir(SWT2_PORT, SWT2_PIN, DIR_INPUT);
        break;
    case SWT3:
        DIO_vSetPinDir(SWT3_PORT, SWT3_PIN, DIR_INPUT);
        break;
    case SWT4:
        DIO_vSetPinDir(SWT4_PORT, SWT4_PIN, DIR_INPUT);
        break;
    case SWT5:
        DIO_vSetPinDir(SWT5_PORT, SWT5_PIN, DIR_INPUT);
        break;
    case SWT6:
        DIO_vSetPinDir(SWT6_PORT, SWT6_PIN, DIR_INPUT);
        break;
    case SWT7:
        DIO_vSetPinDir(SWT7_PORT, SWT7_PIN, DIR_INPUT);
        break;
    default:
        break;
    }
#if SWT_PULLING == INTERNAL_PULLUP
    switch (A_u8SwtID)
    {
    case SWT0:
        DIO_vSetPinVal(SWT0_PORT, SWT0_PIN, HIGH);
        break;
    case SWT1:
        DIO_vSetPinVal(SWT1_PORT, SWT1_PIN, HIGH);
        break;
    case SWT2:
        DIO_vSetPinVal(SWT2_PORT, SWT2_PIN, HIGH);
        break;
    case SWT3:
        DIO_vSetPinVal(SWT3_PORT, SWT3_PIN, HIGH);
        break;
    case SWT4:
        DIO_vSetPinVal(SWT4_PORT, SWT4_PIN, HIGH);
        break;
    case SWT5:
        DIO_vSetPinVal(SWT5_PORT, SWT5_PIN, HIGH);
        break;
    case SWT6:
        DIO_vSetPinVal(SWT6_PORT, SWT6_PIN, HIGH);
        break;
    case SWT7:
        DIO_vSetPinVal(SWT7_PORT, SWT7_PIN, HIGH);
        break;
    default:
        break;
    }
#endif
}
void SWT_vInitAllSwt()
{
    SWT_vInit(SWT0);
    SWT_vInit(SWT1);
    SWT_vInit(SWT2);
    SWT_vInit(SWT3);
    SWT_vInit(SWT4);
    SWT_vInit(SWT5);
    SWT_vInit(SWT6);
    SWT_vInit(SWT7);
}
u8 SWT_u8ReadSwt(u8 A_u8SwtID)
{
    u8 L_u8SwtState;
    switch (A_u8SwtID)
    {
    case SWT0:
        L_u8SwtState = DIO_u8GetPinVal(SWT0_PORT, SWT0_PIN);
        break;
    case SWT1:
        L_u8SwtState = DIO_u8GetPinVal(SWT1_PORT, SWT1_PIN);
        break;
    case SWT2:
        L_u8SwtState = DIO_u8GetPinVal(SWT2_PORT, SWT2_PIN);
        break;
    case SWT3:
        L_u8SwtState = DIO_u8GetPinVal(SWT3_PORT, SWT3_PIN);
        break;
    case SWT4:
        L_u8SwtState = DIO_u8GetPinVal(SWT4_PORT, SWT4_PIN);
        break;
    case SWT5:
        L_u8SwtState = DIO_u8GetPinVal(SWT5_PORT, SWT5_PIN);
        break;
    case SWT6:
        L_u8SwtState = DIO_u8GetPinVal(SWT6_PORT, SWT6_PIN);
        break;
    case SWT7:
        L_u8SwtState = DIO_u8GetPinVal(SWT7_PORT, SWT7_PIN);
        break;
    default:
        break;
    }
    if (L_u8SwtState == 0)
    {
        L_u8SwtState = SWT_ON;
    }
    else
    {
        L_u8SwtState = SWT_OFF;
    }
    return L_u8SwtState;
}
u8 SWT_u8ReadAllSwt()
{
    u8 L_u8SwtVal;
    L_u8SwtVal = SWT_u8ReadSwt(SWT0) << 0 | SWT_u8ReadSwt(SWT1) << 1 | SWT_u8ReadSwt(SWT3) << 3 | SWT_u8ReadSwt(SWT4) << 4 | SWT_u8ReadSwt(SWT5) << 5 | SWT_u8ReadSwt(SWT6) << 6 | SWT_u8ReadSwt(SWT7) << 7;
    return L_u8SwtVal;
}
