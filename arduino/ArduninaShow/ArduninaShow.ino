#include <Servo.h>

const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

// Melodia de videogame criada para a Ardunina (0 = pausa)
const int notas[] = {
  659, 784, 1047, 784, 659, 587,
  698, 880, 1175, 880, 698, 659,
  587, 659, 698, 784, 880, 988, 1047, 0
};
// Duração de cada nota, em milissegundos
const int tempos[] = {
  150, 150, 300, 150, 150, 300,
  150, 150, 300, 150, 150, 300,
  150, 150, 150, 150, 150, 150, 450, 300
};
const int totalDeNotas = 20;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
  pescoco.attach(pinoPescoco);
  pescoco.write(90);
}

void loop() {
  for (int i = 0; i < totalDeNotas; i++) {
    if (i % 2 == 0) {
      digitalWrite(olhoEsquerdo, HIGH);
      digitalWrite(olhoDireito, LOW);
      pescoco.write(70);
    } else {
      digitalWrite(olhoEsquerdo, LOW);
      digitalWrite(olhoDireito, HIGH);
      pescoco.write(110);
    }
    if (notas[i] > 0) {
      tone(boca, notas[i], tempos[i] - 20);
    }
    delay(tempos[i]);
  }
  digitalWrite(olhoEsquerdo, HIGH);
  digitalWrite(olhoDireito, HIGH);
  pescoco.write(90);
  delay(1500);
}
