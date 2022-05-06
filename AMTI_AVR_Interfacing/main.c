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
#include "EEPROM.h"

int main(void)
{
	uint8 ReadValue = 0x00 ;
	uint8 ReadValueString[3]={0};
	LCD_Init();
	EEPROM_write(0x00,'H');
	EEPROM_write(0x01,'E');
	EEPROM_write(0x02,'L');
	EEPROM_write(0x03,'L');
	EEPROM_write(0x04,'O');
	LCD_Postion(1,1);
	EEPROM_read(0x00,&ReadValue);
	_delay_ms(100);
	LCD_Data(ReadValue);
	EEPROM_read(0x01,&ReadValue);
	_delay_ms(100);
	LCD_Data(ReadValue);
	EEPROM_read(0x02,&ReadValue);
	_delay_ms(100);
	LCD_Data(ReadValue);
	EEPROM_read(0x03,&ReadValue);
	_delay_ms(100);
	LCD_Data(ReadValue);
	EEPROM_read(0x04,&ReadValue);
	_delay_ms(100);
	LCD_Data(ReadValue);
	while (1)
	{
		
	}
}
