const int sensorTemp = A3;
const int boca = 9;

void setup() {
  Serial.begin(9600);
  pinMode(boca, OUTPUT);
}

void loop() {
  int leitura = analogRead(sensorTemp);
  float temperatura = leitura * 0.49;
  Serial.println(temperatura);
  if (temperatura > 30) {
    tone(boca, 880, 200);
  }
  delay(1000);
}
