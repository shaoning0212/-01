#include <ESP8266WiFi.h>
const char* ssid     ="K106";
const char* password ="KK106666";
IPAddress local_IP(192,168,50,31);
IPAddress subnet(255,255,255,0);
IPAddress gateway(192,168,50,1);
IPAddress primaryDNS(192,168,50,1);
IPAddress secondaryDNS(8,8,4,4);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  if (!WiFi.config(local_IP, gateway,subnet,primaryDNS,secondaryDNS)) {
    Serial.println("STA Failed to configure");
}
  Serial.println();
  Serial.println(WiFi.macAddress());
}


