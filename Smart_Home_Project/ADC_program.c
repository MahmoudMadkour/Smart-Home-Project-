/*
 * ADC_program.c
 *
 * Created: 11/11/2022 9:46:54 PM
 *  Author: ENG.Mohamed
 */ 

 /* UTILES */

 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"

/* MCAL */

#include "ADC_interface.h"



void ADC_init(void)
{
    // select Vref =AVCC
    SET_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);

	// clear ADLAR select right 
	CLEAR_BIT(ADMUX,5);

	// single conversion mode
	CLEAR_BIT(ADCSRA,5);

	// prescalar
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

	// enable ADC 
	SET_BIT(ADCSRA,7);

}


void ADC_getDigitalValue(u8 channelNum,u16* returendValue)
{
    if((channelNum<32) && returendValue != NULL)
	{
	    ADMUX &=0b11100000;

        ADMUX |=channelNum;

		// start conversion
		SET_BIT(ADCSRA,6);

		while(GET_BIT(ADCSRA,4) == 0);

		// clear flag
		SET_BIT(ADCSRA,4);

		*returendValue=ADC_U16;
	}

}
