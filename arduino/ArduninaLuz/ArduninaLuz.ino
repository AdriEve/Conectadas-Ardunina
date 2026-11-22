#include <Servo.h>

const int sensorLuz = A0;
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
  int luz = analogRead(sensorLuz);
  if (luz < 300) {
    digitalWrite(olhoEsquerdo, HIGH);
    digitalWrite(olhoDireito, HIGH);
    tone(boca, 523, 100);
    pescoco.write(110);
  } else {
    digitalWrite(olhoEsquerdo, LOW);
    digitalWrite(olhoDireito, LOW);
    pescoco.write(70);
  }
  delay(500);
}
