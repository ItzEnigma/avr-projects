/*
 * EEPROM_prg.c
 *
 *  Created on: Sep 28, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "../../MCAL/I2C/I2C_int.h"

#include "EEPROM_cfg.h"
#include "EEPROM_int.h"
void EEPROM_Init()
{
	I2C_vMasterInit(0);
}
/*
*************************************************
Note: The address you pass to the function is ranged from 0 to 1023
*************************************************
 */
void EEPROM_sendDataByte(u8 DataByte, u16 Address)
{

	I2C_ErrStatus status;
	status = I2C_SendStartCondition();

	/* Send the fixed address then A2 pin then the most 2 bit of the 10 bit address */
	status = I2C_SendSlaveAddressWithWrite(0b01010000 | A2 << 2 | Address >> 8);

	/* send the rest of the address */
	status = I2C_MasterWriteDataByte((u8)Address);

	/* Send the data */
	status = I2C_MasterWriteDataByte(DataByte);

	I2C_SendStopCondition();
};
u8 EEPROM_readDataByte(u16 Address)
{
	I2C_ErrStatus status;
	u8 DataByte;
	status = I2C_SendStartCondition();
	/* Send the fixed addres then A2 pin then the most 2 bit of the 10 bit address */
	status = I2C_SendSlaveAddressWithWrite(0b01010000 | A2 << 2 | Address >> 8);
	/* send the rest of the address */
	status = I2C_MasterWriteDataByte((u8)Address);
	/* Repeated Start */
	status = I2C_SendRepeatedStart();
	/* Slave address read*/
	status = I2C_SendSlaveAddressWithRead(0b01010000 | A2 << 2 | Address >> 8);
	/* get the data */
	status = I2C_MasterReadDataByteACK(&DataByte);
	I2C_SendStopCondition();
	return DataByte;
}
