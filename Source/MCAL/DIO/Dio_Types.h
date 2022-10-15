/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  Contains MCU Port Functions Prototypes
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../../COMMON/Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define TOTAL_GPIO_PINS                                     32U


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/*           Type Definition to be used for DIO APIs             */
typedef u08                     DIO_Port;
/*           Type Definition to be used for DIO APIs             */
typedef u08                     DIO_Pinx;
/*   Type Definition to be used for DIO APIs corresponds to MCU Pin Number    */
typedef u08                             DIO_Channel;
/*   Type Definition to be used for DIO APIs corresponds to port w/r value    */
typedef u08                             DIO_PortLevel;


typedef enum
{
	PORT_A      = 0,
	PORT_B      = 1,
	PORT_C      = 2,
	PORT_D      = 3
} DIO_Portx_e;

typedef enum
{
	PIN0       = 0,
	PIN1       = 1,
	PIN2       = 2,
	PIN3       = 3,
	PIN4       = 4,
	PIN5       = 5,
	PIN6       = 6,
	PIN7       = 7
} Port_Pinx_e;

typedef enum
{
	DIO_MODE   				= 0,
	ICU_MODE   				= 1,
	ADC_MODE   				= 2,
	UART_MODE  				= 3,
	EXT_INTERRUPT_MODE 		= 4
} Port_PinModeT_e;

typedef enum
{
	PIN_INPUT	   = 0,
	PIN_OUTPUT	   = 1
}DIO_PinDirection_e;

typedef enum{
    DIO_LOW             = 0,
    DIO_HIGH            = 1
}DIO_PinLevel_e;

typedef enum
{
	PULL_UP     = 0,
	OPEN_DRAIN  = 1
} DIO_PinInternalAttach_e;


/*                         INPUT/OUTPUT                        */
#ifndef INPUT
    #define INPUT                                            0
#endif

#ifndef OUTPUT
    #define OUTPUT                                           1
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct{
    DIO_Portx_e                 portX;
    Port_Pinx_e                 pinX;
    Port_PinModeT_e             pinMode;
	DIO_PinDirection_e			pinDir;
    DIO_PinInternalAttach_e    pinInternaAttach;
    DIO_PinLevel_e             pinLevel;
}Port_strPortSet;

typedef struct{
    Port_strPortSet     pinConfig[TOTAL_GPIO_PINS];
}Port_strConfig;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


 
#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
