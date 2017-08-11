#ifndef BUTTONS_H
#define BUTTONS_H

#define BUTTONS_DDR DDRC
#define BUTTONS_PORT PORTC
#define BUTTONS_PIN PINC
#define BUTTON_IN_1 1
#define BUTTON_IN_2 2
#define BUTTON_IN_3 3
#define BUTTON_IN_4 4
#define BUTTON_IN_5 5

class Buttons
{
	private:
		static bool pressedButton;
	
	public:
		Buttons();
		void initPorts(void);
		void init_Timer0(void);
		void deInit_Timer0(void);
		static void pressedButtonAnalysis(uint8_t *buttons);
		bool getPressedButton(void);
		void clearPressedButton(void);
		
};

#endif