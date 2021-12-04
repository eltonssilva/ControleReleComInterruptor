#include <ESP8266WiFi.h>
#include <AsyncMqttClient.h>
#include <Ticker.h>


#define WIFI_SSID           "AGUIAR_ADM"
#define WIFI_PASSWORD       "a0b9c8d7e6"

#define MQTT_HOST           "mqtt.autodomo.io"
#define MQTT_PORT           1883

const char* USER_MQTT       = "User000001075";
const char* PASSWORD_MQTT   = "upfkk9ym";
#define ID_MQTT             "01AA5B50EBEA"

#define MQTT_PUB_STATE_LUZ_R  "/autodomo/User000001075/01AAA3E894AA/light/state"
#define MQTT_SUB_VALUE_LUZ_R  "/autodomo/User000001075/01AAA3E894AA/light/value"

#define MQTT_PUB_STATE_LUZ_G  "/autodomo/User000001075/01AA5B50EBEA/light/state"
#define MQTT_SUB_VALUE_LUZ_G  "/autodomo/User000001075/01AA5B50EBEA/light/value"

#define MQTT_PUB_STATE_LUZ_Y  "/autodomo/User000001075/14AADD15D5F9/switch/state"
#define MQTT_SUB_VALUE_LUZ_Y  "/autodomo/User000001075/14AADD15D5F9/switch/value"



AsyncMqttClient mqttClient;
Ticker wifiReconnectTimer;
Ticker mqttReconnectTimer;


WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;

unsigned long tempoAnterior = 0;
const long    intervalo     = 250;

int Rele_R = 15; 
int Rele_G = 12; 
int Rele_Y = 4; 

int S1 = 0;
//int S2 = ?;
//int S3 = ?;

void setup() {
  // put your setup code here, to run once:
  initParametros();
  wifiInit();
  connectToWifi();
  mqttInit();

}

void loop() {
  // put your main code here, to run repeatedly:
  interruptor1();

}
