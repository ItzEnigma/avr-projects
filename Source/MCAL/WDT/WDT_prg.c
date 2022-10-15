/*
 * WDT_prg.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Dell
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "WDT_reg.h"
#include "WDT_int.h"
#include "WDT_cfg.h"
#include "WDT_pri.h"

void WDT_vEnable(void)
{
    SET_BIT(WDTCR, WDE);
}
void WDT_vDisable(void)
{
    /* In the same cycle WDE = 1 WDTDFE = 1 */
    WDTCR = 0b00011000;
    /* Within the next four cycles */
    WDTCR = 0;
}
void WDT_vSetSleep(u8 Copy_SleepTime)
{
    WDTCR &= 0b11111000;
    WDTCR |= Copy_SleepTime;
}
