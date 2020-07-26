#include <ESP8266WiFi.h>
const char* ssid = "DCC-LCI"; //Substitua com o nome de sua rede WiFi
const char* password = "aluno.dcc!"; //Substitua com a senha de sua erde WiFi
void setup() {
 delay(1000);
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 Serial.println();
 Serial.print("Conectando");
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("Sucesso!");
 Serial.print("Meu endereco IP é: ");
 Serial.println(WiFi.localIP());
}
void loop() {
  Serial.println(WiFi.status());
}
