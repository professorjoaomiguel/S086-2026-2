# Roteiro em duplas — Do USB ao alarme de temperatura

**UC S086 — Sistemas Microprocessados** · Arduino UNO R3 + Shield 9-em-1
*Versão em duplas do Lab 01 (rascunho para virar documento do Google Docs no Classroom).*

| | |
|---|---|
| **Dupla** | |
| **Turma / data** | |
| **Aluno 1** | |
| **Aluno 2** | |

## Como trabalhar

- **Dois PCs, dois papéis.**
  - **Piloto:** opera a Arduino IDE e escreve o código.
  - **Navegador:** conduz **este roteiro**: lê cada passo em voz alta, confere se foi feito e **registra** aqui (respostas, fotos, vídeos).
- **Telegram Web aberto nos dois PCs.** O piloto manda o código ao navegador pelo chat; o navegador cola no registro.
- **Convite:** a cada etapa, que tal **trocar de papel**? Não é obrigatório, mas quem só pilotou aprende outra coisa navegando.
- **Passos em imperativo** ("Conecte", "Abra", "Meça"). Faça um de cada vez e **marque** ☐ → ☑ quando concluir.
- ⚡ **Já domina?** Onde houver o selo ⚡, faça só o **ponto de checagem** e siga. Quem precisa de reforço faz o passo a passo completo.
- **Registrar o programa na placa:** onde o roteiro pedir "cole o código", vale **foto ou print do código na tela** e/ou **foto, vídeo ou GIF da placa rodando** (de preferência os dois na mesma cena).
- **Pontos de entrega (P0 a P4):** ao chegar em um, **devolva o documento parcial** pelo Classroom (ou mostre ao professor) e continue.

### Legenda

| Selo | Significa |
|---|---|
| 🔮 | **Previsão:** responda *antes* de testar. Não precisa acertar. |
| 🧮 | **Cálculo:** faça a conta antes de conferir na serial. |
| 🔍 | **Pesquisa:** busque na web (Google e afins) e **anote a fonte**. |
| 🤖 | **IA na web:** peça a uma IA; registre a pergunta e avalie a resposta. |
| ☑️ | Pergunta de **múltipla escolha**: marque uma. |
| 🔒 | Pergunta **fechada** (liga teoria, prática e observação): responda **por extenso**. |
| 💭 | Pergunta **aberta**: sem resposta certa; dê sua opinião e justifique. |
| 📸 | **Registro de mídia:** foto, vídeo curto ou GIF. Vale também para registrar o **programa implementado**: foto/print do código na tela **e** vídeo/GIF da placa executando-o. |

---

# Etapa 0 — Ligar, conectar e conhecer a placa

## 0.1 Ligar e achar a porta COM

1. ☐ Conecte o **UNO R3** ao PC com o cabo USB. Encaixe o **Shield 9-em-1** sobre a placa, sem entortar pinos.
2. ☐ Observe o LED **ON** da placa. Ele acendeu? Anote: ____________
3. ☐ Abra o **Gerenciador de Dispositivos** (Windows) → *Portas (COM e LPT)*. Anote o nome da porta: **COM___** e o **texto ao lado dela**:
   - ☐ **"Arduino Uno (COMx)"**: sua placa usa o chip USB **ATmega16U2**.
   - ☐ **"USB-SERIAL CH340 (COMx)"**: sua placa é um **clone com chip CH340**.
   - ☐ **Nenhuma porta aparece, ou aparece "Dispositivo desconhecido"**: faltou o driver (típico do CH340). Avise o professor ou a dupla vizinha.
4. ☐ Desconecte o cabo e conecte de novo. Qual linha **some e volta**? ____________
5. ☐ 📸 Se for possível, fotografe o chip perto do conector USB e compare com o da dupla ao lado: os dois são iguais? ☐ sim ☐ não
6. ☐ ☑️ **Como ter certeza de qual COM é a da sua placa?**
   - ☐ a) É sempre a de menor número.
   - ☐ b) É a que **aparece ao plugar e some ao desplugar**.
   - ☐ c) É sempre a COM1.
   - ☐ d) A IDE escolhe sozinha, não preciso conferir.
