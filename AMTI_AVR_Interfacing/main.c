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
#include "STD_Types.h"
#include "Bitwise.h"
extern volatile uint8 INT0_flag ; 
int main(void)
{
	MCUCR |= (1<<ISC00) | (1<<ISC01) ;
	DDRD &=~ (1<<PD2); // Clearbit(DDRD,PD2) 
	DDRD |= (1<<PD3); // Set LED as output
	GICR |= (1<<INT0) ;			// interrupt INT0 ,INT1 INT2 -> Enable For INT0
	sei();   // Enable I bit
	while (1)
	{
		if (INT0_flag == 1 )
		{
			INT0_flag = 0 ; 
			ToggleBit(PORTD,PD3);
			_delay_ms(500) ;
			
		}
	}
}

