#include <Servo.h>

const int sensorTemp = A3;
const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  Serial.begin(9600);
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
  pescoco.attach(pinoPescoco);
}

void loop() {
  int leitura = analogRead(sensorTemp);
  float temperatura = leitura * 0.49;
  Serial.println(temperatura);
  if (temperatura > 30) {
    digitalWrite(olhoEsquerdo, HIGH);
    digitalWrite(olhoDireito, HIGH);
    tone(boca, 880, 200);
    pescoco.write(60);
    delay(300);
    pescoco.write(120);
  } else {
    digitalWrite(olhoEsquerdo, LOW);
    digitalWrite(olhoDireito, LOW);
    pescoco.write(90);
  }
  delay(1000);
}
