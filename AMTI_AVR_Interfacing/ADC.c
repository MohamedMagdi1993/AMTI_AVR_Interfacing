/*
* ADC.c
*
* Created: 10/28/2021 3:25:17 PM
*  Author: Mohamed Magdi
*/
#include "ADC.h"
void Adc_Init(void)
{
	ADCSRA |= (1<<ADEN) ;
	SetBit(ADMUX,REFS0) ;
	ClearBit(ADMUX,REFS1);
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}

void Adc_ChannelSelect(uint8 ADC_Channel)
{
	Dio_PinSetDirection(A,ADC_Channel,PinInput);
	ADMUX= (ADMUX & ~0x1F) | (ADC_Channel & 0x1F) ;
}
void Adc_ReadChannel(uint8 ADC_Channel , uint16* Adc_Data)
{
	ADCSRA |= (1<<ADSC) ;
	while (GetBit(ADCSRA,ADIF) == 0);
	*Adc_Data = ADCL ;
	*Adc_Data |= (uint16) (ADCH<<8) ;
}