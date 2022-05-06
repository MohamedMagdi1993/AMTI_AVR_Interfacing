/*
 * EEPROM.c
 *
 * Created: 11/20/2021 1:15:00 PM
 *  Author: Mohamed Magdi
 */ 
#include "Bitwise.h"
#include "STD_Types.h"
#include <avr/io.h>
void EEPROM_write(uint16 Address, uint8 Data)
{
	/* Wait for completion of previous write */
	while(GetBit(EECR,EEWE));
	/* Set up address and data registers */
	EEAR = Address;
	EEDR = Data;
	/* Write logical one to EEMWE */
	SetBit(EECR,EEMWE);
	/* Start eeprom write by setting EEWE */
	SetBit(EECR,EEWE);
}

void EEPROM_read(uint16 Address , uint8* Data)
{
	/* Wait for completion of previous write */
	while(GetBit(EECR,EEWE));
	/* Set up address register */
	EEAR = Address;
	/* Start eeprom read by writing EERE */
	SetBit(EECR,EERE);
	/* Return data from data register */
	*Data = EEDR ;
}
