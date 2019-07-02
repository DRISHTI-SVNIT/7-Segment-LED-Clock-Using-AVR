
#define F_CPU 8000000UL

#include <avr/io.h>
#include "usart.h"
#include "i2c.h"
#include <util/delay.h>

#define rtc_readmode 209
#define rtc_writemode 208
#define control 0x07
#define ram_id 0x00

uint8_t hh,mm,ss=55;

/*void rtc_initiate()
{
	initiate_i2c();
	
	start_i2c(rtc_writemode);
	//write_i2c(control);
	//write_i2c(0x00);
	
	stop_i2c();
}*/

void rtc_set_time(uint8_t hh,uint8_t mm,uint8_t ss)
{
	
	initiate_i2c();
	start_i2c(rtc_writemode);
	
	write_i2c(ram_id);
	
	
	write_i2c(ss);
	write_i2c(mm);
	write_i2c(hh);
	stop_i2c();
}

void rtc_get_time()
{
	
	start_i2c(rtc_writemode);
	write_i2c(ram_id);
	stop_i2c();
	
	start_i2c(rtc_readmode);
	ss=read_ack();
	mm=read_ack();
	hh=read_ack();
	stop_i2c();
}

int main()
{
	u_initiate();
	
	rtc_set_time(0x01,0x59,0x00);//0:0:0 24 hr format
	DDRA=0xFF;
	   PORTA=0xFF;
		while(1)
		{
			rtc_get_time();
			
			u_transmit((unsigned char)ss);
			u_transmit((unsigned char)mm);
			u_transmit((unsigned char)hh);
			/*if(ss0x15)
			{
				PORTA=0x00;
				u_transmit('a');
				u_transmit('b');
				u_transmit('c');
				u_transmit('d');
			}
			else
			PORTA=0xFF;*/
			
			
		}
 		
	
}