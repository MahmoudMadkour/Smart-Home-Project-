/*
 * TIMER_program.c
 *
 * Created: 11/27/2022 5:29:21 PM
 *  Author: ENG.Mohamed
 */ 

  /* UTILES LIB */

  #include "ATMEGA32_REG.h"
  #include "bit_math.h"
  #include "DATA.h"

  /* MCAL */

  #include "TIMER_interface.h"
  #include "TIMER_confg.h"
  #include "GI_interface.h"

  //static void(*callback_1)(void)=NULL;
  //static void(*callback_2)(void)=NULL;
  void TMR_INIT(void)
  {
     #if TMR_GEN_MODE==TMR_NORMAL_MODE
	    /* TIMER0 CONFG */
		CLEAR_BIT(TCCR0,TMR_PIN6);
		CLEAR_BIT(TCCR0,TMR_PIN3);
		/* TIMER0 PRELOAD */
		TCNT0=TMR_PRELOAD_VALUE;
		/* TIMER0 INTERRUPT */
		SET_BIT(TIMSK,TMR_PIN0);
	 #elif TMR_GEN_MODE==TMR_CTC_MODE
	    /* TIMER0 CONFG */
	    CLEAR_BIT(TCCR0,TMR_PIN6);
	    SET_BIT(TCCR0,TMR_PIN3);
		/* TIMER0 INTERRUPT */
		SET_BIT(TIMSK,TMR_PIN1);
	 #elif TMR_GEN_MODE==TMR_PWM_MODE
	    /* PIN DIRECTION */
		SET_BIT(DDRB,TMR_PIN3);
	    /* TIMER0 CONFG */
		SET_BIT(TCCR0,TMR_PIN6);
		SET_BIT(TCCR0,TMR_PIN3);
		/* NON INVERTING */
		SET_BIT(TCCR0,TMR_PIN5);
		CLEAR_BIT(TCCR0,TMR_PIN4);

	 #endif
	
	 /* PRESCALER */

	 SET_BIT(TCCR0,TMR_PIN0);
	 SET_BIT(TCCR0,TMR_PIN1);
	 CLEAR_BIT(TCCR0,TMR_PIN2);
	    
  }
  void TMR_CompareMatchValue(u8 CompareValue)
  {
     OCR0=CompareValue;
  }
  /*
  void Set_CallBackFun(void(*ptr_1)(void))
  {
     callback_1=ptr_1;
  }
  


  void Set_CallBackFun_1(void(*ptr_2)(void))
  {
     callback_2=ptr_2;
  }
  

  
  void __vector_10(void) __attribute__ ((signal));
  void __vector_10(void)
  {
	  static u16 count=0;
	  count++;
	  if(count==TMR_COUNT_VALUE)
	  {
	     count=0;
		 //callback_2();
	  }
  }
  */