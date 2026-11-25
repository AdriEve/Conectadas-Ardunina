#include <Servo.h>

const int sensorPresenca = 3;
const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;
bool tinhaAlguem = false;

void olhos(int estado) {
  digitalWrite(olhoEsquerdo, estado);
  digitalWrite(olhoDireito, estado);
}

// Move o pescoço suavemente de um ângulo até outro
void moverPescoco(int de, int ate) {
  int passo = (ate > de) ? 1 : -1;
  for (int a = de; a != ate; a += passo) {
    pescoco.write(a);
    delay(8);            // menor = mais rápido
  }
  pescoco.write(ate);
}

void setup() {
  Serial.begin(9600);
  pinMode(sensorPresenca, INPUT);
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pinMode(boca, OUTPUT);
  pescoco.attach(pinoPescoco);
  pescoco.write(90);

  Serial.println("Calibrando o sensor... aguarde 30 segundos");
  delay(30000);
  Serial.println("Pronto!");
}

void loop() {
  bool temAlguem = digitalRead(sensorPresenca) == HIGH;

  if (temAlguem) {
    Serial.println("Sensor: TEM GENTE");

    if (!tinhaAlguem) {
      tone(boca, 1047, 150);   // apita só quando a pessoa chega
    }
    olhos(HIGH);

    // Balança a cabeça enquanto tiver alguém
    moverPescoco(90, 130);
    moverPescoco(130, 50);
    moverPescoco(50, 90);
  } else {
    Serial.println("Sensor: ninguem");
    olhos(LOW);
    pescoco.write(90);
    delay(200);
  }

  tinhaAlguem = temAlguem;
}
