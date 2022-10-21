/*
 * DIO_int.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Dell
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7

#define DIR_OUTPUT 1
#define DIR_INPUT 0

#define HIGH 1
#define LOW 0

#define PORT_OUT 0xFF
#define PORT_IN 0x00

#define PORT_HIGH 0xFF
#define PORT_LOW 0x00

void DIO_vSetPinDir(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Dir);
void DIO_vSetPinVal(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Val);
void DIO_vTogPinVal(u8 A_u8PortId, u8 A_u8PinId);
u8 DIO_u8GetPinVal(u8 A_u8PortId, u8 A_u8PinId);

void DIO_vSetPortDir(u8 A_u8PortId, u8 A_u8Dir);
void DIO_vSetPortVal(u8 A_u8PortId, u8 A_u8Val);
void DIO_vTogPortVal(u8 A_u8PortId);
u8 DIO_u8GetPortVal(u8 A_u8PortId);
#endif /* MCAL_DIO_DIO_INT_H_ */
