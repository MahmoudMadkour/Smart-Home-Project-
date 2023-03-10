/*
 * TIMER_interface.h
 *
 * Created: 11/27/2022 5:29:48 PM
 *  Author: ENG.Mohamed
 */ 
 /* UTILES LIB */

 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"

 /* MCAL */

 #include "TIMER_confg.h"



#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/* TMR_PIN_CONFG */

#define TMR_PIN0   0
#define TMR_PIN1   1
#define TMR_PIN2   2
#define TMR_PIN3   3
#define TMR_PIN4   4
#define TMR_PIN5   5
#define TMR_PIN6   6
#define TMR_PIN7   7

/* TMR_FUNC_PROTOTYPE */

void TMR_INIT(void);
void TMR_CompareMatchValue(u8 CompareValue);
void Set_CallBackFun(void(*ptr_1)(void));
void Set_CallBackFun_1(void(*ptr_2)(void));




#endif /* TIMER_INTERFACE_H_ */