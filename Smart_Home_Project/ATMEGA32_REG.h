
#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

/* DATA DIRCTION REGISTER*/

#define DDRA (*(volatile u8*)0x3A)  
#define DDRB (*(volatile u8*)0x37)  
#define DDRC (*(volatile u8*)0x34)  
#define DDRD (*(volatile u8*)0x31)

/* PORT REGISTER */

#define PORTA (*(volatile u8*)0x3B)    
#define PORTB (*(volatile u8*)0x38)  
#define PORTC (*(volatile u8*)0x35)  
#define PORTD (*(volatile u8*)0x32)  

/* PIN REGISTER */

#define PINA (*(volatile u8*)0x39)  
#define PINB (*(volatile u8*)0x36)  
#define PINC (*(volatile u8*)0x33)  
#define PIND (*(volatile u8*)0x30)  


/* ADC REGISTER */

#define ADMUX    (*(volatile u8*)0x27)
#define ADCSRA   (*(volatile u8*)0x26)
#define ADCL     (*(volatile u8*)0x24)
#define ADCH     (*(volatile u8*)0x25)
#define ADC_U16  (*(volatile u16*)0x24)
#define SFIOR    (*(volatile u8*)0x50)


/* TIMER0 REGISTERS */

#define  TCNT0   (*(volatile u8*)0x52)
#define  OCR0    (*(volatile u8*)0x5C)
#define  TCCR0   (*(volatile u8*)0x53)
#define  TIMSK   (*(volatile u8*)0x59)
#define  TIFR    (*(volatile u8*)0x58)

/*  EXTERNAL_INTERRUPT REGISTER */

#define MCUCR   (*(volatile u8*)0x55)
#define MCUCSR  (*(volatile u8*)0x54)
#define GICR    (*(volatile u8*)0x5B)
#define GIFR    (*(volatile u8*)0x5A)
#define SREG    (*(volatile u8*)0x5F)

/* TIMER1 REGISTER */

#define TCCR1A  (*(volatile u8*)0x4F)
#define TCCR1B  (*(volatile u8*)0x4E)
#define TCNT1   (*(volatile u16*)0x4C)
#define OCR1A   (*(volatile u16*)0x4A)
#define OCR1B   (*(volatile u16*)0x48)
#define ICR1    (*(volatile u16*)0x46)

/* UART REGISTER */

#define UCSRA   (*(volatile u8*)0x2B)
#define UCSRB   (*(volatile u8*)0x2A)
#define UBRRL   (*(volatile u8*)0x29)
#define UCSRC   (*(volatile u8*)0x40)
#define UBRRH   (*(volatile u8*)0x40)
#define UDR     (*(volatile u8*)0x2C)

/* SPI REGISTER */

#define SPDR    (*(volatile u8*)0x2F)
#define SPSR    (*(volatile u8*)0x2E)
#define SPCR    (*(volatile u8*)0x2D)

/* I2C REGISTER */

#define TWCR        (*(volatile u8*)0x56)
#define TWDR        (*(volatile u8*)0x23)
#define TWAR        (*(volatile u8*)0x22)
#define TWSR        (*(volatile u8*)0x21)
#define TWBR        (*(volatile u8*)0x20)


#endif /* ATMEGA32_REG_H_ */