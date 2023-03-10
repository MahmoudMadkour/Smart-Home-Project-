/*
 * UART_interface.h
 *
 * Created: 12/10/2022 6:44:32 PM
 *  Author: ENG.Mohamed
 */ 

 /* UITELS LIB */

 #include "DATA.h"


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define Data_Not_Recived   0xff
#define MAX_SIZE            4

/* UART PINS */

#define UART_PIN0    0
#define UART_PIN1    1
#define UART_PIN2    2
#define UART_PIN3    3
#define UART_PIN4    4
#define UART_PIN5    5
#define UART_PIN6    6
#define UART_PIN7    7

/* FUNCTION PROTOTYPE */

void UART_INTI(void);
void UART_TransmitDataChar(u8 TxData);
void UART_ReciveChar(u8* RxData);
void UART_TransmitDataString(u8* string);
void UART_ReciveString(u8*arr);
void UART_TransmitDataInt(u16 data);
void SetCallBackFunction_1(void(*ptr)(u8*));
void SetCallBackFunction_2(void(*ptr_1)(u8));

#endif /* UART_INTERFACE_H_ */