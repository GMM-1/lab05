//************************************************************************** 
// Author: Gabriel Andrade
// Carnet: 21499
// Laboratorio # 5
// descripcion: juego de carreras
//**************************************************************************

//variables de estado 
int start_game = 0;
int start_semaf = 0;

volatile byte state = LOW;

//LEDS de incremento del jugador 1 
const int LED1_J1 = 3;
const int LED2_J1 = 4;
const int LED3_J1 = 5;
const int LED4_J1 = 6;
const int LED5_J1 = 7;
const int LED6_J1 = 8;
const int LED7_J1 = 9;
const int LED8_J1 = 10;

//LEDS de incremento del jugador 2 
const int LED1_J2 = 23;
const int LED2_J2 = 24;
const int LED3_J2 = 25;
const int LED4_J2 = 26;
const int LED5_J2 = 27;
const int LED6_J2 = 28;
const int LED7_J2 = 29;
const int LED8_J2 = 13;

//LEDS de ganador 
const int P1_WINN = 15;
const int P2_WINN = 35;

//LEDS de botones para jugar 
const int P1 = PB_3;
const int P2 = PE_0;

//variables auxiliares 
int contador1 = 0;
int contador2 = 0;

void setup() 
{
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);

  pinMode(LED1_J1, OUTPUT);
  pinMode(LED2_J1, OUTPUT);
  pinMode(LED3_J1, OUTPUT);
  pinMode(LED4_J1, OUTPUT);
  pinMode(LED5_J1, OUTPUT);
  pinMode(LED6_J1, OUTPUT);
  pinMode(LED7_J1, OUTPUT);
  pinMode(LED8_J1, OUTPUT);

  pinMode(LED1_J2, OUTPUT);
  pinMode(LED2_J2, OUTPUT);
  pinMode(LED3_J2, OUTPUT);
  pinMode(LED4_J2, OUTPUT);
  pinMode(LED5_J2, OUTPUT);
  pinMode(LED6_J2, OUTPUT);
  pinMode(LED7_J2, OUTPUT);
  pinMode(LED8_J2, OUTPUT);

  pinMode(P1, INPUT);
  pinMode(P2, INPUT);

  pinMode(P1_WINN, OUTPUT);
  pinMode(P2_WINN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(PUSH1), button1, RISING);
  attachInterrupt(digitalPinToInterrupt(PUSH2), button2, RISING);

  attachInterrupt(digitalPinToInterrupt(P1), inter1, RISING);
  attachInterrupt(digitalPinToInterrupt(P2), inter2, RISING);
}

void loop() 
{
  //inicio del semaforo
  if (start_semaf == 1)// si se presiona el push del semaforo
  {
    start_semaf = 0;
    semaforo(); //rutina para encender el semaforo 
    }
  if (start_game == 1) // si se acabo la interrupcion del semaforo
  {
    player1(); //rutina de incremento del jugador 1 
    player2(); //rutina de incremento del jugador 2
    }
}

//botones para iniciar el semaforo 
void button1() {
  start_semaf = 1;
}

void button2() {
  start_semaf = 1;
}

//interrupcion de incremento jugador 1 
void inter1(){
  if (start_game ==1) {
  contador1++;
  delay(500);
  }
}

//interrupcion de incremento jugador 2
void inter2(){
  if (start_game==1){
  contador2++;
  delay(500);
  }
}

//casos de incremento de la variable auxiliar jugador 2 
void player2(){
      switch (contador2){
        case 1: 
          digitalWrite(LED1_J2, HIGH);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 2: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, HIGH);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 3: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, HIGH);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 4: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, HIGH);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 5: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, HIGH);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 6: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, HIGH);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 7: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, HIGH);
          digitalWrite(LED8_J2, LOW);
          break;
        case 8: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, HIGH);

          digitalWrite(P2_WINN, HIGH);
          start_game = 0;
          break;         
      }
}

//casos de incremento de la variable auxiliar del jugador 1 
void player1(){
  switch (contador1){
        case 1: 
          digitalWrite(LED1_J1, HIGH);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 2: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, HIGH);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 3: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, HIGH);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 4: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, HIGH);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 5: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, HIGH);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 6: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, HIGH);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 7: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, HIGH);
          digitalWrite(LED8_J1, LOW);
          break;
        case 8: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, HIGH);

          digitalWrite(P1_WINN, HIGH);
          start_game = 0;
          break;         
      }
}

// reiniciamos el juego, ponemos todo en 0 
void resetear(){
          contador1 = 0;
          contador2 = 0;

          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          digitalWrite(P1_WINN, LOW);

          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);

          digitalWrite(P2_WINN, LOW);

}

//rutina de leds para semaforo 
void semaforo() {
  resetear();
  digitalWrite (RED_LED, HIGH);
  digitalWrite (GREEN_LED, LOW);
  delay(1000);
  digitalWrite (RED_LED, HIGH);  
  digitalWrite (GREEN_LED, HIGH);
  delay(1000);
  digitalWrite (RED_LED, LOW);
  digitalWrite (GREEN_LED, HIGH);
  start_game = 1;
}