/*
 * Atmega32A_ADC.c
 *
 * Created: 5/31/2019 3:43:58 PM
 *  Author: Hamdy
 */ 

	#include "ATmega32A_ADC.h"
	
	
	void ADC_init(void)
	{
		ADMUX = (1<<6) ;
		ADCSRA =(1<<7) | (1<<1) | (1<<0);
	}
	uint16 ADC_Read(uint8 channel)
	{
		uint16 R = 0;
		ADMUX &= 0xE0;
		ADMUX |= channel;
		/* Start ADC Convertion */
		ADCSRA |= (1<<6);		
		/* Polling tell the end of adc conv */
		while((ADCSRA & 0x10) == 0);
		R = ADCL;
		R |= (ADCH << 8);
		/* Clear ADIF flag */
		ADCSRA |= 0x10;
		return R;
	}
