# Doc 3 de 3 — O termômetro

**UC S086 — Sistemas Microprocessados** · Arduino UNO R3 + Shield 9-em-1
*Este documento é o roteiro **e** o relatório. Um arquivo por dupla: os dois alunos entregam o mesmo arquivo.*

## Identificação

| Campo | Preencha |
|---|---|
| Aluno 1 (piloto) | |
| Aluno 2 (navegador) | |
| Turma / bancada | |
| Data | 15/10/2026 |

## Componentes utilizados neste documento

| Componente | Usou? | Anote |
|---|---|---|
| Arduino UNO R3 | ☐ | Porta COM: |
| Shield 9-em-1 | ☐ | |
| LM35 (A2) | ☐ | |
| Termômetro de referência (celular ou do professor) | ☐ | Qual: |

## Como trabalhar

Igual aos documentos anteriores: piloto na IDE, navegador conduzindo e registrando, Telegram Web para trocar código, ⚡ para quem já domina. Selos: 🔮 previsão · 🧮 cálculo · 🔍 pesquisa · ☑️ múltipla escolha · 🔒 fechada · 💭 aberta · 📸 mídia.

- **Monitor e Plotter não funcionam ao mesmo tempo:** feche um antes de abrir o outro.
- **Sketch pronto desta etapa:** `codigo_base/b2_lm35_temperatura`, no repositório
  <https://github.com/professorjoaomiguel/S086-2026-2> (pasta `labs/lab01_analogread_map_ldr_lm35/codigo_base`) ou no link do Telegram. *Arquivo → Abrir…* e escolha `b2_lm35_temperatura.ino`.

### Referências

- [Documentação da linguagem Arduino (português)](https://docs.arduino.cc/language-reference/pt/): [`analogRead()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/analog-io/analogRead/) · [`analogReference()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/analog-io/analogReference/) (desafio) · [`delay()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/delay/) · [`Serial`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/communication/serial/)
- [Repositório lab-boards](https://github.com/professorjoaomiguel/lab-boards): dados do shield 9-em-1, incluindo o [pinout anotado](https://github.com/professorjoaomiguel/lab-boards/blob/main/shields/uno-shield-9in1/imagens/pinout-anotado.jpg) (confira o pino do LM35).

**Tempo deste documento: ~45 min + 5 min de fechamento.** Esta é a **entrega final** da aula.

---

# Etapa 3 — LM35: o Arduino vira termômetro (45 min)

> 🧭 **Orientação:** reúna o que viu até aqui para construir um **termômetro**. Primeiro converta contagens em graus e compare com a temperatura da sala. Depois descubra por que o número oscila e estabilize-o com média. **Ao final desta etapa você tem um termômetro cuja curva no Plotter é lisa e confere com a sala.**

**Objetivo:** ir de contagens (0–1023) a °C e deixar a leitura estável. **Pino:** A2 (LM35).

O LM35 entrega **10 mV por °C**. O caminho é: **contagens → tensão (V) → temperatura (°C)**.

## 3.1 Ler a temperatura (20 min)

1. ☐ **Piloto:** abra `b2_lm35_temperatura`, carregue e abra o **Plotter Serial** (9600).
2. ☐ Compare `tempC` com a temperatura da sala (celular ou termômetro do professor). Para ler o número exato, passe o mouse sobre a curva ou use o Monitor Serial (fechando o Plotter antes).
3. ☐ Segure o LM35 entre os dedos: a curva deve subir devagar.
4. ☐ Em `lerTemperatura()`, ache as duas contas (contagens → volts e volts → °C) e copie.
5. ☐ ☑️ **A 25 °C o LM35 entrega…**
   - ☐ a) 25 mV ☐ b) 250 mV ☐ c) 2,5 V ☐ d) 25 V
6. ☐ 🧮 Com a resposta do passo 5, quantas **contagens** o `analogRead` devolve a 25 °C, com referência de 5 V? Caminho: °C × 10 = mV · mV ÷ 1000 = V · V ÷ 5 × 1023 = contagens. Conta: ______ → ______
7. ☐ 🔒 Sua conta do passo 6 bateu com o `cru` do sketch? Se não, o que explica a diferença? ______________________
8. ☐ 🔍 *(se sobrar tempo)* No datasheet do LM35 (site da Texas Instruments), a **exatidão do LM35D a 25 °C**: ______ · link: ______

