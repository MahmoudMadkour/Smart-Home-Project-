/*
 * keybad.c
 *
 * Created: 10/29/2022 10:36:03 PM
 * Author : ENG.Mohamed
 */ 
 /* utiles_lib */
 #include "DATA.h"
 #include "ATMEGA32_REG.h"
 #include "bit_math.h"


 /* MCAL */
 #include "DIO_interface.h"
 #include "GI_interface.h"
 #include "TIMER_confg.h"
 #include "TIMER_interface.h"
 #include "I2C_interface.h"
 #include "EEPROM_interface.h"
 #include "UART_interface.h"
 #include "ADC_interface.h"
 #include "Timer1_interface.h"


 /* HAL */
 #include "KEY_BAD_INTERFACE.h"
 #include "KBD_confg.h"
 #include "LCD.h"
 #include "LCD_INTERFACE.h"
 #include "LCD_KEYBAD_interface.h"
 #define F_CPU 16000000
 #include <util/delay.h>



  u8 buffer[20];
  u8 buffer_1[20];
  u8 arr_2[20];
  u8 arr_1[20];
  u8 arr_3[20];  // login user name with keybad
  u8 arr_4[20];
  u8 arr_N[20];
  u8 arr_P[20];    
  u8 count_1=0;
  u8 count_2=0;
  u8 counter_1=0;
  u8 counter=0;
  u8 counter_2=0;
  u8 count_S_1=0;
  u8 count_S_2=0;
  u8 count_k_1=0;
  u8 count_k_2=0;
  u8 c1=0;
  static u16 count=0;
  u8 data;
  u8 Key_data;
  u8 Admin=0;
  u8 Admin_1=0;
  u8 User=0;
  static u8 flag=0;
  static u16 analog, ADC_Data; 
  u8 UART;
   //u8 data_1;
 


