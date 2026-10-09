# Ficha 01 — LDR: ler e calibrar (20 min)

**Objetivo:** descobrir a faixa **real** do sensor de luz na sua bancada.
**Pino:** A1 (LDR)

## Passos

1. *Arquivo → Exemplos → 01.Basics → AnalogReadSerial*.
2. 🔮 **Antes de carregar:** com **mais luz**, o número vai **subir** ou **descer**? Anote.
3. Troque `A0` por `A1`, carregue e abra o Monitor.
4. Cubra o LDR com o dedo. Depois aponte a lanterna do celular.
5. Preencha:

| Condição | Valor no Monitor |
|---|---|
| Coberto (escuro) | |
| Luz da sala | |
| Lanterna (claro) | |

## ✅ Entrega

A tabela preenchida **no caderno**. A ficha 02 usa esses dois números (escuro e claro).

## Pergunta rápida

Seu palpite do passo 2 acertou? Quanto da faixa 0–1023 o LDR realmente usa?

> ⚠️ Cada bancada tem uma faixa diferente (luz do ponto da sala). Isso não é erro: é por isso que se calibra.

---
**Fica para depois:** fazer o programa descobrir a faixa sozinho (`min()` e `max()`); por que neste shield o número sobe com a luz.

⬅️ [00 — Ponte](00_ponte.md) · ➡️ [02 — LDR: mapear](02_ldr_mapear.md)
