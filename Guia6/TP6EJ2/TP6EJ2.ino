/* 2. Publicar datos en el tópico antes mencionado.*/

#include "WiFi101.h"
#include <PubSubClient.h>

const char* ssid = "Arduino";
const char* password =  "arduino2019";

const char* mqttServer = "postman.cloudmqtt.com";
const int mqttPort = 16525;
const char* mqttUser = "bjirkdcw";
const char* mqttPassword = "5o-xAF1XrS7S";

WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
   
  Serial.println("Connected to the WiFi network");
  
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
  //client.publish("esp/test", "Hola mundo desde MQTT :)");
  client.subscribe("/chat_arduino");
}

void loop() {
  client.loop();
  client.publish("/chat_arduino","Hola mundo");
  delay(5000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("listo...");
}
