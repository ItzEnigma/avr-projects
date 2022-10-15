/*
 * EXI_int.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Dell
 */

#ifndef MCAL_EXI_EXI_INT_H_
#define MCAL_EXI_EXI_INT_H_

#define INT0_FUNC 0
#define INT1_FUNC 1
#define INT2_FUNC 2

void EXI_vINT0_Init(void);
void EXI_vINT1_Init(void);
void EXI_vINT2_Init(void);

void EXI_vRegFunc(void (*ISR_PTR)(void), u8 A_u8INT);
#endif /* MCAL_EXI_EXI_INT_H_ */
