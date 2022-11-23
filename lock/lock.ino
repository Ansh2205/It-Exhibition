#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "vivo2015";
const char* pass = "ansh2205";

const int relay = 12;


const String url = "http://192.168.137.1:5999/ai";

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);

  Serial.begin(9600);



  WiFi.begin(ssid, pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected!");



  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED) {
    // Serial.println("hdgshdf");
    HTTPClient http;
    WiFiClient client;

    http.begin(client, url);
    int resCode = http.GET();

    if (resCode) {
    digitalWrite(relay, HIGH);
  delay(1000);
  Serial.println("dhgiushdv");
  digitalWrite(relay, LOW);
  delay(3000);
  Serial.println("ushdv");

  digitalWrite(relay, HIGH);

    }

    http.end();
  }
}
