// Primeira versao

//Obs.: Incompleto, ainda nao tem especificado como se lida com os timers e as piscadas do led

#include "event_driven.c"

#define LED_PIN 13
#define BUT_PIN 4
#define BUT_SLW 2

// Provavelmente a funcao esta montada da forma errada, falta esclarecer como deve funcionar a parte dos timers
void button_changed (int pin, int v) {
    
     if(pin == BUT_PIN) {
       
        t *= 2;
        tBtP = now;
     }
     else if(pin == BUT_SLW) {
       
        t /= 2;
        tBtS = now;
     }
}

void timer1_expired () {
  
      
}

void timer2_expired () {
  
      
} 

void init () {

      pinMode(LED_PIN, OUTPUT);
      button_listen(BUT_PIN);
      button_listen(BUT_SLW);
      timer_set(500);
}


/*
VERSAO ANTERIOR ANTES DAS MUDANCAS PARA A NOVA TAREFA, USO COMO BASE DO QUE TEM QUE SER MUDADO


int state = 1;
long tBtP, tBtS; // TIMERS VAO EM EVENT_DRIVEN!!!!!!
unsigned long t, old;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_SLW, INPUT);
  pinMode(BUT_PIN, INPUT);

  tBtP = -10000;
  tBtS = -20000;
  t = 1000;

  old = millis();  
  digitalWrite(LED_PIN, state);
}

void loop() {

  unsigned long now = millis();

  if (now >= old + t) {

    old = now;    
    state = !state;
    digitalWrite(LED_PIN, state);
  }

  if (digitalRead(BUT_PIN))  {    

    t *= 2;
    tBtP = now;    
  }

  if (digitalRead(BUT_SLW))  {  	

    t /= 2;
    tBtS = now;
  }

  if (abs(tBtP - tBtS) < 500)  {    

    while(1);  
  }
}
*/
