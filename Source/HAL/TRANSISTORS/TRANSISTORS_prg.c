/*
 * TRANSISTORS_prg.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "TRANSISTORS_pri.h"
#include "TRANSISTORS_cfg.h"
#include "TRANSISTORS_int.h"
void TRANSISTOR_vInit(u8 A_u8TransID)
{
    switch (A_u8TransID)
    {
    case TRANS0:
        DIO_vSetPinDir(TRANS0_PORT, TRANS0_PIN, DIR_OUTPUT);
        break;
    case TRANS1:
        DIO_vSetPinDir(TRANS1_PORT, TRANS1_PIN, DIR_OUTPUT);
        break;
    case TRANS2:
        DIO_vSetPinDir(TRANS2_PORT, TRANS2_PIN, DIR_OUTPUT);
        break;
    case TRANS3:
        DIO_vSetPinDir(TRANS3_PORT, TRANS3_PIN, DIR_OUTPUT);
        break;

    default:
        break;
    }
}
void TRANSISTOR_vTurnOn(u8 A_u8TransID)
{
    switch (A_u8TransID)
    {
    case TRANS0:
        DIO_vSetPinVal(TRANS0_PORT, TRANS0_PIN, HIGH);
        break;
    case TRANS1:
        DIO_vSetPinVal(TRANS1_PORT, TRANS1_PIN, HIGH);
        break;
    case TRANS2:
        DIO_vSetPinVal(TRANS2_PORT, TRANS2_PIN, HIGH);
        break;
    case TRANS3:
        DIO_vSetPinVal(TRANS3_PORT, TRANS3_PIN, HIGH);
        break;

    default:
        break;
    }
}
void TRANSISTOR_vTurnOff(u8 A_u8TransID)
{
    switch (A_u8TransID)
    {
    case TRANS0:
        DIO_vSetPinVal(TRANS0_PORT, TRANS0_PIN, LOW);
        break;
    case TRANS1:
        DIO_vSetPinVal(TRANS1_PORT, TRANS1_PIN, LOW);
        break;
    case TRANS2:
        DIO_vSetPinVal(TRANS2_PORT, TRANS2_PIN, LOW);
        break;
    case TRANS3:
        DIO_vSetPinVal(TRANS3_PORT, TRANS3_PIN, LOW);
        break;

    default:
        break;
    }
}