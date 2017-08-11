#include "Uart.h"
#include <avr/io.h>

volatile char Uart::rxBuff[BUFF_LENGTH];
//volatile char Uart::txBuff[BUFF_LENGTH];
volatile uint8_t Uart::counterRxBuff = 0;
volatile char Uart::currentByte = 0;
volatile bool Uart::programmingMode = false;

void Uart::InitUart(uint16_t speed)
{
	// setting the baud rate
	UBRR0 = F_CPU/16/speed-1;
	// enabling TX & RX
	UCSR0A = (1 << UDRE0);
	UCSR0C =  (1 << UCSZ01)|(1 << UCSZ00); //Set frame: 8data, 1 stop
}

void Uart::sendUartEn(void)
{
	UCSR0B = (1 << TXEN0);
}


void Uart::getchUartEn(void)
{
	UCSR0B = (1 << RXCIE0)|(1 << RXEN0);
}


void Uart::readByte(void)
{
	currentByte = UDR0; //Считывание Uart
	
	//Признак начала посылки
	if(currentByte == '<')
	{
		counterRxBuff = 0;
		for(uint8_t i = 1; i < BUFF_LENGTH; i++)
		{
			rxBuff[i] = 0;
		}
	}
	
	//Заполнение буфера
	if(counterRxBuff < BUFF_LENGTH)
	{
		rxBuff[counterRxBuff] = currentByte;
		counterRxBuff++;
	}
	
	//Очистка буфера при переполнении
	else
	{
		for(uint8_t i = 0; i < BUFF_LENGTH; i++)
		{
			rxBuff[i] = 0;
		}
		counterRxBuff = 0;
	}
	
	if	   ((rxBuff[0] == '<') &&
			(rxBuff[1] == 'p') &&
			(rxBuff[2] == 'r') &&
			(rxBuff[3] == 'o') &&
			(rxBuff[4] == 'g') &&
			(rxBuff[5] == 'r') &&
			(rxBuff[6] == 'Y') &&
			(rxBuff[7] == '>'))
			{
				programmingMode = true;
			}
	
	else if((rxBuff[0] == '<') &&
			(rxBuff[1] == 'p') &&
			(rxBuff[2] == 'r') &&
			(rxBuff[3] == 'o') &&
			(rxBuff[4] == 'g') &&
			(rxBuff[5] == 'r') &&
			(rxBuff[6] == 'N') &&
			(rxBuff[7] == '>'))
			{
				programmingMode = false;
			}
}

uint8_t Uart::readRxCommand(void)
{			
	if((rxBuff[0] == '<') && (rxBuff[1] == '0') && (rxBuff[2] == '0') && (rxBuff[3] == '0') && (rxBuff[4] == '>'))
	{
		uartCommand = COM_NO;
	}
		
	else if((rxBuff[0] == '<') && (rxBuff[1] == '1') && (rxBuff[7] == '>'))
	{
		uartCommand = COM_SET_BUTTONS;
	}	
			
	else if((rxBuff[0] == '<') && (rxBuff[1] == '2') && (rxBuff[3] == '>'))
	{
		uartCommand = COM_SET_SOUND;
	}
	
	return uartCommand;	
}

volatile char* Uart::readRxData(void)
{
	return (rxBuff + 2);
}

void Uart::sendTxBuff(char *txBuff, uint8_t length)
{
	for(uint8_t i = 0; i < length; i++)
	{
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = txBuff[i];
	}
}

bool Uart::getProgrammingMode(void)
{
	return programmingMode;
}

uint8_t Uart::readButtonStatus(uint8_t number)
{
	uint8_t t;
	t = 0;
	switch(number)
	{
		case 0:
		t = 0;
		break;
		
		case 1:
		t = 3;
		break;
		
		case 2:
		t = 6;
		break;
		
		case 3:
		t = 9;
		break;
		
		case 4:
		t = 12;
		break;
	}
	
	if(eeprom_read_byte((uint8_t*)t) == eeprom_read_byte((uint8_t*)(t+1)))
	{
		buttonStatus = eeprom_read_byte((uint8_t*)t);
	}
	else if(eeprom_read_byte((uint8_t*)t) == eeprom_read_byte((uint8_t*)(t+2)))
	{
		buttonStatus = eeprom_read_byte((uint8_t*)t);
	}
	else if(eeprom_read_byte((uint8_t*)(t+1)) == eeprom_read_byte((uint8_t*)(t+2)))
	{
		buttonStatus = eeprom_read_byte((uint8_t*)(t+1));
	}
	
	return buttonStatus;
}

uint8_t Uart::readSoundStatus(void)
{
	if(eeprom_read_byte((uint8_t*)20) == eeprom_read_byte((uint8_t*)21))
	{
		soundStatus = eeprom_read_byte((uint8_t*)20);
	}
	else if(eeprom_read_byte((uint8_t*)20) == eeprom_read_byte((uint8_t*)22))
	{
		soundStatus = eeprom_read_byte((uint8_t*)20);
	}
	else if(eeprom_read_byte((uint8_t*)21) == eeprom_read_byte((uint8_t*)22))
	{
		soundStatus = eeprom_read_byte((uint8_t*)21);
	}
}

void Uart::clearRxBuff(void)
{
	for(uint8_t i = 0; i < BUFF_LENGTH; i++)
	{
		rxBuff[i] = 0;
	}
	uartCommand = COM_NO;
}
