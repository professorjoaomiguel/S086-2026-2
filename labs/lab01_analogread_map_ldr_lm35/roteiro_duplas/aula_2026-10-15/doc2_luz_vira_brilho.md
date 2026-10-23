# Doc 2 de 3 — Luz vira brilho

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

| Componente | Usou? (S ou N) | Anote |
|---|---|---|
| Arduino UNO R3 | | Porta COM: |
| Shield 9-em-1 | | |
| LDR (A1) | | |
| LED vermelho (D9) | | |
| Lanterna do celular | | |
| IA na web | | Qual: |

## Como trabalhar

Igual ao Doc 1. **Piloto:** opera a IDE e a placa, um passo por vez e dizendo o que faz. **Navegador:** lê o roteiro em voz alta, registra e cobra as evidências, sem digitar o código. Os dois pensam juntos nas perguntas. **Vale trocar de papel** (sugestão: ao começar **2.2** e ao começar **2.3**; antes de trocar, mande o código pelo Telegram). Telegram Web para trocar código, ⚡ para quem já domina. Selos: 🔮 previsão · 🧮 cálculo · 🔍 pesquisa · 🤖 IA na web · ☑️ múltipla escolha · 🔒 fechada · 💭 aberta · 📸 mídia.

- **Monitor e Plotter não funcionam ao mesmo tempo:** feche um antes de abrir o outro.
- **Mídia:** foto, print de tela ou GIF (*Inserir → Imagem* ou `Ctrl+V`; print: `Win + Shift + S`). **Vídeo não cola no Docs.**
- **Sketch pronto desta etapa:** `codigo_base/b1_ldr`, no repositório
  <https://github.com/professorjoaomiguel/S086-2026-2> (pasta `labs/lab01_analogread_map_ldr_lm35/codigo_base`) ou no link do Telegram. *Arquivo → Abrir…* e escolha `b1_ldr.ino`.
- **Trocar de documento conta no tempo** (~2 min).

### Referências

- [Documentação da linguagem Arduino (português)](https://docs.arduino.cc/language-reference/pt/): [`analogRead()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/analog-io/analogRead/) · [`analogWrite()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/analog-io/analogWrite/) · [`map()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/math/map/) · [`constrain()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/math/constrain/) · [`pinMode()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/digital-io/pinMode/) · [`Serial`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/communication/serial/)
- [Repositório lab-boards](https://github.com/professorjoaomiguel/lab-boards): dados do shield 9-em-1, incluindo o [pinout anotado](https://github.com/professorjoaomiguel/lab-boards/blob/main/shields/uno-shield-9in1/imagens/pinout-anotado.jpg) (confira os pinos do LDR e do LED).

**Tempo deste documento: ~35 min.** Ao terminar, entregue pelo Classroom e abra o **Doc 3 de 3**.

---

# Etapa 2 — LDR: ler, calibrar, mapear e limitar (35 min)

> 🧭 **Orientação:** agora o valor depende da luz, não da sua mão, e cada bancada tem uma faixa diferente. Você vai **medir** a faixa do seu LDR, usá-la no `map()` e proteger a saída com `constrain()`. No fim, peça ajuda a uma IA e **avalie** o que ela devolve. **Ao final desta etapa o LED deve acompanhar a luz, sem passar de 0–255.**

**Objetivo:** o LDR controla o brilho do LED usando a faixa **que você mediu**. **Pinos:** A1 (LDR), D9 (LED vermelho).

## 2.1 Ler e calibrar (8 min)

1. Abra o sketch `b1_ldr` e carregue. Abra o **Plotter Serial** (9600): a curva `ldr` é a leitura do LDR.
2. 🔮 Com **mais luz**, o número vai **subir** ou **descer**? ______
3. Cubra o LDR com o dedo; depois aponte a lanterna do celular. Anote o valor de `ldr` (passe o mouse sobre a curva, ou use o Monitor Serial no lugar do Plotter):

| Condição | Valor de `ldr` |
|---|---|
| Coberto (escuro) | |
| Luz da sala | |
| Lanterna (claro) | |

4. 🔒 Acertou o sentido (sobe ou desce)? (S ou N): ______
5. 🧮 Faixa útil do LDR: (claro − escuro) ÷ 1023 × 100 = ______ %

*Cada bancada tem uma faixa diferente. Isso não é erro: é por isso que se calibra.*

> 🔎 **Se não funcionou, olhe nesta ordem:**
> 1. Apareceu **"Carregado"**? Se deu erro, leia a **primeira** linha vermelha.
> 2. O Plotter está em **9600** e o Monitor Serial está **fechado**? Os dois juntos não funcionam.
> 3. `ldr` **fixo** em 0 ou em 1023: o shield está **bem encaixado** no UNO? Cubra e descubra o LDR (o do **A1**) para ver se o número muda.
> 4. Sem curva nenhuma: confira a **porta COM** e se é o sketch `b1_ldr` que está carregado.

> ⚡ **Já domina?** Preencha a tabela e a faixa útil e siga.

## 2.2 Mapear e limitar (15 min)

1. No sketch `b1_ldr`, troque os valores de `MINIMO_MEDIDO` (escuro) e `MAXIMO_MEDIDO` (claro) pelos **seus**. Carregue.
   - **Onde mexer:** no começo do arquivo, nas duas linhas `const int MINIMO_MEDIDO` e `const int MAXIMO_MEDIDO`, logo abaixo do comentário *ETAPA 2.2-1*. Troque só o número de cada uma.
2. Confira na linha do `map()` (dentro do `loop()`) que ela converte a faixa medida para 0–255 e que `analogWrite(PINO_LED, brilho)` manda o resultado ao LED.
3. No Plotter, as curvas `ldr` e `brilho` devem subir e descer juntas. Cubra e descubra o LDR: o LED apaga e acende?
4. Aproxime a lanterna **mais** do que na calibração e observe `brilho`. Depois **cubra mais** do que na calibração. Qual o maior e o menor valor de `brilho` que você viu? ______ e ______ *(pode passar de 255 ou ficar negativo)*
5. ☑️ **O que o `constrain()` resolve que o `map()` não resolve?**
   - a) Converte inteiro em decimal.
   - b) Faz o programa rodar mais rápido.
   - c) Limita o resultado à faixa de saída.
   - d) Nada, fazem o mesmo.
   **Sua resposta (letra): ______**
