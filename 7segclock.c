/*
 * rebootdigiclock.c
 *
 * Created: 31/10/2015 1:54:36 AM
 *  Author: Shubham Singh
 */ 

int i=0;
int counter=0;
int sec=0,min=0,hour=0;
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 8000000UL




int main(void)
{
	
	//set the ddrs
	DDRB=0b00111111;
	DDRD=0b01111111;
	PORTB=0xff;
	PORTD=0b01000000;
	//set DDRC/A for buttons and Rtc
	
	sei();
	//setup the timer
	TCCR1B =(1<<WGM12)|(1<<CS11)|(1<<CS10);   //setting 64 prescalar
	//setup the timer interrupt
	TIMSK =(1<<OCIE1A);
	OCR1A=100;

    while(1)
    {
		_delay_ms(500);
		 
       //set the button pressed condition.
    }
}
 //interrupt service routine for the timer interrupt
 ISR(TIMER1_COMPA_vect)
 {
	 
	 counter++;
	 switch(i)
	 {
		 case 0:
				PORTB=(1<<i);
			
			  
				
				if(counter>150)
				{
					sec++;
					
					
					counter=0;
					if(sec>59)
					{
						sec=0;
						//breakup(sec,min);
						min++;
						breakup(sec,min);
					}
					else
					{
						breakup(sec,min);
					}
				}
				else
				{
					
					breakup(sec,min);
				}
			     i++;
				_delay_ms(5);
		 break;
		 case 1:
				 PORTB=(1<<i);
				breakup(sec,min);
				i++;
				
				 _delay_ms(5);
		 break;
		 case 2:
				 PORTB=(1<<i);
				 breakup(sec,min);
				 i++;
				
				 _delay_ms(5);
		 break;
		 case 3:
				 PORTB=(1<<i);
				breakup(sec,min);
				
				 i=0;
				  
				 _delay_ms(5);
		 break;
	 }
	
 }
void display(int a,int b,int c,int d )
{
	switch(i)
	{
		case 0:
		sevenseg(b);
		break;
		case 1:
		sevenseg(a);
		break;
		case 2:
		sevenseg(d);
		break;
		case 3:
		sevenseg(c);
		break;
	}
	
}
void breakup(int s,int m)
{
	int a=s/10;
	int b=s%10;
	int c=m/10;
	int d=m%10;
	display(a,b,c,d);
	
}
void sevenseg(int t)
{
	
	switch(t)
	{
		case 0:
		PORTD=0b01000000;
		
		break;
		case 1:
		PORTD=0b01111001;
		
		break;
		case 2:
		PORTD=0b00100100;
		
		break;
		case 3:
		PORTD=0b00110000;
		
		break;
		case 4:
		PORTD=0b00011001;
		
		break;
		case 5:
		PORTD=0b00010010;
		
		break;
		case 6:
		PORTD=0b00000010;
		
		break;
		case 7:
		PORTD=0b01111000;
		
		break;
		case 8:
		PORTD=0b00000000;
		
		break;
		case 9:
		PORTD=0b00010000;
		
		break;
	}
	
}