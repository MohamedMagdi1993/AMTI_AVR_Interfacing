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
#include "LED.h"



int main(void)
{
	 Dio_PinSetDirection(C,3,PinOutput);
	 Dio_PinSetDirection(C,4,PinOutput);
	 Dio_PinSetDirection(D,4,PinOutput);
	 
	 Dio_PinWrite(C,3,PinHigh);
	 Dio_PinWrite(C,4,PinLow);
	 
	 SetBit(TCCR1A,WGM10);
	 ClearBit(TCCR1A,WGM11);
	 SetBit(TCCR1B,WGM12);
	 ClearBit(TCCR1B,WGM13);
	 
	 ClearBit(TCCR1A,COM1B0);
	 SetBit(TCCR1A,COM1B1) ;
	 OCR1BH = 0 ;
	 OCR1BL = 128 ;
	 
	 SetBit(TCCR1B,CS10);
	 ClearBit(TCCR1B,CS11);
	 SetBit(TCCR1B,CS12);
	 
	sei();
	while (1)
	{
	_delay_ms(500);
		
	}
}

// ISR(TIMER1_COMPA_vect)
// {
// 	ToggleBit(PORTC,7) ;
// }