/*
 * DCM_prg.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "DCM_cfg.h"
#include "DCM_int.h"
#include "../TRANSISTORS/TRANSISTORS_int.h"

DCM_vInit()
{
    TRANSISTOR_vInit(TRANS1);
    TRANSISTOR_vInit(TRANS2);
}
DCM_vSetDirection(u8 A_u8Direction)
{
    switch (A_u8Direction)
    {
    case CLOCKWISE:
        TRANSISTOR_vTurnOn(TRANS1);
        TRANSISTOR_vTurnOff(TRANS2);

        break;
    case ANTI_CLOCKWISE:
        TRANSISTOR_vTurnOff(TRANS1);
        TRANSISTOR_vTurnOn(TRANS2);
        break;
    case STOP:
        TRANSISTOR_vTurnOff(TRANS1);
        TRANSISTOR_vTurnOff(TRANS2);
        break;
    default:
        break;
    }
}
