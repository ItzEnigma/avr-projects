/*
 * SWITCHES_int.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Dell
 */

#ifndef HAL_SWITCHES_SWITCHES_INT_H_
#define HAL_SWITCHES_SWITCHES_INT_H_

typedef enum
{
    SWT0,
    SWT1,
    SWT2,
    SWT3,
    SWT4,
    SWT5,
    SWT6,
    SWT7,
};
#define SWT_ON 1
#define SWT_OFF 0

void SWT_vInit(u8 A_u8SwtID);
void SWT_vInitAllSwt();
u8 SWT_u8ReadSwt(u8 A_u8SwtID);
u8 SWT_u8ReadAllSwt();

#endif /* HAL_SWITCHES_SWITCHES_INT_H_ */
