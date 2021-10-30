/*
* Dio_Driver_24.c
*
* Created: 10/15/2021 7:44:05 PM
* Author : Mohamed Magdi
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "Bitwise.h"
int main(void)
{
	Dio_PortSetDirection(D,0xFF) ; // PORT D is output
	Dio_PortWrite(D,0x00); // Turn all Leds off 
	TCNT0 = 0x00 ;
	ClearBit(TCCR0,WGM00); ClearBit(TCCR0,WGM01) ; // NormalMode
	SetBit(TCCR0,CS00) ; ClearBit(TCCR0,CS01) ; SetBit(TCCR0,CS02) ;
	SetBit(TIMSK,TOIE0);
	sei();
	while (1)
	{
		_delay_ms(10);
	//	PORTD--;
	}
}

ISR(TIMER0_OVF_vect)
{
	PORTD++;
	 
}