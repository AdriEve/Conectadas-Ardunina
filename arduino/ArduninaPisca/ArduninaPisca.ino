const int olhoEsquerdo = 4;
const int olhoDireito = 7;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  digitalWrite(olhoEsquerdo, HIGH);
  digitalWrite(olhoDireito, HIGH);
}

void loop() {
  delay(2000);
  digitalWrite(olhoEsquerdo, LOW);
  delay(250);
  digitalWrite(olhoEsquerdo, HIGH);
  delay(2000);
  digitalWrite(olhoDireito, LOW);
  delay(250);
  digitalWrite(olhoDireito, HIGH);
}
