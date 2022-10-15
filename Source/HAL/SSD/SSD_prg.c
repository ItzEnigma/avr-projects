/*
 * SSD_prg.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Dell
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "SSD_pri.h"
#include "SSD_cfg.h"
#include "SSD_int.h"
#include <avr/delay.h>

void SSD_vInit(u8 A_u8SSDId)
{
#if SSD_COMM == CATHODE
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPortDir(SSD0_DATA_PORT, PORT_OUT);
        DIO_vSetPinDir(SSD0_EN_PORT, SSD0_EN_PIN, DIR_OUTPUT);
        DIO_vSetPortVal(SSD1_DATA_PORT, PORT_LOW);
        DIO_vSetPinVal(SSD0_EN_PORT, SSD0_EN_PIN, LOW);
        break;
    case SSD1:
        DIO_vSetPortDir(SSD1_DATA_PORT, PORT_OUT);
        DIO_vSetPinDir(SSD1_EN_PORT, SSD1_EN_PIN, DIR_OUTPUT);
        DIO_vSetPortVal(SSD1_DATA_PORT, PORT_LOW);
        DIO_vSetPinVal(SSD1_EN_PORT, SSD1_EN_PIN, LOW);
        break;
    default:
        break;
    }
#else
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPortDir(SSD0_DATA_PORT, PORT_OUT);
        DIO_vSetPinDir(SSD0_EN_PORT, SSD0_EN_PIN, DIR_OUTPUT);
        DIO_vSetPortVal(SSD1_DATA_PORT, PORT_HIGH);
        DIO_vSetPinVal(SSD0_EN_PORT, SSD0_EN_PIN, HIGH);
        break;
    case SSD1:
        DIO_vSetPortDir(SSD1_DATA_PORT, PORT_OUT);
        DIO_vSetPinDir(SSD1_EN_PORT, SSD1_EN_PIN, DIR_OUTPUT);
        DIO_vSetPortVal(SSD1_DATA_PORT, PORT_HIGH);
        DIO_vSetPinVal(SSD1_EN_PORT, SSD1_EN_PIN, HIGH);
        break;
    default:
        break;
    }
#endif
};

void SSD_vTurnOn(u8 A_u8SSDId)
{
#if SSD_COMM == CATHODE
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPinVal(SSD0_EN_PORT, SSD0_EN_PIN, LOW);
        break;
    case SSD1:
        DIO_vSetPinVal(SSD1_EN_PORT, SSD1_EN_PIN, LOW);
        break;
    default:
        break;
    }
#else
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPinVal(SSD0_EN_PORT, SSD0_EN_PIN, HIGH);
        break;
    case SSD1:
        DIO_vSetPinVal(SSD1_EN_PORT, SSD1_EN_PIN, HIGH);
        break;
    default:
        break;
    }
#endif
}
void SSD_vTurnOff(u8 A_u8SSDId)
{
#if SSD_COMM == CATHODE
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPinVal(SSD0_EN_PORT, SSD0_EN_PIN, HIGH);
        break;
    case SSD1:
        DIO_vSetPinVal(SSD1_EN_PORT, SSD1_EN_PIN, HIGH);
        break;
    default:
        break;
    }
#else
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPinVal(SSD0_EN_PORT, SSD0_EN_PIN, LOW);
        break;
    case SSD1:
        DIO_vSetPinVal(SSD1_EN_PORT, SSD1_EN_PIN, LOW);
        break;
    default:
        break;
    }
#endif
}
void SSD_vDisplayNumber(u8 A_u8SSDId, u8 A_u8Number)
{
    static const u8 L_u8NumbersCathode[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

#if SSD_COMM == CATHODE
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPortVal(SSD0_DATA_PORT, L_u8NumbersCathode[A_u8Number]);
        break;
    case SSD1:
        DIO_vSetPortVal(SSD1_DATA_PORT, L_u8NumbersCathode[A_u8Number]);
        break;
    default:
        break;
    }
#else
    switch (A_u8SSDId)
    {
    case SSD0:
        DIO_vSetPortVal(SSD0_DATA_PORT, ~L_u8NumbersCathode[A_u8Number]);
        break;
    case SSD1:
        DIO_vSetPortVal(SSD1_DATA_PORT, ~L_u8NumbersCathode[A_u8Number]);
        break;
    default:
        break;
    }
#endif
};

void SSD_vTurnOnRightSide(u8 A_u8SSDId)
{
    switch (A_u8SSDId)
    {
    case SSD0:
        for (u8 i = 0; i < 4; i++)
        {
            DIO_vSetPortVal(SSD0_DATA_PORT, (1 << i));
            _delay_ms(500);
        }
        DIO_vSetPortVal(SSD0_DATA_PORT, 0x00);
        break;
    case SSD1:
        for (u8 i = 0; i < 4; i++)
        {
            DIO_vSetPortVal(SSD1_DATA_PORT, (1 << i));
            _delay_ms(500);
        }
        DIO_vSetPortVal(SSD1_DATA_PORT, 0x00);
        break;

    default:
        break;
    }
};
void SSD_vTurnOnLeftSide(u8 A_u8SSDId)
{
    switch (A_u8SSDId)
    {
    case SSD0:
        for (u8 i = 3; i < 6; i++)
        {
            DIO_vSetPortVal(SSD0_DATA_PORT, (1 << i));
            _delay_ms(500);
        }
        DIO_vSetPortVal(SSD0_DATA_PORT, (1 << 0));
        _delay_ms(500);
        DIO_vSetPortVal(SSD1_DATA_PORT, 0x00);
    case SSD1:
        for (u8 i = 3; i < 6; i++)
        {
            DIO_vSetPortVal(SSD1_DATA_PORT, (1 << i)); // 3 00001000 //4 00010000 //5 00100000 //
            _delay_ms(500);
        }
        DIO_vSetPortVal(SSD1_DATA_PORT, (1 << 0));
        _delay_ms(500);
        DIO_vSetPortVal(SSD1_DATA_PORT, 0x00);
        break;

    default:
        break;
    }
};
