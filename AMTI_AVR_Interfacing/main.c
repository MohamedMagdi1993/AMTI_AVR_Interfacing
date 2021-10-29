/*
* Dio_Driver_24.c
*
* Created: 10/15/2021 7:44:05 PM
* Author : Mohamed Magdi
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "StringHandler.h"
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
	
	while (1)
	{
	SetBit(ADCSRA,ADSC);
	while (GetBit(ADCSRA,ADIF) ==0 ); 
	ADC_Data = ADCL ;
	ADC_Data |= (uint16) (ADCH<<8) ;
	
	LCD_Postion(1,1);
	Decimal2String( (ADC_Data>>8) ,ADC_Data_String);
	LCD_DataString(ADC_Data_String) ;
	Decimal2String((uint8) ADC_Data ,ADC_Data_String);
	LCD_DataString(ADC_Data_String) ;
	
	}
}


