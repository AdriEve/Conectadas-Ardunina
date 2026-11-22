#include <Servo.h>

const int eixoX = A1;
const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
  pescoco.attach(pinoPescoco);
}

void loop() {
  int x = analogRead(eixoX);
  int angulo = map(x, 0, 1023, 0, 180);
  pescoco.write(angulo);
  if (angulo < 45) {
    digitalWrite(olhoEsquerdo, HIGH);
    tone(boca, 440, 50);
  } else {
    digitalWrite(olhoEsquerdo, LOW);
  }
  if (angulo > 135) {
    digitalWrite(olhoDireito, HIGH);
    tone(boca, 880, 50);
  } else {
    digitalWrite(olhoDireito, LOW);
  }
  delay(15);
}
