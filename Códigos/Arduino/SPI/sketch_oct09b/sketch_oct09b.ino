#include <SPI.h>
#include <stdlib.h>

const int pinEsclavo = 10;
byte valR;

void setup (void)
{
  SPI.begin ();   
  Serial.begin(115200);

  pinMode(SCK, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(pinEsclavo,INPUT);
  pinMode(7 ,OUTPUT);
  valR=0x00;
  Serial.println(valR);
  SPCR |= _BV(SPE);
}  

void loop (void)
{
  valR = SPI.transfer(0);
  Serial.println("Entro loop");
  Serial.println(valR);
  if(valR == 0){
      Serial.println("Entro if");
      digitalWrite(7, LOW);
    }else{
      Serial.println("Entro else");
      digitalWrite(7, HIGH);
    }
} 
