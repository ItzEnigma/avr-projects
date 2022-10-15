/*
 * SERVO_int.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Dell
 */

#ifndef HAL_SERVO_SERVO_INT_H_
#define HAL_SERVO_SERVO_INT_H_

void SERVO_vInit();
void SERVO_vMoveToInitialAngle();
void SERVO_vMoveToAngle(u32 A_u32Angle);
#endif /* HAL_SERVO_SERVO_INT_H_ */
