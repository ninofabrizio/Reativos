// Segunda versao

#define ms 10000

//Timer
// Teste: supostamente posso usar estas variaveis como timers que possa resetar quando queira
extern volatile unsigned long timer0_overflow_count;

/*
unsigned long t1;
*/

// Pin
int pin;

// Pin passado gera notificacoes
void button_listen (int pin) {
  
    //...
}
  
// Timer expira após ms milisegundos
void timer_set (int ms) {
     
    timer0_overflow_count = 0;
}
    
void button_changed (int pin, int v);
void timer_expired (void);
    
// Programa principal  
    
void setup () {
      
    //timer0_overflow_count = millis();
    
    init();
}
      
void loop () {
  
    // Detectando botao pressionado
    if(digitalRead(BUT_PIN))
      button_changed();
    
    // Vendo se timer deve expirar
    if(timer0_overflow_count >= ms) {
    
      timer_set();
      timer_expired();
    }
}
