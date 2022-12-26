/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: SERVO		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 Sep 2022	 	**************/
/*********************************************************/
#ifndef HAL_SERVO_SERVO_CFG_H_
#define HAL_SERVO_SERVO_CFG_H_

/* A derived angle EQN based on TIMER_1 fast PWM with ICR top of 19999
 * 0 angle -> about 3.5% DutyCycle
 * 180 angle -> about 12.5% DutyCycle
 * with frequency of 50HZ
 * */
#define SERVO_ANGLE_EQN (1750*A_u8Angle + (u32)135000) / (180)

#endif /* HAL_SERVO_SERVO_CFG_H_ */
