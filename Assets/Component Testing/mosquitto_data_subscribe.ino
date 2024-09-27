#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char* ssid = "Your WiFi Name";
const char* password = "Your WiFi Password";
const char* mqtt_server = "test.mosquitto.org";
const char* mqtt_topic = "coursera/uci/radar";

WiFiClient espClient;
PubSubClient client(espClient);
StaticJsonDocument <256> doc;

void setup_wifi() {
  delay(200);
  Serial.println();
  Serial.println();
  Serial.print("Connected to WiFi: ");
  Serial.println(ssid);
     
  WiFi.begin(ssid, password);   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }     
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("");
    Serial.println("Wemos D1 R2 has connected to WiFi !!");  
    Serial.print("IP address : ");
    Serial.println(WiFi.localIP());  
  }
  else{
    Serial.println("\nFailed to connect to WiFi !!");
  } 
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "mqtt-explorer-1c59b85b";
    clientId += String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("\n----------------------------------------------");
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Subscribe Information: ");
  for (int i = 0; i < length; i++) {
    (char)payload[i];
  } 
  deserializeJson(doc, payload);
  const char* sensor = doc["sensor"];
  Serial.println(sensor);
  Serial.println("----------------------------------------------");
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback); 
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  delay(2000);
}
