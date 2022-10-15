/*
 * DCM_int.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Dell
 */

#ifndef HAL_DCM_DCM_INT_H_
#define HAL_DCM_DCM_INT_H_

#define CLOCKWISE 0
#define ANTI_CLOCKWISE 1
#define STOP 2


void DCM_vInit();
void DCM_vSetDirection(u8 A_u8Direction);

#endif /* HAL_DCM_DCM_INT_H_ */
