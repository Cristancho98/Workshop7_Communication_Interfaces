#include <Wire.h>

char x='0';

void setup() {

//Estableciendo direccion con Raspberry Pi 3
  Wire.begin(0x10);                   
  Wire.onReceive(receiveEvent); 

//Estableciendo configuracion de Arduino
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7 ,OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); 
  Serial.begin(9600); 
  }


//Ciclo de encendido y apagado del LED

void loop() {
  delay(100);

  if(x==1){
    Serial.println("Encendiendo");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(7, HIGH);
    }else{
    Serial.println("Apagando");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(7, LOW);
      }
}


void receiveEvent(int howMany) {
  while (Wire.available()) { 
    x = Wire.read(); 

  }
}
