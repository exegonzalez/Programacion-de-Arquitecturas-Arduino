/* 4. Ahora suponga el siguiente caso en su casa tiene 5 ambientes (cocina, comedor, baño, habitación_1, habitación_2) 
 en cada una hay un led que se enciende con un pulsador, ahora contemple las siguientes actividades:
 b. Con una wemos deberá realizar las siguiente publicaciones:
    i. Cada ambiente publicara cundo se enciende o apaga la luz en el tópico correspondiente por ejemplo casa/habitación_1/luz, 
    casa/cocina/luz, etc., con el siguiente mensaje “se encendió la luz de la cocina” o “se apagó la luz de la cocina”.*/

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


void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(pulsador1,INPUT);
  pinMode(pulsador2,INPUT);
  pinMode(pulsador3,INPUT);
  pinMode(pulsador4,INPUT);
  pinMode(pulsador5,INPUT);
  
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
  client.subscribe("casa/+/luz");
}

void loop() {
  client.loop();
  lucesCasa(pulsador1,led1,"casa/habitación_1/luz");
  lucesCasa(pulsador2,led2,"casa/habitación_2/luz");
  lucesCasa(pulsador3,led3,"casa/cocina/luz");
  lucesCasa(pulsador4,led4,"casa/comedor/luz");
  lucesCasa(pulsador5,led5,"casa/banio/luz");
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

void lucesCasa(int pulsador, int led,String topic){
  const char * topic2 = topic.c_str();
  if(digitalRead(pulsador)==LOW){
    digitalWrite(led,HIGH);
    client.publish(topic2, "Se encendio la luz");
  }
  else{
    digitalWrite(led,HIGH);
    client.publish(topic2, "Se apago la luz");
  }
}
