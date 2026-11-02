"use strict";
const ORDEM_MISSOES = [
  { id: "visao", check: "check1" },
  { id: "voz", check: "check2" },
  { id: "movimento", check: "check3" },
];
const copyStatus = document.getElementById("copyStatus");
function update() {
  const concluidas = missoesConcluidas();
  let total = 0;
  ORDEM_MISSOES.forEach(({ id, check }, idx) => {
    const ok = concluidas.includes(id);
    if (ok) total += 1;
    const el = document.getElementById(check);
    el.classList.toggle("good", ok);
    el.querySelector(".check-icon").textContent = ok ? "✓" : String(idx + 1);
  });
  const success = total === ORDEM_MISSOES.length;
  document.getElementById("score").textContent =
    `${total} de ${ORDEM_MISSOES.length} concluídas`;
  document.getElementById("finish").classList.toggle("active", success);
  const robot = document.getElementById("robot");
  robot.classList.toggle("awake", success);
  robot.setAttribute(
    "aria-label",
    success
      ? "Ilustração animada da Ardunina comemorando as missões concluídas"
      : "Ilustração da Ardunina rosa aguardando o código corrigido",
  );
}
document.getElementById("copy").addEventListener("click", () => {
  copiarCodigo(CODIGO_COMPLETO, copyStatus);
});
document.getElementById("download").addEventListener("click", () => {
  baixarCodigo(CODIGO_COMPLETO, "Ardunina.ino", copyStatus);
});
document.getElementById("reset").addEventListener("click", () => {
  recomecarMissoes();
  copyStatus.textContent = "";
  update();
});
// Atualiza também ao voltar de uma missão pelo botão do navegador.
window.addEventListener("pageshow", update);