7. ☐ 🔍 **Pesquisa (3 min):** o que é um **driver USB-serial** e por que a placa aparece como "porta COM"? Por que as placas com chip CH340 podem precisar de instalação extra? Escreva em **uma frase** e cole o **link** da fonte:
   ______________________________________________

## 0.2 Configurar a IDE e gravar o primeiro sketch

1. ☐ **Piloto:** abra a Arduino IDE. Em *Ferramentas → Placa*, escolha **Arduino UNO**. Em *Ferramentas → Porta*, escolha a **COM** do passo 0.1.
2. ☐ Abra *Arquivo → Exemplos → 01.Basics → Blink*. Clique em **Carregar** (seta →).
3. ☐ O LED **L** da placa (pino 13) pisca? 📸 **Registre um vídeo curto ou GIF** do piscar. ☐ Colado aqui.
4. ☐ 🔮 Antes de mudar: se você trocar os dois `delay(1000)` por `delay(250)`, o que muda? ______________________
5. ☐ Troque, carregue de novo e confira. Acertou? ☐ sim ☐ não
6. ☐ 🔒 No Blink original, o LED fica 1 s ligado e 1 s desligado. Qual o **período completo** (ligado + desligado)? E quantas vezes ele pisca em 10 s? Confira com a sua observação: ______________________

> ⚡ **Já domina?** Ponto de checagem: Blink piscando em `delay(250)` (📸 um vídeo curto) + o nome da COM anotado. Pule para 0.3.

## 0.3 Localizar as peças

1. ☐ 📸 **Foto 1 — UNO R3 (sem o shield, ou vista por cima):** tire uma foto e **marque com setas ou números** (no próprio Docs ou no celular):
   1. conector **USB**
   2. chip **ATmega328P** (o grande, retangular)
   3. conector de **alimentação** (jack)
   4. botão **RESET**
   5. LEDs **ON** e **L**
   6. pinos **AREF**, **A0–A5**, **5V**, **3V3** e **GND**
2. ☐ 📸 **Foto 2 — Shield 9-em-1:** tire uma foto e marque:
   1. **potenciômetro** (pino A0)
   2. **LDR** (sensor de luz, pino A1)
   3. **LM35** (sensor de temperatura, pino A2)
   4. **LED RGB** (D9 vermelho, D10 azul, D11 verde)
   5. **buzzer** (D5)

   *(Dica: a foto do shield com os pinos marcados está em
   [pinout-anotado.jpg](https://github.com/professorjoaomiguel/lab-boards/blob/main/shields/uno-shield-9in1/imagens/pinout-anotado.jpg). Use para conferir depois, não para copiar.)*
3. ☐ 🔒 O chip **ATmega328P** roda a 16 MHz e tem 2 KB de SRAM e 32 KB de Flash. Em qual dessas memórias o **seu sketch** fica gravado? Por quê isso permite desligar o USB e a placa continuar funcionando? ______________________
4. ☐ 💭 Qual peça você **achou mais difícil de localizar**? O que a identificação na placa poderia ter para ajudar? ______________________

### ✅ P0 — Ponto de entrega 0
Devolva: **COM anotada, vídeo/GIF do Blink, Foto 1 e Foto 2 com marcações.**

---

# Etapa 1 — Ponte: potenciômetro e `map()`

**Objetivo:** ver o `map()` funcionando antes de usá-lo com sensores. **Pinos:** A0 (potenciômetro), D9 (LED vermelho).

1. ☐ **Piloto:** *Arquivo → Exemplos → 03.Analog → AnalogInOutSerial*. Carregue na placa.
2. ☐ Abra o **Monitor Serial** (9600 baud) e gire o potenciômetro. Você deve ver algo como `sensor = 812	output = 202` e o LED vermelho mudando de brilho.
3. ☐ Ache no código a linha do `map()`. Copie-a aqui: ______________________
4. ☐ 📸 **Vídeo curto:** gire o potenciômetro mostrando, na mesma cena, o LED e os números no Monitor.
5. ☐ 🔮 O sensor **nunca** chega a 0 nem a 1023 (só varia de 300 a 700). O que acontece com o brilho do LED?
6. ☐ ☑️ Marque o que você acha, depois confira com um `Serial.println` de `output`:
   - ☐ a) O LED apaga totalmente e chega ao brilho máximo.
   - ☐ b) O LED **nunca apaga totalmente e nunca chega ao brilho máximo**.
   - ☐ c) O LED pisca.
   - ☐ d) Dá erro de compilação.
