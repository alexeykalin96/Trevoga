#ifndef Sound_H
#define Sound_H

class Sound
{
	protected:
		static volatile uint8_t point;
		static volatile uint16_t timer;
		static volatile uint8_t counter;
	
	public:
		Sound();
		void soundOn(void);
		void soundOff(void);
		virtual void PWM_Generator(void);
		
};

class SoundOne : public Sound
{
	public:
		void PWM_Generator(void);
};

class SoundTwo : public Sound
{
	public:
		void PWM_Generator(void);
};

class SoundThree : public Sound
{
	public:
		void PWM_Generator(void);
};

#endif