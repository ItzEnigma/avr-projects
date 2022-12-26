/*
 * LCD_prg.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_pri.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include <avr/delay.h>
#include <stdlib.h>
void LCD_vInit()
{
    _delay_ms(100);
    DIO_vSetPinDir(LCD_EN_PORT, LCD_EN_PIN, DIR_OUTPUT);
    DIO_vSetPinDir(LCD_RW_PORT, LCD_RW_PIN, DIR_OUTPUT);
    DIO_vSetPinDir(LCD_RS_PORT, LCD_RS_PIN, DIR_OUTPUT);
    DIO_vSetPortDir(LCD_DATA_PORT, PORT_OUT);

#if LCD_MODE == MODE_8_BIT
    LCD_vWriteCommand(MODE_8BIT_2LINE);
    _delay_us(50);
    LCD_vWriteCommand(DISPLAY_ON_CUR_OFF_BL_OFF);
    _delay_us(50);
    LCD_vWriteCommand(CLEAR);
    _delay_ms(2);
    LCD_vWriteCommand(CURSOR_INC);
#else
    LCD_vWriteCommand(MODE_4BIt_START);
    _delay_us(50);
    LCD_vWriteCommand(MODE_4BIT_2LINE);
    _delay_us(50);
    LCD_vWriteCommand(DISPLAY_ON_CUR_OFF_BL_OFF);
    _delay_us(50);
    LCD_vWriteCommand(CLEAR);
    _delay_ms(2);
    LCD_vWriteCommand(CURSOR_INC);
#endif
}
static void LCD_vWriteCommand(u8 A_u8Cmd)
{

#if LCD_MODE == MODE_8_BIT
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    DIO_vSetPinVal(LCD_RW_PORT, LCD_RW_PIN, LOW);
    DIO_vSetPinVal(LCD_RS_PORT, LCD_RS_PIN, LOW);
    DIO_vSetPortVal(LCD_DATA_PORT, A_u8Cmd);
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, LOW);
#else
    // 4-bit
    // High
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    DIO_vSetPinVal(LCD_RW_PORT, LCD_RW_PIN, LOW);
    DIO_vSetPinVal(LCD_RS_PORT, LCD_RS_PIN, LOW);
    DIO_vSetPortVal(LCD_DATA_PORT, (A_u8Cmd & 0xF0));
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, LOW);
    // LOW
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    DIO_vSetPinVal(LCD_RW_PORT, LCD_RW_PIN, LOW);
    DIO_vSetPinVal(LCD_RS_PORT, LCD_RS_PIN, LOW);
    DIO_vSetPortVal(LCD_DATA_PORT, ((A_u8Cmd << 4) & 0xF0));
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, LOW);
#endif
}
void LCD_vDisplayString(u8 *A_u8Str)
{
    _delay_us(50);
    for (u32 i = 0; A_u8Str[i] != 0; i++) /* Send each char of string till the NULL */
    {
        LCD_vDisplayChar(A_u8Str[i]);
        _delay_us(10);
    }
}
void LCD_vDisplayChar(u8 A_u8Char)
{

#if LCD_MODE == MODE_8_BIT
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    DIO_vSetPinVal(LCD_RW_PORT, LCD_RW_PIN, LOW);
    DIO_vSetPinVal(LCD_RS_PORT, LCD_RS_PIN, HIGH);
    DIO_vSetPortVal(LCD_DATA_PORT, A_u8Char);
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, LOW);
#else
    // 4-bit
    // High
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    DIO_vSetPinVal(LCD_RW_PORT, LCD_RW_PIN, LOW);
    DIO_vSetPinVal(LCD_RS_PORT, LCD_RS_PIN, HIGH);
    DIO_vSetPortVal(LCD_DATA_PORT, (A_u8Char & 0xF0));
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, LOW);
    // Low
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    DIO_vSetPinVal(LCD_RW_PORT, LCD_RW_PIN, LOW);
    DIO_vSetPinVal(LCD_RS_PORT, LCD_RS_PIN, HIGH);
    DIO_vSetPortVal(LCD_DATA_PORT, ((A_u8Char << 4) & 0xF0));
    DIO_vSetPinVal(LCD_EN_PORT, LCD_EN_PIN, LOW);
#endif
}
void LCD_vDisplayNumInteger(u32 A_u32Num)
{
    u8 L_u8Str[20];
    sprintf(L_u8Str, "%i", A_u32Num);
    LCD_vDisplayString(L_u8Str);
}
void LCD_vDisplayNumFloat(f32 A_f32Num)
{
    u8 L_u8Str[20];
    sprintf(L_u8Str, "%f", A_f32Num);
    LCD_vDisplayString(L_u8Str);
}
void LCD_vClearDisplay()
{
    LCD_vWriteCommand(CLEAR);
    _delay_ms(2);
};
void LCD_vSetPostion(u8 A_u8Row, u8 A_u8Column)
{
    switch (A_u8Row)
    {
    case ROW0:
        LCD_vWriteCommand(ROW_0_ADD + A_u8Column);
        break;
    case ROW1:
        LCD_vWriteCommand(ROW_1_ADD + A_u8Column);
        break;
    default:
        break;
    }
};
void LCD_vShiftRight(u32 A_u8NoCells)
{
    while (A_u8NoCells > 0)
    {
        LCD_vWriteCommand(SHIFT_RIGHT);
        A_u8NoCells--;
    }
}
void LCD_vShiftLeft(u32 A_u8NoCells)
{
    while (A_u8NoCells > 0)
    {
        LCD_vWriteCommand(SHIFT_LEFT);
        A_u8NoCells--;
    }
}
void LCD_vReturnHome()
{
    LCD_vWriteCommand(RETURN_HOME);
    _delay_ms(2);
}
void LCD_vWriteSpecialChar(u8 *A_SpecialChar, u8 A_BlockNo, u8 A_u8Row, u8 A_u8Column)
{
    u8 L_u8CGRAMAdrress = 0;
    /*Write Inside CGRAM*/
    /*Address = BLOCKNO * 8  ;*/
    /*Send Command (Address + 64) //64 0100 0000 */
    L_u8CGRAMAdrress = (A_BlockNo * 8) + CG_RAM_ADDRESS;
    LCD_vWriteCommand(L_u8CGRAMAdrress);
    /*LOOP on arary of special char*/
    for (u8 k = 0; k < 8; k++)
    {
        LCD_vDisplayChar(A_SpecialChar[k]);
    }

    /*Set Location To DDRAM*/
    LCD_vSetPostion(A_u8Row, A_u8Column);
    /*Send The location of Block to display */
    LCD_vDisplayChar(A_BlockNo);
}
