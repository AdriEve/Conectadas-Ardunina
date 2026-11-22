const int sensorLuz = A0;
const int olhoEsquerdo = 4;
const int olhoDireito = 7;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
}

void loop() {
  int luz = analogRead(sensorLuz);
  if (luz < 300) {
    digitalWrite(olhoEsquerdo, HIGH);
    digitalWrite(olhoDireito, HIGH);
  } else {
    digitalWrite(olhoEsquerdo, LOW);
    digitalWrite(olhoDireito, LOW);
  }
}
