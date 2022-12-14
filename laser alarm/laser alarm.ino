#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "Lappy";
const char* pass = "ansh2205";

const int ldr = 12;
const int buz = 14;

void setup() {
  pinMode(ldr, INPUT);
  pinMode(buz, OUTPUT);

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
  int data = digitalRead(ldr);
  Serial.println(data);

  if (data == 0) {
    // tone(buz, 1000, 500);

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      WiFiClient client;

      http.begin(client, "http://10.10.101.157:5999/door-intruder");
      int resCode = http.GET();

      http.end();
    }
  delay(500);
  }
}