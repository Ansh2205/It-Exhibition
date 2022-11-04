#include <Servo.h>
Servo mot;

void setup() {
  // put your setup code here, to run once:
  pinMode(14, OUTPUT);
  mot.attach(14);
  delay(10);

  mot.write(15);
  delay(2000);
  mot.write(165);
  delay(2000);
  mot.write(15);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
