#include <Servo.h>

const int trig = 8;
const int echo = 12;
const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
  pescoco.attach(pinoPescoco);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long tempo = pulseIn(echo, HIGH);
  int distancia = tempo * 0.034 / 2;
  if (distancia < 15) {
    digitalWrite(olhoEsquerdo, HIGH);
    digitalWrite(olhoDireito, HIGH);
    tone(boca, 880, 100);
    pescoco.write(130);
  } else {
    digitalWrite(olhoEsquerdo, LOW);
    digitalWrite(olhoDireito, LOW);
    pescoco.write(90);
  }
  delay(200);
}
