#include <Servo.h>
Servo mot;

const int trig = 9;
const int echo = A0;
const int servo = 10;
const int pump = 8;

long duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(servo, OUTPUT);
  pinMode(pump, OUTPUT);
  mot.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 14.14) {
    mot.write(165);
    delay(1000);

    mot.write(15);
    delay(2000);

    mot.write(165);
    delay(1500);

    digitalWrite(pump, HIGH);
    delay(3000);
    digitalWrite(pump, LOW);
  }

  delay(5);

  Serial.println(distance);
}


