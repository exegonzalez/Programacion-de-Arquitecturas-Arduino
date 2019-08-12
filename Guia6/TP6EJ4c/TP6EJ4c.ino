/* 4. Ahora suponga el siguiente caso en su casa tiene 5 ambientes (cocina, comedor, baño, habitación_1, habitación_2) 
 en cada una hay un led que se enciende con un pulsador, ahora contemple las siguientes actividades:
 c. Con otra wemos deberá escuchar los cambios de estados (es decir cada vez que se enciende o apaga una luz) y publicarlos por consola: 
    i. Deberá utilizar comodines (Wilcards) para escuchar todos los tópicos.
    ii. Debe poder publicar un mensaje “apagar luces” que apague las luces de todos los ambientes.*/

#include "WiFi101.h"
#include <PubSubClient.h>

#define led1 1
#define led2 2
#define led3 3
#define led4 4
#define led5 5
#define pulsador1 6
#define pulsador2 7
#define pulsador3 8
#define pulsador4 9
#define pulsador5 10

const char* ssid = "Arduino";
const char* password =  "arduino2019";

const char* mqttServer = "postman.cloudmqtt.com";
const int mqttPort = 13570;
const char* mqttUser = "fstbyttg";
const char* mqttPassword = "BCIZbC7Q1Kvj";

WiFiClient espClient;
PubSubClient client(espClient);
String mensaje;

void setup() {
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
  client.subscribe("casa");
}

void loop() {
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    mensaje.concat((char)payload[i]);
  }
  if (mensaje = "Apagar luces"){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }
  Serial.println();
  Serial.println("listo...");
}
