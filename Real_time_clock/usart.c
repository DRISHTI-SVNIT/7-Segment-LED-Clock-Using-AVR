#define F_CPU 8000000UL
#define baud 9600
#define  baudrate 51

#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"


void u_initiate()
{
	UBRR0H=(unsigned char)(baudrate>>8);
	UBRR0L=(unsigned char)baudrate;
	UCSR0B=(1<<RXEN | 1<<TXEN); //enable tx and rx
	UCSR0C=(1<<UCSZ1 | 1<<UCSZ0); //8bit
}
void u_transmit(unsigned char data)
{
	while(!(UCSR0A & 1<<UDRE));
	
	UDR0=data;
}
unsigned char  u_recieve()
{
	while(!(UCSR0A & 1<<UDRE));
	while(!(UCSR0A & 1<<RXC));
	return UDR0;
}