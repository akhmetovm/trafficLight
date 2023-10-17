void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(1,INPUT);
}

bool buttonState = false;

void crossSound(){
  if (buttonState) {
    buttonState = false;
    tone(8, 987);
    delay(500);
    noTone(8);
    delay(500);

    tone(8, 987);
    delay(500);
    noTone(8);
    delay(500);

    tone(8, 987);
    delay(500);
    noTone(8);
    delay(500);

    tone(8, 987);
    delay(250);
    noTone(8);
    delay(250);

    tone(8, 987);
    delay(250);
    noTone(8);
    delay(250);
    
    tone(8, 987);
    delay(250);
    noTone(8);
    delay(250);

    tone(8, 987);
    delay(250);
    noTone(8);
    delay(250);
  }
}

void wait(int time) {
  for (int i=0; i<=time/10; i++){
    delay(10);
    if (digitalRead(1) == 0){
      buttonState = true;
      tone(8, 880, 100);
    }
  } 
}
void lights(bool r1, bool y1, bool g1, bool r2, bool y2, bool g2) {
  digitalWrite(2, g1);
  digitalWrite(3, y1);
  digitalWrite(4, r1);
  digitalWrite(5, g2);
  digitalWrite(6, y2);
  digitalWrite(7, r2);
}

void loop() {
  lights(1, 0, 0, 1, 1, 0);// beat 1
  wait(2000);
  lights(1, 0, 0, 0, 0, 1);// beat 2
  wait(3000);
  lights(1, 0, 0, 0, 0, 0); // beat 3
  wait(500);
  lights(1, 0, 0, 0, 0, 1); // beat 4
  wait(500);
  lights(1, 0, 0, 0, 0, 0); // beat 5
  wait(500);
  lights(1, 0, 0, 0, 0, 1); // beat 6
  wait(500);
  lights(1, 0, 0, 0, 0, 0); // beat 7
  wait(500);
  lights(1, 0, 0, 0, 0, 1); // beat 8
  wait(500);
  lights(1, 0, 0, 0, 1, 0); // beat 9
  wait(2000);
  lights(1, 0, 0, 1, 0, 0); // beat 10
  wait(2000);
  crossSound();

  lights(1, 1, 0, 1, 0, 0); // beat 11
  wait(2000);
  lights(0, 0, 1, 1, 0, 0); // beat 12
  wait(3000);
  lights(0, 0, 0, 1, 0, 0); // beat 13
  wait(500);
  lights(0, 0, 1, 1, 0, 0); // beat 14
  wait(500);
  lights(0, 0, 0, 1, 0, 0); // beat 15
  wait(500);
  lights(0, 0, 1, 1, 0, 0); // beat 16
  wait(500);
  lights(0, 0, 0, 1, 0, 0); // beat 17
  wait(500);
  lights(0, 0, 1, 1, 0, 0); // beat 18
  wait(500);
  lights(0, 1, 0, 1, 0, 0); // beat 19
  wait(2000);
  lights(1, 0, 0, 1, 0, 0); // beat 20
  wait(2000);
  crossSound();
}