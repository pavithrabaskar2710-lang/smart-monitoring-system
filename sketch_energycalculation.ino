int zero = 511;

float energy = 0;

unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
  lastTime = millis();
}

void loop() {

  long sum = 0;

  for (int i = 0; i < 100; i++) {
    sum += analogRead(A0);
  }

  float avg = sum / 100.0;

  float voltageSensor = (avg - zero) * (5.0 / 1023.0);

  float current = voltageSensor / 0.185;

  float voltage = 9.0;

  float power = voltage * current;

  // Time calculation
  unsigned long currentTime = millis();

  float timeHours = (currentTime - lastTime) / 3600000.0;

  lastTime = currentTime;

  // Energy calculation
  energy += power * timeHours;

  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" W");

  Serial.print("Energy: ");
  Serial.print(energy);
  Serial.println(" Wh");

  Serial.println("----------------");

  delay(1000);
}
