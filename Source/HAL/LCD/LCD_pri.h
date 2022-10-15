/*
 * LCD_pri.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Dell
 */

#ifndef HAL_LCD_LCD_PRI_H_
#define HAL_LCD_LCD_PRI_H_

#define MODE_4_BIT 0
#define MODE_8_BIT 1

#define CLEAR 0x01
#define RETURN_HOME 0x02
#define CURSOR_INC 0x06
#define DISPLAY_OFF 0x08			   // Display off / Cursor off / blink off
#define DISPLAY_ON_CUR_OFF_BL_OFF 0x0C // Display on / Cursor off / blink off
#define DISPLAY_ON_CUR_ON_BL_OFF 0x0E  // Display on / Cursor on / blink off
#define DISPLAY_ON_CUR_ON_BL_ON 0x0F   // Display on / Cursor on / blink on
#define MODE_8BIT_1LINE 0x30
#define MODE_8BIT_2LINE 0x38
#define MODE_4BIT_1LINE 0x20
#define MODE_4BIT_2LINE 0x28
#define MODE_4BIt_START 0x02

#define ROW_0_ADD 0x80
#define ROW_1_ADD 0xC0
#define CG_RAM_ADDRESS 0x40
#define SHIFT_RIGHT 0x1C
#define SHIFT_LEFT 0x18
/*
 u8 Alef[8] = {
	0b00001000,
	0b00001000,
	0b00001000,
	0b00001000,
	0b00001000,
	0b00001000,
	0b00001000,
	0b0000000};
u8 haa[8] = {
	0b00000000,
	0b00011000,
	0b00001100,
	0b00000011,
	0b00011111,
	0b00000000,
	0b00000000,
	0b00000000};
u8 mem[8] = {
	0b00000000,
	0b00000000,
	0b00001100,
	0b00011011,
	0b00011111,
	0b00000000,
	0b00000000,
	0b00000000};
u8 dal[8] = {
	0b00000000,
	0b00000000,
	0b00000011,
	0b00000011,
	0b00011111,
	0b00000000,
	0b00000000,
	0b00000000};
u8 person[8] = {

	0b00000100,
	0b00001110,
	0b00000100,
	0b00001110,
	0b00010101,
	0b00001110,
	0b00001011,
	0b00000000};
u8 personW[8] = {
	0b00000100,
	0b00001101,
	0b00000111,
	0b00001100,
	0b00010100,
	0b00001110,
	0b00001010,
	0b00000000};

 * */
#endif /* HAL_LCD_LCD_PRI_H_ */
