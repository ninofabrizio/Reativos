// Terceira versao

#include "event_driven.c"

#define LED_PIN 13
#define BUT_PIN 2

void button_changed (int pin, int v) {
    
     if(pin == BUT_PIN)
       digitalWrite(LED_PIN, v);
}

void init () {

      pinMode(LED_PIN, OUTPUT);
      button_listen(BUT_PIN);
}
