#include <Servo.h>
Servo name_servo;
int i;
void setup() {
  // put your setup code here, to run once:
  name_servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<=90; i++){
    name_servo.write(i);
    delay(10);
  }
}
