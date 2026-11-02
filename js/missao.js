"use strict";
const missaoId = document.body.dataset.missao;
const missao = MISSOES[missaoId];
const comErro = missao.correto.replace(missao.trecho, missao.trechoErrado);
const editor = document.getElementById("editor");
const feedback = document.getElementById("feedback");
const finish = document.getElementById("finish");
const score = document.getElementById("score");
const copyStatus = document.getElementById("copyStatus");
const hintsButton = document.getElementById("hints");
// Comparação didática: ignora espaços e comentários de uma linha; não compila C++.
const normalize = (code) =>
  code.replace(/\/\/[^\n]*/g, "").replace(/\s+/g, "");
const corrigido = () => normalize(editor.value) === normalize(missao.correto);
function update({ announce = false } = {}) {
  const success = corrigido();
  score.textContent = success ? "Erro corrigido" : "1 erro para corrigir";
  finish.classList.toggle("active", success);
  if (success) concluirMissao(missaoId);
  if (announce) {
    if (success) {
      feedback.className = "success";
      feedback.innerHTML =
        "<strong>Parabéns!</strong> Você encontrou o erro. Agora teste o código na Arduino IDE e na robô real!";
    } else if (editor.value.includes(missao.trechoErrado)) {
      feedback.className = "warning";
      feedback.textContent =
        "O erro ainda está no código. Continue procurando! Se precisar, abra a dica.";
    } else {
      feedback.className = "warning";
      feedback.textContent =
        "O código ainda não está certo. Confira se alterou outra parte sem querer ou use “Recomeçar”.";
    }
  } else if (!success && finish.dataset.wasActive === "true") {
    feedback.className = "";
    feedback.textContent =
      "O código mudou. Verifique novamente para concluir a missão.";
  }
  finish.dataset.wasActive = success ? "true" : "false";
}
editor.value = comErro;
editor.addEventListener("input", () => update());
document
  .getElementById("verify")
  .addEventListener("click", () => update({ announce: true }));
document.getElementById("reset").addEventListener("click", () => {
  editor.value = comErro;
  feedback.className = "";
  feedback.textContent = "Sua missão recomeçou. Encontre o erro!";
  copyStatus.textContent = "";
  update();
  editor.focus();
});
hintsButton.addEventListener("click", () => {
  const hints = document.getElementById("hintBox");
  hints.hidden = !hints.hidden;
  hintsButton.textContent = hints.hidden ? "Ver dica" : "✕ Ocultar dica";
  hintsButton.setAttribute("aria-expanded", String(!hints.hidden));
});
document.getElementById("copy").addEventListener("click", () => {
  if (corrigido()) copiarCodigo(missao.correto, copyStatus);
});
document.getElementById("download").addEventListener("click", () => {
  if (corrigido()) baixarCodigo(missao.correto, missao.arquivo, copyStatus);
});
update();
