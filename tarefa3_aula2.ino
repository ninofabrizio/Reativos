// Segunda versao

#include "event_driven.c"

#define LED_PIN 13
#define BUT_PIN 2

void button_changed (int pin, int v) {
    
    if(pin == 13) // pin é do led?
      digitalWrite(pin, v);
}

void timer_expired() {
  
    printf("Tempo expirado!\n");
}

void init () {

    button_listen(BUT_PIN);
}
