int counterDecenas = 0;
int counterUnidades = 0; 
const int boton = 13; 
const int numbers[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103}; //0,1,2,3,4,5,6,7,8,9
int entradaBoton = 0; 
int i = 0;
void setup() {
  // put your setup code here, to run once:
  DDRC = OUTPUT;
  DDRA = OUTPUT;
  pinMode(boton, INPUT);

  DDRA = 0;
  DDRC = 0;
}

void loop() {
  entradaBoton = digitalRead(boton);
  
  if( entradaBoton == LOW && counterUnidades < 9){
    delay(100);
    counterUnidades = counterUnidades + 1;
    DDRC = numbers[counterUnidades];
  }else if(entradaBoton == LOW && counterUnidades > 8 && counterDecenas < 9){
    delay(100);
    counterUnidades = 0;
    counterDecenas = counterDecenas + 1;
    DDRC = numbers[counterUnidades];
    DDRA = numbers[counterDecenas];
  }else if(entradaBoton == LOW && counterDecenas > 8 && counterUnidades > 8 ){
    delay(200);
    counterUnidades = 0;
    counterDecenas = 0;
    DDRC = numbers[counterUnidades];
    DDRA = numbers[counterDecenas];
  }

  
  
}

/*
 * Indice
 * Objetivo
 * Intruduccion
 * Referencia
 * Figuras citadas
 * Problema
 * Material
 * SW
 * Anexo de instalacion y conexión de arduino
 */
