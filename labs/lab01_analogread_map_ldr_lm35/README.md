# Lab 01 — analogRead, map() e AREF: luz e temperatura no Shield 9-em-1

**UC S086 — Sistemas Microprocessados** · Arduino UNO R3 + Shield 9-em-1

Este laboratório está dividido em **fichas curtas**. Cada ficha tem um objetivo,
poucos passos e uma **entrega** que o professor confere na serial. Faça uma
ficha por vez e só avance depois de mostrar a entrega.

## Fichas

| # | Ficha | Tempo | Pino(s) | Entrega |
|---|---|---|---|---|
| 00 | [Ponte: potenciômetro e `map()`](fichas/00_ponte.md) | 15 min | A0, D9 | LED varia com o potenciômetro |
| 01 | [LDR: ler e calibrar](fichas/01_ldr_calibrar.md) | 20 min | A1 | Tabela de faixa no caderno |
| 02 | [LDR: mapear e limitar](fichas/02_ldr_mapear.md) | 30 min | A1, D9 | LED segue a luz, sem passar de 255 |
| 03 | [LM35: ler](fichas/03_lm35_ler.md) | 30 min | A2 | Gráfico de `tempC` subindo no dedo |
| 04 | [LM35: precisão e ruído](fichas/04_lm35_precisao_ruido.md) | 40 min | A2 | Curva da média mais lisa que a crua |
| 05 | [AREF: `DEFAULT` × `INTERNAL`](fichas/05_aref.md) | 30 min | A2, A0 | Tabela comparativa + leitura estável após RESET |
| 06 | [Alarme e dublê de teste](fichas/06_alarme.md) | 50 min | A2, A0, D5, D9–D11 | Três cores + buzzer, validados com o potenciômetro |

Sugestão de aulas: **(00 + 01 + 02)**, **(03 + 04)**, **(05)**, **(06)**.

## Objetivos

Ao final do laboratório, você vai saber:

1. **Calibrar** um sensor e usar `map()` e `constrain()` com a faixa real.
2. **Converter** a leitura do LM35 em °C e **reduzir o ruído**.
3. **Comparar** as referências `DEFAULT` e `INTERNAL`: o que se ganha e o que se perde.
4. **Validar** a lógica de um alarme **sem esperar o sensor esquentar**.

## Componentes do shield

| Componente | Pino | Detalhe importante |
|---|---|---|
| Potenciômetro | A0 | Gira de 0 V até 5 V |
| LDR (sensor de luz) | A1 | Divisor de tensão com resistor fixo; o número **sobe** com a luz |
| LM35 (temperatura) | A2 | 10 mV para cada °C |
| LED RGB | D9 vermelho, D10 azul, D11 verde | Acende com `HIGH`; os três aceitam PWM (`analogWrite`) |
| Buzzer | D5 | Ativo: liga com `HIGH` e apita sozinho |

Foto do shield com os pinos marcados:
[pinout-anotado.jpg](https://github.com/professorjoaomiguel/lab-boards/blob/main/shields/uno-shield-9in1/imagens/pinout-anotado.jpg)

**Plotter Serial:** *Ferramentas → Plotter Serial*. Imprima no formato
`nome:valor,nome:valor` e termine com `Serial.println`. Feche o Monitor Serial
antes de abrir o Plotter (os dois não usam a porta ao mesmo tempo). Velocidade: 9600 baud.

## Legenda das fichas

- 🔮 **Previsão:** responda *antes* de testar. Não precisa acertar.
- 🧮 **Cálculo:** faça a conta no caderno antes de conferir na serial.
- 🔍 **Datasheet:** abra o PDF indicado e ache o número (~2 min).
- ✅ **Entrega:** o que mostrar ao professor para avançar.
- **Fica para depois:** extras que não são necessários para a entrega.

## Sketches-base

Em [`codigo_base/`](codigo_base/): `b2_lm35_temperatura` (fichas 03 a 05) e
`b4_alarme` (ficha 06). Os comentários `ETAPA 2b`, `2c`, `3b`, `4a` e `4d`
seguem a numeração antiga dos blocos:

| Comentário no código | Ficha |
|---|---|
| `ETAPA 2b` | 04 (Parte A) |
| `ETAPA 2c` | 04 (Parte B) |
| `ETAPA 3b` | 05 |
| `ETAPA 4a`, `4d` | 06 |

## Se der errado

| Problema | O que fazer |
|---|---|
| O LM35 lê ≈ 0 °C ou um valor absurdo, mesmo com a média | Avise o professor e trabalhe com a dupla. Os valores das tabelas não vão bater com a sala. |
| A sala está acima de 30 °C e o alarme já começa disparado | Mude o `LIMIAR` para alguns graus acima da temperatura do painel. |
| O Plotter não mostra os nomes das curvas | Versão antiga da IDE. Use o Monitor Serial: o formato `nome:valor` continua legível. |
| Na ficha 06 o potenciômetro só muda num pedacinho do giro | Sobrou um `analogReference(INTERNAL)`. Apague a linha e volte `TENSAO_REFERENCIA` para `5.0`. |
| Caracteres estranhos no Plotter ou no Monitor | Confira a velocidade: 9600 baud, a mesma do `Serial.begin`. |

## Fechamento

Responda no caderno, uma pergunta por conjunto de fichas:

1. **LDR (01–02):** por que medir a faixa antes de usar `map()`? O que o `constrain()` resolve que o `map()` não resolve?
2. **LM35 (03–04):** por que imprimir 2 casas decimais não significa medir com precisão de 0,01 °C?
3. **AREF (05):** quando vale trocar para `INTERNAL`? E quando isso atrapalha?
4. **Dublê (06):** o que o teste com o potenciômetro valida, e o que ele não valida?

## Fontes

- Datasheet do LM35 (Texas Instruments):
  [`datasheets/sensores/TI_LM35_Temperatura.pdf`](../../datasheets/sensores/TI_LM35_Temperatura.pdf)
- Datasheet do ATmega328P (Microchip), seção do conversor A/D:
  [`datasheets/ATmega328P_Datasheet_Microchip.pdf`](../../datasheets/ATmega328P_Datasheet_Microchip.pdf)
- Referência Arduino:
  [`analogRead()`](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/),
  [`analogReference()`](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReference/),
  [`map()`](https://docs.arduino.cc/language-reference/en/functions/math/map/),
  [`constrain()`](https://docs.arduino.cc/language-reference/en/functions/math/constrain/)
