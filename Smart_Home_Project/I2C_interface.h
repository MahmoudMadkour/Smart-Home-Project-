/*
 * I2C_interface.h
 *
 * Created: 12/16/2022 4:40:47 PM
 *  Author: ENG.Mohamed
 */ 
  /* UTILIES LIB */

  #include "DATA.h"

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


void I2C_INITMASTER(void);
void I2C_SendStartCondition(void);
void I2C_SendStopCondition(void);
void I2C_SendRepStartCondition(void);
void I2C_SendSlaveAddWithWrite(u8 SlaveAdd);
void I2C_SendSlaveAddWithRead(u8 SlaveAdd);
void I2C_SendMasterDataByte(u8 Senddata);
void I2C_ReciveMasterDataByte(u8* RxData);




#endif /* I2C_INTERFACE_H_ */