7. ☐ 🧮 Faça a conta: quanto vale `output` para `sensor = 300` e para `sensor = 700`? ______ e ______

> ⚡ **Já domina?** Checagem: vídeo do passo 4 + resposta da pergunta 6.

---

# Etapa 2 — LDR: ler, calibrar, mapear e limitar

**Objetivo:** o LDR controla o brilho do LED usando a faixa **que você mediu**. **Pinos:** A1 (LDR), D9 (LED vermelho).

## 2.1 Ler e calibrar

1. ☐ Abra *Exemplos → 01.Basics → AnalogReadSerial* e troque `A0` por `A1`.
2. ☐ 🔮 Com **mais luz**, o número vai **subir** ou **descer**? ______
3. ☐ Carregue, abra o Monitor, cubra o LDR com o dedo e depois aponte a lanterna do celular. Preencha:

| Condição | Valor no Monitor |
|---|---|
| Coberto (escuro) | |
| Luz da sala | |
| Lanterna (claro) | |

4. ☐ 🔒 Seu palpite do passo 2 acertou? Que **porcentagem da faixa 0–1023** o LDR realmente usou? (Calcule: (claro − escuro) ÷ 1023.) ______

> Cada bancada tem uma faixa diferente. Isso não é erro: é por isso que se calibra.

## 2.2 Mapear e limitar

1. ☐ Crie duas constantes com os valores medidos: `MINIMO_MEDIDO` (escuro) e `MAXIMO_MEDIDO` (claro).
2. ☐ Converta com `map(leitura, MINIMO_MEDIDO, MAXIMO_MEDIDO, 0, 255)` e mande ao pino 9 com `analogWrite`.
3. ☐ Imprima no formato do Plotter: `ldr:347,brilho:12` (feche o Monitor e abra *Ferramentas → Plotter Serial*).
4. ☐ 📸 **GIF ou vídeo curto:** cobrir e descobrir o LDR faz o LED apagar e acender; no Plotter as duas curvas sobem e descem juntas.
5. ☐ Aproxime a lanterna **mais** do que na calibração. O `brilho` passou de 255? ☐ sim ☐ não
6. ☐ ☑️ **O que o `constrain()` resolve que o `map()` não resolve?**
   - ☐ a) Converte número inteiro em decimal.
   - ☐ b) Faz o programa rodar mais rápido.
   - ☐ c) **Limita o resultado** à faixa de saída, pois o `map()` não limita.
   - ☐ d) Nada, os dois fazem o mesmo.
7. ☐ Aplique `constrain(brilho, 0, 255)` e teste de novo. Cole o **trecho de código** final aqui (via Telegram): `______`

## 2.3 🤖 Peça ajuda a uma IA (e pergunte direito)

**Meta:** o LED deve acender **só no escuro** e apagar na luz (o contrário do que você fez).

1. ☐ **Primeiro, escreva um pedido vago** (30 s), como se tivesse pressa: `______`
2. ☐ **Agora, escreva um bom pedido** com 3 partes:
   - **Contexto:** placa, pino do LDR e do LED, o que seu código faz hoje (cole o código).
   - **Objetivo:** o que deve passar a fazer.
   - **Resultado esperado:** como você vai confirmar que deu certo (ex.: "no escuro `brilho` perto de 255, na luz perto de 0").
