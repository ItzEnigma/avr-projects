/*
 * WDT_int.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Dell
 */

#ifndef MCAL_WDT_WDT_INT_H_
#define MCAL_WDT_WDT_INT_H_

#define WDT_SLEEP_16_3_ms 0
#define WDT_SLEEP_32_5_ms 1
#define WDT_SLEEP_65_ms 2
#define WDT_SLEEP_0_13_s 3
#define WDT_SLEEP_0_26_s 4
#define WDT_SLEEP_0_52_s 5
#define WDT_SLEEP_1_0_s 6
#define WDT_SLEEP_2_1_s 7

void WDT_vEnable(void);
void WDT_vDisable(void);
void WDT_vSetSleep(u8 Copy_SleepTime);

#endif /* MCAL_WDT_WDT_INT_H_ */
