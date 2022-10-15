/*
 * SERVO_prg.c
 *
 *  Created on: Sep 19, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/TIMER/TIMER_int.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SERVO_int.h"
#include "SERVO_cfg.h"
#include "SERVO_pri.h"

void SERVO_vInit()
{
    DIO_vSetPinDir(PORTD_ID, PIN5_ID, DIR_OUTPUT);
    TIMER_vInit(TIMER1);
}
void SERVO_vMoveToInitialAngle()
{
	/* 600 to OCR1AW */
    TIMER_vPWMSignal(TIMER1, 3);

}
void SERVO_vMoveToAngle(u32 A_u32Angle)
{
    switch (A_u32Angle)
    {
    case 180:
        TIMER_vPWMSignal(TIMER1, 12.5);
        break;
    case 135:
        TIMER_vPWMSignal(TIMER1, 10.125);
        break;
    case 90:
        TIMER_vPWMSignal(TIMER1, 7.75);
        break;
    case 45:
        TIMER_vPWMSignal(TIMER1, 5.375);
        break;
    default:
        break;
    }

    // TIMER_vSetOcrValue(TIMER1, 2500);
}
