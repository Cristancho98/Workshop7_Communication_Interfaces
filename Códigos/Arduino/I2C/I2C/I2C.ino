#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

void setup() {
    pinMode(7, OUTPUT);
    Serial.begin(9600);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Serial.println("Ready!");
}

void loop() {
    delay(100);
}

void receiveData(int byteCount){

    while(Wire.available()) {
          number = Wire.read();
          Serial.print("data received: ");
          Serial.println(number);

          if (number == 1)
              digitalWrite(7, HIGH); // set the LED on
          else
              digitalWrite(7, LOW); // set the LED on
   }
}
