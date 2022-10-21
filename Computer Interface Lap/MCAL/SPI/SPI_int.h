/*
 * SPI_int.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Dell
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

void SPI_vMasterInit(void);
void SPI_vSlaveInit(void);
u8 SPI_u8Traceiver(u8 A_u8Data);
void SPI_vTransmitData(u8 A_u8Data);
void SPI_vTransmitString(u8 *A_u8Data);
u8 SPI_u8ReceiveData(void);

void SPI_vTransmitDataAsync(u8 A_u8Data);
void SPI_vReciceveDataAsync(FUNC_PTR_Iu8_OV A_Fptr);
#endif /* MCAL_SPI_SPI_INT_H_ */
