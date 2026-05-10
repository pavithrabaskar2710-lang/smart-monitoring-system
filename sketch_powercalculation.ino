int zero = 511;

void setup() {
  Serial.begin(9600);
}

void loop() {

  long sum = 0;

  for(int i = 0; i < 100; i++) {
    sum += analogRead(A0);
  }

  float avg = sum / 100.0;

  float voltageSensor = (avg - zero) * (5.0 / 1023.0);

  float current = voltageSensor / 0.185;

  float voltage = 9.0;   // assumed AC voltage

  float power = voltage * current;

  Serial.print("Current: ");
  Serial.print(current);

  Serial.print(" A   ");

  Serial.print("Power: ");
  Serial.print(power);

  Serial.println(" W");

  delay(1000);
}
