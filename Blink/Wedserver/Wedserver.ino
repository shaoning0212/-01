#include <ESP8266WiFi.h>
    #include <ESPAsyncTCP.h>
    #include <ESPAsyncWebServer.h>
    
    const char*   ssid ="K106";
    const char*   password ="KK106666";
    AsyncWebServer server(80);
    IPAddress local_IP(192,168,50,17);
    IPAddress subnet(255,255,255,0);
    IPAddress gateway(192,168,50,1);
    IPAddress primaryDNS(192,168,50,1);
    IPAddress secondaryDNS(8,8,4,4);

  #include <SimpleDHT.h> 
  int pinDHT11 = D1; 
  SimpleDHT11 dht11(pinDHT11);\
  String NOWtemperature=" ";
    
    const char index_temperature_html[] PROGMEM = R"rawliteral(
    <!DOCTYPE HTML><html>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
    <head>
      <meta name = "viewport"content = "width=device-width,initial-scale=1">
      <meta charset = "utf-8">
      <meta http-equiv="refresh" content="5">

      <title>資管三A D1104241015洪浩倫</title>

    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
        <div class="container-fluid">
          <a class="navbar-brand" href="#">溫度與濕度</a>
          <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDarkDropdown" aria-controls="navbarNavDarkDropdown" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
          </button>
          <div class="collapse navbar-collapse" id="navbarNavDarkDropdown">
            <ul class="navbar-nav">
              <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" id="navbarDarkDropdownMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                  Dropdown
                </a>
                <ul class="dropdown-menu dropdown-menu-dark" aria-labelledby="navbarDarkDropdownMenuLink">
                  <li><a class="dropdown-item" href="/">溫度</a></li>
                  <li><a class="dropdown-item" href="/features">濕度</a></li>
                </ul>
              </li>
            </ul>
          </div>
        </div>
      </nav>
    </head>
   
    <hr>
      <h1>DHT11溫度即時監測</h1>
      <h2>現在溫度攝氏<span>%TEMPERATURE%</span></h2>
      <hr>
      <p1>版權所有，盜用必究</p1>
      <p>洪浩倫</p>
      <p>龍華科技大學資訊管理學系</p>
    </hr>
    </body>
    </html>
    )rawliteral";

    String processor(const String& var){
      if (var == "TEMPERATURE"){ return NOWtemperature; }
      return String();
    }


  



    void setup() {
      // put your setup code here, to run once:
      Serial.begin(115200);
      WiFi.begin(ssid,password);
      if (!WiFi.config(local_IP, gateway,subnet,primaryDNS,secondaryDNS)) {
      Serial.println("STA Failed to configure");
      }
    
      Serial.println(WiFi.macAddress());
      Serial.println(WiFi.localIP());
      Serial.println(WiFi.subnetMask());
      Serial.println(WiFi.gatewayIP());
      Serial.println(WiFi.dnsIP());
    
      //指定網站首頁及跟目錄ROUTE
      server.on("/temperature",HTTP_GET,[](AsyncWebServerRequest*request){
        request->send_P(200,"text/html",index_temperature_html,processor);
      });

      server.begin();
    }
    
    
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
      NOWtemperature = String(temperature);
      delay(2000);
    }
    