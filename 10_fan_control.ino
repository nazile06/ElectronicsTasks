int tempPin = A0;
int relayPin = 9;

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(tempPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 100;

  Serial.print("Temperatur: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  if (temperatureC > 30) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Fan: ISLEYIR");
  } else {
    digitalWrite(relayPin, LOW);
    Serial.println("Fan: DAYANIB");
  }

  Serial.println("------------------");
  delay(1000);
}