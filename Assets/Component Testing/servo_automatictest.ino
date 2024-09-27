#include <Servo.h>

Servo myservo;
#define servoPin D6

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
  myservo.write(0);
}

void loop() {
  for(int i=15;i<=165;i++){  
    myservo.write(i);
    delay(30);
    Serial.print(i);
  }
  for(int i=165;i>15;i--){  
    myservo.write(i);
    delay(30);
    Serial.print(i);
  }
}
