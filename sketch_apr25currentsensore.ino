int zero = 511;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);

  float voltage = (value - zero) * (5.0 / 1023.0);
  float current = voltage / 0.185;

  Serial.print("Current: ");
  Serial.println(current);

  delay(500);
}