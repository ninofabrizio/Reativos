// Primeira versao


//Timers
unsigned long t1;
unsigned long t2;

// Pin
int pin;

// Pin passado gera notificacoes
void button_listen (int pin) {
  
  //...
}

// Timer expira após ms milisegundos
void timer_set (int ms) {
     
    if(t1 >= ms)
        t1 = 0; // Provisorio, nao deve 'resetar' a contagem....
}
    
void button_changed (int pin, int v);
void timer_expired (void);
    
// Programa principal  
    
void setup () {
      
    t1 = millis();
    t2 = millis();
    
    init();
}
      
void loop () {
        //...
    button_changed();
        //...
    timer_expired();
}
