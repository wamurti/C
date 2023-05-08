#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"
#include "stm32f4xx.h" //Device Header för enhetsspecifika angivelser om hårdvaran

/*
Här definieras macron som användas i Led.cpp.
Genom att ge namn åt de olika pinsen osv som används blir koden i Led.cpp enklare att följa och arbeta i.
*/

//Definera vilken GPIO som skall vara ansvarig för LED-funktionen
#define LED_PORT GPIOB

//Definerar klocksignalen för porten
#define LED_PORT_CLOCK (1U<<1)

//Definera de olika pinsen för de olika LED-färgerna
#define LED_RED_PIN (1U<<14)// Sätter bit 14 till 1, utan att påverka andra bitar i registret.
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

//Definera mode bits för varje LED-färg
// Här förbereds general purpose output mode för respektive pin
#define LED_RED_MODE_BIT (1U<<28) // PB14
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//Definerar de olika LED-färgerna som finns mha Typedef enum som gör det möjligt att använda ord som siffror. T.ex. LedColor_Type RED == LedColor_Type 0
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

//Definerar/numrerar de olika lägena som LED kan befinna sig i
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;

// Definerar de attribut som LED består utav
// En klass som gör det möjligt att skapa ett LED objekt. 
class Led{

  private:
      LedColor_Type color;
      LedState_Type state;

  public:

      Led(LedColor_Type _color,LedState_Type _state);
      void setState(LedState_Type _state);
      LedState_Type getState() const;

};

#endif
