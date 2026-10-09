# Ficha 05 — A referência do conversor (AREF) (30 min)

> Aula separada. Pré-requisito: fichas 03 e 04 concluídas.

**Objetivo:** comparar `DEFAULT` e `INTERNAL` e entender o que se ganha e o que se perde.

O conversor compara a tensão lida com uma **referência**: 0 V vira 0 e a referência vira 1023. Até aqui foi a alimentação (~5 V). `analogReference()` troca isso.

| `analogReference(...)` | Referência | Faixa | 1 contagem vale |
|---|---|---|---|
| `DEFAULT` | Alimentação (~5 V) | 0 a ~5 V | |
| `INTERNAL` | ~1,1 V interna | 0 a ~1,1 V | |
| `EXTERNAL` | Tensão no pino AREF | até a tensão no AREF | depende |

## Parte A — Conta e datasheet (10 min)

1. 🧮 Preencha a última coluna para `DEFAULT` e `INTERNAL` (em mV) e converta para °C pela regra do LM35.
2. 🔍 [`ATmega328P_Datasheet_Microchip.pdf`](../../../datasheets/ATmega328P_Datasheet_Microchip.pdf), tabela *ADC Characteristics*: valores mín/típico/máx de `Vint` e a faixa permitida de `VREF`.

## Parte B — LM35 com `INTERNAL` (20 min)

0. **Antes de mudar:** anote `cru` e temperatura da linha `DEFAULT` na tabela do passo 6.
1. No `setup()`, linha `ETAPA 3b`: `analogReference(INTERNAL);`
2. `TENSAO_REFERENCIA` de `5.0` para `1.1`. (Por que a conta precisa mudar junto?)
3. 🧮 Com 1,1 V, quantas contagens o LM35 deve dar a 25 °C?
4. Para ver o efeito: troque `delay(500)` por `delay(20)` e use uma leitura só (comente o `delay(100)` e a média). Carregue, abra o Plotter e aperte **RESET** do shield. A leitura começa no valor certo?
5. Explicação: o capacitor do pino AREF precisa descarregar de ~5 V a 1,1 V, e o `analogReference()` só vale de verdade no próximo `analogRead()`. No `setup()`, depois do `analogReference(INTERNAL)`: faça **uma leitura descartada** e **espere ~0,5 s**. RESET de novo e compare. Depois, restaure `delay(500)`, `delay(100)` e a média.
6. Tabela (LM35 parado):

| Referência | `cru` | Temperatura (°C) |
|---|---|---|
| DEFAULT (5 V) | | |
| INTERNAL (1,1 V) | | |

**✅ Entrega:** a tabela preenchida e a leitura estável após o RESET.

## Parte C — O preço da precisão

1. 🔮 Ainda com `INTERNAL`, o que acontece se você ler o potenciômetro (A0)?
2. Troque `PINO_SENSOR` para `A0` e gire o potenciômetro de ponta a ponta. Em que parte do giro a leitura ainda muda?
3. Conclusão: a referência vale para **todos** os pinos analógicos. Mais precisão = **menos faixa**. Volte `PINO_SENSOR` para `A2`.

## EXTERNAL: só teoria

O shield cobre o pino AREF do UNO, então não dá para fazer na prática.

> ⚠️ Se um dia usar: chame `analogReference(EXTERNAL)` **antes** de qualquer `analogRead()` e ligue a tensão ao AREF por um resistor em série (~5 kΩ). Veja a [referência](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReference/).

**Bônus:** medir a tensão da própria placa lendo a referência interna de 1,1 V (`Vcc ≈ 1,1 × 1023 / leitura`).

> ⛔ **Antes da ficha 06:** apague `analogReference(INTERNAL)` e volte `TENSAO_REFERENCIA` para `5.0`.

⬅️ [04 — LM35: precisão e ruído](04_lm35_precisao_ruido.md) · ➡️ [06 — Alarme](06_alarme.md)
