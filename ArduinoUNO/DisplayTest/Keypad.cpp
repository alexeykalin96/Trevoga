#include "Keypad.h"
#include <avr/io.h>
#include <math.h>

volatile uint8_t Keypad::voltage_ADC = 255;

Keypad::Keypad()
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		voltage_ADC = 255;
		key = 255;
	}
}

void Keypad::Init_ADC(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		ADMUX = (0 << REFS1)|(1 << REFS0)|(1 << ADLAR)|(0 << MUX3)|(0 << MUX2)|(0 << MUX1)|(0 << MUX0);
		ADCSRA = (1 << ADEN)|(1 << ADSC)|(1<<ADIE)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);
	}	
}

void Keypad::deInit_ADC(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		ADCSRA &= ~((1 << ADEN)|(1<<ADIE));
	}
}

void Keypad::ADC_INTERRUPT(void)
{
	voltage_ADC = ADCH;
	ADCSRA |= (1 << ADSC);	
}

uint8_t Keypad::getKey(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if ((fabs(voltage_ADC - RIGHT)) <= 10) {key = RIGHT;}
		else if((fabs(voltage_ADC - UP)) <= 10) {key = UP;}
		else if((fabs(voltage_ADC - DOWN)) <= 10) {key = DOWN;}
		else if((fabs(voltage_ADC - LEFT)) <= 10) {key = LEFT;}
		else if((fabs(voltage_ADC - SELECT)) <= 10) {key = SELECT;}
		else {key = NO;}
		return key;
	}
}