3. ☐ Mande o **bom pedido** para uma IA na web (Gemini, com a conta SENAI). Cole aqui a **resposta** (ou o trecho principal): `______`
4. ☐ **Não confie: teste na placa.** Funcionou? ☐ sim ☐ não ☐ em parte. O que você teve que ajustar? `______`
5. ☐ 💭 O que **mudou na resposta** entre o pedido vago e o bom pedido (se você tiver testado os dois)? O que você vai dizer da próxima vez que pedir ajuda?

### ✅ P1 — Ponto de entrega 1
Devolva: **Etapa 1 e Etapa 2 completas** (tabela do LDR, GIF/vídeo, código final, pedido vago × bom pedido, resposta e avaliação da IA).

---

# Etapa 3 — LM35: de contagens a graus Celsius

**Objetivo:** ir de contagens (0–1023) a °C e entender por que a leitura oscila. **Pino:** A2 (LM35). **Sketch pronto:** `codigo_base/b2_lm35_temperatura`.

O LM35 entrega **10 mV por °C**. O caminho é sempre: **contagens → tensão (V) → temperatura (°C)**.

## 3.1 Ler a temperatura

1. ☐ **Piloto:** abra `b2_lm35_temperatura`, carregue na placa e abra o **Plotter Serial** (9600).
2. ☐ Compare `tempC` com a temperatura da sala (use o celular ou o termômetro do professor). Anote: `tempC = ____` · sala = `____`
3. ☐ Segure o LM35 entre os dedos. 📸 **GIF ou print do Plotter:** a curva sobe devagar.
4. ☐ Na função `lerTemperatura()`, ache as duas contas (contagens → volts e volts → °C). Copie-as: `______`
5. ☐ 🧮 A 25 °C, quantos **mV** o LM35 entrega? E quantas **contagens** o `analogRead` devolve, com referência de 5 V? Conta: ______ → resposta: ______
6. ☐ ☑️ **A 25 °C o LM35 entrega…**
   - ☐ a) 25 mV
   - ☐ b) 250 mV
   - ☐ c) 2,5 V
   - ☐ d) 25 V
7. ☐ 🔒 Compare sua conta do passo 5 com o `cru` que você viu no sketch. Bateu? Se houve diferença, o que pode explicá-la? ______________________
8. ☐ 🔍 **Pesquisa (3 min), sem o PDF do repositório:** busque no Google o **datasheet do LM35** (site oficial da Texas Instruments). Anote a **exatidão do LM35D a 25 °C** e cole o **link**: `______`

> ⚠️ Se o LM35 ler ≈ 0 °C ou um valor absurdo, avise o professor.

## 3.2 Precisão e ruído

1. ☐ Troque `Serial.println(tempC, 1)` por `(tempC, 2)`. Olhe as "escadinhas" no Plotter: de quantos °C é cada degrau?
2. ☐ ☑️ **Com referência de 5 V, uma contagem do conversor equivale a aproximadamente…**
   - ☐ a) 0,01 °C
   - ☐ b) 0,1 °C
   - ☐ c) 0,5 °C
   - ☐ d) 1 °C
3. ☐ 🔒 Por que **2 casas decimais não significam precisão de 0,01 °C**? Use o tamanho do degrau do passo 1. `______`
4. ☐ Deixe o LM35 parado 1 minuto e veja `cru` no Plotter: ela oscila? ☐ sim ☐ não
5. ☐ Na `lerTemperatura()`, aplique o que o professor mostrou: faça uma leitura e **descarte**; `delay(100)`; faça **16 leituras**, some e divida por 16 (cuidado com o tipo da soma).
6. ☐ Imprima `cru` e `tempC` juntos. 📸 **Print ou GIF do Plotter:** a curva da média está mais lisa que a crua.
7. ☐ 💭 Em que aplicação do dia a dia um degrau de 0,5 °C é **aceitável**? Em qual **não seria**? Justifique.

### ✅ P2 — Ponto de entrega 2
Devolva: **Etapa 3 completa** (temperatura × sala, GIF/print do Plotter, contas, pesquisa com link, curva crua × média).

---

# Etapa 4 — A referência do conversor (AREF)

