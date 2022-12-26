/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: SERVO		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 19 Sep 2022	 	**************/
/*********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TIMER/TIMER_int.h"
#include "SERVO_cfg.h"
#include "SERVO_int.h"

/**********************************************************************************************************
 * Description : Interface Function to setup the Servo_Motor
 * Outputs     : void
 * Inputs      : void
 * NOTES	   : must configure timer_1 in fast PWM mode with ICR1 TOP (mode 14) of value 19999
 ***********************************************************************************************************/

void SERVO_vInit(){
	TIMER_vInit();
}

/**********************************************************************************************************
 * Description : Interface Function to turn ON the Servo_Motor
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/

void SERVO_vTurnOn(){
	TIMER_vTurnOn(TIMER1_ID);
}

/**********************************************************************************************************
 * Description : Interface Function to turn OFF the Servo_Motor
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SERVO_vTurnOff(){
	TIMER_vTurnOff(TIMER1_ID);
}

/**********************************************************************************************************
 * Description : Interface Function to set the angle of Servo_Motor
 * Outputs     : void
 * Inputs      : the required angle
 * NOTES	   : any given angle within 0 - 180 will work just fine. this will work only in TIMER_1 fast PWM
 * 				 with TOP ICR1 of 19999
 ***********************************************************************************************************/
void SERVO_vSetAngle(u8 A_u8Angle){
	u16 L_u8CompareVal = 750; /*Default is zer0*/
	if(A_u8Angle < 180)
		L_u8CompareVal = SERVO_ANGLE_EQN ;

	TIMER_vSetIcr1Val(L_u8CompareVal);
}
