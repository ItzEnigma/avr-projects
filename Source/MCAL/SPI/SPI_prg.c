/*
 * SPI_prg.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Dell
 */
#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../DIO/DIO_int.h"
#include "../GIE/GIE_int.h"

#include "SPI_reg.h"
#include "SPI_int.h"
#include "SPI_cfg.h"
#include "SPI_pri.h"

FUNC_PTR_Iu8_OV GLB_PTR_FUNC;
void SPI_vMasterInit(void)
{
    /* SELECT CLK FREQ */
    SPCR = (SPCR & CLK_FREQ_MASK_SPCR) | MASTER_CLK_FREQ_SPCR;
    SPSR = (SPSR & CLK_FREQ_MASK_SPSR) | MASTER_CLK_FREQ_SPSR;
    /* SELECT CLK POLARITY */
    SPCR = (SPCR & CLOCK_POLARITY_MASK) | MASTER_CLK_POL << 3;
    /* SELECT CLK PHASE */
    SPCR = (SPCR & CLOCK_PHASE_MASK) | MASTER_CLK_PHASE << 2;
    /* SELECT DATA ORDER */
    SPCR = (SPCR & DATA_ORDER_MASK) | MASTER_DATA_ORDER_MODE << 5;
    /* CONFIGURE AS MASTER*/
    SET_BIT(SPCR, MSTR);
    /* SET MOSI OUTPUT PB5 */
    DIO_vSetPinDir(PORTB_ID, PIN5_ID, DIR_OUTPUT);
    /* SET MISO INPUT PB6 */
    DIO_vSetPinDir(PORTB_ID, PIN6_ID, DIR_INPUT);
    /* SET CLK OUTPUT PB7 */
    DIO_vSetPinDir(PORTB_ID, PIN7_ID, DIR_OUTPUT);
    /* SET SS OUTPUT PB4 */
    DIO_vSetPinDir(PORTB_ID, PIN4_ID, DIR_OUTPUT);
    /* ENABLE SPE */
    SET_BIT(SPCR, SPE);
}
void SPI_vSlaveInit(void)
{
    /* SELECT CLK FREQ */
    SPCR = (SPCR & CLK_FREQ_MASK_SPCR) | SLAVE_CLK_FREQ_SPCR;
    SPSR = (SPSR & CLK_FREQ_MASK_SPSR) | SLAVE_CLK_FREQ_SPSR;
    /* SELECT CLK POLARITY */
    SPCR = (SPCR & CLOCK_POLARITY_MASK) | SLAVE_CLK_POL << 3;
    /* SELECT CLK PHASE */
    SPCR = (SPCR & CLOCK_PHASE_MASK) | SLAVE_CLK_PHASE << 2;
    /* SELECT DATA ORDER */
    SPCR = (SPCR & DATA_ORDER_MASK) | SLAVE_DATA_ORDER_MODE << 5;
    /* CONFIGURE AS SLAVE*/
    CLR_BIT(SPCR, MSTR);
    /* SET MOSI INPUT PB5 */
    DIO_vSetPinDir(PORTB_ID, PIN5_ID, DIR_INPUT);
    /* SET MISO OUTPUT PB6 */
    DIO_vSetPinDir(PORTB_ID, PIN6_ID, DIR_OUTPUT);
    /* SET CLK INPUT PB7 */
    DIO_vSetPinDir(PORTB_ID, PIN7_ID, DIR_INPUT);
    /* SET SS INPUT PB4 */
    DIO_vSetPinDir(PORTB_ID, PIN4_ID, DIR_INPUT);
    /* ENABLE SPE */
    SET_BIT(SPCR, SPE);
}
u8 SPI_u8Traceiver(u8 A_u8Data)
{
    SPDR = A_u8Data;
    while ((SPSR & 1 << SPIF) == 0)
    {
        /* Waiting */
    }
    return SPDR;
}

void SPI_vTransmitData(u8 A_u8Data)
{
    SPDR = A_u8Data;
    while ((SPSR & (1 << SPIF)) == 0)
    {
        /* Waiting */
    }
}
void SPI_vTransmitString(u8 *A_u8Data)
{
    /* Send each char of string till the NULL */
    for (u32 i = 0; A_u8Data[i] != 0; i++)
    {
        SPI_vTransmitData(A_u8Data[i]);
    }
}
u8 SPI_u8ReceiveData(void)
{
    while ((SPSR & (1 << SPIF)) == 0)
    {
        /* Waiting */
    }
    return SPDR;
}

void SPI_vReciceveDataAsync(FUNC_PTR_Iu8_OV A_Fptr)
{
    /* Enable Global Interrupt */
    GIE_vSetGlobalInterrupt();
    /* Enable SPI Interrupt */
    SET_BIT(SPCR, SPIE);
    /* Register CallBack Function */
    GLB_PTR_FUNC = A_Fptr;
}
void SPI_vTransmitDataAsync(u8 A_u8Data);

/* Serial Transfer Complete Interrupt */
void __vector_12(void)
{
    GLB_PTR_FUNC(SPDR);
};
