const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;

// Notas de "Brilha, brilha, estrelinha" (vibrações por segundo)
const int notas[] = {
  523, 523, 784, 784, 880, 880, 784,
  698, 698, 659, 659, 587, 587, 523
};
// Duração de cada nota, em milissegundos
const int tempos[] = {
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800
};
const int totalDeNotas = 14;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
}

void loop() {
  for (int i = 0; i < totalDeNotas; i++) {
    digitalWrite(olhoEsquerdo, HIGH);
    digitalWrite(olhoDireito, HIGH);
    tone(boca, notas[i], tempos[i]);
    delay(tempos[i]);
    digitalWrite(olhoEsquerdo, LOW);
    digitalWrite(olhoDireito, LOW);
    delay(60);
  }
  delay(2000);
}
