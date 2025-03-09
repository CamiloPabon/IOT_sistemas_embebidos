#include <Arduino.h>

#define LED 2//definimos el pin 2 como LED

void setup() {
  Serial.begin(115200);//inicia la comunicacion serial
  pinMode(LED, OUTPUT);//configura el pin LED como salida
  digitalWrite(LED, LOW);
}

void loop() {
  Serial.println("Hello World");
  delay(1000);//espera 3 segundos
  digitalWrite(LED, HIGH);//enciende el LED
  delay(1000);//espera 1 segundo
  digitalWrite(LED, LOW);//apaga el LED
}

