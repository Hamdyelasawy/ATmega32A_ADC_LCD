/*
 * ATmega32A_ADC.h
 *
 * Created: 5/31/2019 3:44:12 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_ADC_H_
#define ATMEGA32A_ADC_H_


	#include "ATmega32A_GPIO.h"
	#include "StandardTypes.h"
	#include "uc_Config.h"
	

	#define ADMUX	(*(vuint8 *)0x27)
	#define ADCSRA  (*(vuint8 *)0x26)
	#define ADCH	(*(vuint8 *)0x25)
	#define ADCL	(*(vuint8 *)0x24)
	
	void ADC_init(void);
	uint16 ADC_Read(uint8 channel);
#endif /* ATMEGA32A_ADC_H_ */