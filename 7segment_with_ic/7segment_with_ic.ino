// pin untuk 7segment
int latchPin = 5; //pin 12 on the 595
int dataPin = 4; //pin 14 on the 595
int clockPin = 6; //pin 11 on the 595

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  //0
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 64);
  digitalWrite(latchPin, HIGH);
  delay(1000);
  Serial.println("kosong");

  //1
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 121);
  digitalWrite(latchPin, HIGH);
  delay(1000);
  Serial.println("ciek");
}
