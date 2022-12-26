/*
 * DIO_prg.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Dell
 */

#include "../../LIB/std_types.h"
#include "../../LIB/bit_map.h"

#include "DIO_reg.h"
#include "DIO_int.h"

void DIO_vSetPinDir(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Dir)
{

	switch (A_u8PortId)
	{
	case PORTA_ID:
		WRT_BIT(DDRA, A_u8PinId, A_u8Dir);
		break;
	case PORTB_ID:
		WRT_BIT(DDRB, A_u8PinId, A_u8Dir);
		break;
	case PORTC_ID:
		WRT_BIT(DDRC, A_u8PinId, A_u8Dir);
		break;
	case PORTD_ID:
		WRT_BIT(DDRD, A_u8PinId, A_u8Dir);
		break;
	default:
		break;
	}
}

void DIO_vSetPinVal(u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Val)
{

	switch (A_u8PortId)
	{
	case PORTA_ID:
		WRT_BIT(PORTA, A_u8PinId, A_u8Val);
		break;
	case PORTB_ID:
		WRT_BIT(PORTB, A_u8PinId, A_u8Val);
		break;
	case PORTC_ID:
		WRT_BIT(PORTC, A_u8PinId, A_u8Val);
		break;
	case PORTD_ID:
		WRT_BIT(PORTD, A_u8PinId, A_u8Val);
		break;
	default:
		break;
	}
}
void DIO_vTogPinVal(u8 A_u8PortId, u8 A_u8PinId)
{

	switch (A_u8PortId)
	{
	case PORTA_ID:
		TOG_BIT(PORTA, A_u8PinId);
		break;
	case PORTB_ID:
		TOG_BIT(PORTB, A_u8PinId);
		break;
	case PORTC_ID:
		TOG_BIT(PORTC, A_u8PinId);
		break;
	case PORTD_ID:
		TOG_BIT(PORTD, A_u8PinId);
		break;
	default:
		break;
	}
}
u8 DIO_u8GetPinVal(u8 A_u8PortId, u8 A_u8PinId)
{
	u8 L_PinVal;
	switch (A_u8PortId)
	{
	case PORTA_ID:
		L_PinVal = READ_BIT(PINA, A_u8PinId);
		break;
	case PORTB_ID:
		L_PinVal = READ_BIT(PINB, A_u8PinId);
		break;
	case PORTC_ID:
		L_PinVal = READ_BIT(PINC, A_u8PinId);
		break;
	case PORTD_ID:
		L_PinVal = READ_BIT(PIND, A_u8PinId);
		break;
	default:
		break;
	}
	return L_PinVal;
}

void DIO_vSetPortDir(u8 A_u8PortId, u8 A_u8Dir)
{
	switch (A_u8PortId)
	{
	case PORTA_ID:
		DDRA = A_u8Dir;
		break;
	case PORTB_ID:
		DDRB = A_u8Dir;
		break;
	case PORTC_ID:
		DDRC = A_u8Dir;
		break;
	case PORTD_ID:
		DDRD = A_u8Dir;
		break;
	default:
		break;
	}
}
void DIO_vSetPortVal(u8 A_u8PortId, u8 A_u8Val)
{
	switch (A_u8PortId)
	{
	case PORTA_ID:
		PORTA = A_u8Val;
		break;
	case PORTB_ID:
		PORTB = A_u8Val;
		break;
	case PORTC_ID:
		PORTC = A_u8Val;
		break;
	case PORTD_ID:
		PORTD = A_u8Val;
		break;
	default:
		break;
	}
}
void DIO_vTogPortVal(u8 A_u8PortId)
{
	switch (A_u8PortId)
	{
	case PORTA_ID:
		PORTA ^= 0xff;
		break;
	case PORTB_ID:
		PORTB ^= 0xff;
		break;
	case PORTC_ID:
		PORTC ^= 0xff;
		break;
	case PORTD_ID:
		PORTD ^= 0xff;
		break;
	default:
		break;
	}
}
u8 DIO_u8GetPortVal(u8 A_u8PortId)
{
	u8 L_u8PortVal;
	switch (A_u8PortId)
	{
	case PORTA_ID:
		L_u8PortVal = PINA;
		break;
	case PORTB_ID:
		L_u8PortVal = PINB;
		break;
	case PORTC_ID:
		L_u8PortVal = PINC;
		break;
	case PORTD_ID:
		L_u8PortVal = PIND;
		break;
	default:
		break;
	}
	return L_u8PortVal;
}
