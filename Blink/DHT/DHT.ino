#include <DHT11.h>

#include <SimpleDHT.h> //form GitHub SimpleDHT, KEYES OK
 int pinDHT11 = D1; //GPIO2或D4 of ESP8266,不是ADC0
 SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200);}

// the loop function runs over and over again forever
void loop() {
 byte temperature = 0;
 byte humidity = 0;
 int err = SimpleDHTErrSuccess;
 if((err = dht11.read(&temperature, &humidity, NULL )) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed,err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return; }
  Serial.print("Sample OK:");
  Serial.print((int)temperature); 
  Serial.print("*C,");
  Serial.print((int)humidity); 
  Serial.println(" H");
  delay(2000);
}
