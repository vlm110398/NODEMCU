/************************* Inclusão das Bibliotecas *************************/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <Wire.h>


/****************************** Conexão WiFi *********************************/

const char* SSID      = "homewifi_D68"; // rede wifi
const char* PASSWORD  = "09114147"; // senha da rede wifi

/****************************** Broker MQTT **********************************/

const char* BROKER_MQTT = "broker.iot-br.com";
int BROKER_PORT         = 8080;

/*************************** Variaveis globais *******************************/

long previousMillis = 0;

/************************ Declaração dos Prototypes **************************/

void initSerial();
void initWiFi();
void initMQTT();
void initMCP9808();

/************************ Instanciação dos objetos  **************************/


WiFiClient client;
PubSubClient mqtt(client); // instancia o mqtt

/********************************* Sketch ************************************/

void setup() {
  initSerial();
  initWiFi();
  initMQTT();

}

void loop() {
  if (!mqtt.connected()) {
    reconnectMQTT();
  }
  recconectWiFi();
  mqtt.loop();
  sensorLoop();

}

/*********************** Implementação dos Prototypes *************************/

/* Função responsável por publicar a cada X segundos o valor do sensor */
void sensorLoop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > 1000 && mqtt.connected()) {
    previousMillis = currentMillis;

 
    //float c =  aki é o valor do angulo
    float c = 1.0;
    char temp[4];
    dtostrf(c, 2, 2, temp);
    mqtt.publish("DZ/gauge/temperature", temp);
    delay(250);


  }
}

/* Conexao Serial */
void initSerial() {
  Serial.begin(115200);
}

/* Configuração da conexão WiFi */
void initWiFi() {
  delay(10);
  Serial.println("Conectando-se em: " + String(SSID));

  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado na Rede " + String(SSID) + " | IP => ");
  Serial.println(WiFi.localIP());
}

/* Configuração da conexão MQTT */
void initMQTT() {
  mqtt.setServer(BROKER_MQTT, BROKER_PORT);
  mqtt.setCallback(mqtt_callback);
}

/* Inicialização do Sensor */

/* Funcão responsável por receber os callbacks do mqtt */
void mqtt_callback(char* topic, byte* payload, unsigned int length) {

  String message;
  for (int i = 0; i < length; i++) {
    char c = (char)payload[i];
    message += c;
  }
  Serial.println("Tópico => " + String(topic) + " | Valor => " + String(message));
  Serial.flush();
}

/* Demais implementações */

void reconnectMQTT() {
  while (!mqtt.connected()) {
    Serial.println("Tentando se conectar ao Broker MQTT: " + String(BROKER_MQTT));
    if (mqtt.connect("anonymous")) {
      Serial.println("Conectado");
      mqtt.subscribe("DZ/gauge/temperature");

    } else {
      Serial.println("Falha ao Reconectar");
      Serial.println("Tentando se reconectar em 2 segundos");
      delay(2000);
    }
  }
}

void recconectWiFi() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
}
