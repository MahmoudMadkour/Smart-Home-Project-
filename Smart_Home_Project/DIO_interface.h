/*
 * DIO_interface.h
 *
 * Created: 10/30/2022 12:21:40 AM
 *  Author: ENG.Mohamed
 */ 
#include "DATA.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/* PIN_CONFIG */

#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7


/* PORT_CONFIG */

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

/* PIN_STATE */

#define DIO_PIN_HIGH  1
#define DIO_PIN_LOW   0

/* PIN_DIRECTION_STATE */

#define DIO_PIN_OUT   1
#define DIO_PIN_IN    0


/* FUNCTIONS_PROTOTYBE */

void DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PinDir);
void DIO_SetPinValue(u8 PortId,u8 PinId,u8 PinValue);
void DIO_SetRegValue(u8 PortId,u8 PortValue);
void DIO_SetRegDirection(u8 PortId,u8 PortDir);
u8 DIO_GetPinValue(u8 PortId,u8 PinId);
void DIO_SetPullupRes(u8 PortId,u8 PinId);
u8 DIO_GetRegValue(u8 PortId);

#endif /* DIO_INTERFACE_H_ */