# Ficha 02 — LDR: mapear e limitar (30 min)

**Objetivo:** o LDR controla o brilho do LED, usando a faixa que **você** mediu.
**Pinos:** A1 (LDR), D9 (LED vermelho) · **Precisa de:** a tabela da ficha 01

## Parte A — `map()` (15 min)

1. Crie duas constantes com os valores medidos: `MINIMO_MEDIDO` (escuro) e `MAXIMO_MEDIDO` (claro).
2. Converta: `map(leitura, MINIMO_MEDIDO, MAXIMO_MEDIDO, 0, 255)` e envie ao pino 9 com `analogWrite`.
3. 🧮 No caderno, antes de testar: o que o `map()` devolve para uma leitura **igual ao mínimo**? E **bem no meio** da faixa?
4. Imprima no formato do Plotter: `ldr:347,brilho:12`.

**✅ Entrega A:** cobrir e descobrir o LDR faz o LED apagar e acender, e no Plotter as duas curvas sobem e descem juntas.

## Parte B — Quando passa da faixa (15 min)

1. Aproxime a lanterna **mais** do que na calibração. Olhe `brilho`: pode passar de 255 (ou ficar negativo no escuro total).
2. Por quê? O `map()` só faz regra de três, não sabe que o `analogWrite` vai de 0 a 255.
3. Use `constrain(brilho, 0, 255)` ([referência](https://docs.arduino.cc/language-reference/en/functions/math/constrain/)) e teste de novo.

**✅ Entrega B:** com a lanterna bem perto, `brilho` nunca passa de 255.

> ⚠️ O `map()` **não limita** o resultado e **só trabalha com inteiros** (corta as casas decimais).

---
**Fica para depois:** luz noturna (inverter a ordem dos dois números do `map()`).

⬅️ [01 — LDR: calibrar](01_ldr_calibrar.md) · ➡️ [03 — LM35: ler](03_lm35_ler.md)
