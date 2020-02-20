// Variable encargada de llevar la cuenta de las decenas
int counterDecenas = 0;
// Variable encargada de llevar la cuenta de las unidades
int counterUnidades = 0; 
// Constante que tiene el valor del pin donde está conectado el botón
const int boton = 13; 
// Arreglo que contiene la representación decimal de los números del 0 al 9
const int numbers[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103}; //0,1,2,3,4,5,6,7,8,9
// Variable que va a almacenar posteriormente la lectura de la entrada del botón
int entradaBoton = 0; 
void setup() {
  // Define el puerto C como salida
  DDRC = OUTPUT;
  // Define el puerto A como salida
  DDRA = OUTPUT;
  // Define el pin 13 como entrada 
  pinMode(boton, INPUT);
  // inicializa en 0 los puertos 
  DDRA = 0;
  DDRC = 0;
}

void loop() {
  // Lectura del pin 13
  entradaBoton = digitalRead(boton);
  /*
   * Primera condición:
   * Sirve para determinar si el botón ha sido presionado y en caso de ser así
   * Saber también si las unidades son menores a nueve
   */
  if( entradaBoton == LOW && counterUnidades < 9){
    // Retraso de 200 mseg  
    delay(100);
    // Aumentar las unidades en uno
    counterUnidades = counterUnidades + 1;
    /* 
     * Enviar el contenido del contador de unidades a la salida en el puerto C
     * que es el que contiene el valor de las unidades
     */
    DDRC = numbers[counterUnidades];
    /*
     * Segunda condición:
     * Sirve para determinar si el botón ha sido presionado y en caso de ser así
     * Saber si el contador de unidades es mayor a 8 y el contador de decenas 
     * menor que nueve
     */
  }else if(entradaBoton == LOW && counterUnidades > 8 && counterDecenas < 9){
    // Retraso de 200 mseg 
    delay(200);
    // Asignamos cero al contador de unidades
    counterUnidades = 0;
    // Aumenta el contador de decenas en uno
    counterDecenas = counterDecenas + 1;
    /* 
     * Enviar el contenido del contador de unidades a la salida en el puerto C
     * que es el que contiene el valor de las unidades
     */
    DDRC = numbers[counterUnidades];
    /* 
     * Enviar el contenido del contador de unidades a la salida en el puerto A
     * que es el que contiene el valor de las decenas
     */
    DDRA = numbers[counterDecenas];
    /*
     * Tercera condición:
     * Sirve para determinar si el botón ha sido presionado y en caso de ser así
     * Saber si el contador de unidades es mayor a 8 y el contador de decenas 
     * mayor que nueve
     */
  }else if(entradaBoton == LOW && counterDecenas > 8 && counterUnidades > 8 ){
    // Retraso de 200 mseg 
    delay(200);
    // Asignamos cero al contador de unidades
    counterUnidades = 0;
    // Asignamos cero al contador de decenas
    counterDecenas = 0;
    /* 
     * Enviar el contenido del contador de unidades a la salida en el puerto C
     * que es el que contiene el valor de las unidades
     */
    DDRC = numbers[counterUnidades];
    /* 
     * Enviar el contenido del contador de unidades a la salida en el puerto A
     * que es el que contiene el valor de las decenas
     */
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
