#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// const char* ssid = "AADITYA";
// const char* pass = "aaditya1515";

const int gas = A0;
const int fan = 14;
const int buz = 12;
const String url = "http://192.168.137.1:5999/smoke";

void setup() {
  pinMode(gas, INPUT);
  pinMode(fan, OUTPUT);
  pinMode(buz, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("HI from 8266");

  // WiFi.begin(ssid, pass);

  // Serial.print("Connecting");
  // while (WiFi.status() != WL_CONNECTED) {
  //   Serial.print(".");
  //   delay(1000);
  // }
  // Serial.println("Connected!");
}

void loop() {
  int data = analogRead(gas);
  Serial.println(data);

  if (data < 500) {
    Serial.println("GOOD");
  } else if (data < 650) {
    Serial.println("BAD");
    digitalWrite(fan, HIGH);
    digitalWrite(buz, HIGH);
    delay(4000);
    digitalWrite(fan, LOW);
    digitalWrite(buz, LOW);


    // if (WiFi.status() == WL_CONNECTED) {
    //   // Serial.println("hdgshdf");
    //   HTTPClient http;
    //   WiFiClient client;

    //   http.begin(client, url);
    //   int resCode = http.GET();

    //   http.end();
    // }
  } else {
    Serial.println("VERY BAD");
    digitalWrite(fan, HIGH);
    digitalWrite(buz, HIGH);
    delay(4000);
    digitalWrite(fan, LOW);
    digitalWrite(buz, LOW);

    // if (WiFi.status() == WL_CONNECTED) {
    //   // Serial.println("hdgshdf");
    //   HTTPClient http;
    //   WiFiClient client;

    //   http.begin(client, url);
    //   int resCode = http.GET();

    //   http.end();
    // }
  }

  Serial.println("\n");
  delay(750);
}
