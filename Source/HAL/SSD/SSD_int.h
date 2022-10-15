/*
 * SSD_int.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Dell
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

typedef enum
{
    SSD0,
    SSD1
};

void SSD_vInit(u8 A_u8SSDId);
void SSD_vTurnOn(u8 A_u8SSDId);
void SSD_vTurnOff(u8 A_u8SSDId);
void SSD_vDisplayNumber(u8 A_u8SSDId, u8 A_u8Number);
void SSD_vTurnOnRightSide(u8 A_u8SSDId);
void SSD_vTurnOnLeftSide(u8 A_u8SSDId);

#endif /* HAL_SSD_SSD_INT_H_ */
