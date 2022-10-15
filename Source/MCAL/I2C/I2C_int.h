/*
 * I2C_int.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Dell
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_
typedef enum
{
    NoError,
    StartConditionErr,
    RepeatedStartErr,
    SlaveAddressWithWriteErr,
    SlaveAddressWithReadErr,
    MasterWriteByteErr,
    MasterReadByteErr,
} I2C_ErrStatus;

/* Pass 0 in the slave address if master will not be addressed */
void I2C_vMasterInit(u8 A_u8SlaveAddress);
void I2C_vSlaveInit(u8 A_u8SlaveAddress);

I2C_ErrStatus I2C_SendStartCondition();
I2C_ErrStatus I2C_SendRepeatedStart();

void I2C_SendStopCondition();

I2C_ErrStatus I2C_SendSlaveAddressWithWrite(u8 A_u8SlaveAddress);
I2C_ErrStatus I2C_SendSlaveAddressWithRead(u8 A_u8SlaveAddress);

I2C_ErrStatus I2C_MasterWriteDataByte(u8 A_u8DataByte);

I2C_ErrStatus I2C_MasterReadDataByteACK(u8 *A_u8DataByte);
I2C_ErrStatus I2C_MasterReadDataByteNACK(u8 *A_u8DataByte);

#endif /* MCAL_I2C_I2C_INT_H_ */
