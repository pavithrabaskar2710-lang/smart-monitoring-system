const int sensorPin = A0;
const int ledPin = 13;

float zero = 511.0;      // ACS712 zero value
float supplyVoltage = 9.0;

float overloadLimit = 1.4;   // overload power limit in watts

void setup()
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop()
{
  long sum = 0;

  // Average 100 readings
  for(int i = 0; i < 100; i++)
  {
    sum += analogRead(sensorPin);
  }

  float avg = sum / 100.0;

  // Convert analog value to sensor voltage
  float sensorVoltage = (avg - zero) * (5.0 / 1023.0);

  // Convert voltage to current
  float current = sensorVoltage / 0.185;

  // Remove negative noise
  if(current < 0)
  {
    current = -current;
  }

  // Power calculation
  float power = supplyVoltage * current;

  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A   ");

  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" W");

  // Overload condition
  if(power > overloadLimit)
  {
    Serial.println("OVERLOAD DETECTED");
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    Serial.println("SYSTEM NORMAL");
    digitalWrite(ledPin, LOW);
  }

  Serial.println("-------------------");

  delay(1000);
}