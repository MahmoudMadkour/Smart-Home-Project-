/*
 * UART_program.c
 *
 * Created: 12/10/2022 6:43:49 PM
 *  Author: ENG.Mohamed
 */
 /* UITLES LIB */

 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"
 
 /* MCAL */
 
 #include "UART_interface.h"
 #include "LCD_INTERFACE.h" 
 #include "GI_interface.h"

 static void(*Recieve)(u8*)=NULL;
 

 /* FUN IMPELEMANTION */
 u8 data;
 void UART_INTI(void)
 {
    /* UART CONFG */
    CLEAR_BIT(UCSRB,UART_PIN2);
	UCSRC=0x86;  //0b10000110
	/* BAUD RATE VALUE */
	UBRRL=103;   //BAUD RATE = 9600
	/* UART TX,RX INIT */
	//SET_BIT(UCSRB,UART_PIN4);
    SET_BIT(UCSRB,UART_PIN3);
 }
 
 void UART_TransmitDataChar(u8 TxData)
 {
     UDR=TxData;
	 while(GET_BIT(UCSRA,UART_PIN5)==0);
	 
 }
 
 void UART_ReciveChar(u8* RxData)
 {
   if(RxData!=NULL)
   {
     SET_BIT(UCSRB,UART_PIN4);
     while(GET_BIT(UCSRA,UART_PIN7)==0);
	 *RxData=UDR;
	 CLEAR_BIT(UCSRB,UART_PIN4);
   }
   else
   {
     // DO NOTHING
   }
 }

 void UART_TransmitDataString(u8* string)
 {
    u8 i=0;
	while(string[i] !='\0')
	{
	  UART_TransmitDataChar(string[i]);
	  i++;
	}
	string[i]='\0';

 }
 
 void UART_ReciveString(u8*arr)
 {
    for(u8 i=0; i<MAX_SIZE;i++)
    {
	    UART_ReciveChar(&arr[i]);
    }
 }

 void UART_TransmitDataInt(u16 data)
 {
    u8 buffer[20];
	convert_dec_to_string(data,buffer);
	UART_TransmitDataString(buffer);
 }

 /*
 void SetCallBackFunction_1(void(*ptr)(u8*))
 {
    Recieve=ptr;
 }
 
 void __vector_13(void) __attribute__ ((signal));
 void __vector_13(void)
 {
	 Recieve(&data);
 }
 */