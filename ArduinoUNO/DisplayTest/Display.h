#ifndef Display_H
#define Display_H

#define CDDR DDRB
#define CPORT PORTB
#define RS  0 //PB0
#define E   1 //PB1

#define DDDR DDRD
#define DPORT PORTD
#define D4  4 //PD4
#define D5  5 //PD5
#define D6  6 //PD6
#define D7  7 //PD7

#define mks_after_com 4000
#define mks_strobe    5

class Display
{
	public:
		void command(uint8_t RS_val, uint8_t D4_val, uint8_t D5_val, uint8_t D6_val, uint8_t D7_val);	
		void init(void);
		void clearScreen(void);
		void setCursor(uint8_t numberOfString, uint8_t position);
		void sendByte(uint8_t data);
		void sendString(char *data);
		void ledOn(void);
		void ledOff(void);
};

#endif