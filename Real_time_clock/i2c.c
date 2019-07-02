#ifndef  F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include "i2c.h"
#define scl_freq 50000				
						
				

void initiate_i2c()
{
	TWBR=72;
}

void start_i2c(uint8_t address)
{
	x:
	TWCR=0x00;									//control register should be set to 0x00 
	
	TWCR=(1<<TWINT | 1<<TWSTA | 1<<TWEN);		 //interrupt flag cleared, start condition bit, twi interface on
	
	while( !(TWCR & (1<<TWINT)) );				//TWINT flag should be cleared/ set to 1
	
	if((TWSR & 0xF8)!=0x08)
	goto x;
	
	//y:
	TWDR=address;									//slave's address
	
	TWCR=(1<<TWINT | 1<<TWEN);					//* clear TWEN~(enable bit)
	
	while( !(TWCR & (1<<TWINT)) );				//again TWINT should be cleared/set to 1
	
	//if((TWSR & 0xF8)!=0x18)				//to acknowledge that SLA_W has been loaded
	//goto y;
	
}

void write_i2c(uint8_t data)
{
	//z:
	TWDR=data;									//load up data to be transmitted 
	
	TWCR = (1<<TWINT |1<<TWEN);					//clear interrupt flag, enable bit
	
	while( !(TWCR & (1<<TWINT)) );				//TWINT flag should be cleared/ set to 1
	
	//if((TWSR & 0xF8)!=0x18)				// checking for ack
	//goto z;									
}

uint8_t read_ack()								//start transmission with ack
{
	TWCR=(1<<TWINT | 1<<TWEN | 1<<TWEA);
	while( !(TWCR & (1<<TWINT)) );	
	return TWDR;
}

uint8_t read_nack()								//start transmission without ack
{
	TWCR=(1<<TWINT | 1<<TWEN);
	while( !(TWCR & (1<<TWINT)) );
	return TWDR;
}

void stop_i2c()
{
	TWCR=(1<<TWINT | 1<<TWEN | 1<<TWSTO);		
}

/*uint8_t transmit(uint8_t address, uint8_t* data, uint8_t length)
{
	start_i2c(address | write);
	for(int i=0;i<length;i++)
	{
		if(write_i2c(data[i]))
		return 1;
	}
	stop_i2c();
	return 0;
}
uint8_t recieve(uint8_t address, uint8_t length)
{
	start_i2c(address | read);
	
}*/