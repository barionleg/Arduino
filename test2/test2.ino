/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
#include <Servo.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

#include <Wire.h>


LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

#include <DB.h>
#include <string.h>

#include <Time.h>


#define MY_PINTU 1
#define MY_USER 2

// pin untuk 7segment
int latchPin = 5; //pin 12 on the 595
int dataPin = 4; //pin 14 on the 595
int clockPin = 6; //pin 11 on the 595

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

DB db;
struct Pintu {
   char waktu[30];
   char username[10];
   char password[10];
   char berhasil[5];
} pintu;

struct User{
  char username[10];
  char email[20];
} user;

int cekPassword(char* a, char* b){
   if (strcmp(a, b)==0){
    return 1; // Kalau 1 maka nilai a dan b sama
   } else {
    return 0; // Kalau 0 maka nilai a dan b berbeda
   }
}

void databasePintu(){
    sprintf(pintu.waktu, "10-04-2018 14:07:11");
    sprintf(pintu.username, "leo");
    sprintf(pintu.password, "masukaja");
    Serial.println("Creating Table pintu...");  
    db.create(MY_PINTU, sizeof(pintu));
    db.open(MY_PINTU);
    Serial.println("Creating records pintu");
    db.append(DB_REC pintu);
    db.read(1, DB_REC pintu);
    Serial.print("waktu : "); Serial.println(pintu.waktu);
    Serial.print("username : "); Serial.println(pintu.username);
    Serial.print("password : "); Serial.println(pintu.password);
}

void databaseUser(){
//  sprintf(user.username, "leo");
//  sprintf(user.email, "leo@gmail.com");
//  Serial.println("Creating Table user...");
//  db.create(MY_USER, sizeof(user));
  db.open(MY_USER);
//  Serial.println("Creating records user");
//  db.append(DB_REC user);
  db.read(1, DB_REC user);
  Serial.print("username : "); Serial.println(user.username);
  Serial.print("email : "); Serial.println(user.email);
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
 
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
 
  lcd.setCursor(0,0);
  lcd.print(" Input Password : ");
  
}

// the loop routine runs over and over again forever:
void loop() {
  lcd.setCursor(0,1);
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  char pass[4] = {' ', ' ', ' ', ' '};
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
    lcd.print(pass);
  }

  if (counter == 4) {
    for (int x = 0; x < 4; x++) {
      Serial.print(pass[x]);
    }
    Serial.println();

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

        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, 64);
        digitalWrite(latchPin, HIGH);
        delay(1000);
        Serial.println("kosong");
    }
    else {
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, 121);
        digitalWrite(latchPin, HIGH);
        delay(1000);
        Serial.println("ciek");
      }
    name_servo.detach();
//    delay(1000);
    
    value = analogRead(sensorPin); // read the value from the sensor 
    value = constrain(value, 0, 700);
    value = map(value, 0, 700, 255, 0);
  
    Serial.println(value);
    analogWrite(ledPin, value);
    
    counter = 0;
    for (int u = 0; u < 4; u++) {
      pass[u] = ' ';
    }
  }
 
  delay(500);        // delay in between reads for stability
}
