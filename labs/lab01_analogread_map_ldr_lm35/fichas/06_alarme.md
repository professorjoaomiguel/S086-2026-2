# Ficha 06 — Alarme de temperatura e dublê de teste (50 min)

> Aula separada. Pré-requisito: ficha 04 (e `analogReference(INTERNAL)` já apagado, `TENSAO_REFERENCIA = 5.0`).

**Objetivo:** montar um alarme e validá-lo **sem esperar o sensor esquentar**.
**Sketch:** [`b4_alarme`](../codigo_base/b4_alarme/b4_alarme.ino) · **Pinos:** A2 (LM35), D9 vermelho, D10 azul, D11 verde, D5 buzzer

## Parte A — Montar (20 min)

1. Copie o **corpo** da sua `lerTemperatura()` da ficha 04 (descarte + média) para dentro da `lerTemperatura()` do sketch. Mantenha a primeira linha `float lerTemperatura() {` e copie também as constantes que ela usa.
2. Complete `atualizarSaidas()`:
   - **LED RGB:** azul abaixo de uma faixa confortável, verde dentro, vermelho acima do `LIMIAR` (30 °C). Crie constantes para os limites.
   - **Buzzer (D5):** ligado acima do `LIMIAR`. Use `digitalWrite`, **não** `tone()` (o `tone()` conflita com o PWM do D11).
   - **Estado:** `FRIO`, `OK` ou `ALARME`.

**✅ Entrega A:** o painel `temp=26.3 lim=30.0 estado=OK` mostra um estado coerente com a cor e o buzzer.

## Parte B — Prove que funciona (10 min)

Com o LM35 real, mostre o alarme disparando acima de 30 °C e desligando quando cai. Mostre as três cores. **Anote quanto tempo levou.**

## Parte C — Pare e pense (5 min)

🔮 Como testar o alarme em 35 °C **sem** esperar o sensor esquentar? Discuta com a dupla e com a turma **antes de seguir**.

<details>
<summary>Travou? Uma pista</summary>

O que o potenciômetro, o LDR e o LM35 têm em comum, do ponto de vista do `analogRead`?

</details>

## Parte D — Trocar o sensor em uma linha (15 min)

**Só depois da discussão.**

1. Troque `PINO_SENSOR` de `A2` para `A0` e gire o potenciômetro.
2. Que "temperatura" aparece com o giro todo? Faz sentido?
3. Ajuste a escala para o potenciômetro "fingir" 15 a 45 °C.

   <details>
   <summary>Pista</summary>

   No LDR você já usou uma função para ajustar a faixa de um sensor.

   </details>

4. **Onde** o ajuste deve ficar para o resto do programa nem perceber a troca?
5. Por que este bloco usa `DEFAULT` e não `INTERNAL`?

**✅ Entrega D:** girando o potenciômetro, as três cores, o buzzer ligando/desligando e o painel acompanhando, em menos de 1 minuto.

## Parte E — De volta ao real

Volte `PINO_SENSOR` para `A2` e desfaça o ajuste. No caderno: **o que o teste com o potenciômetro NÃO valida?**

**Isso tem nome:** trocar uma peça difícil de controlar por outra que você controla, só para testar a lógica, é um **dublê de teste** (*test double* ou *mock*). A versão industrial é o *hardware-in-the-loop* (HIL).

**Bônus: histerese.** Com o LM35 parado perto de 30 °C o buzzer pode ficar ligando e desligando. Por quê? E se ligasse em 30 °C e só desligasse em 29 °C?

⬅️ [05 — AREF](05_aref.md) · ➡️ [Fechamento](../README.md#fechamento)
