#include "led.h"

//Globala variabler som innehåller på/av status
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

Led led1(RED,ON); // Skapar ett objekt "led1" med status "på" 

int main(void){ //huvudfunktion konstruerar och hanterar LED-lamporna
  USART2_Init(); // Initierar och sätter upp USART2_Init

  Led led2(BLUE,ON); // Skapar ett objekt "led2" på stacken

  Led *led3 = new Led(YELLOW,ON); // Skapar ett objekt "led3" med allokeratr dynamisk minne på heap. 

  led1_state = led1.getState(); //Sätter state till ON mha getState()

  led1.setState(OFF); //Sätter led1s state till OFF
  delete led3; //För att undvika minnesläckage tas variabel med dynamiskt allokerat minne bort. 

  while(1){} //Loop som körs för evigt. 

}
