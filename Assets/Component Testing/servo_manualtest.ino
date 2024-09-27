#include <Servo.h>

Servo myservo;  
#define servoPin D6

int pos;  

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
  myservo.write(0);
}

void loop() {
  Serial.println("\nEnter position: ");  
  while (Serial.available()==0){}            
  pos = Serial.readString().toInt(); 
  if(pos >=0 && pos <= 180){
    myservo.write(pos);
    Serial.print("Turned to ");                   
    Serial.println(pos);          
    Serial.flush();  
  } else {
    Serial.println("Invalid position");
  } 
}
