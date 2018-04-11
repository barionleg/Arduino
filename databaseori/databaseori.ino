#include <EEPROM.h>

#include <DB.h>
#include <string.h>

#include <Time.h>
#include <TimeLib.h>

#define MY_PINTU 1
#define MY_USER 2

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

void databasePintu(){
    sprintf(pintu.waktu, "10-04-2018 20:07:11");
    sprintf(pintu.username, "leo");
    sprintf(pintu.password, "masukaja");
    sprintf(pintu.berhasil, "ya");
    Serial.println("Creating Table pintu...");  
    db.insert(MY_PINTU, sizeof(pintu));
    db.open(MY_PINTU);
    Serial.println("Creating records pintu");
    db.append(DB_REC pintu);
    db.read(2, DB_REC pintu);
    Serial.print("waktu : "); Serial.println(pintu.waktu);
    Serial.print("username : "); Serial.println(pintu.username);
    Serial.print("password : "); Serial.println(pintu.password);
    Serial.print("berhasil : "); Serial.println(pintu.berhasil);
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
  Serial.begin(9600);
  databaseUser();
}

void loop() {
  // put your main code here, to run repeatedly:

}
