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

int beats[] = { 2000, 3000, 500, 500, 500, 500, 500, 500, 2000, 2000,
                2000, 3000, 500, 500, 500, 500, 500, 500, 2000, 2000  
};
bool lightMatrix[][6] = { 
  //1RED, 1YELLOW, 1GREEN, 2RED, 2YELLOW, 2GREEN
  {1, 0, 0, 1, 1, 0}, // beat 1
  {1, 0, 0, 0, 0, 1}, // beat 2
  {1, 0, 0, 0, 0, 0}, // beat 3
  {1, 0, 0, 0, 0, 1}, // beat 4
  {1, 0, 0, 0, 0, 0}, // beat 5
  {1, 0, 0, 0, 0, 1}, // beat 6
  {1, 0, 0, 0, 0, 0}, // beat 7
  {1, 0, 0, 0, 0, 1}, // beat 8
  {1, 0, 0, 0, 1, 0}, // beat 9
  {1, 0, 0, 1, 0, 0}, // beat 10
  {1, 1, 0, 1, 0, 0}, // beat 11
  {0, 0, 1, 1, 0, 0}, // beat 12
  {0, 0, 0, 1, 0, 0}, // beat 13
  {0, 0, 1, 1, 0, 0}, // beat 14
  {0, 0, 0, 1, 0, 0}, // beat 15
  {0, 0, 1, 1, 0, 0}, // beat 16
  {0, 0, 0, 1, 0, 0}, // beat 17
  {0, 0, 1, 1, 0, 0}, // beat 18
  {0, 1, 0, 1, 0, 0}, // beat 19
  {1, 0, 0, 1, 0, 0}, // beat 20
};

int beatsCount = 20;

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

void trafficLightSwitcher(bool sw[]) {
  digitalWrite(trafficLight1R, 0);
  digitalWrite(trafficLight1Y, 0);
  digitalWrite(trafficLight1G, 0);
  digitalWrite(trafficLight2R, 0);
  digitalWrite(trafficLight2Y, 0);
  digitalWrite(trafficLight2G, 0);
  digitalWrite(trafficLight1R, sw[0]);
  digitalWrite(trafficLight1Y, sw[1]);
  digitalWrite(trafficLight1G, sw[2]);
  digitalWrite(trafficLight2R, sw[3]);
  digitalWrite(trafficLight2Y, sw[4]);
  digitalWrite(trafficLight2G, sw[5]);
}

void loop() {
  int pedestrainDelay = 0;
  for (int i = 0; i < beatsCount; i++)
  {
    trafficLightSwitcher(lightMatrix[i]);

    int delayOnBeat = beats[i];
    if  ((i == 9 || i == 19)) {
      delayOnBeat = pedestrainDelay;
      //tone(speakerPin, 800);
    }
    Serial.println("Beat number: ");
    Serial.println(i);
    Serial.println("Waiting: ");
    Serial.println(delayOnBeat);
    for (int j = 0; j <= delayOnBeat; j = j + 10) {
      if  (buttonReadOnce()) { 
        pedestrainDelay = 5000;
      }
      delay(10);
    }
    noTone(speakerPin);
  }
}
