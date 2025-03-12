#include <WiFi.h>
#include "libwifi.h"

void conectarWifi(const char * ssid, const char * password){
  WiFi.begin(ssid, password);
  Serial.println("Estableciendo vinculo con el AP.");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\r\nConexion establecida");
  Serial.print("Numero IP asignado: ");
  Serial.println(WiFi.localIP()); //Imprime el numero IP   
}
