/*
 * DisplayTest.cpp
 *
 * Created: 12.07.2017 10:53:58
 *  Author: user
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/atomic.h>
#include <stdlib.h>
#include <avr/eeprom.h>
#include "Display.h"
#include "Display.cpp"
#include "Keypad.h"
#include "Keypad.cpp"
#include "Sound.h"
#include "Sound.cpp"
#include "Buttons.h"
#include "Buttons.cpp"
#include "Uart.h"
#include "Uart.cpp"

#define MENU_HOME 0
#define MENU_BUTTONS 1
#define MENU_SOUND_TEST 2

#define CURSOR_BUTTONS 3
#define CURSOR_SOUND_TEST 4
#define CURSOR_SOUND_OFF 5
#define CURSOR_SOUND_ON 6

//Глобальные переменные
uint8_t currentKey;
bool currentLed;
uint8_t statusOfButtons[5];
uint8_t currentMenu;
uint8_t currentCursor;
uint8_t currentCommand;

//Объявление объектов
Sound sound, *signal[3], *currentSignal;
SoundOne one;
SoundTwo two;
SoundThree three;

int main(void)
{
	_delay_ms(1000);
	
	//Объявление объектов
	Display lcd;
	Keypad keypad;
	Buttons buttons;
	Uart uart;
	
	//Создание массива указателей на объекты
	signal[0] = &sound;
	signal[1] = &one;
	signal[2] = &two;
	signal[3] = &three;
	
	//Инициализация
	lcd.init();
	lcd.ledOff();
	buttons.initPorts();
	uart.InitUart(9600);
	uart.getchUartEn();
	
	bool currentMode = true;
	
    while(1)
    {
		if(uart.getProgrammingMode() == false)
		{
			if(currentMode == true)
			{
				cli();
				//Инициализация
				keypad.Init_ADC();
				buttons.init_Timer0();
				
				//Начальное меню
				lcd.clearScreen();
				lcd.setCursor(0,0);
				lcd.sendString(">Buttons");
				lcd.setCursor(1,0);
				lcd.sendString(" Sound test");
				
				//Начальные параметры
				currentKey = NO; //Состояние клавиатуры
				currentLed = false; //Состояние подсветки
				//Активные кнопки
				statusOfButtons[0] = uart.readButtonStatus(0);
				statusOfButtons[1] = uart.readButtonStatus(1);
				statusOfButtons[2] = uart.readButtonStatus(2);
				statusOfButtons[3] = uart.readButtonStatus(3);
				statusOfButtons[4] = uart.readButtonStatus(4);
				currentMenu = MENU_HOME; //Положение меню
				currentCursor = CURSOR_BUTTONS; //Положение курсора
				currentSignal = signal[uart.readSoundStatus()]; //Сигнал
				
				uart.sendUartEn();
				uart.sendTxBuff("ProgrOff\n", 10);
				uart.getchUartEn();
				currentMode = false;
				sei();
			}
		//==Опрос клавиатуры=============================================
			if(currentKey != keypad.getKey())
			{
			currentKey = keypad.getKey();
			switch(currentKey)
			{		
				case UP:
				if(currentMenu == MENU_HOME)
				{
					lcd.clearScreen();
					lcd.setCursor(0,0);
					lcd.sendString(">Buttons");
					lcd.setCursor(1,0);
					lcd.sendString(" Sound test");
					currentCursor = CURSOR_BUTTONS;
				}
				else if(currentMenu == MENU_SOUND_TEST)
				{
					lcd.clearScreen();
					lcd.setCursor(0,0);
					lcd.sendString(">Sound Off");
					lcd.setCursor(1,0);
					lcd.sendString(" Sound On");
					sound.soundOff();
					currentCursor = CURSOR_SOUND_OFF;
				}
				break;	
		
				case DOWN:
				if(currentMenu == MENU_HOME)
				{
					lcd.clearScreen();
					lcd.setCursor(0,0);
					lcd.sendString(" Buttons");
					lcd.setCursor(1,0);
					lcd.sendString(">Sound test");
					currentCursor = CURSOR_SOUND_TEST;
				}
				else if(currentMenu == MENU_SOUND_TEST)
				{
					lcd.clearScreen();
					lcd.setCursor(0,0);
					lcd.sendString(" Sound Off");
					lcd.setCursor(1,0);
					lcd.sendString(">Sound On");
					sound.soundOn();
					currentCursor = CURSOR_SOUND_ON;
				}
				break;	
				
				case LEFT:
				lcd.clearScreen();
				lcd.setCursor(0,0);
				lcd.sendString(">Buttons");
				lcd.setCursor(1,0);
				lcd.sendString(" Sound test");
				currentCursor = CURSOR_BUTTONS;
				currentMenu = MENU_HOME;
				sound.soundOff();
				break;
				
				case RIGHT:
				if(currentCursor == CURSOR_BUTTONS)
				{
					currentMenu = MENU_BUTTONS;
					lcd.clearScreen();
					lcd.setCursor(0,0);
					lcd.sendString("Enabled:");
					lcd.setCursor(1,0);
					for (uint8_t i = 0; i < 5; i++)
					{
						if(statusOfButtons[i] == 1)
						{
							char t[1];
							itoa((i+1),t,10);
							lcd.sendString(t);
							lcd.sendString(" ");
						}
					}
				}
				else if(currentCursor == CURSOR_SOUND_TEST)
				{
					currentMenu = MENU_SOUND_TEST;
					lcd.clearScreen();
					lcd.setCursor(0,0);
					lcd.sendString(">Sound Off");
					lcd.setCursor(1,0);
					lcd.sendString(" Sound On");
				}
				break;
				
				case SELECT:
				if(currentLed == true)
				{
					lcd.ledOff();	
					currentLed = false;
				}
				else if(currentLed == false)
				{
					lcd.ledOn();
					currentLed = true;
				}
				break;								
				
				/*default:
				lcd.clearScreen();
				lcd.setCursor(0,0);
				lcd.sendString("Press any button");*/							
			}
		}
		//=================================================================
		
		//==Опрос кнопок===================================================
			if(buttons.getPressedButton() == true)
			{
				lcd.clearScreen();
				lcd.setCursor(0,0);
				lcd.ledOn();
				lcd.sendString("    TREVOGA");
				sound.soundOn();
				while(1);
			}
		//=================================================================
		}
	
		if(uart.getProgrammingMode() == true)
		{
			if(currentMode == false)
			{
				cli();
				keypad.deInit_ADC();
				buttons.deInit_Timer0();
				lcd.ledOn();
				lcd.clearScreen();
				lcd.setCursor(0,0);
				lcd.sendString("Programming...");
				uart.sendUartEn();
				uart.sendTxBuff("ProgrOn\n", 9);
				uart.getchUartEn();
				currentMode = true;
				uart.clearRxBuff();
				sei();
			}
			
			if(uart.readRxCommand() != currentCommand)
			{
				currentCommand = uart.readRxCommand();
				switch(currentCommand)
				{
					case COM_NO:
					/*uart.sendUartEn();
					uart.sendTxBuff("RESET\n", 7);
					uart.getchUartEn();*/
					break;
					
					case COM_SET_BUTTONS:
					uint8_t t;
					t = 0;
					for(uint8_t j = 0; j < 5; j++)
					{
						for(uint8_t i = t; i < t+3; i++)
						{
							eeprom_write_byte((uint8_t*)i, *(uart.readRxData() + j) - 0x30);
						}
						t += 3;
					}
					uart.sendUartEn();
					uart.sendTxBuff("ButSet\n", 8);
					uart.clearRxBuff();
					uart.getchUartEn();
					break;
					
					case COM_SET_SOUND:
					for(uint8_t i = 20; i < 23; i++)
					{
						eeprom_write_byte((uint8_t*)i, *(uart.readRxData()) - 0x30);
					}
					uart.sendUartEn();
					uart.sendTxBuff("SoundSet\n", 10);
					uart.clearRxBuff();
					uart.getchUartEn();
					break;
				}
			}
		}
    }
}

ISR(ADC_vect, ISR_BLOCK)
{
	Keypad::ADC_INTERRUPT();
}

ISR(TIMER0_OVF_vect,ISR_BLOCK)
{
	Buttons::pressedButtonAnalysis(statusOfButtons);
}

ISR(TIMER1_OVF_vect, ISR_BLOCK)
{
	currentSignal -> PWM_Generator();
}

ISR(USART_RX_vect, ISR_BLOCK)
{
	Uart::readByte();
}