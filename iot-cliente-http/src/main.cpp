#include <Arduino.h>
#include "libwifi.h"
#include <WiFi.h>

#define LED 2

const char* ssid = "MIRED";
const char* password = "a1b2c3d4";
const char* host="dweet.io";
const int port = 80;
int Temperatura ;
int humedad ;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Iniciando cliente http");
  conectarWifi(ssid,password);
  
}

void loop() {
  Temperatura = random(19, 31);
  humedad = random(0, 100);
  WiFiClient cliente;

  if(!cliente.connect(host,port)){
    delay(2000);
    return;
  }

  cliente.print("GET /dweet/for/PABON?Temperatura:=" + String(Temperatura)+"&Humedad="+humedad + " HTTP/1.1\r\nHost: " + String(host) + "\r\nConnection: close\r\n\r\n");

  //Agrgamos lun tiempo de espera para recibir los primeros caracteres del servidor
  unsigned long tiempo = millis();
  while (cliente.available()==0){
    if(millis()-tiempo>5000){
      Serial.println("Tiempo de espera agotado");
      cliente.stop();
      return;
    }
  }
  
  while (cliente.available()){
    
    String linea = cliente.readStringUntil('\r');
    Serial.println(linea);
  }

  Serial.println("Fin de la conexion");
  cliente.stop();
  delay(3000);

}
