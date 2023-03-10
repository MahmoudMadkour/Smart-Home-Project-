/*
 * DIO_program.c
 *
 * Created: 10/30/2022 12:21:16 AM
 *  Author: ENG.Mohamed
 */ 

 /* UTILES_LIB */

 #include "DATA.h"
 #include "ATMEGA32_REG.h"
 #include "bit_math.h"

/* MCAL */

#include "DIO_interface.h"









 void DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PinDir)
 {
    if(PortId>=0 && PortId<=3)
	{
	   if(PinId>=0 && PinId<=7 && PinDir==DIO_PIN_OUT || PinDir==DIO_PIN_IN)
	   {
	       switch(PortId)
		   {
		      case DIO_PORTA:
			      if( PinDir==DIO_PIN_OUT )
				  {
				     SET_BIT(DDRA,PinId);
					  break;
				  }
				  else
				  {
				     CLEAR_BIT(DDRA,PinId);
					  break;
				  }

			  case DIO_PORTB:
			     if( PinDir==DIO_PIN_OUT )
			     {
				    SET_BIT(DDRB,PinId);
					 break;
			     }
			     else
			     {
				    CLEAR_BIT(DDRB,PinId);
					 break;
			     }

			  case DIO_PORTC:
			     if( PinDir==DIO_PIN_OUT )
			     {
				    SET_BIT(DDRC,PinId);
					 break;
			     }
			     else
			     {
				    CLEAR_BIT(DDRC,PinId);
					 break;
			     }

			  case DIO_PORTD:
			     if( PinDir==DIO_PIN_OUT )
			     {
				    SET_BIT(DDRD,PinId);
					 break;
			     }
			     else
			    {
				    CLEAR_BIT(DDRD,PinId);
					 break;
			    }
			  
		   }
	   }
	}
 }
 void DIO_SetPinValue(u8 PortId,u8 PinId,u8 PinValue)
 {
     if(PortId>=0 && PortId<=3)
     {
	     if(PinId>=0 && PinId<=7 && PinValue==DIO_PIN_HIGH || PinValue==DIO_PIN_LOW)
	     {
		     switch(PortId)
		     {
			     case DIO_PORTA:
			     if( PinValue==DIO_PIN_HIGH )
			     {
				     SET_BIT(PORTA,PinId);
					 break;
			     }
			     else
			     {
				     CLEAR_BIT(PORTA,PinId);
					 break;
			     }

			     case DIO_PORTB:
			     if( PinValue==DIO_PIN_HIGH )
			     {
				     SET_BIT(PORTB,PinId);
					 break;
			     }
			     else
			     {
				     CLEAR_BIT(PORTB,PinId);
					 break;
			     }

			     case DIO_PORTC:
			     if( PinValue==DIO_PIN_HIGH )
			     {
				     SET_BIT(PORTC,PinId);
					 break;
			     }
			     else
			     {
				     CLEAR_BIT(PORTC,PinId);
					  break;
			     }

			     case DIO_PORTD:
			     if( PinValue==DIO_PIN_HIGH )
			     {
				     SET_BIT(PORTD,PinId);
					 break;
			     }
			     else
			     {
				     CLEAR_BIT(PORTD,PinId);
					 break;
			     }
			     
		     }
	     }
     }

 }
 void DIO_SetRegValue(u8 PortId,u8 PortValue)
 {
    if(PortId>=0 && PortId<=3)
	{
	    switch(PortId)
		{
		   case DIO_PORTA:
		        PORTA=PortValue;
				break;
		   case DIO_PORTB:
		        PORTB=PortValue;
				break;
		   case DIO_PORTC:
		        PORTC=PortValue;
				break;
		   case DIO_PORTD:
		        PORTD=PortValue;
				break;
		} 
	}

 }
 void DIO_SetRegDirection(u8 PortId,u8 PortDir)
 {
       if(PortId>=0 && PortId<=3)
       {
	       switch(PortId)
	       {
		       case DIO_PORTA:
		       DDRA=PortDir;
		       break;
		       case DIO_PORTB:
		       DDRB=PortDir;
		       break;
		       case DIO_PORTC:
		       DDRC=PortDir;
		       break;
		       case DIO_PORTD:
		       DDRD=PortDir;
		       break;
	       }
       }

 }
 u8 DIO_GetPinValue(u8 PortId,u8 PinId)
 {
      u8 PinVal=0;

     if(PortId>=0 && PortId<=3)
	 {
	     
	    
	     switch(PortId)
		 {

		     case DIO_PORTA:
			 PinVal=GET_BIT(PINA,PinId);
			 break;
			 case DIO_PORTB:
			 PinVal = GET_BIT(PINB,PinId);
			 break;
			 case DIO_PORTC:
			 PinVal = GET_BIT(PINC,PinId);
			 break;
			 case DIO_PORTD:
			 PinVal =GET_BIT(PIND,PinId);
			 break;



		 }	
	 }
	  
	 return PinVal;
 }

 void DIO_SetPullupRes(u8 PortId,u8 PinId)
 {
    if(PortId>=0 && PortId<=3)
	{
	   switch(PortId)
	   {
	      case DIO_PORTA:
		  SET_BIT(PORTA,PinId);
		  break;
		  case DIO_PORTB:
		  SET_BIT(PORTB,PinId);
		  break;
		  case DIO_PORTC:
		  SET_BIT(PORTC,PinId);
		  break;
		  case DIO_PORTD:
		  SET_BIT(PORTD,PinId);
		  break;
	   }
	   
	}
 }

 u8 DIO_GetRegValue(u8 PortId)
  {
	  u8 RegValue=0;
	  if(PortId>=0 && PortId<=3)
	  {
		  
		  switch(PortId)
		  {
			  case DIO_PORTA:
			  RegValue=PINA;
			  break;
			  case DIO_PORTB:
			  RegValue=PINB;
			  break;
			  case DIO_PORTC:
			  RegValue=PINC;
			  break;
			  case DIO_PORTD:
			  RegValue=PIND;
			  break;
		  }
	  }
	  return RegValue;
	  

  }