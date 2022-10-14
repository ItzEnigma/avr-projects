/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Dio.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void DIO_Init(const Port_strConfig* strConfigPtr)
{
	/* TODO: Show Error if strConfigPtr == NULL_PTR */
    
    u08 u08Pin;
    u08 u08TempPin;
    for (u08Pin = 0 ; u08Pin < TOTAL_GPIO_PINS ; u08Pin++)
    {

    /*                         Pin Mode Configuration                        */
        switch ( strConfigPtr->pinConfig[u08Pin].pinMode )
        {
        case DIO_MODE :         /*  PIN DIO CONFIG  */
            /*                  PORTA CONFIGURATION                */
            switch (strConfigPtr->pinConfig[u08Pin].portX)
            {
            case PORT_A :        /*  PORTA DIO   */
                u08TempPin = strConfigPtr->pinConfig[u08Pin].pinX;
                if (strConfigPtr->pinConfig[u08Pin].pinDir == INPUT){
                    CLEAR_BIT(DDRA, u08TempPin);
                    if(strConfigPtr->pinConfig[u08Pin].pinInternaAttach == PULL_UP)        SET_BIT(PORTA, u08TempPin);
                    /* TODO: OPEN DRAIN INTERNAL ATTACH */
                    /* TODO: SLEW RATE INTERNAL ATTACH */
                }
                else if ((strConfigPtr->pinConfig[u08Pin].pinDir == OUTPUT)){
                    SET_BIT(DDRA, u08TempPin);
                }
                break;
            case PORT_B :        /*  PORTB DIO   */
                u08TempPin = strConfigPtr->pinConfig[u08Pin].pinX;
                if (strConfigPtr->pinConfig[u08Pin].pinDir == INPUT){
                    CLEAR_BIT(DDRB, u08TempPin);
                    if(strConfigPtr->pinConfig[u08Pin].pinInternaAttach == PULL_UP)        SET_BIT(PORTB, u08TempPin);
                    /* TODO: OPEN DRAIN INTERNAL ATTACH */
                    /* TODO: SLEW RATE INTERNAL ATTACH */
                }
                else if ((strConfigPtr->pinConfig[u08Pin].pinDir == OUTPUT)){
                    SET_BIT(DDRB, u08TempPin);
                }
                break;
            case PORT_C :        /*  PORTC DIO   */
                u08TempPin = strConfigPtr->pinConfig[u08Pin].pinX;
                if (strConfigPtr->pinConfig[u08Pin].pinDir == INPUT){
                    CLEAR_BIT(DDRC, u08TempPin);
                    if(strConfigPtr->pinConfig[u08Pin].pinInternaAttach == PULL_UP)        SET_BIT(PORTC, u08TempPin);
                    /* TODO: OPEN DRAIN INTERNAL ATTACH */
                    /* TODO: SLEW RATE INTERNAL ATTACH */
                }
                else if ((strConfigPtr->pinConfig[u08Pin].pinDir == OUTPUT)){
                    SET_BIT(DDRC, u08TempPin);
                }
                break;
            case PORT_D :        /*  PORTD DIO   */
                u08TempPin = strConfigPtr->pinConfig[u08Pin].pinX;
                if (strConfigPtr->pinConfig[u08Pin].pinDir == INPUT){
                    CLEAR_BIT(DDRD, u08TempPin);
                    if(strConfigPtr->pinConfig[u08Pin].pinInternaAttach == PULL_UP)        SET_BIT(PORTD, u08TempPin);
                    /* TODO: OPEN DRAIN INTERNAL ATTACH */
                    /* TODO: SLEW RATE INTERNAL ATTACH */
                }
                else if ((strConfigPtr->pinConfig[u08Pin].pinDir == OUTPUT)){
                    SET_BIT(DDRD, u08TempPin);
                }
                break;
            }
			default :
				break;
        case UART_MODE :
            u08TempPin = strConfigPtr->pinConfig[u08Pin].pinX;
            /* RX PIN */
            if ( (strConfigPtr->pinConfig[u08Pin].portX == PORT_D) && (u08TempPin == PIN0) )
                CLEAR_BIT(DDRD, u08TempPin);        /* Configuring RX as INPUT */
            else if ( ((strConfigPtr->pinConfig[u08Pin].portX == PORT_D) && (u08TempPin == PIN1)) )
                SET_BIT(DDRD, u08TempPin);        /* Configuring TX as OUTPUT */

        }
    }
    
}

