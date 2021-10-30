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
#include "ADC.h"
volatile uint8 ADC_Flag = 0;
int main(void)
{
	
	uint16 ADC_Data = 0 ;
	uint8 ADC_Data_String[4] = {0} ;
	LCD_Init();
	Adc_Init();
	Adc_ChannelInit(ADC1) ;
	
	while (1)
	{
	
	
	Adc_ReadChannel(ADC0,&ADC_Data) ;
	LCD_Postion(1,1);
	Decimal2String( (ADC_Data>>8) ,ADC_Data_String);
	LCD_DataString(ADC_Data_String) ;
	Decimal2String((uint8) ADC_Data ,ADC_Data_String);
	LCD_DataString(ADC_Data_String) ;
	} 
		
	
}

