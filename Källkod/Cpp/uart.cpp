#include "UART.h" //Läser in vår samlingsfil för headers och funktioner

void USART2_Init(void) { //Deklarerar en funktion för att initiera USART-protkokollet

// 1. Enablea klocktillgång för uart2

RCC->APB1ENR |= 0x20000; //Atkiverar UART2 genom att sätta bit 17 (USART2 clock enable) i APB1ENR till 1.

/* 2. Enablea klocktillgång för portA. 
(Krigutrustningens klocktillgång styrs av AHB1 klockaktiveringsregister
(RCC_AHB1ENR) och AHB2 klockaktiveringsregister)*/

RCC->AHB1ENR |= 0x01; //Atkiverar GPIOA genom att sätta bit 0 (GPIOAEN: IO port A clock enable) i AHB1ENR till 1. bit 1 = B, bit 2 = C...


// 3. Enablea pins relaterade till vald port, för alternativ funktion
GPIOA->MODER &= ~0x00F0; //Sätter bitarna 4-7 till 0 för att förbereda pins PA2 och PA3
  //0x00F0 är 1111 0000 i binär.  '&' jämför enligt "and-logiken" och '~' inverterar bitarna vilket i slutändan gör att operationen endast påverkar bitarna 4-7 och sätter dessa till 0. Bitarna 0-3 förblir oförändrade

GPIOA->MODER |= 0x00A0; //0x00A0 är 1010 0000 i binär. Sätter bitarna 5 och 7 till 1 enligt or "or-logiken" som i sin tur ställer in pinsen PA2 och PA3 till "Alternate function mode". Eftersom bitarna 0-3 är 0 och vi använder 'or' förblir dessa oförändrade.
/*00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode*/

// 4. Väljer typen av Alternate function. GPIOx_AFRL (for pin 0 to 7) and GPIOx_AFRH (for pin 8 to 15) 
GPIOA->AFR[0] &= ~0xFF00; //Rensar bitarna 8-15 för att förbereda pins PA2 och PA3
GPIOA->AFR[0] |= 0x7700; //Sätter bitarna 8-11 och 12-15 till formatet 0111 som innebär AF07 med USART funktion

/* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART

USART2->BRR = 0x0683; //Sätter standard baud-rate med hjälp av hexadecimalen 0x0683 (9600bps)
USART2->CR1 = 0x000C; //Sätter tx och rx till att arbeta i 8 bitars data. (8 bitars data, 1 stop bit, ingen paritet)
USART2->CR2 = 0x000; //Sätter samtliga CR2s bitar till 0 
USART2->CR3 = 0x000; //Sätter samtliga CR3s bitar till 0 
USART2->CR1 |= 0x2000; //Aktiverar USART genom att sätta bit 13 (USART ENABLE) till  1

}
// UART Write
int USART2_write(int ch){ //Deklarerar skrivfunktionen (Överföringen av data till terminalen)

  while(!(USART2->SR & 0x0080)){} //Kontrollerar statusregistrets bit 7 TXE (Transmit data register empty) att överföringen inte används och är tom så att den kan ta emot nästa byte
  USART2->DR = (ch & 0xFF); //Sätter överföringen av byten till dataregistret

  return ch;

}
// UART Read
int USART2_read(void){ //Deklarerar läsfunktionen (mottagning av information)

  while(!(USART2->SR & 0x0020)){} //Kontrollerar statusregistrets bit 5 RXNE(Read data register not empty) om det finns data att hämta
  return USART2->DR; //Läser ut datan
}
