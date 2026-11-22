#include <Servo.h>

const int sensorPresenca = 2;
const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pinMode(sensorPresenca, INPUT);
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
  pescoco.attach(pinoPescoco);
}

void loop() {
  int presenca = digitalRead(sensorPresenca);
  if (presenca == HIGH) {
    digitalWrite(olhoEsquerdo, HIGH);
    digitalWrite(olhoDireito, HIGH);
    tone(boca, 1047, 150);
    pescoco.write(120);
  } else {
    digitalWrite(olhoEsquerdo, LOW);
    digitalWrite(olhoDireito, LOW);
    pescoco.write(90);
  }
  delay(300);
}
