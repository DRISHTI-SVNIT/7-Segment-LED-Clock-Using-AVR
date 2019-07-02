#ifndef i2c
#define i2c
#define write 0x00
#define read 0x01
#include <util/twi.h>

void initiate_i2c();
void start_i2c(uint8_t address);
void stop_i2c();
uint8_t read_ack();
uint8_t read_nack();
void write_i2c(uint8_t data);

#endif