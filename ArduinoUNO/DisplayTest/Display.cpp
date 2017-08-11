#include "Display.h"
#include <avr/io.h>
#include <util/delay.h>

void Display::command(uint8_t RS_val, uint8_t D4_val, uint8_t D5_val, uint8_t D6_val, uint8_t D7_val)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		// RS устанавливаем 0-у если идут команды, 1-у если идут данные
		if(RS_val == 0) {CPORT &= ~(1 << RS);}
		else if(RS_val == 1) {CPORT |= (1 << RS);}
		
		// E устанавливаем в 0, пока нет стробирующего импульса
		CPORT &= ~(1 << E);

		// выставляем на DB4-DB7 логические нули и единицы
		if(D4_val == 0) {DPORT &= ~(1 << D4);}
		else if(D4_val == 1) {DPORT |= (1 << D4);}
		if(D5_val == 0) {DPORT &= ~(1 << D5);}
		else if(D5_val == 1) {DPORT |= (1 << D5);}
		if(D6_val == 0) {DPORT &= ~(1 << D6);}
		else if(D6_val == 1) {DPORT |= (1 << D6);}
		if(D7_val == 0) {DPORT &= ~(1 << D7);}
		else if(D7_val == 1) {DPORT |= (1 << D7);}

		CPORT |= (1 << E);
		_delay_us(mks_strobe);
		CPORT &= ~(1 << E);
	}
}

void Display::init(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		//Инициализация портов на выход
		CDDR |= (1 << RS)|(1 << E);
		DDDR |= (1 << D7)|(1 << D6)|(1 << D5)|(1 << D4);
		_delay_ms(20); // при запуске рекомендуется выждать 20 мс
		
		//команда №6 (установка разрядности) D4-D7
		command(0,1,1,0,0); // RS=0, DB4=1, DB5=1, DB6=0, DB7=0
		_delay_us(mks_after_com);

		//команда №6 (установка разрядности 4-е бита) D4-D7
		command(0,0,1,0,0); // RS=0, DB4=0, DB5=1, DB6=0, DB7=0
		_delay_us(mks_after_com);
		command(0,0,1,0,0); // RS=0, DB4=0, DB5=1, DB6=0, DB7=0
		command(0,0,0,0,1); // RS=0, DB4=0, DB5=0, DB6=0, DB7=1
		_delay_us(mks_after_com);

		//команда №4 (выключение дисплея)
		command(0,0,0,0,0); // RS=0, DB4=0, DB5=0, DB6=0, DB7=0
		command(0,0,0,0,1); // RS=0, DB4=0, DB5=0, DB6=0, DB7=1
		_delay_us(mks_after_com);

		//команда №1 (сброс дисплея)
		command(0,0,0,0,0); // RS=0, DB4=0, DB5=0, DB6=0, DB7=0
		command(0,1,0,0,0); // RS=0, DB4=1, DB5=0, DB6=0, DB7=0
		_delay_us(mks_after_com); // ожидаем 40мкс, время на обработку команд (см. таблицу)

		//команда №3 (при записи курсор движется в право)
		command(0,0,0,0,0); // RS=0, DB4=0, DB5=0, DB6=0, DB7=0
		command(0,0,1,1,0); // RS=0, DB4=0, DB5=1, DB6=1, DB7=0
		_delay_us(mks_after_com);

		//команда №4 (включение дисплея)
		command(0,0,0,0,0); // RS=0, DB4=0, DB5=0, DB6=0, DB7=0
		command(0,0,0,1,1); // RS=0, DB4=0, DB5=0, DB6=1, DB7=1
		_delay_us(mks_after_com);
	}
}

void Display::clearScreen(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		command(0,0,0,0,0);
		command(0,1,0,0,0);
		_delay_us(mks_after_com);
	}
}

void Display::setCursor(uint8_t numberOfString, uint8_t position)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if(numberOfString == 0)
		{
			//Установить курсор в нулевую позицию 0-й строки
			command(0,0,0,0,1);
			command(0,0,0,0,0);
			_delay_us(mks_after_com);
			
			//Установить курсор в указанную позиию
			for(uint8_t i = 0; i < position; i++)
			{
				command(0,1,0,0,0);
				command(0,0,0,1,0);
				_delay_us(mks_after_com);
			}
		}
		
		else if(numberOfString == 1)
		{
			//Установить курсор в нулевую позицию 1-й строки
			command(0,0,1,0,1);
			command(0,0,0,0,1);
			_delay_us(mks_after_com);
			
			//Установить курсор в указанную позиию
			for(uint8_t i = 0; i < position; i++)
			{
				command(0,1,0,0,0);
				command(0,1,1,1,0);
				_delay_us(mks_after_com);
			}
		}
	}
}

void Display::sendByte(uint8_t data)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		uint8_t bit0 = (data & 0b00000001) >> 0;
		uint8_t bit1 = (data & 0b00000010) >> 1;
		uint8_t bit2 = (data & 0b00000100) >> 2;
		uint8_t bit3 = (data & 0b00001000) >> 3;
		uint8_t bit4 = (data & 0b00010000) >> 4;
		uint8_t bit5 = (data & 0b00100000) >> 5;
		uint8_t bit6 = (data & 0b01000000) >> 6;
		uint8_t bit7 = (data & 0b10000000) >> 7;

		command(1, bit4, bit5, bit6, bit7);
		command(1, bit0, bit1, bit2, bit3);
		_delay_us(mks_after_com);
	}
}

void Display::sendString(char *data)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		for(uint8_t i = 0; data[i] != '\0'; i++)
		{
			sendByte(*(data + i));
		}
	}
}

void Display::ledOn(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		PORTB &= ~(1 << 2);
		DDRB &= ~(1 << 2);
	}
}

void Display::ledOff(void)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		PORTB &= ~(1 << 2);
		DDRB |= (1 << 2);
	}
}
