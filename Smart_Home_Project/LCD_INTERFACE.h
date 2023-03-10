#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/**** include data types file ****/
#include "DATA.h"

/*** define LCD commands ***/

#define clear_LCD              0x01
#define move_cursor_right      0x14
#define move_cursor_left       0x10
#define first_line_begin       0x80
#define second_line_begin      0xc0
#define mode_8_bit             0x38
#define mode_4_bit             0x02
#define mode_4_bit_dot_matrix  0x28
#define LCD_display_on         0x0c

//#define ARRAY(arr_name)                ((sizeof(arr_name))/(sizeof(arr_name[0])))
//#define NULL                           ((void*)0)

void init_lcd(void);
void write_char(u8 ch);
void write_string(u8*ptr);
void write_command(u8 comm);
void write_int(u32 value);
void convert_dec_to_string(u32 dec,u8* arr);
void reverse_string(u8* buffer);
void move_cursor(u8 x,u8 y); /*start from (0,0)*/
void peek_lcd(void);



#endif
