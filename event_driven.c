// Terceira versao
// Obs.: Daonde vem o ms? Da tarefa 2??
//#define ms 10000

// Timers
// Teste: supostamente posso usar estas variaveis como timers que possa resetar quando queira
extern volatile unsigned long timer0_overflow_count;
extern volatile unsigned long timer1_overflow_count;

/*
unsigned long t1;
unsigned long t2;
*/

// Pin do botao
int bPin;

// Pin passado gera notificacoes
void button_listen (int pin) {
  
    bPin = pin;
    pintMode(bPin, INPUT);
}
  
// Timer expira após ms milisegundos
// Nao terminado, falta associar com o que tem que ser feito na tarefa 2...
void timer_set (int ms) {
     
    timer0_overflow_count = 0;
}
    
void button_changed (int pin, int v);  // Notifica pin mudado para modo 'v'
void timer_expired (void);  // Notifica timer expirado
    
// Programa principal  
    
void setup () {
      
    //timer0_overflow_count = millis();
    
    init();
}
      
void loop () {
  
    int v = digitalRead(bPin);
    
    // Detectando botao pressionado
    if(v)
      button_changed(bPin, v);
    
    // Vendo se timer deve expirar
    if(timer0_overflow_count >= ms) {
    
      timer_set(ms);
      timer_expired();
    }
}
