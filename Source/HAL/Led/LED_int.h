/*
 * LED_int.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Dell
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

typedef enum
{
	LED0,
	LED1,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6,
	LED7,
};

void LED_vInit(u8 A_u8LEDNo);
void LED_vTurnOn(u8 A_u8LEDNo);
void LED_vTurnOff(u8 A_u8LEDNo);

#endif /* HAL_LED_LED_INT_H_ */
