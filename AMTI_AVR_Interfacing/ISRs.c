/*
 * ISRs.c
 *
 * Created: 10/28/2021 2:12:07 PM
 *  Author: Mohamed Magdi
 */ 

#include <avr/interrupt.h>
#include "STD_Types.h"
uint8 INT0_flag = 0 ;
ISR(INT0_vect)
{
	INT0_flag = 1 ;
}