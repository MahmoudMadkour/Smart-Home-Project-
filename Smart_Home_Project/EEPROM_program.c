/*
 * EEPROM_program.c
 *
 * Created: 12/16/2022 8:18:36 PM
 *  Author: ENG.Mohamed
 */ 

 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"

 /* MCAL */

 #include "I2C_interface.h"

 /* HAL */

 #include "EEPROM_interface.h"

 #define F_CPU  16000000
 #include <util/delay.h>

 /* FUN IMPEL */

 void EEPROM_WriteByte(u16 ByteAddress,u8 data)
 {
     u8 address =(u8)((0x50) | (u8)(ByteAddress>>8));
	 I2C_SendStartCondition();
	 I2C_SendSlaveAddWithWrite(address);
	 I2C_SendMasterDataByte((u8)ByteAddress);
	 I2C_SendMasterDataByte(data);
	 I2C_SendStopCondition();
	 _delay_ms(5);
 }
 void EEPROM_ReadByte(u16 ByteAddress,u8* data)
 {
    u8 address =(u8)((0x50) | (u8)(ByteAddress>>8));
    I2C_SendStartCondition();
    I2C_SendSlaveAddWithWrite(address);
    I2C_SendMasterDataByte((u8)ByteAddress);
	I2C_SendRepStartCondition();
	I2C_SendSlaveAddWithRead(address);
	I2C_ReciveMasterDataByte(data);
	I2C_SendStopCondition();
	_delay_ms(5);
}
void EEPROM_Compare(u8*arr,u8*arr_1)
{
  for(u8 i=0;i<4;i++)
  {
      EEPROM_ReadByte(i,&arr[i]);
  }
  for(u8 j=0; j<4;j++)
  {
      EEPROM_ReadByte((j+4),&arr_1[j]);
  }
}