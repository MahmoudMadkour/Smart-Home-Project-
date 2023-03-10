#include "ATMEGA32_REG.h"
#include "DATA.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "LCD_INTERFACE.h"
#include "LCD.h"
#define F_CPU 16000000
#include <util/delay.h>





void init_lcd(void)
{
  
    //write_DDR_reg(A,(1<<D4) | (1<<D5) | (1<<D6) | (1<<D7));
    //write_DDR_reg(B,(1<<RS) | (1<<E) | (1<<RW));
	DIO_SetRegDirection(DIO_PORTA,(1<<D4) | (1<<D5) | (1<<D6) | (1<<D7));
	DIO_SetRegDirection(DIO_PORTB,(1<<RS) | (1<<E) | (1<<RW));
	
    //clear_pin(B,E);
   DIO_SetPinValue(DIO_PORTB,E,DIO_PIN_LOW);
	
	
	_delay_ms(20);



    write_command(mode_4_bit);

	write_command(mode_4_bit_dot_matrix);

    write_command(LCD_display_on);

    write_command(clear_LCD);

    write_command(first_line_begin);

    write_string("User:");
	write_command(second_line_begin);
    write_string("Pass:");
	
	


	

   

	
	






}
void write_char(u8 ch)
{
    
   
	{
	      /** upper nipple **/
	      //write_port_reg(A, (ch & 0xF0) | (get_port_reg(A) & 0x0F));
	      //set_pin(B,RS);
	      //clear_pin(B,RW);
		  DIO_SetRegValue(DIO_PORTA,(ch & 0xF0) | (DIO_GetRegValue(DIO_PORTA) & 0x0F));
		  DIO_SetPinValue(DIO_PORTB,RS,DIO_PIN_HIGH);
		  DIO_SetPinValue(DIO_PORTB,RW,DIO_PIN_LOW);
		  
	      peek_lcd();
	      _delay_ms(2);
	      

	      /** lower nipple **/
	      //write_port_reg(A,(ch<<4) | (get_port_reg(A) & 0x0F));
	      //set_pin(B,RS);
	      //clear_pin(B,RW);
		 DIO_SetRegValue(DIO_PORTA,(ch<<4) | (DIO_GetRegValue(DIO_PORTA) & 0x0F));
		 DIO_SetPinValue(DIO_PORTB,RS,DIO_PIN_HIGH);
		 DIO_SetPinValue(DIO_PORTB,RW,DIO_PIN_LOW);
	      peek_lcd();
	      _delay_ms(2);
	}
    
   


}
void write_string(u8* ptr)
{
   
       u32 i=0;
       while(ptr[i] != '\0')
       {
        write_char(ptr[i]);
        i++;
       }
   

}
void write_command(u8 comm)
{
    /** upper nipple **/
    //write_port_reg(A,(comm & 0xF0) |(get_port_reg(A) & 0x0F));
    //clear_pin(B,RS);
	//clear_pin(B,RW);
	DIO_SetRegValue(DIO_PORTA,(comm & 0xF0) | (DIO_GetRegValue(DIO_PORTA) & 0x0F));
	DIO_SetPinValue(DIO_PORTB,RS,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,RW,DIO_PIN_LOW);
    peek_lcd();
	_delay_ms(2);


    /** lower nipple **/
    //write_port_reg(A,(comm<<4) | (get_port_reg(A) & 0x0F));
    //clear_pin(B,RS);
	//clear_pin(B,RW);
	DIO_SetRegValue(DIO_PORTA,(comm<<4) | (DIO_GetRegValue(DIO_PORTA) & 0x0F));
	DIO_SetPinValue(DIO_PORTB,RS,DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB,RW,DIO_PIN_LOW);
    peek_lcd();
	_delay_ms(2);

}
void write_int(u32 value)
{
    u8 buffer[20];
    convert_dec_to_string(value,buffer);
    write_string(buffer);

}
void convert_dec_to_string(u32 dec,u8* buffer)
{
    
    
        if(dec==0)
        {
            buffer[0]='0';
            buffer[1]='\0';
        }
        else
        {
           u8 i=0;
           u8 rem=0;
           while(dec != 0)
           {
		    rem=dec%10;
            dec=dec/10;
           
            buffer[i]=48+rem;
			i++;

           }
		   buffer[i]='\0';
          
           reverse_string(buffer);

        }
    

}
void reverse_string(u8* buffer)
{   
    u8 x = 0;
    while(buffer[x] != '\0')  x++;
	
	 
	   u8 buffer_end = x-1;
	   u8 buffer_center = buffer_end/2;
	
    
    u8 i = 0;
    while(i <= buffer_center)
    {
	    u8 temp = buffer[i];
	    buffer[i] = buffer[buffer_end - i];
	    buffer[buffer_end - i] = temp;
	    i++;
    }

}
void move_cursor(u8 x,u8 y)
{
    write_command((0x80 | (x +64* y)));

} /*start from (0,0)*/
void peek_lcd(void)
{
    //set_pin(B,E);
   DIO_SetPinValue(DIO_PORTB,E,DIO_PIN_HIGH);
    _delay_us(2);
    //clear_pin(B,E);
   DIO_SetPinValue(DIO_PORTB,E,DIO_PIN_LOW);


}
