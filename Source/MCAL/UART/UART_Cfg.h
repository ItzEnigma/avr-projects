/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  UART_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_CFG_H
#define UART_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../../COMMON/Std_Types.h"
#include "UART_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Configuration
 *********************************************************************************************************************/

#define     DOUBLE_TRANSMISSION_SPEED       DISABLE
#define     MULTIPROC_COMMUNICATION_MODE    DISABLE

#define     UART_TX_INTERRUPT_ENABLE        DISABLE
#define     UART_RX_INTERRUPT_ENABLE        DISABLE
#define     UART_DATA_REGISTER_EMPTY_INTERRUPT_ENABLE        DISABLE
#define     UART_RECEIVER_ENANBLE           ENABLE
#define     UART_TRANSMITTER_ENANBLE           ENABLE

/*  Selects the UART Character Size for TX/RX
 *   FRAME_5BIT
 *   FRAME_6BIT
 *   FRAME_7BIT
 *   FRAME_8BIT
 *   FRAME_9BIT       */
#define     FRAME_CHAR_SIZE                                 FRAME_8BIT

#define     SYNCHRONOUS_MODE_SELECT                         0

/*  Selects the UART Parity Mode for TX/RX
 *   PARITY_DISABLED
 *   PARITY_EVEN
 *   PARITY_ODD       */
#define     PARITY_MODE                                     PARITY_DISABLED

#define     FRAME_TWO_STOP_BITS                             0






#endif  /* UART_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: UART_Cfg.h
 *********************************************************************************************************************/
