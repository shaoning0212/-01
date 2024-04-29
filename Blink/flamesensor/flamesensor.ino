int isFlamePin = D4;
int isFlame = HIGH;
int meterFlamePin = A0;
int meterFlame = 0;
bool change = true;



void setup() {
 pinMode(isFlamePin, INPUT);
 Serial.begin(115200);
}

void loop() {
  isFlame = digitalRead(isFlamePin);
  meterFlame = analogRead(meterFlamePin);
  if (isFlame== LOW){Serial.println("FLAME, FLAME, FLAME");}
  else {Serial.println("no flame");}
  Serial.println(meterFlame);
    if(change) {Serial.println("++++++");}
  else{Serial.println("------");}
change = not change;
delay(500);}
