/*
 * EEPROM_int.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Dell
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

void EEPROM_Init();
void EEPROM_sendDataByte(u8 DataByte, u16 Address);
u8 EEPROM_readDataByte(u16 Address);

#endif /* HAL_EEPROM_EEPROM_INT_H_ */
