/*
 * LCD_int.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Dell
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

typedef enum
{
    ROW0,
    ROW1
};

typedef enum
{
    COLUMN0,
    COLUMN1,
    COLUMN2,
    COLUMN3,
    COLUMN4,
    COLUMN5,
    COLUMN6,
    COLUMN7,
    COLUMN8,
    COLUMN9,
    COLUMN10,
    COLUMN11,
    COLUMN12,
    COLUMN13,
    COLUMN14,
    COLUMN15
};
typedef enum
{
    BLOCK0,
    BLOCK1,
    BLOCK2,
    BLOCK3,
    BLOCK4,
    BLOCK5,
    BLOCK6,
    BLOCK7,
};
void LCD_vInit();
static void LCD_vWriteCommand(u8 A_u8Cmd);
void LCD_vDisplayString(u8 *A_u8Str);
void LCD_vDisplayChar(u8 A_u8Char);
void LCD_vDisplayNumInteger(u32 A_u32Num);
void LCD_vDisplayNumFloat(f32 A_u32Num);
void LCD_vClearDisplay();
void LCD_vSetPostion(u8 A_u8Row, u8 A_u8Column);
void LCD_vShiftRight(u32 A_u8NoCells);
void LCD_vShiftLeft(u32 A_u8NoCells);
void LCD_vReturnHome();
void LCD_vWriteSpecialChar(u8 *A_SpecialChar, u8 A_BlockNo, u8 A_u8Row, u8 A_u8Column);
#endif /* HAL_LCD_LCD_INT_H_ */
