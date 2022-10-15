/*
 * STM_int.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Dell
 */

#ifndef HAL_STM_STM_INT_H_
#define HAL_STM_STM_INT_H_

#define FULL_STEP 0
#define HALF_STEP 1

#define CLOCKWISE 0
#define ANTI_CLOCKWISE 1

void STM_vInit();
void STM_vSetStepMode(u8 A_u8Step);
void STM_vSetMotorSpeedRPM(u8 A_u8MotorSpeedRpm);
void STM_vMoveCycle(u8 A_u8Direction);
void STM_vMove(u8 A_u8Direction, u32 A_u8Angle);
#endif /* HAL_STM_STM_INT_H_ */
