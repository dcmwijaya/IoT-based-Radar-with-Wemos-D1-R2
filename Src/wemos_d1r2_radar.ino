#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Servo.h>

Servo myservo;
WiFiClient espClient;
PubSubClient client(espClient);
StaticJsonDocument<256> DataPublish, DataSubscribe;

#define ssid "YOUR_WIFI_NAME"
#define password "YOUR_WIFI_PASSWORD"
#define mqtt_server "test.mosquitto.org"
#define mqtt_topic "coursera/uci/radar"
String clientId = "YOUR_CLIENT_ID";
#define servoPin D6
#define trigPin D5
#define echoPin D4

long duration;
int distance;
String sensor_information;
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
    Serial.println("\n");
  }
  else{
    Serial.println("\nFailed to connect to WiFi !!");
  } 
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
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

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(0);
}

void loop() {
  for(int i=15; i<=180; i++){  
    myservo.write(i);
    delay(30);
    
    Serial.print("Degree: ");
    Serial.print(i);
    distance = calculateDistance();
    Serial.print(", Distance: ");
    Serial.print(distance);
    Serial.println(".");
    
    if (distance > 0 && distance <= 15){
      sensor_information = "detected";  
    }
    else {
      sensor_information = "not detected";
    }   
  }
  for(int i=180; i>15; i--){  
    myservo.write(i);
    delay(30);
    
    Serial.print("Degree: ");
    Serial.print(i);
    distance = calculateDistance();
    Serial.print(", Distance: ");
    Serial.print(distance);
    Serial.println(".");
    
    if (distance > 0 && distance <= 15){
      sensor_information = "detected";  
    }
    else {
      sensor_information = "not detected";
    }
  }

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  DataPublish["sensor"] = String(sensor_information);
  serializeJson(DataPublish, Payload);
  boolean dataout = client.publish(mqtt_topic, Payload);

  Serial.println("\n----------------------------------------------");
  Serial.println("Json Packages: " + String(Payload));
  Serial.println("Publish Information: Data Sent");
  Serial.println("----------------------------------------------");
  delay(2000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("\n----------------------------------------------");
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Subscribe Information: ");
  for (int i = 0; i < length; i++) {
    (char)payload[i];
  } 
  deserializeJson(DataSubscribe, payload);
  const char* sensor = DataSubscribe["sensor"];
  Serial.println(sensor);
  Serial.println("----------------------------------------------");
}

int calculateDistance(){   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  return distance;
}
