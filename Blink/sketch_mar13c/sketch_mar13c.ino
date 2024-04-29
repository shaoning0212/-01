long currentTIME;
long check1TIME;
long check2TIME;
bool check1LIGHTON = false;
bool check2LIGHTON = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  check1TIME = millis();
  check2TIME = millis();
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTIME = millis();
  if (check1LIGHTON == true) {
    if((currentTIME-check1TIME)>2000){
      digitalWrite(D1,LOW);
      check1TIME = currentTIME;
      check1LIGHTON = false;
    }
  } else if(check1LIGHTON == false){
    if((currentTIME-check1TIME)>3000) {
      digitalWrite(D1,HIGH);
      check1TIME = currentTIME;
      check1LIGHTON = true;
    }
  }
   currentTIME = millis();
  if (check2LIGHTON == true) {
    if((currentTIME-check2TIME)>5000){
      digitalWrite(D2,LOW);
      check2TIME = currentTIME;
      check2LIGHTON = false;
    }
  } else if(check2LIGHTON == false){
    if((currentTIME-check2TIME)>6000) {
      digitalWrite(D2,HIGH);
      check2TIME = currentTIME;
      check2LIGHTON = true;    }
  }
}