⚠️ Se o LM35 ler ≈ 0 °C ou algo absurdo, avise o professor.

> ⚡ **Já domina?** Carregue, compare com a sala, cole as duas contas e o resultado do passo 6, e siga.

| 📝 Registre aqui: `tempC` do sensor = ____ · temperatura da sala = ____ |
|---|
| |

| 📝 Cole aqui: as duas contas de `lerTemperatura()` |
|---|
| |

| 📸 Cole aqui: GIF ou print do Plotter com a curva subindo ao segurar o sensor |
|---|
| |

## 3.2 Precisão e ruído (20 min)

1. ☐ Troque `Serial.println(tempC, 1)` por `(tempC, 2)`. Olhe as "escadinhas" no Plotter.
2. ☐ ☑️ **Com referência de 5 V, uma contagem equivale a aproximadamente…**
   - ☐ a) 0,01 °C ☐ b) 0,1 °C ☐ c) 0,5 °C ☐ d) 1 °C
3. ☐ 🔒 Por que **2 casas decimais não significam precisão de 0,01 °C**? Use o tamanho do degrau. ______________________
4. ☐ Deixe o LM35 parado por 1 minuto. O `cru` oscila? ☐ sim ☐ não
5. ☐ No sketch, no trecho marcado **ETAPA 2c** (dentro de `lerTemperatura()`), troque a leitura única por este esqueleto e complete os `___`:

   ```cpp
   analogRead(PINO_SENSOR);          // 1ª leitura: descartada
   delay(100);
   long soma = 0;
   for (int i = 0; i < ___; i++) {
     soma += analogRead(PINO_SENSOR);
   }
   float leitura = soma / ___;       // média das leituras
   ```

6. ☐ 🔒 16 × 1023 cabe em um `int` (máximo 32767)? E por que dividir por `16.0` e não por `16` mantém os decimais da média? ______________________
7. ☐ Carregue e compare as curvas no Plotter. O `cru` é **uma leitura avulsa**; o `tempC` usa a **média das 16**. As duas linhas ficam em escalas diferentes (`cru` ~50, `tempC` ~25): isso é normal. Compare a **suavidade**, não a altura.

> Os comentários **ETAPA 2b** e **ETAPA 3b** do sketch ficam para a próxima aula.

| 📸 Cole aqui: print ou GIF do Plotter com `cru` e `tempC` (a média deve estar mais lisa) |
|---|
| |

| 📝 Cole aqui: código final de `lerTemperatura()` |
|---|
| |

💭 Em que aplicação um degrau de 0,5 °C é aceitável? Em qual **não seria**? Justifique. ______________________

> 🏆 **Desafio opcional (não entra na evidência):** use `analogReference(INTERNAL)` (referência de ~1,1 V, cerca de 0,1 °C por contagem) e ajuste `TENSAO_REFERENCIA`. Anote o que mudou na curva e o que acontece nas primeiras leituras depois do `RESET`.

**📎 Evidência — Etapa 3:** ☐ `tempC` × sala · ☐ duas contas e resultado do passo 6 · ☐ Plotter com a curva subindo · ☐ Plotter com `cru` e `tempC` · ☐ código final de `lerTemperatura()` · ☐ respostas 3.1-5, 3.1-7, 3.2-2, 3.2-3, 3.2-6

---

# Fechamento (individual, 5 min)

Cada aluno responde em 2 a 3 linhas.

| 💭 **Aluno 1** — Qual etapa da aula foi mais fácil e qual foi mais difícil? Por quê? O que você faria diferente ao pedir ajuda a uma IA (Doc 2)? |
|---|
| |

| 💭 **Aluno 2** — Qual etapa da aula foi mais fácil e qual foi mais difícil? Por quê? O que você faria diferente ao pedir ajuda a uma IA (Doc 2)? |
|---|
| |

| O que não deu tempo ou ficou para a próxima aula? |
|---|
| |

---

**Entrega final:** salve o arquivo e entregue no Classroom. **Os dois alunos entregam o mesmo arquivo.** Confira antes: ☐ identificação preenchida ☐ componentes marcados ☐ todas as evidências da Etapa 3 ☐ fechamento dos dois alunos.
