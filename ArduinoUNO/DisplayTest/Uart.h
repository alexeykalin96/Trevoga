#ifndef Uart_H
#define Uart_H

#define BUFF_LENGTH 20

#define COM_NO 0
#define COM_SET_BUTTONS 1
#define COM_SET_SOUND 2

class Uart
{
	private:
		static volatile char rxBuff[BUFF_LENGTH];
		static volatile char txBuff[BUFF_LENGTH];
		static volatile uint8_t counterRxBuff;
		static volatile char currentByte;
		static bool volatile programmingMode;
		uint8_t volatile uartCommand;
		uint8_t buttonStatus;
		uint8_t soundStatus;
	
	public:
		void InitUart(uint16_t speed);
		void sendUartEn(void);
		void getchUartEn(void);
		static void readByte(void);
		uint8_t readRxCommand(void);
		volatile char* readRxData(void);
		void sendTxBuff(char *txBuff, uint8_t length);
		static bool getProgrammingMode(void);
		uint8_t readButtonStatus(uint8_t number);
		uint8_t readSoundStatus(void);
		void clearRxBuff(void);
};

#endif