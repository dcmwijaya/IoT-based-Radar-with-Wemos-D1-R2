#include <ESP8266WiFi.h>
 
const char* ssid     = "Your WiFi Name";
const char* password = "Your WiFi Password";     
     
void setup() {
  Serial.begin(115200);
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
     
void loop() {}
