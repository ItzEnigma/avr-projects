/*
 * KEYPAD_prg.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "KEYPAD_pri.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_int.h"
#include <avr/delay.h>
void KP_vInit()
{
    // SET ROWS AS INPUTS
    for (u32 PIN = ROW_START_PIN; PIN <= ROW_END_PIN; PIN++)
    {
        DIO_vSetPinDir(KEYPAD_PORT, PIN, DIR_INPUT);
        DIO_vSetPinVal(KEYPAD_PORT, PIN, HIGH);
    }
    // SET COLUMS AS OUTPUTS
    for (u32 PIN = COLUMN_START_PIN; PIN <= COLUMN_END_PIN; PIN++)
    {
        DIO_vSetPinDir(KEYPAD_PORT, PIN, DIR_OUTPUT);
        DIO_vSetPinVal(KEYPAD_PORT, PIN, HIGH);
    }
}
u8 KP_u8ReadKP()
{
    u32 L_u8SaveRow = -1, L_u8SaveColumn = -1;
    u8 L_u8Value, L_u8Flag = 1;
    const u8 L_u8KeyPad[4][4] =
        {{'7', '8', '9', '-'},
         {'4', '5', '6', '+'},
         {'1', '2', '3', '*'},
         {'0', 'c', '=', '/'}};

    for (u32 c = 0; c < 4; c++)
    {
        DIO_vSetPinVal(KEYPAD_PORT, COLUMN_START_PIN + c, LOW);
        for (u32 r = 0; r < 4; r++)
        {
            if (DIO_u8GetPinVal(KEYPAD_PORT, ROW_START_PIN + r) == 0)
            {
                while (DIO_u8GetPinVal(KEYPAD_PORT, ROW_START_PIN + r) == 0)
                    ;
                L_u8SaveRow = r;
                L_u8SaveColumn = c;
                L_u8Flag = 0;
                _delay_ms(15);
                break;
            }
        }
        DIO_vSetPinVal(KEYPAD_PORT, COLUMN_START_PIN + c, HIGH);
        if (L_u8Flag == 0)
        {
            break;
        }
    }

    if (L_u8SaveRow == -1 && L_u8SaveColumn == -1)
    {
        L_u8Value = NOT_PRESSED;
    }
    else
    {
        L_u8Value = L_u8KeyPad[L_u8SaveRow][L_u8SaveColumn];
    }

    return L_u8Value;
}
