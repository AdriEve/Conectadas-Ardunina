#include <Servo.h>

const int vermelho = 5;
const int verde = 6;
const int azul = 3;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(boca, OUTPUT);
  pescoco.attach(pinoPescoco);
}

// LED de ânodo comum: a perna maior vai no 5V
// e cada cor acende com LOW. O ! inverte: 1 vira LOW.
void cor(int r, int g, int b) {
  digitalWrite(vermelho, !r);
  digitalWrite(verde, !g);
  digitalWrite(azul, !b);
}

void loop() {
  cor(1, 0, 0);
  tone(boca, 523, 200);
  pescoco.write(60);
  delay(1000);
  cor(0, 1, 0);
  tone(boca, 659, 200);
  pescoco.write(90);
  delay(1000);
  cor(0, 0, 1);
  tone(boca, 784, 200);
  pescoco.write(120);
  delay(1000);
}
