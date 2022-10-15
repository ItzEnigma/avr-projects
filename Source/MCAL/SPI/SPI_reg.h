/*
 * SPI_reg.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Dell
 */

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_

/* SPI Control Register – SPCR */

#define SPCR *((volatile u8 *)0x2D)

#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

/* SPI Status Register – SPSR */
#define SPSR *((volatile u8 *)0x2E)

#define SPI2X 0
#define WCOL 6
#define SPIF 7

/* SPI Data Register – SPDR */
#define SPDR *((volatile u8 *)0x2F)

#endif /* MCAL_SPI_SPI_REG_H_ */
