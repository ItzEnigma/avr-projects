/*
 * GIE_reg.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Dell
 */

#ifndef MCAL_GIE_GIE_REG_H_
#define MCAL_GIE_GIE_REG_H_

typedef enum{
	C, /* Carry Flag */
	Z, /* Zero Flag */
	N, /* Negative Flag */
	V, /* Overflow Flag */
	S, /* Sign Flag */
	H, /* Half Carry Flag */
	T, /* Bit Copy Storage */
	I  /* Interrupt Flag */
};

#define SREG *((volatile u8 *) 0x5F)
#endif /* MCAL_GIE_GIE_REG_H_ */