int main(void)
{

   /*  Initialization for all drivers that needed to project   */
    init_lcd();
	TMR_INIT();
	TMR1_INIT();
	GI_enable();
	I2C_INITMASTER();
	UART_INTI();
	ADC_init();
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_IN);//POT
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_IN);//BUTTON 0
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_IN);//BUTTON 2
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_IN);//BUTTON 1
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_IN);//RX
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUT);//TX
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUT);//LED 1
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);//LED 0
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUT);//LED 2
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUT);//BUZZER
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);//H-A1
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUT);//H-A2
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUT);//EN
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUT);
	KPD_initDiretions();
	write_command(0x85);
	/*  The beginning of project start with this message on Mobile  */
	UART_TransmitDataString("*-Login As Admin\n");
	UART_TransmitDataString("#-Sign In As User\n");
	/* Calling Rx Func To Choose One Of This Options  */
    UART_ReciveChar(&UART);
	
	
	
    while (1) 
    {
	  
	
	  if(UART=='*')
	  {
	    UART_TransmitDataString("Enter Admin Name\n");
		/* First Login As Admin Using UART By Mobile */

	    while(1)
		{
		   if(count_2!=4)
		   {
		     UART_ReciveChar(&UART);
		     if(count_1<=3 && UART!='1') // This Condition To Limit The Name Chars
		     {
			     arr_1[count_1]=UART;  // Assign the name of admin in empty array called (arr_1) 
			     write_char(UART); // print every chars to LCD
			     count_1++;  // Increment The count to Assign The UART data to array indexs
				 /* Ending the access in arr_1 */
			     if(count_1==4)
			     {
				     UART_TransmitDataString("Enter Admin Pass\n");
			     }
		     }
			 /* Starting Asigning the Admin Pass */
		     else
		     {
			     arr_2[count_2]=UART; // Assign the pass of admin in empty array called (arr_2) 
			     write_command((0xc5) + (count_2)); //Incrementing The Cursor In every Cycle 
			     write_char(UART); // print every chars to LCD
			     count_2++; // Increment The count to Assign The UART data to array indexs
			     
		     }
		   }
		   /*******************************************************************************************************************************************************************************/

		   /* Comparing The Pass and the Name in arr_1,arr_2 */

		   if(count_2==4)
		   {
		      
		      if(Compare_String(arr_1,"ABCD")==1 && Compare_String(arr_2,"1234")==1)
			  {
			     /* While The pass and name is correct this two messages will send by UART to Choose Options */
			     UART_TransmitDataString("X-Sign Up Users\n");
				 UART_TransmitDataString("Z-Resume Project Normally\n");
				 /* Calling Rx Func To Choose One Of This Options  */
				 UART_ReciveChar(&UART);
				 if(UART=='Z')
				 {
				    Admin=1;
					while(1)
					{
					    /* Check The state of Button  */
					    if(DIO_GetPinValue(DIO_PORTD,DIO_PIN2)==1)
					    {

						    /* Comparing The Pass and the Name in arr_1,arr_2 */
						    if((Compare_String(arr_1,"ABCD")==1  &&  Compare_String(arr_2,"1234")==1))
						    {
							    counter=0; 
							    counter_1=0;
							    counter_2=0;
							    write_command(clear_LCD);
							    write_command(first_line_begin);
							    write_string("Welcome Home:)");
							    UART_TransmitDataString("\nThe Door Opened\n");
							    TMR1_SetCompareMatch(499); // Activate The Servo Motor
							    _delay_ms(2000); // Timing to Access
							    TMR1_SetCompareMatch(100); // Return Servo Motor to initial position
								UART_TransmitDataString("\nThe Door Closed\n");
							    if(Admin==1)
							    {
								    /* Choosing Any Leds in rooms to Turn it ON  */
								    UART_TransmitDataString("O-LED0 ON\n");
								    UART_TransmitDataString("F-LED0 OFF\n");
								    UART_TransmitDataString("N-LED1 ON\n");
								    UART_TransmitDataString("C-LED1 OFF\n");
								    UART_TransmitDataString("H-LED2 ON\n");
								    UART_TransmitDataString("L-LED2 OFF\n");
								    UART_TransmitDataString("D-DIMMER ON\n");
								    UART_TransmitDataString("S-Break\n");
								    while(1)
								    {
									    /* Calling Rx Func To Choose One Of This Options  */
									    UART_ReciveChar(&UART);
									    if(UART=='O')
									    {
										    DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
										    UART_TransmitDataString("LED0 IS ON\n");
									    }
									    else if(UART=='F')
									    {
										    DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
										    UART_TransmitDataString("LED0 IS OFF\n");
									    }
									    else if(UART=='N')
									    {
										    DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
										    UART_TransmitDataString("LED1 IS ON\n");
									    }
									    else if(UART=='C')
									    {
										    DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
										    UART_TransmitDataString("LED1 IS OFF\n");
									    }
									    else if(UART=='H')
									    {
										    DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
										    UART_TransmitDataString("LED2 IS ON\n");
									    }
									    else if(UART=='L')
									    {
										    DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
										    UART_TransmitDataString("LED2 IS OFF\n");
									    }
									    else if(UART=='D')
									    {
										    DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_HIGH);
										    UART_TransmitDataString("DIMMER IS ON\n");
									    }
									    else if(UART=='S')
									    {
										    break;
									    }
								    }
							    }
							    _delay_ms(1000);
							    UART_TransmitDataString("Temp Sensor Begin\n"); 
							    write_command(clear_LCD);
							    write_command(first_line_begin);
							    write_string("Temp Sensor");
							    flag=1; //Set Flag 1 To Activate Temp Sensor Readings In Real-Time
						    }
					    }
					    /* Reset Any Activation To Give Access To User To Login */
					    if(DIO_GetPinValue(DIO_PORTD,DIO_PIN6)==1)
					    {
						    write_command(clear_LCD);
						    write_command(first_line_begin);
						    write_string("User:");
						    write_command(second_line_begin);
						    write_string("Pass:");
						    write_command(0x85);
						    UART_TransmitDataString("\nTemp Sensor Stop");
						    
						    UART_TransmitDataString("\nLogin Again\n");
						    counter=0;
						    counter_1=0;
						    flag=0;
						    DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
						    DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
						    DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
						    DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
						    DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
						    DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
						    DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_LOW);
						    
					    }

						/* Temp Sensor Activation With Real-Time */
					    if(flag==1)
					    {
						    ADC_getDigitalValue(ADC_CHANNEL1,&ADC_Data); // Passing The ADC Channel Pin and Variable to assigning the data of temp sensor to it
						    analog = ((u32)ADC_Data*50)/1024; // analog value of temp sensor
						    
						    if(DIO_GetPinValue(DIO_PORTB,DIO_PIN0)==0 && DIO_GetPinValue(DIO_PORTD,DIO_PIN6)==0)
						    {
							    write_command(second_line_begin);
							    _delay_ms(500);
							    UART_TransmitDataString("\nTemp Sensor readings\n");
							    UART_TransmitDataInt(analog); // Printing Temp Sensor Readings With UART
							    UART_TransmitDataString("\n");
							    write_int(analog); // Printing Temp Sensor Readings With LCD
							    if(analog<25) 
							    {
								    /* Turning OFF Air Conditioning */
								    UART_TransmitDataString("Air Conditioning Stop\n");
								    DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
								    DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
								    DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
								    
							    }
							    else
							    {

								    /* Turning ON Air Conditioning */
								    UART_TransmitDataString("Air Conditioning Start\n");
								    

								    DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
								    DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
								    DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
								    
							    }
						    }
					    }
						/* Breaking From Admin Mode To User Mode */
					    if(DIO_GetPinValue(DIO_PORTB,DIO_PIN0)==1)
					    {
						    Admin_1=1;
						    break;
					    }
					   
					}
					if(Admin_1==1)
					{
					  break;
					}
				    
				 }
				 /*****************************************************************************************************************************************************************************/

				 /* Choosing Signing Up A User */
				 if(UART=='X')
				 {
				    write_command(clear_LCD);
					write_command(first_line_begin);
					write_string("User:");
					write_command(second_line_begin);
					write_string("Pass:");
					write_command(0x85);
					UART_TransmitDataString("Sign Up User Name\n");
					while(1)
					{
					   /* Sending data from UART To EEPROM address To Save The Name and Pass */
					   UART_ReciveChar(&UART);
					   if(count_S_1<=3 && UART!='X')
					   {
					     EEPROM_WriteByte(count_S_1,UART);
						 count_S_1++;
						 if(count_S_1==4)
						 {
						  UART_TransmitDataString("Sign Up User Pass\n");
						 }
					   }
					   else
					   {
					      EEPROM_WriteByte((count_S_2+4),UART);
						  count_S_2++;
					   }
					   /* Ending Storing Of Pass and Name of User In EEPROM */
					   if(count_S_2==4)
					   {
					     break;
					   }

					}
				 }
				 /* Giving Access To User To Login */
				 if(count_S_2==4)
				 {
				   User=1;
				   break;
				 }
			  }
		   }
		   
		   
		   
		}
	  }
	  if(UART=='#')
	  {
	     if(c1==0)
		 {
		    UART_TransmitDataString("Sign In Using Keybad\n");
			User=1;
			c1++;
		 }
		 

	  }
	  /**********************************************************************************************************************************************************************************/



	  /* Signing In Using Keybad */


	  KPD_getValue(&data); // Passing Variable Data to KPD func and store the data from KPD to (data)
	  if(data !=KPD_NOT_PRESSED)
	   {
		    
		    User=1;
			Admin=0;
		    if(counter<=3)
		    {
			    
			    write_char(data); // Printing Data To LCD
			    buffer[counter]=data; // Assign the name of User in empty array called (arr_1) 
			    counter++; // Increment The count to Assign The UART data to array indexs
		    }
		    else if(counter_1<=3)
		    {
			    
			    
			    write_command((0xc5) + (counter_1));
			    write_char(data); // Printing Data To LCD
			    buffer_1[counter_1]=data; // Assign the Pass of User in empty array called (arr_1)
			    counter_1++; // Increment The count to Assign The UART data to array indexs
				
			    
	        }
			
		    
		    
	    }
		/* Check The State Of Button */
		if(DIO_GetPinValue(DIO_PORTD,DIO_PIN2)==1)
		{

		    
			buffer[counter]='\0';
			buffer_1[counter_1]='\0';
			EEPROM_Compare(arr_N,arr_P); //Calling EEPROM fun that assigning the data from it addresses to two empty arrays (arr_N,arr_P)
			arr_N[4]='\0'; // ending array
			arr_P[4]='\0'; // ending array

		    /* Comparing The Pass and the Name in arr_N,arr_P */ 
			if((Compare_String(buffer,arr_N)==1 && Compare_String(buffer_1,arr_P)==1)) 
			{
			    counter=0;
			    counter_1=0;
			    counter_2=0;
				
				write_command(clear_LCD);
				write_command(first_line_begin);
				write_string("Welcome Home:)");
				UART_TransmitDataString("\nThe Door Opened\n");
				TMR1_SetCompareMatch(499); // Turning on servo motor
				_delay_ms(2000);
				TMR1_SetCompareMatch(100); // Return servo motor to its position
				UART_TransmitDataString("\nThe Door Closed\n");
				if(User==1)
				{
				   
				   write_command(clear_LCD);
				   write_command(first_line_begin);
				   write_string("*-L0O");
				   write_command(0x85);
				   write_string("#-L1O");
				   write_command((0x80) + 11);
				   write_string("0-L2O");
				   write_command(second_line_begin);
				   write_string("7-L0F");
				   write_command(0xc5);
				   write_string("8-L1F");
				   write_command((0xc0) + 11);
				   write_string("9-L2F");

				   while(1)
				   {
				      /* Getting the data from KPD to Choose Options */
				      KPD_getValue(&data);
					  if(data!=KPD_NOT_PRESSED)
					  {
					     switch(data)
					     {
						     case '*':
						     DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
							 UART_TransmitDataString("LED0 IS ON\n");
						     break;
						     case '#':
						     DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
							 UART_TransmitDataString("LED1 IS ON\n");
						     break;
						     case '0':
						     DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
							 UART_TransmitDataString("LED2 IS ON\n");
							 break;
							 case '7':
							 DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
							 UART_TransmitDataString("LED0 IS OFF\n");
							 break;
							 case '8':
							 DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
							 UART_TransmitDataString("LED1 IS OFF\n");
							 break;
							 case '9':
							 DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
							 UART_TransmitDataString("LED2 IS OFF\n");
							 break;
							 case 'D':
							 DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_HIGH);
							 UART_TransmitDataString("DIMMER IS ON\n");
							 break;

						     

					     }
						 /* To activate The Temp Sensor */
						 if(data=='C')
						 {
						    break;
						 }
					  }
					  _delay_ms(130);
				   }
				}
				
				_delay_ms(1000);
				UART_TransmitDataString("Temp Sensor Begin\n");
				write_command(clear_LCD);
				write_command(first_line_begin);
				write_string("Temp Sensor");
				flag=1;	// Activating Temp Sensor In Real-Time 	
			}
			

			/* Wrong Access to Home Condition */
			else
			{

				counter_2++;
				if(counter_2<3)
				{
					write_command(clear_LCD);
					write_command(first_line_begin);
					_delay_ms(50);
					write_string("Wrong access");
					write_command(second_line_begin);
					write_string("Try Again");
					UART_TransmitDataString("\nWrong access to home\n");
					counter=0;
					counter_1=0;
				}
				
			}
			
			
		}
		

		/* Deactivation to Sensors And Buttons */
		if(DIO_GetPinValue(DIO_PORTD,DIO_PIN6)==1)
		{
			write_command(clear_LCD);
			write_command(first_line_begin);
			write_string("User:");
			write_command(second_line_begin);
			write_string("Pass:");
			write_command(0x85);
			UART_TransmitDataString("\nTemp Sensor Stop");
			
			UART_TransmitDataString("\nLogin Again\n");
			counter=0; // Reset Counter to login again
			counter_1=0;
			flag=0; //stop Temp Sensor
			DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
			DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_LOW);
			// count_1=0;
			//count_2=0;
		}
		/* Activation Off Temp Sensor In Real-Time */
		if(flag==1)
		{
		   ADC_getDigitalValue(ADC_CHANNEL1,&ADC_Data); // Passing The ADC Channel Pin and Variable to assigning the data of temp sensor to it
		   analog = ((u32)ADC_Data*50)/1024;  // analog value of temp sensor
		   
		  if(DIO_GetPinValue(DIO_PORTB,DIO_PIN0)==0 && DIO_GetPinValue(DIO_PORTD,DIO_PIN6)==0)
		  {
			  write_command(second_line_begin);
			  _delay_ms(500);
			  UART_TransmitDataString("\nTemp Sensor readings\n");
			  UART_TransmitDataInt(analog); // Printing analog value To Mobile
			  UART_TransmitDataString("\n");
			  write_int(analog); // Printing analog Value To Mobile
			  if(analog<25)
			  {
			      /* Turning Air Conditioning OFF */
			      UART_TransmitDataString("Air Conditioning Stop\n");
				  DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
				  DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
				  DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
				  
			  }
			  else
			  {  

			     /* Turning Air Conditioning ON */
			     UART_TransmitDataString("Air Conditioning Start\n");
				 

				 DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
				 DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
				 DIO_SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
				  
			  }
		  }
		  
		  
		}
		
		
		
		
		_delay_ms(130);
		
	  }
	  
	  
	
	 
	  
	  
	  
    
	
}


/* Activating The ISR For Timer0 Normal Mode When Counter_2==3 */
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
    
	
	if(counter_2==3) //when user assigning wrong above two times
	{
	  
	  count++;
	  write_command(clear_LCD);
	  write_command(first_line_begin);
	  //write_string("Wait 3 Sec:)");
	  DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
	  if(count==TMR_OVF_NUMBER) // waiting 3 sec
	  {

	      /* Activating System Again */
		  TCNT0=TMR_PRELOAD_VALUE;
		  count=0;
		  counter=0;
		  counter_1=0;
		  counter_2=0;
		  DIO_SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		  write_command(clear_LCD);
		  write_command(first_line_begin);
		  write_string("User:");
		  write_command(second_line_begin);
		  write_string("Pass:");
		  write_command(0x85);
		  UART_TransmitDataString("\nTime Out\n");
		  UART_TransmitDataString("Login Again\n");
	  }
	}
	
	
}
	
