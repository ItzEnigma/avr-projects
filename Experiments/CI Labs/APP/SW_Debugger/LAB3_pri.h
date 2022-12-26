/*
 * LAB3_pri.h
 *
 * Created: 28/10/2022 11:26:15 PM
 *  Author: 20109
 */ 


#ifndef LAB3_PRI_H_
#define LAB3_PRI_H_

/* Internal EEPROM Addresses */

#define EEAR	*(volatile *u16)(0x3E)
#define EEARH	*(volatile *u8)(0x3F)
#define EEARL	*(volatile *u8)(0x3E)
#define EEDR	*(volatile *u8)(0x3D)
#define EECR	*(volatile *u8)(0x3C)

/*****************************/

#define MEMTYPE_INDEX		0
#define R_W_INDEX			1
#define ADDRESS_INDEX		2
#define VALUE_INDEX			7
#define READ_OP				'r'
#define WRITE_OP			'w'

#define RAM_TYPE			'#'
#define ROM_TYPE			'$'


#define _MEM(LOC)	*((volatile u8*)LOC)

/*
		# ==> RAM 
		$ ==> ROM
		READ:    #r(ABCD)^(AB);
		WRITE:  #w(ABCD)^(AB)
*/
static u8 G_u8Buffer[16];
static u8 G_u8HexBuffer[128*4];//each page is 128 byte
static u8 G_u8IsBufferReady = 1;

static void dataHandler(u8 A_u8Data);

static u8 EEPROM_read(u16 uiAddress);
static void EEPROM_write(u16 uiAddress, u8 ucData);

#endif /* LAB3_PRI_H_ */