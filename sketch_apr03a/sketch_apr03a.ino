void setup() {
  // put your setup code here, to run once:
  int isOpen=0, isMatch=0, isBroken=0;
  float distance=0;
  char *password;
}

void loop() {
  // put your main code here, to run repeatedly:

  if(password == "12345")
    isMatch = 1;
  if(distance>1.0)
    isOpen = 1;


  if(isOpen && isMatch){
    // add time to database
    }
  else {
    isBroken = 1;
    }
}
