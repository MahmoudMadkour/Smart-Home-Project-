/*
 * Timer1_interface.h
 *
 * Created: 12/3/2022 7:32:31 PM
 *  Author: ENG.Mohamed
 */ 
 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define TMR1_NORMAL_MODE   1
#define TMR1_CTC_MODE      2
#define TMR1_FAST_PWM_MODE 3

/* TIMER1 */

void TMR1_INIT(void);
void TMR1_SetCompareMatch(u16 CompareValue);




#endif /* TIMER1_INTERFACE_H_ */