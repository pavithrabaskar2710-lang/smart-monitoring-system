const int sensorPin = A0;
const int ledPin = 13;
const int relayPin = 8;

float zero = 503.5;          // ACS712 zero value
float supplyVoltage = 9.0;   // Battery voltage

float overloadLimit = 0.5;   // Change if needed

void setup()
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  // Normal condition: relay allows load
  digitalWrite(relayPin, LOW);
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

  // Convert ADC value to sensor voltage
  float sensorVoltage = (avg - zero) * (5.0 / 1023.0);

  // Convert voltage to current
  float current = sensorVoltage / 0.185;

  // Remove negative values
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

  // Overload Protection
  if(power > overloadLimit)
  {
    Serial.println("OVERLOAD DETECTED");

    digitalWrite(ledPin, HIGH);    // Warning LED ON
    digitalWrite(relayPin, HIGH);  // Cut load
  }
  else
  {
    Serial.println("SYSTEM NORMAL");

    digitalWrite(ledPin, LOW);     // Warning LED OFF
    digitalWrite(relayPin, LOW);   // Load ON
  }

  Serial.println("-------------------");

  delay(1000);
}