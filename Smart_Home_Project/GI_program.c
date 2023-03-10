/*
 * GI_program.c
 *
 * Created: 11/12/2022 10:46:52 PM
 *  Author: ENG.Mohamed
 */ 

 /* UTILES */

 #include "ATMEGA32_REG.h"
 #include "bit_math.h"
 #include "DATA.h"

/* MCAL */

#include "GI_interface.h"

void GI_enable(void)
{
   SET_BIT(SREG,7);
}
void GI_disable(void)
{
   CLEAR_BIT(SREG,7);
}
