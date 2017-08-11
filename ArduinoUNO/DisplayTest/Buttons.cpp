#include "Buttons.h"
#include <avr/io.h>

bool Buttons::pressedButton = false;

Buttons::Buttons()
{
	pressedButton = false;
}

void Buttons::initPorts()
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		BUTTONS_PORT |= (1 << BUTTON_IN_1)|(1 << BUTTON_IN_2)|(1 << BUTTON_IN_3)|(1 << BUTTON_IN_4)|(1 << BUTTON_IN_5);
		BUTTONS_DDR &= ~((1 << BUTTON_IN_1)|(1 << BUTTON_IN_2)|(1 << BUTTON_IN_3)|(1 << BUTTON_IN_4)|(1 << BUTTON_IN_5));
	}
}

void Buttons::init_Timer0(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		TCCR0B |= (1 << CS02)|(0 << CS01)|(1 << CS00);
		TIMSK0 |= (1 << TOIE0);
	}
}

void Buttons::deInit_Timer0(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		TIMSK0 &= ~(1 << TOIE0);
	}
}

void Buttons::pressedButtonAnalysis(uint8_t *buttons)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		for(uint8_t i = 0; i < 5; i++)
		{
			if((*(buttons + i) == 1) && ((BUTTONS_PIN & (1 << (i + 1))) == 0))
			{
				pressedButton = true;
			}
		}
	}
}

bool Buttons::getPressedButton(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		return pressedButton;
	}
}

void Buttons::clearPressedButton(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		pressedButton = false;
	}
}