**Objetivo:** comparar `DEFAULT` e `INTERNAL`: o que se ganha e o que se perde. *(Pode ser feita em outra aula; exige as Etapas 3.1 e 3.2.)*

| `analogReference(...)` | Referência | Faixa | 1 contagem vale |
|---|---|---|---|
| `DEFAULT` | Alimentação (~5 V) | 0 a ~5 V | |
| `INTERNAL` | ~1,1 V interna | 0 a ~1,1 V | |

1. ☐ 🧮 Preencha a última coluna (em mV) para os dois casos e converta para °C pela regra do LM35 (10 mV/°C).
2. ☐ **Antes de mudar:** com `DEFAULT`, anote `cru` ___ e temperatura ___ °C.
3. ☐ No `setup()`, acrescente `analogReference(INTERNAL);` e mude `TENSAO_REFERENCIA` de `5.0` para `1.1`.
4. ☐ 🧮 Com 1,1 V, quantas contagens o LM35 deve dar a 25 °C? ______
5. ☐ Para ver o efeito: troque `delay(500)` por `delay(20)` e use uma leitura só. Carregue, abra o Plotter e aperte **RESET** do shield. A leitura começa no valor certo? ☐ sim ☐ não
6. ☐ Explicação: o capacitor do pino AREF precisa descarregar de ~5 V a 1,1 V, e o `analogReference()` só vale no próximo `analogRead()`. No `setup()`, depois do `analogReference(INTERNAL)`: faça **uma leitura descartada** e **espere ~0,5 s**. RESET de novo e compare.
7. ☐ Restaure `delay(500)`, `delay(100)` e a média. Preencha com o LM35 parado:

| Referência | `cru` | Temperatura (°C) |
|---|---|---|
| DEFAULT (5 V) | | |
| INTERNAL (1,1 V) | | |

8. ☐ 🔮 Ainda com `INTERNAL`, o que acontece se você ler o **potenciômetro (A0)**? Troque `PINO_SENSOR` para `A0`, gire de ponta a ponta e anote em que parte do giro a leitura ainda muda: `______`
9. ☐ ☑️ **Ao trocar para `INTERNAL` o que acontece?**
   - ☐ a) Mais precisão e **menos faixa** (~0 a 1,1 V), vale para **todos** os pinos analógicos.
   - ☐ b) Mais precisão e a mesma faixa.
   - ☐ c) Menos precisão e mais faixa.
   - ☐ d) Nada muda.
10. ☐ 💭 Quando você usaria `INTERNAL` num projeto seu? E quando **não** usaria?

> ⛔ **Antes da Etapa 5:** apague `analogReference(INTERNAL)` e volte `TENSAO_REFERENCIA` para `5.0`; volte `PINO_SENSOR` para `A2`.

### ✅ P3 — Ponto de entrega 3
Devolva: **Etapa 4 completa** (tabelas, vídeo/print da leitura estável após RESET, respostas).

---

# 🎆 Etapa 5 — Grand finale: alarme de temperatura e dublê de teste

**Objetivo:** montar um alarme e **validá-lo sem esperar o sensor esquentar**. Reúne tudo: LM35 com média (Etapa 3), `map()`/`constrain()` (Etapa 2) e saídas (LED RGB e buzzer).
**Sketch-base:** `codigo_base/b4_alarme`. **Pinos:** A2 (LM35), D9 vermelho, D10 azul, D11 verde, D5 buzzer.

## 5.1 Montar

1. ☐ Copie o **corpo** da sua `lerTemperatura()` da Etapa 3 (descarte + média) para a `lerTemperatura()` do sketch. Mantenha a primeira linha `float lerTemperatura() {` e copie as constantes que ela usa.
2. ☐ Complete `atualizarSaidas()`:
   - **LED RGB:** azul abaixo de uma faixa confortável, verde dentro, vermelho acima do `LIMIAR` (30 °C). Crie constantes para os limites.
   - **Buzzer (D5):** ligado acima do `LIMIAR`. Use `digitalWrite`, **não** `tone()` (o `tone()` conflita com o PWM do D11).
   - **Estado:** `FRIO`, `OK` ou `ALARME`.
