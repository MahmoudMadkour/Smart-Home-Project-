/*
 * Timer1_program.c
 *
 * Created: 12/3/2022 7:30:52 PM
 *  Author: ENG.Mohamed
 */ 
 /*		UTILS LIB    */
  #include "ATMEGA32_REG.h"
  #include "bit_math.h"
  #include "DATA.h"
  /*    MCAL   */
  #include "Timer1_interface.h"






 void TMR1_INIT(void)
 {
     /* SET PIN DIRECTION */
     SET_BIT(DDRD,5);
     /*  FAST PWM MODE 14 */
	 CLEAR_BIT(TCCR1A,0);
	 SET_BIT(TCCR1A,1);
	 SET_BIT(TCCR1B,3);
	 SET_BIT(TCCR1B,4);

	 /*  NON INVERTING MODE */
	 SET_BIT(TCCR1A,7);
	 CLEAR_BIT(TCCR1A,6);

	 /* ICR1 PERIOD TIME */
	 ICR1=4999;

	 /*  PRESCALER 64 */
	 SET_BIT(TCCR1B,0);
	 SET_BIT(TCCR1B,1);
	 CLEAR_BIT(TCCR1B,2);
 }
 void TMR1_SetCompareMatch(u16 CompareValue)
 {
     OCR1A = CompareValue;
 }