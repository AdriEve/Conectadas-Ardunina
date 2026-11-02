"use strict";
const MISSOES = {
  visao: {
    arquivo: "ArduninaVisao.ino",
    correto: `const int olhoEsquerdo = 4;
const int olhoDireito = 7;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  digitalWrite(olhoEsquerdo, HIGH);
  digitalWrite(olhoDireito, HIGH);
}

void loop() {
}`,
    trecho: "pinMode(olhoEsquerdo, OUTPUT);",
    trechoErrado: "pinMode(olhoEsquerdo, OUTPUT)",
  },
  voz: {
    arquivo: "ArduninaVoz.ino",
    correto: `const int boca = 9;

void setup() {
  pinMode(boca, OUTPUT);
}

void loop() {
  tone(boca, 880, 180);
  delay(1000);
}`,
    trecho: "tone(boca, 880, 180);",
    trechoErrado: "tone(bocaa, 880, 180);",
  },
  movimento: {
    arquivo: "ArduninaMovimento.ino",
    correto: `#include <Servo.h>

const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pescoco.attach(pinoPescoco);
  pescoco.write(90);
}

void loop() {
  pescoco.write(75);
  delay(650);
  pescoco.write(105);
  delay(650);
}`,
    trecho: "pescoco.write(105);",
    trechoErrado: "pescoco.writ(105);",
  },
};
const CODIGO_COMPLETO = `#include <Servo.h>

const int olhoEsquerdo = 4;
const int olhoDireito = 7;
const int boca = 9;
const int pinoPescoco = 11;

Servo pescoco;

void setup() {
  pinMode(olhoEsquerdo, OUTPUT);
  pinMode(olhoDireito, OUTPUT);
  pescoco.attach(pinoPescoco);
  pescoco.write(90);
}

void loop() {
  digitalWrite(olhoEsquerdo, HIGH);
  digitalWrite(olhoDireito, HIGH);
  tone(boca, 880, 180);
  pescoco.write(75);
  delay(650);
  pescoco.write(105);
  delay(650);
  digitalWrite(olhoEsquerdo, LOW);
  digitalWrite(olhoDireito, LOW);
  delay(450);
}`;
const CHAVE_PROGRESSO = "ardunina-missoes-concluidas";
function missoesConcluidas() {
  try {
    return JSON.parse(localStorage.getItem(CHAVE_PROGRESSO)) || [];
  } catch (e) {
    return [];
  }
}
function concluirMissao(id) {
  const concluidas = missoesConcluidas();
  if (concluidas.includes(id)) return;
  try {
    localStorage.setItem(
      CHAVE_PROGRESSO,
      JSON.stringify([...concluidas, id]),
    );
  } catch (e) {
    // Sem armazenamento: a missão funciona, só não fica registrada na página inicial.
  }
}
function recomecarMissoes() {
  try {
    localStorage.removeItem(CHAVE_PROGRESSO);
  } catch (e) {
    // Sem armazenamento: não há progresso guardado para apagar.
  }
}
async function copiarCodigo(codigo, status) {
  try {
    try {
      await navigator.clipboard.writeText(codigo);
    } catch (e) {
      const temp = document.createElement("textarea");
      temp.value = codigo;
      temp.style.position = "fixed";
      temp.style.opacity = "0";
      document.body.appendChild(temp);
      temp.select();
      const copiou = document.execCommand("copy");
      temp.remove();
      if (!copiou) throw new Error("Sem permissão para copiar");
    }
    status.textContent = "✓ Código copiado! Agora cole na Arduino IDE.";
  } catch (e) {
    status.textContent =
      "Não foi possível copiar automaticamente neste navegador. Use o botão “Baixar código .ino”.";
  }
}
function baixarCodigo(codigo, arquivo, status) {
  const blob = new Blob([codigo + "\n"], {
    type: "text/plain;charset=utf-8",
  });
  const a = document.createElement("a");
  const url = URL.createObjectURL(blob);
  a.href = url;
  a.download = arquivo;
  document.body.appendChild(a);
  a.click();
  a.remove();
  setTimeout(() => URL.revokeObjectURL(url), 1000);
  status.textContent = `✓ Arquivo ${arquivo} preparado para abrir na Arduino IDE.`;
}
