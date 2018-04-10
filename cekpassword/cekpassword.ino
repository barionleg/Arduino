#include <EEPROM.h>
#include <string.h>

int cekPassword(char* a, char* b){
   if (strcmp(a, b)==0){
    return 1; // Kalau 1 maka nilai a dan b sama
   } else {
    return 0; // Kalau 0 maka nilai a dan b berbeda
   }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(cekPassword("abc", "ab"));
}

void loop() {
  // put your main code here, to run repeatedly:

}