/***********************************************************************************
* Syntax          : (enum (Zero/One)) DIO_ReadChannel(u08 port, u08 channel)        
* Description     : API for reading MCU channel without knowing the port.                                                                         
* Sync\Async      : Synchronous                                                                                       
* Parameters (in) : [port - desired port corresponding to MCU] - [channel - pin number corresponding to MCU] -                     
* Parameters (out): None                                                      
* Return value:   : DIO_PinLevel enum  0
*                                       1
************************************************************************************/
DIO_PinLevel_e      DIO_ReadChannel  ( DIO_Portx_e port, Port_Pinx_e channel )
{
    u08 u08PinLevel = DIO_LOW;
    switch (port)
    {
    case PORT_A :
        u08PinLevel = GET_BIT( PINA, channel );
        break;
        
    case PORT_B :
        u08PinLevel = GET_BIT( PINB, channel );
        break;
        
    case PORT_C :
        u08PinLevel = GET_BIT( PINC, channel );
        break;
        
    case PORT_D :
        u08PinLevel = GET_BIT( PIND, channel );
        break;
    
    default:
        break;
    }
    if ( u08PinLevel == DIO_HIGH )
        return DIO_HIGH;
    else    return DIO_LOW;
}
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
void                DIO_WriteChannel ( DIO_Portx_e port, Port_Pinx_e channel, DIO_PinLevel_e level )
{
    switch (port)
    {
    case PORT_A :
        if      (level == DIO_HIGH)      SET_BIT  ( PORTA, channel );
        else if (level == DIO_LOW)       CLEAR_BIT( PORTA, channel );
        else    /*  MISRA Rule   */
        break;
        
    case PORT_B :
        if      (level == DIO_HIGH)      SET_BIT  ( PORTB, channel );
        else if (level == DIO_LOW)       CLEAR_BIT( PORTB, channel );
        else    /*  MISRA Rule   */
        break;
        
    case PORT_C :
        if      (level == DIO_HIGH)      SET_BIT  ( PORTC, channel );
        else if (level == DIO_LOW)       CLEAR_BIT( PORTC, channel );
        else    /*  MISRA Rule   */
        break;
        
    case PORT_D :
        if      (level == DIO_HIGH)      SET_BIT  ( PORTD, channel );
        else if (level == DIO_LOW)       CLEAR_BIT( PORTD, channel );
        else    /*  MISRA Rule   */
        break;
    
    default:
        break;
    }
}
/**********************************************************************************************************************/

/***********************************************************************************
* Syntax          : void DIO_ToggleChannel(u08 port, u08 channel, enum(Zero/One) level)        
* Description     : API for toggling level on MCU channel without knowing the port.                                                                         
* Sync\Async      : Synchronous                                                                                        
* Parameters (in) : [port - desired port corresponding to MCU] - [channel - pin number corresponding to MCU] -          
* Parameters (out): None                                                      
* Return value:   : None
************************************************************************************/
void                DIO_ToggleChannel( DIO_Portx_e port, Port_Pinx_e channel )
{
    switch (port)
    {
    case PORT_A :
        TOGGLE_BIT(PORTA, channel);
        break;
        
    case PORT_B :
        TOGGLE_BIT(PORTB, channel);
        break;
        
    case PORT_C :
       TOGGLE_BIT(PORTC, channel);
        break;
        
    case PORT_D :
        TOGGLE_BIT(PORTD, channel);
        break;
    
    default:
        break;
    }
}
/**********************************************************************************************************************/

/******************************************* Port APIs ********************************************/

/***********************************************************************************
* Syntax          : u08 Dio_ReadPort(enum{PORTA : PORTD} port)        
* Description     : API for reading MCU port.                                                                         
* Sync\Async      : Synchronous                                                                                          
* Parameters (in) : [port - desired port corresponding to MCU] -                     
* Parameters (out): None                                                      
* Return value:   : u08 ===> 0 : 255
************************************************************************************/
void       Dio_ReadPort     ( DIO_Portx_e port, uint8_t *value)
{
    switch(port)
    {
		case PORT_A:
			*value = PINA;
		break;
		
		case PORT_B:
			*value = PINB;
		break;
		
		case PORT_C:
			*value = PINC;
		break;
		
		case PORT_D:
			*value = PIND;
		break;
	}
}
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
void                DIO_WritePort    ( DIO_Portx_e port, DIO_PortLevel value )
{
    switch (port)
    {
    case PORT_A :
        PORTA = value;
        break;

    case PORT_B :
        PORTB = value;
        break;

    case PORT_C :
        PORTC = value;
        break;

    case PORT_D :
        PORTD = value;
        break;
    
    default:
        break;
    }
}
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
