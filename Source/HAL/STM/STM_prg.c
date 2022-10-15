/*
 * STM_prg.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "STM_cfg.h"
#include "STM_int.h"
#include "STM_pri.h"
#include <math.h>
#include <avr/delay.h>

static u8 G_u8DelayTimeInMs = 2, G_u8StepMode;

void STM_vInit()
{
    DIO_vSetPinDir(COIL_ORANGE_PORT, COIL_ORANGE_PIN, DIR_OUTPUT);
    DIO_vSetPinDir(COIL_YELLOW_PORT, COIL_YELLOW_PIN, DIR_OUTPUT);
    DIO_vSetPinDir(COIL_PINK_PORT, COIL_PINK_PIN, DIR_OUTPUT);
    DIO_vSetPinDir(COIL_BLUE_PORT, COIL_BLUE_PIN, DIR_OUTPUT);
}
void STM_vSetStepMode(u8 A_u8Step)
{
    G_u8StepMode = A_u8Step;
};

void STM_vSetMotorSpeedRPM(u8 A_u8MotorSpeedRpm)
{
    if (G_u8StepMode == FULL_STEP)
    {
        G_u8DelayTimeInMs = round((60 * 1.0 / (A_u8MotorSpeedRpm * (360 / STEP_ANGLE_FULL_STEP))) * 1000);
    }
    else
    {
        G_u8DelayTimeInMs = round((60 * 1.0 / (A_u8MotorSpeedRpm * (360 / STEP_ANGLE_HALF_STEP))) * 1000);
    }
}
void STM_vMoveCycle(u8 A_u8Direction)
{
    switch (G_u8StepMode)
    {
    case FULL_STEP:
        switch (A_u8Direction)
        {
        case ANTI_CLOCKWISE:
            for (u32 i = 0; i < 4; i++)
            {
                DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8FullStepSeq[i][0]);
                DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8FullStepSeq[i][1]);
                DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8FullStepSeq[i][2]);
                DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8FullStepSeq[i][3]);
                _delay_ms(G_u8DelayTimeInMs);
            }
            break;
        case CLOCKWISE:
            for (s8 i = 3; i >= 0; i--)
            {
                DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8FullStepSeq[i][0]);
                DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8FullStepSeq[i][1]);
                DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8FullStepSeq[i][2]);
                DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8FullStepSeq[i][3]);
                _delay_ms(G_u8DelayTimeInMs);
            }
            break;
        default:
            break;
        }
        break;
    case HALF_STEP:
        switch (A_u8Direction)
        {
        case ANTI_CLOCKWISE:
            for (u32 i = 0; i < 8; i++)
            {
                DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8HalfStepSeq[i][0]);
                DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8HalfStepSeq[i][1]);
                DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8HalfStepSeq[i][2]);
                DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8HalfStepSeq[i][3]);
                _delay_ms(G_u8DelayTimeInMs);
            }
            break;
        case CLOCKWISE:
            for (s8 i = 7; i >= 0; i--)
            {
                DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8HalfStepSeq[i][0]);
                DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8HalfStepSeq[i][1]);
                DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8HalfStepSeq[i][2]);
                DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8HalfStepSeq[i][3]);
                _delay_ms(G_u8DelayTimeInMs);
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void STM_vMove(u8 A_u8Direction, u32 A_u8Angle)
{
    u32 L_u8NumberSteps;
    switch (G_u8StepMode)
    {
    case FULL_STEP:
        L_u8NumberSteps = round((A_u8Angle / (STEP_ANGLE_FULL_STEP * 4)));
        switch (A_u8Direction)
        {
        case ANTI_CLOCKWISE:
            for (u32 i = 0; i < L_u8NumberSteps; i++)
            {
                for (u32 i = 0; i < 4; i++)
                {
                    DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8FullStepSeq[i][0]);
                    DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8FullStepSeq[i][1]);
                    DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8FullStepSeq[i][2]);
                    DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8FullStepSeq[i][3]);
                    _delay_ms(G_u8DelayTimeInMs);
                }
            }
            break;
        case CLOCKWISE:
            for (u32 i = 0; i < L_u8NumberSteps; i++)
            {
                for (s8 i = 3; i >= 0; i--)
                {
                    DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8FullStepSeq[i][0]);
                    DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8FullStepSeq[i][1]);
                    DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8FullStepSeq[i][2]);
                    DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8FullStepSeq[i][3]);
                    _delay_ms(G_u8DelayTimeInMs);
                }
            }
            break;
        default:
            break;
        }
        break;
    case HALF_STEP:
        L_u8NumberSteps = round((A_u8Angle / (STEP_ANGLE_HALF_STEP * 4)));
        switch (A_u8Direction)
        {
        case ANTI_CLOCKWISE:
            for (u32 i = 0; i < L_u8NumberSteps; i++)
            {
                for (u32 i = 0; i < 8; i++)
                {
                    DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8HalfStepSeq[i][0]);
                    DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8HalfStepSeq[i][1]);
                    DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8HalfStepSeq[i][2]);
                    DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8HalfStepSeq[i][3]);
                    _delay_ms(G_u8DelayTimeInMs);
                }
            }
            break;
        case CLOCKWISE:
            for (u32 i = 0; i < L_u8NumberSteps; i++)
            {
                for (s8 i = 7; i >= 0; i--)
                {
                    DIO_vSetPinVal(COIL_ORANGE_PORT, COIL_ORANGE_PIN, G_u8HalfStepSeq[i][0]);
                    DIO_vSetPinVal(COIL_YELLOW_PORT, COIL_YELLOW_PIN, G_u8HalfStepSeq[i][1]);
                    DIO_vSetPinVal(COIL_PINK_PORT, COIL_PINK_PIN, G_u8HalfStepSeq[i][2]);
                    DIO_vSetPinVal(COIL_BLUE_PORT, COIL_BLUE_PIN, G_u8HalfStepSeq[i][3]);
                    _delay_ms(G_u8DelayTimeInMs);
                }
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
};
