const int gas = A0;
const int fan = 14;

void setup() {
  pinMode(gas, INPUT);
  pinMode(fan, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("HI from 8266");
}

void loop() {
  int data = analogRead(gas);
  Serial.println(data);

  if (data < 500) {
    Serial.println("GOOD");
  } else if (data < 650) {
    Serial.println("BAD");
    digitalWrite(fan, HIGH);
    delay(4000);
    digitalWrite(fan, LOW);
  } else {
    Serial.println("VERY BAD");
    digitalWrite(fan, HIGH);
    delay(4000);
    digitalWrite(fan, LOW);
  }

  Serial.println("\n");
  delay(750);
}
