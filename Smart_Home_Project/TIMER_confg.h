/*
 * TIMER_confg.h
 *
 * Created: 11/27/2022 5:31:12 PM
 *  Author: ENG.Mohamed
 */ 


#ifndef TIMER_CONFG_H_
#define TIMER_CONFG_H_

/* TIMER MODE CONFG */

#define TMR_NORMAL_MODE  1
#define TMR_CTC_MODE     2
#define TMR_PWM_MODE     3

/* TIMER MODE SELECTION */

#define TMR_GEN_MODE     TMR_NORMAL_MODE    

/* TIMER PRELOAD SELECTION */

#define TMR_PRELOAD_VALUE  0
#define TMR_OVF_NUMBER     375 

/* TIMER OCR VALUE */

#define TMR_OCR_VALUE  249
#define TMR_COUNT_VALUE   60000  

/* TIMER OCN MODE */

#define TMR_TOGGLE_MODE  1
#define TMR_SET_MODE     2
#define TMR_CLEAR_MODE   3

/* TIMER OCN MODE SELECT */

#define TMR_OCN_MODE   TMR_TOGGLE_MODE




#endif /* TIMER_CONFG_H_ */