/*
 * EXI_reg.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Dell
 */

#ifndef MCAL_EXI_EXI_REG_H_
#define MCAL_EXI_EXI_REG_H_
/*MCU Control Register */
#define MCUCR *((u8 *) 0x55)
/* from bit 4 to 7 are not used in this  */
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3


/*MCU Control and Status  */
#define MCUCSR *((volatile u8 *) 0x54)
/* ALl Bits except bit 6 are not used in thid*/
#define ISC2 6

/*General Interrupt Control */
#define GICR  *((u8 *) 0x5B)
/*the remaining bits are not used in this  */
#define INT0 6
#define INT1 7
#define INT2 5

/*General Interrupt Flag*/
#define GIFR  *((volatile u8 *) 0x5A)
/*the remaining bits are not used in this  */
#define INTF0 6
#define INTF1 7
#define INTF2 5

#endif /* MCAL_EXI_EXI_REG_H_ */
