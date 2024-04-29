long currentTIME;
long check1TIME;
long check2TIME;
long check3TIME;

/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

void setup() {
  Serial.begin(115200);
  check1TIME = millis();
  check2TIME = millis();
  check3TIME = millis();
  pinMode(D1, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  pinMode(D2, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  pinMode(D3, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  currentTIME = millis();
  if ((currentTIME-check1TIME) > 2000) {
    Serial.println(currentTIME);
    Serial.println("**********");
    check1TIME = currentTIME;
  }

  if ((currentTIME-check2TIME) > 3000) {
    Serial.println(currentTIME);
    Serial.println("==========");
    check2TIME = currentTIME;
  }
  if ((currentTIME-check3TIME) > 5000) {
    Serial.println(currentTIME);
    Serial.println("1111111111");
    check3TIME = currentTIME;
  }

  digitalWrite(D1, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(3000); 
  digitalWrite(D2, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);   
    digitalWrite(D2, LOW);  // Turn the LED off by making the voltage HIGH
    delay(1000); 
    digitalWrite(D2, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);                   // Wait for two seconds (to demonstrate the active low LED)
  digitalWrite(D3, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(3000);  
                      // Wait for two seconds (to demonstrate the active low LED)
  
  digitalWrite(D1, LOW);  // Turn the LED off by making the voltage HIGH
  delay(1000); 
  digitalWrite(D2, LOW);  // Turn the LED off by making the voltage HIGH
  delay(1000);                      // Wait for two seconds (to demonstrate the active low LED)
  digitalWrite(D3, LOW);  // Turn the LED off by making the voltage HIGH
  delay(1000);  

  digitalWrite(D1, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(3000); 
  digitalWrite(D2, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);   
    digitalWrite(D2, LOW);  // Turn the LED off by making the voltage HIGH
    delay(1000); 
    digitalWrite(D2, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);                   // Wait for two seconds (to demonstrate the active low LED)
  digitalWrite(D3, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(3000);  
}
