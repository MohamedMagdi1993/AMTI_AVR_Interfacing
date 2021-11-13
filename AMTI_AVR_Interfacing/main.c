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
#include "UART.h"
#include "PushButton.h"

int main(void)
{
	PushButton_Init();
	LCD_Init();
	UART_Init();
	uint8 UARTData = 0 ;
	ReturnValueType ret = NOK;
	while (1)
	{
		UART_SendChar('A');
		if (UART_Receive(&UARTData) == OK)
		{
			UART_SendChar(UARTData);
			LCD_Data(UARTData);
		}
	}
}