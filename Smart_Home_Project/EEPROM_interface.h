/*
 * EEPROM_interface.h
 *
 * Created: 12/16/2022 8:19:00 PM
 *  Author: ENG.Mohamed
 */ 
 /* UTILES LIB */

 #include "DATA.h"

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_WriteByte(u16 ByteAddress,u8 data);
void EEPROM_ReadByte(u16 ByteAddress,u8* data);
void EEPROM_Compare(u8*arr,u8*arr_1);



#endif /* EEPROM_INTERFACE_H_ */