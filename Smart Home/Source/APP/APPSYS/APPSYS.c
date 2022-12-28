/*********************************************************/
/***********		Author: Smart Home	 	**************/
/***********		Layer: APP			 	**************/
/***********		Component: APPSYS  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 28 Dec 2022	 	**************/
/***********		Updated: 28 Sep 2022	**************/
/*********************************************************/



/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "APPSYS.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/EXTI/EXTI_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "../../HAL/LDR/LDR_int.h"
#include "../../HAL/TEMPS/TEMPS_int.h"
#include "../../HAL/KeyPad/KeyPad_int.h"
#include <string.h>
#include <avr/delay.h>

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* Home Password */
u8 password[8] = "1234";
u8 trials = 4;


/* Entry Password */
u8 tempPassword[8] = {0};
char password_i = 0;


u16 channelsValues[2] = {0};
u8 channels[2] = {TEMPS_PIN, LDR_CHANNEL};

u8 Home_State = _HOME_LOCKED;



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void DisplayOverLCD(void)        
* \Description     : The API responsible for displaying data over LCD
                     periodically
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None                         
*******************************************************************************/
void DisplayOverLCD()
{
	channelsValues[0] = TEMPS_ConvertValue(channelsValues[0]);	/* Getting Temp Value */
	channelsValues[1] = LDR_ConvertValue(channelsValues[1]);	/* Getting LDR Value */
	LCD_vSetPosition(ROW0_ID, COL0_ID);
	LCD_vDispNum(channelsValues[0]);
	LCD_vSetPosition(ROW1_ID, COL0_ID);
	LCD_vDispNum(channelsValues[1]);
	LCD_vSetPosition(ROW1_ID, COL6_ID);
}

/******************************************************************************
* \Syntax          : void Animation1_LcdPassword(void)
* \Description     : The API responsible for displaying LCD Password
*******************************************************************************/
void Animation1_LcdPassword()
{
	/*		LCD-Password Phase		 */
	_delay_ms(250);
	LCD_vClrDisp();
	_delay_ms(2);
	
	LCD_vDispStr("Enter Password:");
	LCD_vSetPosition(ROW1_ID, COL0_ID);
}


/******************************************************************************
* \Syntax          : void startKeypad(void)        
* \Description     : The API responsible for getting from keypad when triggered
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None  
*******************************************************************************/
void StartKeypad(){
	MCU_WAKEUP();
	if (Home_State == _HOME_LOCKDOWN_STATE);		/* Do Nothing */
	else
	{
		DIO_vSetPinVal(PORTB_ID, PIN7_ID, VAL_HIGH);
		Home_State = _HOME_KEYPAD_STATE;
		
		/*		LCD Welcome Message		 */
		LCD_vSetPosition(ROW0_ID, COL0_ID);
		LCD_vDispStr("Welcome ");
		_delay_ms(50);
		for(u8 i=0 ; i<3; i++)	/* Dots Animation */
		{
			LCD_vDispChar('.');
			_delay_ms(100);
		}
		
		/*		LCD-Password Phase		 */
		Animation1_LcdPassword();
		
		/* Start Inactivity Countdown Timer */
		TIM0_vTurnOn();
		TIM0_vDelayMilli(8000, 0, &Timer0Elapsed_KeyOFF);
	}
}



/******************************************************************************
* \Syntax          : void Timer0Elapsed_KeyOFF(void)        
* \Description     : The API responsible for turning OFF keypad & LCD
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None  
*******************************************************************************/
void Timer0Elapsed_KeyOFF()
{
	if (Home_State == _HOME_LOCKDOWN_STATE);		/* Do Nothing */
	else
	{
		DIO_vSetPinVal(PORTB_ID, PIN7_ID, VAL_LOW);
		Home_State = _HOME_LOCKED;	/* To be Handled */
		TIM0_vTurnOff();
		
		/*		Clearing LCD		*/
		LCD_vClrDisp();
		_delay_ms(2);
		LCD_vDispStr("B Y E ...");
		_delay_ms(250);
		LCD_vClrDisp();
		_delay_ms(2);
		for(u8 i=0 ; i<3; i++)	/* Animation */
		{
			LCD_vSetPosition(ROW0_ID, COL5_ID);
			LCD_vDispStr(" ! ! !");
			_delay_ms(100);
			LCD_vClrDisp();
			_delay_ms(100);
		}
	}
}


/******************************************************************************
* \Syntax          : void System_Start(void)
* \Description     : Initializing and preparing the system for the first time
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void System_Start()
{
	DIO_vSetPinDir(PORTC_ID, PIN0_ID, DIR_OUTPUT);	/* Buzzer */
	DIO_vSetPinDir(PORTD_ID, PIN7_ID, DIR_OUTPUT);
	DIO_vSetPinDir(PORTB_ID, PIN7_ID, DIR_OUTPUT);
	EXTI_vReg_Func(&StartKeypad, INT0_ID);
}


/******************************************************************************
* \Syntax          : void System_WakeUp(void)        
* \Description     : Waking the system-up and doing its functions
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None 
*******************************************************************************/
void System_WakeUp()
{
	u8 L_u8Char = NO_PRESSED_KEY;
	DIO_vTogPin(PORTD_ID, PIN7_ID);
	ADC_stChain chain = { channels, channelsValues, 2, &DisplayOverLCD };
	
	if (Home_State == _HOME_KEYPAD_STATE)
	{
		L_u8Char = KeyPad_u8GetPressedKey();
		
		if(L_u8Char == '#')		/* Enter Button */
		{
			trials--;
			if( strcmp(password, tempPassword) == 0)	/* Correct Password */
			{
				TIM0_vTurnOff();
				LCD_vClrDisp();
				_delay_ms(100);
				LCD_vDispStr("WELCOME !!!");
				_delay_ms(1000);
				LCD_vClrDisp();
				Home_State = _HOME_UNLOCKED;
				trials = 3;
			}
			else{		/* Incorrect Password */
				TIM0_vDelayMilli(8000, 0, &Timer0Elapsed_KeyOFF);
				LCD_vClrDisp();
				_delay_ms(100);
				LCD_vDispStr("Wrong Password !");
				_delay_ms(500);
				
				if (trials == 1)	/*	System LockDown	 */
				{
					LCD_vClrDisp();
					_delay_ms(100);
					DIO_vSetPinVal(PORTC_ID, PIN0_ID, VAL_HIGH);
					LCD_vDispStr("System LockDown");
					_delay_ms(2000);
					/*	TODO: Send Warning Message */
					
					LCD_vClrDisp();
					Home_State = _HOME_LOCKDOWN_STATE;
				}
				else { Animation1_LcdPassword(); }	/* Try Again */
			}
			/* Resetting Password */
			password_i = 0;
			for(u8 i=0 ; i<8 ; i++)	tempPassword[i] = 0;
		}
		else if(L_u8Char != NO_PRESSED_KEY)
		{
			TIM0_vDelayMilli(8000, 0, &Timer0Elapsed_KeyOFF);
			tempPassword[password_i] = L_u8Char;
			password_i++;
			LCD_vDispChar('*');
		}
	}
	else if(Home_State == _HOME_UNLOCKED)
	{
		ADC_StartChain(&chain);
		_delay_ms(500);
	}
	else;	/* What State ??? */
}
