#include <Servo.h>

const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pescoco.attach(pinoPescoco);
  pescoco.write(90);
}

void loop() {
  digitalWrite(olhoEsquerdo, HIGH);
  digitalWrite(olhoDireito, LOW);
  pescoco.write(70);
  delay(400);
  digitalWrite(olhoEsquerdo, LOW);
  digitalWrite(olhoDireito, HIGH);
  pescoco.write(110);
  delay(400);
}
