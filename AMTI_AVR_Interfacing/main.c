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
#include "LCD.h"
#include "StringHandler.h"
volatile uint8 ADC_Flag = 0;
int main(void)
{
	
	uint16 ADC_Data = 0 ;
	uint8 ADC_Data_String[4] = {0} ;
	LCD_Init();
	DDRA &=~ (1<<PA1) ; // 1 
	ADCSRA |= (1<<ADEN) ; // 2 
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
	SetBit(ADMUX,REFS0) ;
	ClearBit(ADMUX,REFS1);
	SetBit(ADMUX,MUX0);
	ADMUX &= ~ (1<<MUX1) & ~ (1<<MUX2) & ~ (1<<MUX3) & ~ (1<<MUX4);
	ADCSRA |= (1<<ADIE) ;
	sei();
	SetBit(ADCSRA,ADSC);
	while (1)
	{
	
	if (ADC_Flag == 1)
	{
		ADC_Flag = 0 ;
	ADC_Data = ADCL ;
	ADC_Data |= (uint16) (ADCH<<8) ;
	
	LCD_Postion(1,1);
	HEX2String( (ADC_Data>>8) ,ADC_Data_String);
	LCD_DataString(ADC_Data_String) ;
	HEX2String((uint8) ADC_Data ,ADC_Data_String);
	LCD_DataString(ADC_Data_String) ;
	SetBit(ADCSRA,ADSC);
	} 
		
	}
}

ISR(ADC_vect)
{
	ADC_Flag = 1 ;
	
}
