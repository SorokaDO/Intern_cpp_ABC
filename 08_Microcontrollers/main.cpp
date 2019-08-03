/*
 * GccApplication2.cpp
 *
 * Created: 02.08.2019 18:02:42
 * Author : Dima
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

void preset()
{
	DDRB=0xFF;
	PORTB=0x00;
}

int main(void)
{
    preset();
    while (1) 
    {
		PORTB=0xFF;
		_delay_ms(1000);
		PORTB=0x00;
		_delay_ms(1000);
    }
}