3. ☐ O painel `temp=26.3 lim=30.0 estado=OK` mostra um estado **coerente** com a cor e o buzzer? ☐ sim ☐ não

## 5.2 Com o sensor real

1. ☐ Aqueça o LM35 com os dedos até passar de 30 °C. O alarme dispara? Desliga quando esfria?
2. ☐ 📸 **Vídeo:** mostre o alarme disparando e desligando, e as três cores. **Anote quanto tempo levou:** `______ s`

## 5.3 Pare e pense

🔮 Como testar o alarme em **35 °C** sem esperar o sensor esquentar? **Discutam na dupla e com a turma antes de seguir.**

<details>
<summary>Travou? Uma pista</summary>

O que o potenciômetro, o LDR e o LM35 têm em comum, do ponto de vista do `analogRead`?

</details>

Resposta da dupla (antes de ler a próxima etapa): `______`

## 5.4 O dublê de teste

1. ☐ Troque `PINO_SENSOR` de `A2` para `A0` e gire o potenciômetro.
2. ☐ Que "temperatura" aparece com o giro todo? Faz sentido? `______`
3. ☐ Ajuste a escala para o potenciômetro "fingir" **15 a 45 °C**. (Pista: no LDR você já usou uma função para ajustar a faixa de um sensor.)
4. ☐ 💭 **Onde** deve ficar esse ajuste para o resto do programa nem perceber a troca de sensor? Por quê?
5. ☐ 📸 **Vídeo curto:** girando o potenciômetro, as **três cores**, o buzzer ligando e desligando e o painel acompanhando, em **menos de 1 minuto**.
6. ☐ 🔒 Compare com o tempo da etapa 5.2. Quanto tempo você **ganhou** com o dublê? `______`

## 5.5 De volta ao real

1. ☐ Volte `PINO_SENSOR` para `A2` e desfaça o ajuste.
2. ☐ ☑️ **O que o teste com o potenciômetro valida?**
   - ☐ a) A calibração do LM35.
   - ☐ b) O ruído do LM35.
   - ☐ c) A **lógica de decisão** (limiar, cores, buzzer, estado).
   - ☐ d) O tempo de resposta térmica do sensor.
3. ☐ 🔒 Então o que o teste com o potenciômetro **NÃO** valida? Dê **dois** exemplos. `______`
4. ☐ **Isso tem nome:** trocar uma peça difícil de controlar por outra que você controla, só para testar a lógica, é um **dublê de teste** (*test double* ou *mock*). A versão industrial é o *hardware-in-the-loop* (HIL). Cite **uma situação** (fora desta aula) em que você usaria um dublê: `______`

## 5.6 Desafio (bônus): histerese

Com o LM35 parado perto de 30 °C, o buzzer pode ficar ligando e desligando.
- ☐ 🔒 Por quê? `______`
- ☐ E se ligasse em 30 °C e só desligasse em 29 °C?
- ☐ 🤖 Peça a uma IA para acrescentar a histerese ao **seu** código, com **contexto + objetivo + resultado esperado**. Cole o pedido, a resposta e o resultado do teste.

### ✅ P4 — Entrega final
Devolva o documento completo, com **vídeo do alarme real, vídeo do dublê, código final e as respostas**.

---

# Fechamento

Cada aluno responde **individualmente**, em 2 a 3 linhas:

1. 💭 Qual etapa foi **mais fácil** e qual foi **mais difícil** para você? Por quê?
2. 💭 Como foi alternar (ou não) os papéis de piloto e navegador? O que funcionou?
3. 💭 O que você faria de diferente ao pedir ajuda a uma IA na próxima vez?

---

**Fontes**
- Datasheet do LM35 (TI) e do ATmega328P (Microchip): em `datasheets/` do repositório.
- Referência Arduino: [`analogRead()`](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/) · [`analogReference()`](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReference/) · [`map()`](https://docs.arduino.cc/language-reference/en/functions/math/map/) · [`constrain()`](https://docs.arduino.cc/language-reference/en/functions/math/constrain/)
