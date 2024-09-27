#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char* ssid = "Your WiFi Name";
const char* password = "Your WiFi Password";
const char* mqtt_server = "test.mosquitto.org";
const char* mqtt_topic = "coursera/uci/radar";

WiFiClient espClient;
PubSubClient client(espClient);
StaticJsonDocument<256> DataJSON;
char Payload[128];

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
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  String ultrasonic = "detected";
  DataJSON["sensor"] = String(ultrasonic);
  serializeJson(DataJSON, Payload);
  boolean dataout = client.publish(mqtt_topic, Payload);

  Serial.println("\n----------------------------------------------");
  Serial.println("Json Packages: " + String(Payload));
  Serial.println("Publish Information: Data Sent");
  Serial.println("----------------------------------------------");
  delay(2000);
}
