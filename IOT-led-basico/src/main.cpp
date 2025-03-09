#include <Arduino.h>

void setup() {
  Serial.begin(115200);//inicia la comunicacion serial
}

void loop() {
  Serial.println("Hello World");
  delay(3000);//espera 3 segundos
}

