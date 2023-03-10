/*
 * KEY_BAD_program.c
 *
 * Created: 10/29/2022 10:36:50 PM
 *  Author: ENG.Mohamed
 */ 

 /* utiles_lib */
 #include "DATA.h"
 #include "ATMEGA32_REG.h"
 #include "bit_math.h"


 /* MCAL */
 #include "DIO_interface.h"

 /* HAL */
 #include "KEY_BAD_INTERFACE.h"
 #include "KBD_confg.h"

 static u8 KPD_ColumnsPins[4]={KPD_COLS0_PIN,KPD_COLS1_PIN,KPD_COLS2_PIN,KPD_COLS3_PIN};
 static u8 KPD_RowsPins[4]={KPD_ROWS0_PIN,KPD_ROWS1_PIN,KPD_ROWS2_PIN,KPD_ROWS3_PIN};
 
 


 void KPD_getValue(u8* returnedValue)
 {
     u8 KPD_KEYS[4][4]={
	     {'1','2','3','A'},
	     {'4','5','6','B'},
	     {'7','8','9','C'},
	     {'*','0','#','D'}
     };
    *returnedValue=KPD_NOT_PRESSED;
    u8 col;
	u8 row;
	u8 pinvalue;
	u8 PinFlag=0;
	for(col=0;col<4;col++)
	{
	   // activate each col//
	   DIO_SetPinValue(DIO_PORTB,KPD_ColumnsPins[col],DIO_PIN_LOW);
	   for(row=0;row<4;row++)
	   {
	      pinvalue=DIO_GetPinValue(KPD_ROWS_PORT,KPD_RowsPins[row]);
		  if(pinvalue==0)
		  { 
		      *returnedValue=KPD_KEYS[row][col];
			  
			  while(pinvalue=0)
			  {
			     pinvalue=DIO_GetPinValue(KPD_ROWS_PORT,KPD_RowsPins[row]);
			  }
			  
			  PinFlag=1;
		      break;
		  }
	   }
	   DIO_SetPinValue(DIO_PORTB,KPD_ColumnsPins[col],DIO_PIN_HIGH);
	   if(PinFlag==1)
		{
		   break;
		}
		
	}

 }

 void KPD_initDiretions(void)
 {
    DIO_SetPinDirection(KPD_COLS_PORT,KPD_COLS0_PIN,DIO_PIN_OUT);
	DIO_SetPinDirection(KPD_COLS_PORT,KPD_COLS1_PIN,DIO_PIN_OUT);
	DIO_SetPinDirection(KPD_COLS_PORT,KPD_COLS2_PIN,DIO_PIN_OUT);
	DIO_SetPinDirection(KPD_COLS_PORT,KPD_COLS3_PIN,DIO_PIN_OUT);

    DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROWS0_PIN,DIO_PIN_IN);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROWS1_PIN,DIO_PIN_IN);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROWS2_PIN,DIO_PIN_IN);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROWS3_PIN,DIO_PIN_IN);

	DIO_SetPullupRes(KPD_ROWS_PORT,KPD_ROWS0_PIN);
	DIO_SetPullupRes(KPD_ROWS_PORT,KPD_ROWS1_PIN);
	DIO_SetPullupRes(KPD_ROWS_PORT,KPD_ROWS2_PIN);
	DIO_SetPullupRes(KPD_ROWS_PORT,KPD_ROWS3_PIN);


 }