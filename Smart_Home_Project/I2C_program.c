/*
 * I2C_program.c
 *
 * Created: 12/16/2022 4:40:16 PM
 *  Author: ENG.Mohamed
 */ 
 /* UTILES LIB */

 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"

 /* MCAL */

 #include "I2C_interface.h"


 /* FUN IMPELE */

 void I2C_INITMASTER(void)
 {  
   
    // Set Prescaller = 1 >> Set Freq. = 400KHZ
    CLEAR_BIT(TWSR,0);
	CLEAR_BIT(TWSR,1);
    TWBR=12;
	// Set ACK bit
	SET_BIT(TWCR,6);
	// Enable I2C
	SET_BIT(TWCR,2);
 }
 void I2C_SendStartCondition(void)
 {
    // Set Start Condition Bit
	  SET_BIT(TWCR,5);

	 //Clear Flag To Start 
	 SET_BIT(TWCR,7);

	 //Wait for Set flag
	 while(GET_BIT(TWCR,7)==0);
     
	 //Check ACK =SC ACK
	 while((TWSR & 0xF8) != 0x08);
 }
 void I2C_SendRepStartCondition(void)
 {
     // Set Start Condition Bit
     SET_BIT(TWCR,5);

     //Clear Flag To Start
     SET_BIT(TWCR,7);

     //Wait for Set flag
     while(GET_BIT(TWCR,7)==0);
     
	 //Check ACK = SC ACK
	 while((TWSR & 0xF8) != 0x10);
 }
 void I2C_SendStopCondition(void)
 {
    // Send Stop Condition
	SET_BIT(TWCR,4);

	//Clear Flag to start 
	SET_BIT(TWCR,7);
 }
 void I2C_SendSlaveAddWithWrite(u8 SlaveAdd)
 {
     if(SlaveAdd<128)
	 { 
	     TWDR=SlaveAdd<<1;
		 CLEAR_BIT(TWDR,0);

		 //Clear start Cond
		 CLEAR_BIT(TWCR,5);

		 //Clear Flag to start
		 SET_BIT(TWCR,7);

		 //Wait for Set flag
		 while(GET_BIT(TWCR,7)==0);

		 //Check ACK = SC ACK
		 while((TWSR & 0xF8) != 0x18);
	 }

	 
 }
 void I2C_SendSlaveAddWithRead(u8 SlaveAdd)
 {
     if(SlaveAdd<128)
     {
	     TWDR=SlaveAdd<<1;
	     SET_BIT(TWDR,0);

	     //Clear start Cond
	     CLEAR_BIT(TWCR,5);

	     //Clear Flag to start
	     SET_BIT(TWCR,7);

	     //Wait for Set flag
	     while(GET_BIT(TWCR,7)==0);

	     //Check ACK = SC ACK
	     while((TWSR & 0xF8) != 0x40);
  }  
 }
 void I2C_SendMasterDataByte(u8 Senddata)
 {
    TWDR=Senddata;

	//Clear Flag to start
	
	TWCR=(1<<7) | (1<<2);
	//Wait for Set flag
	while(GET_BIT(TWCR,7)==0);

	//Check ACK = SC ACK
	while((TWSR & 0xF8) != 0x28);
 }
 void I2C_ReciveMasterDataByte(u8* RxData)
 {
    if(RxData != NULL)
	{
	  //Clear Flag to start
	  
	  TWCR=(1<<7) | (1<<2);
	  //Wait for Set flag
	  while(GET_BIT(TWCR,7)==0);

	  //Check ACK = SC ACK
	  while((TWSR & 0xF8) != 0x58);
	  *RxData=TWDR;
	}
 }