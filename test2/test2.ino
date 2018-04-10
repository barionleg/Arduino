/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

#include <Servo.h>

int sensorPin = A1; // select the input pin for LDR 
int sensorValue = 0; // variable to store the value coming from the sensor 
int ledPin = 9;
int value = 0;
int counter = 0;

Servo name_servo;
int i;

const int trigPin = 11;
const int echoPin = 10;
// defines variables
long duration;
int distance;
// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // DISINI DICEK DULU KONDISI PINTU APA TERBUKA ATAU ENGGA
  // JIKA TERNYATA BUKA DAN TERNYATA PENGECEKAN PASSWORD TIDAK PERNAH DILAKUKAN ATAU SALAG BERARTI,
  // DILAKUKAN PENANGANAN UNTUK PENCURIAN
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  char pass[4];
  char input = 'x';  
//
//  while (sensorValue == 1023) {
//    delay(1);
//  }
  // print out the value you read:
//  Serial.println(sensorValue);
  if (sensorValue >=551 && sensorValue <= 599) {
    input = '1';
  } else if (sensorValue >=510 && sensorValue <= 520) {
    input = '2';
  } else if (sensorValue >=310 && sensorValue <= 330) {
    input = '3';
  } else if (sensorValue >=700 && sensorValue <= 720) {
    input = '4';
  } else if (sensorValue >= 680 && sensorValue <= 699) {
    input = '5';
  } else if (sensorValue >= 600 && sensorValue <= 630) {
    input = '6';
  } else if (sensorValue >= 780 && sensorValue <= 789) {
    input  = '7';
  } else if (sensorValue >= 760 && sensorValue <= 779) {
    input = '8';
  } else if (sensorValue >= 721 && sensorValue <= 739) {
    input = '9';
  } else if (sensorValue >= 825 && sensorValue <= 835) {
    input = '*';
  } else if (sensorValue >= 790 && sensorValue <= 800) {
    input = '#';
  } else if (sensorValue >= 815 && sensorValue <= 825) {
    input = '0';  
  } else {
    input = 'x';
  }
  
  if (input != 'x') {
    Serial.println(input);
    pass[counter] = input;
    counter++;
  }
  
  if (counter == 4) {
    
    // DISINI DILAKUKAN PENGECEKAN PASSWORD
    for (int x = 0; x < 4; x++) {
      Serial.print(pass[x]);
    }
    Serial.println();

    //BAGIAN INI DIJALANKAN APABILA PASSWORD YANG DIINPUT BENAR
    name_servo.attach(12);
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

    if(distance <15){
      for(i=0; i<=90; i++){
      name_servo.write(i);
      delay(10);
      }
    }
//    delay(10000);

    value = analogRead(sensorPin); // read the value from the sensor 
    value = constrain(value, 0, 700);
    value = map(value, 0, 700, 255, 0);
  
    Serial.println(value);
    analogWrite(ledPin, value);
    
    counter = 0;

    // DISINI DILAKUKAN PENGINPUTAN DATA YANG INGIN DIMASUKKAN KE DALAM DATABASE
  }

  delay(500);        // delay in between reads for stability
}
