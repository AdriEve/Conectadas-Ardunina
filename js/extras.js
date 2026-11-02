"use strict";
document.querySelectorAll("[data-arquivo]").forEach((cartao) => {
  const codigo = cartao.querySelector("pre").textContent.trim();
  const arquivo = cartao.dataset.arquivo;
  const status = cartao.querySelector("[role=status]");
  cartao
    .querySelector(".copiar")
    .addEventListener("click", () => copiarCodigo(codigo, status));
  cartao
    .querySelector(".baixar")
    .addEventListener("click", () => baixarCodigo(codigo, arquivo, status));
});
