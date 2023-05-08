#include "LED.h" //Inkluderar header filen för att även denna fil skall känna till de olika LED-beteckningarna och funktioner

//Konstruktorn för LED-lamporna
Led::Led(LedColor_Type _color, LedState_Type _state)
{

  this->color = _color;
  this->state = _state;

  //Enablea klockan för LED-porten (GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK; // Sätter bit 1 i AHB1ENR till 1

  //Konfigurera LED-pinsen baserad på deras färg och status
  switch(_color){

    case RED: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT; // Sätter bit 28 i GPIOB MODE-registret till 1 som ställer PB14 till general purpose output mode.
      if(this->state == ON){  // kontrollerar om statusen/state är på. 
        //Stänga på LED
        LED_PORT->ODR |= LED_RED_PIN; //aktiverar output till GPIOB PB14 genom att sätta bit 14 till på eller "1" 
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_RED_PIN; // Stänger output till PB14
      }
      break;

      case YELLOW: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}
// En funktion som ändrar statusen på LED-objekt, utan att behöva skapa nytt objekt.
void Led::setState(LedState_Type _state){

  //Sätta statusen av LED:n
  this->state = _state;

  //Kolla färgen på LED för att veta att korrekt LED manipuleras
  switch(this->color){

      //om LED Röd
    case RED:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  //Kontrollera färgen av den LED som efterfrågas, printa sedan statusen. Eftersom alla fall har samma funktion behövs inte specifika instruktioner. 
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             //Returnerar LED-lampans status av vald färg
             return this->state;
}
