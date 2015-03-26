// Quarta versao

// Obs.: As partes que lidam com os timers ainda nao estao acabadas. O malloc de lista nao foi testado, mas aparentemente
// o Arduino aceita malloc

// Duvidas:
// - Os papeis dos timers (cada um eh ativado conforme seu respectivo botao eh apertado?)
// - Onde controlar as piscadas do led? ja que aparentemente os timers ficam na API event_driven e o tarefa2 nao passa o pin
//   do led (neste caso, posso fazer uma funcao que passe o pin do led pra ele?)

#include <stdlib.h>

// Lista para pin de buttons
typedef struct listPin {
  
    int bPin;
    struct listPin *prox;
    struct listPin *ant;
} listP;

typedef struct cabecaLista {
	
	listP *ini;	
	listP *corrent;
} cbcLista;

cbcLista cabeca;

// Timers
extern volatile unsigned long timer1;
extern volatile unsigned long timer2;

/*
unsigned long t1;
unsigned long t2;
*/

// Pin
//int bPin;

// Intervalor de tempo
unsigned long intMs;

// Pin passado gera notificacoes
void button_listen (int pin) {
  
    listP no = (listP *)malloc(sizeof(listP));
    
    no->bPin = pin;
    no->prox = NULL;
    no->ant = NULL;
  
    if(cabeca->ini == NULL) {
      
      cabeca->ini = no;  
      cabeca->corrent = no;
    }
    else {
      
      cabeca->corrent->prox = no;
      no->ant = cabeca->corrent;
    }

    pinMode(no->bPin, INPUT);
}
  
// Timer expira após ms milisegundos passados por usuario
void timer_set (int ms) {
     
    intMs = ms;
}
    
void button_changed (int pin, int v);  // Notifica pin mudado para modo 'v'
void timer1_expired (void);  // Notifica timer 1 expirado
void timer2_expired (void); // Notifica timer 2 expirado
    
// Inicio do Programa principal  
    
void setup () {
      
    //timer1 = millis();
    
    cabeca = (cbcLista *)malloc(sizeof(cbcLista));
    
    cabeca->ini = NULL;
    
    init();
}
      
void loop () {
  
    int v = digitalRead(bPin);
    
    // Detectando botao pressionado
    if(v)
      button_changed(bPin, v);
    
    // Vendo se timer deve expirar
    if(timer1 >= intMs) {
    
      timer1_expired();
    }
}
