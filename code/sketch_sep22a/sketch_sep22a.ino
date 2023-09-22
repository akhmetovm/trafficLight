int buttonPin = 2;
int trafficLight1G = 3;
int trafficLight1Y = 4;
int trafficLight1R = 5;
int trafficLight2G = 6;
int trafficLight2Y = 7;
int trafficLight2R = 8;

int speakerPin = 9;
bool buttonOn = false;
bool buttonOnPrev = false;

int beats[] = { 2.0, 3.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 2.0, 2.0,
                2.0, 3.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 2.0, 2.0  
};

void setup() {
	pinMode(buttonPin, INPUT);
	pinMode(trafficLight1G, OUTPUT);
	pinMode(trafficLight1Y, OUTPUT);
	pinMode(trafficLight1R, OUTPUT);
	pinMode(trafficLight2G, OUTPUT);
	pinMode(trafficLight2Y, OUTPUT);
	pinMode(trafficLight2R, OUTPUT);
	pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

bool buttonReadOnce() {
  buttonOn = digitalRead(buttonPin);
  bool retVal = false;
	if (buttonOn & !buttonOnPrev) {
    retVal = true;
  }
  else{
    retVal = false;
  }
  buttonOnPrev = buttonOn;
  return retVal;
}

void loop() {
  if (buttonReadOnce()) {  
    tone(speakerPin, 880); // генерируем звук с частотой 100 Гц
    digitalWrite(trafficLight1G, 1);
    digitalWrite(trafficLight2G, 1);
    delay(100); // пауза 100 миллисекунд
  }
  else {
    digitalWrite(trafficLight1G, 0);
    digitalWrite(trafficLight2G, 0);
    noTone(speakerPin); // выключаем звук
  }

  Serial.println(buttonReadOnce());
}
