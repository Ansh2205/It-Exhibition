const int relay = 14;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);

  Serial.begin(9600);

  digitalWrite(relay, LOW);
  delay(1000);
  Serial.println("dhgiushdv");
  digitalWrite(relay, HIGH);
  delay(5000);
  Serial.println("ushdv");

  digitalWrite(relay, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

}
