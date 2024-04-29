#include <ESP8266WiFi.h>


void setup()
{
	Serial.begin(115200);

	WiFi.begin("K106","KK106666");
	Serial.println("");
	Serial.print("Connecting");
	while (WiFi.status() !=WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	//DHCP動態取得
	Serial.println("Connected !");
	Serial.print("MAC address:"); 
  Serial.println(WiFi.macAddress());
	Serial.print("IP address:"); 
  Serial.println(WiFi.localIP());
	Serial.print("ISubnetMask:"); 
  Serial.println(WiFi.subnetMask());
	Serial.print("Gateway IP:"); 
  Serial.println(WiFi.gatewayIP());
	Serial.print("PrimaryDNS:"); 
  Serial.println(WiFi.dnsIP());
}

void loop(){}
