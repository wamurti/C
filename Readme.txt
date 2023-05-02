Det här projektet innehåller drivrutiner skrivna i c och c++ för STM32f411x plattformen och använder sig av UART som kommunikationsprotokoll för att skicka och ta emot data. 
För att kunna ta del av projektet behövs: STM32F411x utvecklingskort, STM32CubeIDE eller annan kompatibel IDE, STM32F411x HAL Bibliotek samt en UART kabel eller USB-to-UART konverterare.

Kom igång: 
1) Klona eller ladda ner källkoden som en zip fil och importera sedan projektet till din IDE och lägg till de nödvändiga HAL biblioteken. Man hittar enkelt dessa genom     att starta ett nytt projekt i stm32cubeIDE.
2) Inkludera uart_driver.h header filen i din kod. 
3) Initiera UART genom att anropa USART2_Init() som i sin tur ställer in korrekt baudrate, stop-bit osv. 


Följande funktioner finns definerade i UART drivrutinen: 

    int USART2_write()
    int USART2_read()

Example

The following example demonstrates how to use the UART driver to transmit and receive data:

c
#include "uart.h"

void USART2_Init(void){
//1.enable clock access to uart2
 RCC->APB1ENR  |=  0x20000;
//2.enable closk access to portA
 RCC->AHB1ENR   |=0x01;
//3.Enable pins for alternate fucntions, pa2, pa3

GPIOA->MODER &=~0x00F0;
GPIOA->MODER |= 0x00A0; /*Enable alt. function for PA2, PA3*/
//4.Configure type of alternate function

 GPIOA->AFR[0] &= ~0xFF00;
 GPIOA->AFR[0] |= 0x7700;

//Configure uart

USART2->BRR  =  0x0683;
USART2->CR1  =  0x000C; /*Enabled tx rx, 8-bit data*/
USART2->CR2  =  0x000;
USART2->CR3  =  0x000;
USART2->CR1  |=  0x2000; /*Enable uart */

}


License

This project is licensed under the MIT License
