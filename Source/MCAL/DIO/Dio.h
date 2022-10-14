/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Port_strConfig Port_strPortConfig;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* Syntax          : void DIO_Init(struct strConfigPtr)        
* Description     : Initialization for Port for the AVR Controller for all the pins.
                   - Setup the pin-mode
                       - If DIO ... Setup pin's : (Direction, internal attach, output current)
                   * IF OTHER MODES ... TO BE SETUPED                                                                          
* Sync\Async      : Synchronous                                               
* Reentrancy      : Non Reentrant                                             
* Parameters (in) : strConfigPtr - Pointer to Port Configuration struct -                     
* Parameters (out): None                                                      
* Return value:   : None                                
*******************************************************************************/
void               DIO_Init(const Port_strConfig* strConfigPtr);
/**********************************************************************************************************************/


/******************************************* Pin APIs ********************************************/

/***********************************************************************************
* Syntax          : (enum (Zero/One)) DIO_ReadChannel(u08 port, u08 channel)        
* Description     : API for reading MCU channel without knowing the port.                                                                         
* Sync\Async      : Synchronous                                                                                        
* Parameters (in) : [port - desired port corresponding to MCU] - [channel - pin number corresponding to MCU] -                     
* Parameters (out): None                                                      
* Return value:   : DIO_PinLevel enum  0
*                                       1
************************************************************************************/
DIO_PinLevel_e      DIO_ReadChannel  ( DIO_Portx_e port, Port_Pinx_e channel );
/**********************************************************************************************************************/

/***********************************************************************************
* Syntax          : void DIO_WriteChannel(u08 port, u08 channel, enum(Zero/One) level)        
* Description     : API for writing level on MCU channel without knowing the port.                                                                         
* Sync\Async      : Synchronous                                                                                        
* Parameters (in) : [port - desired port corresponding to MCU] - 
                    [channel - pin number corresponding to MCU] -
                    [level   - pin value (DIO_LOW/DIO_HIGH)]                    
* Parameters (out): None                                                      
* Return value:   : None
************************************************************************************/
void                DIO_WriteChannel ( DIO_Portx_e port, Port_Pinx_e channel, DIO_PinLevel_e level );
/**********************************************************************************************************************/

/***********************************************************************************
* Syntax          : void DIO_ToggleChannel(u08 port, u08 channel, enum(Zero/One) level)        
* Description     : API for toggling level on MCU channel without knowing the port.                                                                         
* Sync\Async      : Synchronous                                                                                         
* Parameters (in) : [port - desired port corresponding to MCU] - [channel - pin number corresponding to MCU] -          
* Parameters (out): None                                                      
* Return value:   : None
************************************************************************************/
void                DIO_ToggleChannel( DIO_Portx_e port, Port_Pinx_e channel );
/**********************************************************************************************************************/


/******************************************* Port APIs ********************************************/

/***********************************************************************************
* Syntax          : u08 Dio_ReadPort(enum{PORTA : PORTD} port, u08 pointer to the value to be read)        
* Description     : API for reading MCU port.                                                                         
* Sync\Async      : Synchronous                                                                                         
* Parameters (in) : [port - desired port corresponding to MCU] - [value - will store the port current value] -                    
* Parameters (out): None                                                      
* Return value:   : u08 ===> 0 : 255
************************************************************************************/
void       Dio_ReadPort     ( DIO_Portx_e port, uint8_t *value);
/**********************************************************************************************************************/

/***********************************************************************************
* Syntax          : void DIO_WritePort(enum{PORTA : PORTD} port, u08 value)        
* Description     : API for writing value on MCU port.                                                                         
* Sync\Async      : Synchronous                                                                                      
* Parameters (in) : [port    - port corresponding to MCU] -
                    [value   - port value (0 : 255)]                    
* Parameters (out): None                                                      
* Return value:   : None
************************************************************************************/
void                DIO_WritePort    ( DIO_Portx_e port, DIO_PortLevel value );
/**********************************************************************************************************************/

#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
