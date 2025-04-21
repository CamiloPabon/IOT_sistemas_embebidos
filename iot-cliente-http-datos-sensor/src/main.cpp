#include <Arduino.h>
#include "libwifi.h"
#include <WiFi.h>

#define LED 2

const char * ssid = "MIRED";
const char * password = "a1b2c3d4";
const char * host = "codelab.denkitronik.com";
const char * name = "PABON";
const int port = 8080;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Iniciando cliente http");
  conectarWifi(ssid, password);

}

void loop() {
    Serial.println("Iniciando loop");
    int temperatura = random(0, 100);
    int humedad = random(0, 100);
    String url = "/thingname/" + String(name) + "?presion=" + String(humedad) +"&altitud=300&temperatura=" + String(temperatura);
    Serial.println("Enviando datos a freeboard...");
    Serial.println(url);

  WiFiClient cliente;
  if (!cliente.connect(host, port)) {
    Serial.println("Error al conectar con freeboard");
    delay(2000);
    return;
  }

  cliente.print("GET " + url + " HTTP/1.1\r\nHost: " + String(host) + "\r\nConnetion: close\r\n\r\n");// el HTTP/1.1 es la version del protocolo
  
  //Agregamos un tiempo de espera para recibir los primeros caracteres enviados por el servidor
  unsigned long timeout = millis();
  while (cliente.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println("Tiempo de espera agotado");
      cliente.stop();
    }
  }

  Serial.println("Respuesta del servidor:");
  while (cliente.available()) {
    String line = cliente.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println("Finando conexion");
  cliente.stop();

  
  delay(3000);

}
