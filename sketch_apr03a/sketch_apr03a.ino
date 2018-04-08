/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
const int trigPin = 9;
const int LEDPin = 8;
const int echoPin = 10;
int VCC = 7;
int segA = 8;
int segB = 11;
int segC = 2;
int segD = 3;
int segE = 4;
int segF = 5;
int segG = 6;
// defines variables
int isOpen;
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(LEDPin, OUTPUT);//LED
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(VCC,OUTPUT);//VCC
pinMode(segA,OUTPUT);//a
pinMode(segB,OUTPUT);//b
pinMode(segC,OUTPUT);//c
pinMode(segD, OUTPUT);//d
pinMode(segE,OUTPUT);//e
pinMode(segF,OUTPUT);//f
pinMode(segG,OUTPUT);//g
Serial.begin(9600); // Starts the serial communication

void lightNumber(int numberToDisplay);
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if (distance > 15){
  lightNumber(1);
  delayMicroseconds(5);
  isOpen = 1;
  Serial.println("Pintu Terbuka");
  }else {
      lightNumber(0);
      delayMicroseconds(5);
      isOpen = 0;
      Serial.println("Pintu Tertutup");
  }
}

void lightNumber(int numberToDisplay) {

#define SEGMENT_ON  LOW
#define SEGMENT_OFF HIGH
digitalWrite(VCC, HIGH);

  switch (numberToDisplay){

  case 0:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 1:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;
  }
}
