/*
 * EXI_pri.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Dell
 */

#ifndef MCAL_EXI_EXI_PRI_H_
#define MCAL_EXI_EXI_PRI_H_

#define INT0_LOW_LEVEL 0
#define INT0_LOGICAL_CHANGE 1
#define INT0_FALLING_EDGE 2
#define INT0_RISING_EDGE 3

#define INT1_LOW_LEVEL 0
#define INT1_LOGICAL_CHANGE 1
#define INT1_FALLING_EDGE 2
#define INT1_RISING_EDGE 3

#define INT2_FALLING_EDGE 0
#define INT2_RISING_EDGE 1

void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));
void __vector_3 (void) __attribute__((signal));
#endif /* MCAL_EXI_EXI_PRI_H_ */
