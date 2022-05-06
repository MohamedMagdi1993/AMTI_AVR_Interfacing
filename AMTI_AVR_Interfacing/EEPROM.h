/*
 * EEPROM.h
 *
 * Created: 11/20/2021 1:14:42 PM
 *  Author: Mohamed Magdi
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(uint16 Address, uint8 Data);
void EEPROM_read(uint16 Address , uint8* Data);

#endif /* EEPROM_H_ */