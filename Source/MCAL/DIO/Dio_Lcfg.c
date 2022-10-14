/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio_Lcfg.c
 *        \brief  
 *
 *      \details  Contains Port Struct Configuration
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"



/**********************************************************************************************************************
 *  Configuration
 *********************************************************************************************************************/



    /*                          CONFIGURATION NOTES
     * 1 : ********** Don't Change The Ports **********
     * 2 : ********** Don't Change The Pins  **********
     * 3 : You can change pin mode using Port_PinModeT_e (enum)
     * 4 : You can change pin direction using Port_PinDirection_e (enum)
     * 5 : You can change pin internal using attach Port_PinInternalAttach_e (enum)
     * 6 : You can change pin output current using Port_PinOutputCurrent_e (enum)
     * 7 : You can change pin level for output using Port_PinLevel_e (enum) *** BUT DEFAULT PIN_LEVEL_LOW ***
     * 
     *                                                                                                              */
const Port_strConfig Port_strPortConfig =
{
    /*                          PORTA CONFIGURATION                        */
    PORT_A, PIN0, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_HIGH  ,
    PORT_A, PIN1, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_HIGH  ,
    PORT_A, PIN2, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_HIGH  ,
    PORT_A, PIN3, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_LOW   ,
    PORT_A, PIN4, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_LOW   ,
    PORT_A, PIN5, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_LOW   ,
    PORT_A, PIN6, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_LOW   ,
    PORT_A, PIN7, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_LOW   ,
 
    /*                          PORTB CONFIGURATION                        */
    PORT_B, PIN0, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    PORT_B, PIN1, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    PORT_B, PIN2, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    PORT_B, PIN3, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    PORT_B, PIN4, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    PORT_B, PIN5, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    PORT_B, PIN6, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    PORT_B, PIN7, DIO_MODE,  PIN_OUTPUT, PULL_UP, DIO_LOW     ,
    
    /*                          PORTC CONFIGURATION                        */
    PORT_C, PIN0, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_C, PIN1, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_C, PIN2, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_C, PIN3, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_C, PIN4, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_C, PIN5, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_C, PIN6, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_C, PIN7, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,

    /*                          PORTD CONFIGURATION                        */
    PORT_D, PIN0, UART_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_D, PIN1, UART_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_D, PIN2, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_D, PIN3, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_D, PIN4, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_D, PIN5, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_D, PIN6, DIO_MODE, PIN_INPUT, PULL_UP, DIO_LOW     ,
    PORT_D, PIN7, DIO_MODE, PIN_OUTPUT, PULL_UP, DIO_LOW  ,
};

/**********************************************************************************************************************
 *  END OF FILE: Dio_Lcfg.c
 *********************************************************************************************************************/
