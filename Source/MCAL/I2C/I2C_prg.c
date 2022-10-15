#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../DIO/DIO_int.h"
#include "../GIE/GIE_int.h"

#include "I2C_reg.h"
#include "I2C_int.h"
#include "I2C_cfg.h"
#include "I2C_pri.h"

/*
        NOTE :  Pass 0 in the slave address if master will not be addressed
 */
void I2C_vMasterInit(u8 A_u8SlaveAddress)
{
    /* Set The Clock Rate to 400000*/
    /* Set TWBR to 2 */
    TWBR = 2;
    /* Clear the 2 bits of TWPS */
    CLR_BIT(TWSR, TWPS0);
    CLR_BIT(TWSR, TWPS1);

    /* Initialize The node address */
    /* Check if this master other master will talk to it */
    if (A_u8SlaveAddress != 0)
    {
        TWAR = A_u8SlaveAddress << 1;
    }

    /* Enable I2C*/
    SET_BIT(TWCR, TWEN);
}
void I2C_vSlaveInit(u8 A_u8SlaveAddress)
{
    /* Initialize The node address */
    TWAR = A_u8SlaveAddress << 1;
    /* Enable I2C*/
    SET_BIT(TWCR, TWEN);
}
I2C_ErrStatus I2C_SendStartCondition()
{
    I2C_ErrStatus L_ErrStatus = NoError;
    /* Send Start Bit */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    /*
    **********************************************************************
    Explain :

    The Flag is initially High at this time the clock is LOW
    so you can configure what you what and after you finish you clear the flag
    so the clock bus return to normal state __|**|__|**|__

    ***********************************************************************
     */

    /* Wait for flag */
    while (READ_BIT(TWCR, TWINT) == 0)
    {
        /* Wait for TWINT FLag is Set */
    }

    /* Check The Status */
    if ((TWSR & 0xF8) != MT_START_CONDITION_TRANSMITTED)
    {
        L_ErrStatus = StartConditionErr;
    }
    else
    {
        /* Do Nothing */
    }

    return L_ErrStatus;
}
I2C_ErrStatus I2C_SendRepeatedStart()
{
    I2C_ErrStatus L_ErrStatus = NoError;
    /* Send Start Bit */
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);

    /* Wait for flag */
    while (READ_BIT(TWCR, TWINT) == 0)
    {
        /* Wait for TWINT FLag is Set */
    }

    /* Check The Status */
    if ((TWSR & 0xF8) != MT_REPEATED_START_CONDITION_TRANSMITTED)
    {
        L_ErrStatus = RepeatedStartErr;
    }
    else
    {
        /* Do Nothing */
    }

    return L_ErrStatus;
}

I2C_ErrStatus I2C_MasterWriteDataByte(u8 A_u8DataByte)
{
    I2C_ErrStatus L_ErrStatus = NoError;
    /* Load the Data
     * May be SLA_W
     * Or the Data
     */
    TWDR = A_u8DataByte;
    /* Clear The Flag by writing 1 and Enable */
    TWCR = (1 << TWINT) | (1 << TWEN);

    /* Wait for flag */
    while (READ_BIT(TWCR, TWINT) == 0)
    {
        /* Wait for TWINT FLag is Set */
    }

    /* Check The Status */
    if ((TWSR & 0xF8) != MT_DATA_TRANSMITTED_RECEIVED_ACK)
    {
        L_ErrStatus = MasterWriteByteErr;
    }
    else
    {
        /* Do Nothing */
    }
    return L_ErrStatus;
}

/*
*********************************************
Enable ACK Or Not? When Reading
-> it depends on the device you will talk to
-> every  device ack has different meaning to it's functionality
-> so always check the datasheet for the device you will talk to
-> in our case here we talk to the eeprom , ack means for it work sequentially and access the next byte ,
and will continue if the microcontroller responds every time with ack,
if the microcontroller stops sending ack the eeprom stop access the next byte
*********************************************
 */
I2C_ErrStatus I2C_MasterReadDataByteNACK(u8 *A_u8DataByte)
{
    I2C_ErrStatus L_ErrStatus = NoError;
    /* Don't Enable the Ack */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for flag */
    while (READ_BIT(TWCR, TWINT) == 0)
    {
        // Wait for TWINT FLag is Set
    }
    /* Check The Status */
    if ((TWSR & 0xF8) != MR_DATA_BYTE_RECEIVED_NACK)
    {
        L_ErrStatus = MasterReadByteErr;
    }
    else
    {
        /* Save The received data in the pointer received as parameter */
        *A_u8DataByte = TWDR;
    }

    return L_ErrStatus;
}
I2C_ErrStatus I2C_MasterReadDataByteACK(u8 *A_u8DataByte)
{
    I2C_ErrStatus L_ErrStatus = NoError;

    /* Enable Master Generating Ack bit after receiving the data*/
    TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
    // SET_BIT(TWCR, TWEA);
    /* Wait for flag */
    while (READ_BIT(TWCR, TWINT) == 0)
    {
        // Wait for TWINT FLag is Set
    }
    /* Check The Status */
    if ((TWSR & 0xF8) != MR_DATA_BYTE_RECEIVED_ACK)
    {
        L_ErrStatus = MasterReadByteErr;
    }
    else
    {
        /* Save The received data in the pointer received as parameter */
        *A_u8DataByte = TWDR;
    }
    /*************************************/
    /* Clear The ACk*/
    /*************************************/
    /* clear the flag */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for flag */
     while (READ_BIT(TWCR, TWINT) == 0)
     {
         // Wait for TWINT FLag is Set
     }

    return L_ErrStatus;
}
I2C_ErrStatus I2C_SendSlaveAddressWithWrite(u8 A_u8SlaveAddress)
{
    I2C_ErrStatus L_ErrStatus = NoError;
    /* Set The Slave Address in the 7 MSB in the data Register */
    TWDR = A_u8SlaveAddress << 1;
    /* Clear Bit 0 for Write */
    CLR_BIT(TWDR, 0);

    /* Clear The Flag By Writing 1*/
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for flag */
    while (READ_BIT(TWCR, TWINT) == 0)
    {
        /* Wait for TWINT FLag is Set */
    }

    /* Check The Status */
    if ((TWSR & 0xF8) != MT_SLA_W_TRANSMITTED_RECEIVED_ACK)
    {
        L_ErrStatus = SlaveAddressWithWriteErr;
    }
    else
    {
        /* Do Nothing */
    }
    return L_ErrStatus;
}
I2C_ErrStatus I2C_SendSlaveAddressWithRead(u8 A_u8SlaveAddress)
{
    I2C_ErrStatus L_ErrStatus = NoError;
    /* Clear The Start Condition Bit */
    // CLR_BIT(TWCR, TWSTA);

    /* Set The Slave Address in hte 7 MSB in the data Register */
    TWDR = A_u8SlaveAddress << 1;

    /* Set Bit 0 for Read */
    SET_BIT(TWDR, 0);

    /* Clear The Flag By Writing 1*/
    TWCR = (1 << TWINT) | (1 << TWEN);

    /* Wait for flag */
    while (READ_BIT(TWCR, TWINT) == 0)
    {
        /* Wait for TWINT FLag is Set */
    }

    /* Check The Status */
    if ((TWSR & 0xF8) != MR_SLA_R_TRANSMITTED_ACK)
    {
        L_ErrStatus = SlaveAddressWithReadErr;
    }
    else
    {
        /* Do Nothing */
    }

    return L_ErrStatus;
}
void I2C_SendStopCondition()
{
    /* Send Stop Bit */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}
