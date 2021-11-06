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
#include "LCD.h"
#include "StringHandler.h"
volatile uint16 Period = 0;
volatile uint8 MeasurmentCount = 0 ;

int main(void)
{
	LCD_Init();
	Dio_PinSetDirection(D,6,PinInput);
	Dio_PinPullupState(D,6,Active);
	 uint8 DataString[6] = {0} ;
	 ClearBit(TCCR1A,WGM10);
	 ClearBit(TCCR1A,WGM11);
	 ClearBit(TCCR1B,WGM12);
	 ClearBit(TCCR1B,WGM13);
	 	 
	 SetBit(TCCR1B,CS10);
	 ClearBit(TCCR1B,CS11);
	 SetBit(TCCR1B,CS12);
	 
	 SetBit(TCCR1B,ICES1);
	 SetBit(TIMSK,TICIE1);
	
	sei();
	while (1)
	{
			if (MeasurmentCount %2 == 0)
			{
				U16Decimal2String(Period,DataString);
				LCD_Postion(1,1);
				LCD_DataString(DataString);
			}
	}
}
ISR(TIMER1_CAPT_vect)
{
	if (MeasurmentCount%2 == 0)
	{
		
		Period = ICR1;
	}
	else
	{
		Period = ICR1 - Period;
		//TCNT1 = 0 ;
	}
	MeasurmentCount++;
}