6. No lugar do comentário *ETAPA 2.2-6*, acrescente `brilho = constrain(brilho, 0, 255);` (antes do `analogWrite`) e teste de novo.
   - **Onde colar:** dentro de `loop()`, **depois** da linha do `map()` (ela cria `brilho`) e **antes** de `analogWrite(PINO_LED, brilho);`.
   - **Se não funcionou, olhe:**
     1. Erro de compilação: falta o `;` no fim da linha? `brilho` está escrito igual (minúsculas)? A linha ficou **dentro** do `loop()`?
     2. Erro `'brilho' was not declared`: você colou **antes** da linha do `map()`. Mova para depois dela.
     3. O LED continua sem acompanhar a luz: o `ldr` mexe no Plotter? Seus `MINIMO_MEDIDO` e `MAXIMO_MEDIDO` cobrem a faixa que **você mediu** (o mínimo menor que o máximo)?

| 📸 Cole aqui: **duas fotos**, cada uma com o LED e o Plotter na mesma imagem: (1) LDR coberto; (2) LDR com a lanterna. **Ou um GIF** cobrindo e descobrindo o LDR |
|---|
| |

| 📝 Cole aqui: o código final (via Telegram) |
|---|
| |

## 2.3 🤖 Peça ajuda a uma IA, e pergunte direito (12 min)

**Meta:** o LED deve acender **só no escuro** e apagar na luz (o contrário do que você fez).

1. Escreva um **pedido vago** (30 s), como se tivesse pressa.
2. Escreva um **bom pedido** com 3 partes:
   - **Contexto:** placa, pinos do LDR e do LED, o que seu código faz hoje (cole o código).
   - **Objetivo:** o que deve passar a fazer.
   - **Resultado esperado:** como você confirma que deu certo (ex.: "no escuro `brilho` perto de 255; na luz, perto de 0").
3. Envie o **bom pedido** à IA (Gemini em <https://gemini.google.com>, conta SENAI). Se não estiver logado, peça ajuda ao professor.
4. **Teste na placa; não confie sem testar.** Se o código da IA não compilar, cole a mensagem de erro de volta na IA e peça a correção.
   - **Se não funcionou, olhe:** o código da IA manteve `PINO_LDR = A1` e `PINO_LED = 9`? A IA pode ter trocado os pinos. O Monitor Serial continua em 9600? O LED acende no escuro e apaga na luz, ou ficou o contrário?
5. 💭 Compare com a sua solução: dá para obter o mesmo resultado trocando só dois números no `map()`? Qual?

| 📝 Registre aqui: pedido vago · bom pedido · resposta da IA (trecho principal) |
|---|
| |

| 📝 Avalie: funcionou? (S, N ou P para em parte): ______ · o que você ajustou? O que mudou entre o pedido vago e o bom pedido? |
|---|
| |

> 🏆 **Desafio opcional (não entra na evidência):** peça à IA algo que **não** seja só inverter: o LED liga abaixo de um limiar e só desliga um pouco acima dele (**histerese**), para não ficar piscando. Registre o pedido e o resultado.

**📎 Evidência — Etapa 2:** confira que tem: tabela do LDR, sentido e faixa útil · maior e menor `brilho` vistos · fotos ou GIF do LDR+LED (coberto e com lanterna) · código final com `map()` e `constrain()` · pedido vago, bom pedido, resposta e avaliação da IA

---

# Você leva para o próximo documento

No **Doc 3**, você vai reusar:

- a sua **porta COM** e o jeito de abrir e carregar um sketch;
- o **Plotter Serial** para ver curvas (lembre de fechar o Monitor antes);
- a ideia de transformar uma **leitura em unidade física**, agora em °C.

**Entrega:** salve o arquivo, entregue no Classroom e abra o **Doc 3 de 3 — O termômetro**.
