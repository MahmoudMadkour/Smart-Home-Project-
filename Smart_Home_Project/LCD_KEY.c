/*
 * LCD_KEY.c
 *
 * Created: 2/11/2023 1:06:29 AM
 *  Author: ENG.Mohamed
 */ 
 /*  MCAL  */
 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"

 /*   HAL   */
 #include "LCD_KEYBAD_interface.h"
 #include "KEY_BAD_INTERFACE.h"
 #include "LCD.h"
 #include "LCD_INTERFACE.h"


 u8 Compare_String(u8*ptr,u8*password)
 {
    if(String_Length(ptr)!=String_Length(password))
	{
	  return 0;
	}
	
	  u8 i=0;
	  while(password[i]!='\0')
	  {
	     if(ptr[i]==password[i])
		 {
		   i++;
		   continue;
		 }
		 else
		 {
		    return 0;
		 }
      }
	  return 1;
 }
 u8 String_Length(u8*ptr_1)
 {
    static u8 i=0;
	while(ptr_1[i]!='\0')
	{
	   i++;
	}
	return i;
 } 
