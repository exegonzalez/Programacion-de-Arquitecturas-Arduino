/* 4. Ahora suponga el siguiente caso en su casa tiene 5 ambientes (cocina, comedor, baño, habitación_1, habitación_2) 
 en cada una hay un led que se enciende con un pulsador, ahora contemple las siguientes actividades:
 d. Ahora en la cocina es necesario agregar un sensor de temperatura que publique los datos en el 
 tópico casa/cocina/temperatura, esto datos también deben ser publicados por la otra wemos.*/

#include "WiFi101.h"
#include <PubSubClient.h>
#include "DHT.h"
#define DHTPIN 6
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

#define led1 1
#define led2 2
#define led3 3
#define led4 4
#define led5 5

String mensaje;
const char* ssid = "Arduino";
const char* password =  "arduino2019";

const char* mqttServer = "postman.cloudmqtt.com";
const int mqttPort = 13570;
const char* mqttUser = "fstbyttg";
const char* mqttPassword = "BCIZbC7Q1Kvj";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  dht.begin();
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  
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
  client.subscribe("casa/cocina/temperatura");
}

void loop() {
  client.loop();
  float t = dht.readTemperature();
  String temp= "La temperatura es:" +String(t);
  char msj[24]; 
  temp.toCharArray(msj,24);
  client.publish("casa/cocina/temperatura",msj);
  delay(3000);
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
