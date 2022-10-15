/*
 * DIO_reg.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Dell
 */

#ifndef MCAL_DIO_DIO_REG_H_
#define MCAL_DIO_DIO_REG_H_

#define PORTA *((u8 *) 0x3B) //the content of this address and u8 because it's 8 bit
#define DDRA *(( u8 *) 0X3A)
#define PINA *((volatile u8 *) 0x3A)

#define PORTB *((u8 *) 0x38) //the content of this address and u8 because it's 8 bit
#define DDRB *(( u8 *) 0X37)
#define PINB *((volatile u8 *) 0x36)

#define PORTC *((u8 *) 0x35) //the content of this address and u8 because it's 8 bit
#define DDRC *(( u8 *) 0X34)
#define PINC *((volatile u8 *) 0x33)

#define PORTD *((u8 *) 0x32) //the content of this address and u8 because it's 8 bit
#define DDRD *(( u8 *) 0X31)
#define PIND *((volatile u8 *) 0x30)

#endif /* MCAL_DIO_DIO_REG_H_ */
