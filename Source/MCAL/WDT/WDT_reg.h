/*
 * WDT_reg.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Dell
 */

#ifndef MCAL_WDT_WDT_REG_H_
#define MCAL_WDT_WDT_REG_H_


#define WDTCR *((volatile u8 *)0x41)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDTOE 4
#endif /* MCAL_WDT_WDT_REG_H_ */
