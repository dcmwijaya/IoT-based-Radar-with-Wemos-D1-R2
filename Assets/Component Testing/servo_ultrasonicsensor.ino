#include <Servo.h>

Servo myservo;
#define servoPin D6
#define trigPin D5
#define echoPin D4

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  myservo.attach(servoPin);
  myservo.write(0);
}

void loop() {
  for(int i=15;i<=165;i++){  
    myservo.write(i);
    delay(30);
    Serial.print("Degree: ");
    Serial.print(i);
    distance = calculateDistance();
    Serial.print(", Distance: ");
    Serial.print(distance);
    Serial.println(".");
  }
  for(int i=165;i>15;i--){  
    myservo.write(i);
    delay(30);
    Serial.print("Degree: ");
    Serial.print(i);
    distance = calculateDistance();
    Serial.print(", Distance: ");
    Serial.print(distance);
    Serial.println(".");
  }
}

int calculateDistance(){   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}
