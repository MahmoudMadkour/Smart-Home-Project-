/*
 * ADC_interface.h
 *
 * Created: 11/11/2022 9:47:19 PM
 *  Author: ENG.Mohamed
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* CHANNEL NUM */

#define   ADC_CHANNEL0   0
#define   ADC_CHANNEL1   1
#define   ADC_CHANNEL2   2
#define   ADC_CHANNEL3   3
#define   ADC_CHANNEL4   4
#define   ADC_CHANNEL5   5
#define   ADC_CHANNEL6   6
#define   ADC_CHANNEL7   7

void ADC_init(void);
void ADC_getDigitalValue(u8 channelNum,u16* returendValue);





#endif /* ADC_INTERFACE_H_ */