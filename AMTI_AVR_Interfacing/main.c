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
#include "SPI.h"

extern uint8 SPI_Slave_DataReceived; 
extern uint8 SPI_Slave_DataSend;
int main(void)
{
	
	LCD_Init();
	SPI_Init();
	
	uint8 SPI_SendByte = 0x55 ;
	uint8 SPI_ReceivedByte = 0 ;
	uint8 HexString[3] = {0};
	ReturnValueType ret = NOK;
	sei();
	while (1)
	{
		LCD_Postion(1,1);
		#if (SPIMODE == MASTER)
		SPI_SingleSendReceive(SPI_SendByte,&SPI_ReceivedByte);
		U8HEX2String(SPI_ReceivedByte,HexString);
		#endif
		
		#if (SPIMODE == SLAVE)
		U8HEX2String(SPI_Slave_DataReceived,HexString);
		
		#endif
		LCD_DataString(HexString);
		_delay_ms(500);
	}
}
