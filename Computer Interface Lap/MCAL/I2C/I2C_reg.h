/*
 * I2C_reg.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Dell
 */

#ifndef MCAL_I2C_I2C_REG_H_
#define MCAL_I2C_I2C_REG_H_

/* TWI Bit Rate Register – TWBR */
#define TWBR *((volatile u8 *)0x20)

/* TWI Control Register – TWCR */
#define TWCR *((volatile u8 *)0x56)

#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

/* TWI Status Register – TWSR */
#define TWSR *((volatile u8 *)0x21)

#define TWPS0 0
#define TWPS1 1

/* TWI Data Register – TWDR */
#define TWDR *((volatile u8 *)0x23)

/* TWAR */
#define TWAR *((volatile u8 *)0x22)
#define TWGCE 0
#endif /* MCAL_I2C_I2C_REG_H_ */
