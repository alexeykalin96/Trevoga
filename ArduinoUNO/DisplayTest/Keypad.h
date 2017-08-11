#ifndef Keypad_H
#define Keypad_H

#define RIGHT 0
#define UP 36
#define DOWN 82
#define LEFT 126
#define SELECT 185
#define NO 255

class Keypad
{
	private:
		volatile static uint8_t voltage_ADC;
		volatile uint8_t key;
	
	public:
		Keypad();
		void Init_ADC(void);
		void deInit_ADC(void);
		static void ADC_INTERRUPT(void);
		uint8_t getKey(void);
};

#endif