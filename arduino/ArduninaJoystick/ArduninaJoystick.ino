#include <Servo.h>

const int eixoX = A1;
const int eixoY = A0;
const int botao = 2;
const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
  pinMode(botao, INPUT_PULLUP);   // apertado = LOW
  pescoco.attach(pinoPescoco);
}

void loop() {
  // Pescoço no eixo X
  int x = analogRead(eixoX);
  pescoco.write(map(x, 0, 1023, 0, 180));

  // Olhos no eixo Y (centro fica perto de 512)
  int y = analogRead(eixoY);
  digitalWrite(olhoEsquerdo, y < 300 ? HIGH : LOW);
  digitalWrite(olhoDireito,  y > 700 ? HIGH : LOW);

  // Buzzer no botão do joystick
  if (digitalRead(botao) == LOW) {
    tone(boca, 660);
  } else {
    noTone(boca);
  }

  delay(15);
}
