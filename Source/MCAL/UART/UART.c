/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  UART.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "UART.h"

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
* \Syntax          : void UART_Init(void)        
* \Description     : Initialization for the UART Peripheral.
*                                                                                                                       
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void UART_Init  ( void )
{
    /*  RESET   */
    UCSRB->REG = 0x00;

	/*            UART TX/RX Configuration              */
    #if UART_TRANSMITTER_ENANBLE == DISABLE
        CLEAR_BIT(UCSRB->REG, 3);
    #elif   UART_TRANSMITTER_ENANBLE == ENABLE
        SET_BIT(UCSRB->REG, 3);
    #else
        #error "Undefinied Transmitter State"
    #endif
    #if UART_RECEIVER_ENANBLE    == DISABLE
        CLEAR_BIT(UCSRB->REG, 4);
    #elif   UART_RECEIVER_ENANBLE    == ENABLE
        SET_BIT(UCSRB->REG, 4);
    #else
        #error "Undefinied Receiever State"
    #endif
/*********************************************************/


	/*          UART Interrupts Configuration            */
    #if UART_TX_INTERRUPT_ENABLE == DISABLE
        CLEAR_BIT(UCSRB->REG, 6);
    #elif   UART_TX_INTERRUPT_ENABLE == ENABLE
        SET_BIT(UCSRB->REG, 6);
    #else
        #error "Undefinied TX Interrupt State"
    #endif
    #if UART_RX_INTERRUPT_ENABLE == DISABLE
        CLEAR_BIT(UCSRB->REG, 7);
    #elif   UART_RX_INTERRUPT_ENABLE == ENABLE
        SET_BIT(UCSRB->REG, 7);
    #else
        #error "Undefinied RX Interrupt State"
    #endif
    #if UART_DATA_REGISTER_EMPTY_INTERRUPT_ENABLE == DISABLE
        CLEAR_BIT(UCSRB->REG, 5);
    #elif   UART_DATA_REGISTER_EMPTY_INTERRUPT_ENABLE == ENABLE
        SET_BIT(UCSRB->REG, 5);
    #else
        #error "Undefinied Data Register Empty Interrupt State"
    #endif
/***************************************************************/


	/*****          UART Frame Character Size Configuration           *****/
    /*The URSEL must be one when writing the UCSRC.*/
	UCSRC->REG = 0x80;      /* Clear the UCSRC register */
	UCSRC->REG |= (1 << 7);
    /*  5-bit : 8-bit Config    */
    /******** TO BE MODIFIED FOR 9-BITS **********/
    UCSRC->REG = (FRAME_CHAR_SIZE << 1);
    /**********************************************/


    /*          UART Mode Select            */
    #if SYNCHRONOUS_MODE_SELECT == 0    /* Asynchronous */
        CLEAR_BIT(UCSRC->REG, 6);
    #elif   SYNCHRONOUS_MODE_SELECT == 1
        SET_BIT(UCSRC->REG, 6);    /* Synchronous */
    #else
        #error "Undefinied UART Mode"
    #endif
    /**********************************************/
    /*          UART Parity Mode            */
    UCSRC->REG = (PARITY_MODE << 4);
    /**********************************************/
    /*          UART Stop Bits           */
    #if FRAME_TWO_STOP_BITS == 0    /* 1-Bit */
        CLEAR_BIT(UCSRC->REG, 3);
    #elif   FRAME_TWO_STOP_BITS == 1
        SET_BIT(UCSRC->REG, 3);    /* 2-Bits */
    #else
        #error "Undefinied UART Stop Bits"
    #endif


    /**********************************************/
    /******          BAUD RATE           ******/
    CLEAR_BIT(UCSRC->REG, 7);
    UCSRC->REG = (0 << 7) | (BAUD_RATE >> 8);
    UBRRL      = (u08) BAUD_RATE; 
}

/******************************************************************************
* \Syntax          : void UART_TransmitByte(u08 data)        
* \Description     : Transmitting Data Byte.
*                                                                                                                       
* \Parameters (in) : [data - transmtting data byte using UART]
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void UART_TransmitByte(u08 data)
{
    while(!(UCSRA->REG & (1 << 5)));
	UDR = (u08)data;
}

/******************************************************************************
* \Syntax          : void UART_ReceiveByte(u08 data)        
* \Description     : Receiving Data Byte and storing it into the pointer.
*                                                                                                                       
* \Parameters (in) : [data - pointer that contains the received data]
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void UART_ReceiveByte(u08 *data)
{
    while ( !(UCSRA->REG & (1<<7)) ); 
	*data = UDR;
}

/**********************************************************************************************************************
 *  END OF FILE: UART.c
 *********************************************************************************************************************/
