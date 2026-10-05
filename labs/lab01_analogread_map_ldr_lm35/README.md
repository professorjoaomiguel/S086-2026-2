# Lab 01 — analogRead, map() e AREF: luz e temperatura no Shield 9-em-1

**UC S086 — Sistemas Microprocessados** · Arduino UNO R3 + Shield 9-em-1 · ~3 h

## Objetivos

Ao final deste laboratório, você vai saber:

1. **Calibrar** um sensor (medir a faixa real dele) e usar `map()` e
   `constrain()` com essa faixa.
2. **Converter** a leitura do LM35 em graus Celsius e **reduzir o ruído**
   da leitura.
3. **Comparar** as referências do conversor `DEFAULT` e `INTERNAL`:
   o que você ganha e o que você perde.
4. **Validar** a lógica de um alarme de temperatura **sem esperar o
   sensor esquentar**.

## Antes de começar

Encaixe o Shield 9-em-1 no UNO R3 e ligue o cabo USB. Os componentes que
você vai usar:

| Componente | Pino | Detalhe importante |
|---|---|---|
| Potenciômetro | A0 | Gira de 0 V até 5 V |
| LDR (sensor de luz) | A1 | Forma um divisor de tensão com um resistor fixo |
| LM35 (sensor de temperatura) | A2 | 10 mV para cada °C |
| LED RGB | D9 vermelho, D10 azul, D11 verde | Acende com `HIGH`; os três aceitam PWM (`analogWrite`) |
| Buzzer | D5 | Liga com `HIGH` (é um buzzer *ativo*: apita sozinho) |

Foto do shield com os pinos marcados:
[pinout-anotado.jpg](https://github.com/professorjoaomiguel/lab-boards/blob/main/shields/uno-shield-9in1/imagens/pinout-anotado.jpg)

**Plotter Serial:** na Arduino IDE, *Ferramentas → Plotter Serial*. Ele
desenha um gráfico com o que o seu programa imprime. Para dar nome a cada
curva, imprima no formato `nome:valor,nome:valor` e termine com uma quebra
de linha (`Serial.println`). Feche o Monitor Serial antes de abrir o
Plotter: os dois não usam a porta ao mesmo tempo.

## Como usar este roteiro

Ao longo do roteiro, três tipos de pausa:

- 🔮 **Previsão:** responda *antes* de testar. Não precisa acertar: o
  objetivo é comparar o seu palpite com o que a placa mostra.
- 🧮 **Cálculo:** faça a conta no caderno antes de conferir na serial.
- 🔍 **Datasheet:** abra o PDF indicado e encontre o número pedido
  (~2 minutos).

**A serial é o seu instrumento de medição.** Toda etapa diz o que deve
aparecer no Monitor ou no Plotter. Confira o seu resultado antes de chamar
o professor.

---

## Bloco 0 — Ponte com a aula passada (15 min)

1. Abra *Arquivo → Exemplos → 03.Analog → AnalogInOutSerial* e carregue na
   placa. Ele lê o A0 (potenciômetro) e controla o pino 9, que no shield é
   o **vermelho do LED RGB**.
2. Abra o Monitor Serial e gire o potenciômetro. Você deve ver linhas como
   `sensor = 812	output = 202`, e o LED mudando de brilho.
3. Encontre a linha do `map()` no código. Ela diz: "o que vai de 0 a 1023
   passa a ir de 0 a 255".
4. Troque o `map()` por `sensorValue / 4`, carregue de novo e compare. Muda
   alguma coisa? Por quê?

🔮 **Previsão:** e se o sensor **nunca** chegar a 0 nem a 1023? Por
exemplo, se ele só variar entre 300 e 700, o que acontece com o brilho do
LED usando esse mesmo `map()`? Anote o seu palpite: o Bloco 1 responde.

---

## Bloco 1 — LDR no A1 (45 min)

O LDR é um resistor que muda de valor com a luz. No shield, ele forma um
divisor de tensão com um resistor fixo, e o A1 lê a tensão do meio.

### 1a. Ler o LDR

1. Abra *Arquivo → Exemplos → 01.Basics → AnalogReadSerial*.
2. 🔮 **Previsão**, antes de carregar: com **mais luz** no LDR, o número
   no Monitor vai **subir** ou **descer**? Anote.
3. Troque `A0` por `A1`, carregue e abra o Monitor. Cubra o LDR com o dedo
   e depois aponte a lanterna do celular para ele.
4. O seu palpite acertou? Se você procurar "LDR Arduino" na internet, vai
   achar muitos circuitos em que o número *desce* com a luz. Por que neste
   shield é diferente? (Pista: depende de que lado do divisor o LDR está.)

### 1b. Calibrar: medir a faixa real

Calibrar é descobrir **entre quais valores** o seu sensor realmente varia,
na sua bancada. Observe o Monitor e preencha:

| Condição | Valor no Monitor |
|---|---|
| Coberto com o dedo (escuro) | |
| Luz da sala | |
| Lanterna do celular (claro) | |

Compare com a faixa 0 a 1023 do conversor. Quanto dela o LDR realmente usa?

**Terminou antes?** Faça o próprio programa descobrir a faixa: guarde o
menor e o maior valor visto em duas variáveis (as funções `min()` e `max()`
ajudam) e imprima os dois.

### 1c. Mapear com a faixa medida

Agora o LDR vai controlar o brilho do LED vermelho (pino 9).

1. Crie duas constantes com os valores que **você** mediu:
   `MINIMO_MEDIDO` (escuro) e `MAXIMO_MEDIDO` (claro).
2. Converta a leitura em brilho com
   `map(leitura, MINIMO_MEDIDO, MAXIMO_MEDIDO, 0, 255)` e envie para o
   pino 9 com `analogWrite`.
3. 🧮 **Cálculo:** com a faixa que **você** mediu, quanto o `map()` deve
   devolver para uma leitura bem no meio da faixa? E para uma leitura igual
   ao mínimo? Faça a conta e depois confira no Monitor.
4. Imprima a leitura e o brilho na mesma linha. No Monitor você deve ver
   algo como `ldr=347 brilho=12` (os seus números serão outros).
5. Mude a impressão para o formato do Plotter (`ldr:347,brilho:12`), abra o
   Plotter e cubra e descubra o LDR. As duas curvas devem subir e descer
   juntas.

### 1d. Quando o sensor passa da faixa

1. Aproxime a lanterna **mais** do que você fez na calibração. Olhe o valor
   de `brilho` no Monitor. O que aconteceu? Pode aparecer um número maior
   que 255, ou negativo no escuro total.
2. Por quê? O `map()` só faz uma regra de três: ele não sabe que o
   `analogWrite` aceita só de 0 a 255.
3. Procure a função `constrain()` na
   [referência do Arduino](https://docs.arduino.cc/language-reference/en/functions/math/constrain/)
   e use-a para manter o brilho entre 0 e 255. Teste de novo com a lanterna
   bem perto.

**Opcional, luz noturna:** inverta o mapeamento para o LED acender **mais**
quando estiver **mais escuro**. (Pista: só a ordem de dois números do
`map()` muda.)

> ⚠️ **Armadilhas deste bloco**
> - O `map()` **não limita** o resultado. Fora da faixa de entrada, a saída
>   também sai da faixa. Para limitar, use `constrain()`.
> - O `map()` só trabalha com **números inteiros**: as casas decimais são
>   cortadas. Isso volta no Bloco 2.
> - Cada bancada tem uma faixa diferente, porque depende da luz de cada
>   ponto da sala. Isso não é erro: é exatamente por isso que se calibra.

---

## Bloco 2 — LM35 no A2 (40 min)

O LM35 é um sensor de temperatura que entrega uma **tensão** proporcional
à temperatura: 10 mV para cada grau Celsius. O `analogRead` não sabe o que
é temperatura: ele só devolve um número de 0 a 1023. O caminho é sempre o
mesmo:

**contagens** (0 a 1023) → **tensão** (V) → **temperatura** (°C)

### 2a. Contagens → tensão → °C

1. Abra o sketch [`codigo_base/b2_lm35_temperatura`](codigo_base/b2_lm35_temperatura/b2_lm35_temperatura.ino)
   e carregue na placa. Ele já funciona: lê o A2 e imprime `cru` (a
   leitura) e `tempC` (a temperatura).
2. Leia a função `lerTemperatura()`. A conversão tem dois passos, os mesmos
   do exemplo `ReadAnalogVoltage` da aula passada: primeiro contagens para
   volts, depois volts para °C.
3. 🔍 **Datasheet** — abra
   [`datasheets/sensores/TI_LM35_Temperatura.pdf`](../../datasheets/sensores/TI_LM35_Temperatura.pdf)
   e encontre:
   - o fator de escala do sensor (quantos mV por °C?). Dica: primeira página;
   - a exatidão do **LM35D** (a versão do shield) a 25 °C. Dica: tabela
     *Electrical Characteristics*.
4. 🧮 **Cálculo:** a 25 °C, quantos volts o LM35 entrega? E quantas
   contagens o `analogRead` devolve, com a referência de 5 V? Que fração
   da faixa de 0 a 1023 isso ocupa?
5. Abra o Plotter. Confira se `tempC` está perto da temperatura da sala.
   Segure o LM35 entre os dedos: a curva deve subir devagar.

### 2b. Conta com `float` × conta com `map()`

1. No `loop()`, na linha marcada `ETAPA 2b`, calcule a temperatura também
   com o `map()`:

   ```cpp
   int tempMap = map(cru, 0, 1023, 0, 500);
   ```

   (Por que 0 a 500? Com 5 V de referência, 1023 contagens = 5 V = 500 °C
   pela regra do LM35.)
2. Acrescente `,tempMap:` e o valor na impressão. No Monitor você deve ver
   algo como `cru:57,tempC:27.9,tempMap:27`.
3. Os dois cálculos discordam. Por quê? (Pista: reveja as armadilhas do
   Bloco 1.)
4. Troque `Serial.println(tempC, 1)` por `Serial.println(tempC, 2)`. Agora
   aparecem 2 casas decimais. Isso quer dizer que o seu termômetro mede com
   precisão de 0,01 °C? Olhe a curva no Plotter: ela anda em "escadinhas".
   De quanto é cada degrau, em °C?

### 2c. A leitura que não para quieta

1. Deixe o LM35 parado e observe `cru` no Plotter por um minuto. A leitura
   oscila e às vezes dá saltos, mesmo com a temperatura parada.
2. Duas causas para discutir com a dupla:
   - **Resolução:** cada contagem do conversor equivale a um "degrau" de
     temperatura (o mesmo do 2b.4). Uma oscilação de só ±1 contagem já
     aparece como ±1 degrau.
   - **Memória do conversor:** dentro do microcontrolador, o conversor tem
     um pequeno capacitor que "guarda" a tensão da última leitura. Se o
     programa leu outro pino antes (o LDR, por exemplo), a primeira leitura
     do LM35 ainda sai contaminada. O LM35 fornece pouca corrente e demora a
     corrigir esse capacitor (o datasheet fala disso em *Capacitive Drive
     Capability*).
3. Melhore a `lerTemperatura()` na linha marcada `ETAPA 2c`. Três pistas:
   - faça uma leitura e **jogue fora** (não use o valor);
   - espere um pouco, por exemplo `delay(100)`;
   - faça **16 leituras**, some todas e divida por 16 (um laço de repetição
     ajuda). Atenção ao tipo da variável da soma: 16 × 1023 cabe num `int`?
4. Imprima também a leitura crua para comparar. No Plotter, a curva da
   média deve ficar bem mais "lisa" que a curva crua.

> 💡 **Por que a leitura fica isolada na função `lerTemperatura()`?** O
> resto do programa só pergunta "qual é a temperatura?" e não sabe *como*
> ela foi medida. No Bloco 4 você vai entender por que isso vale ouro.

---

## Bloco 3 — A referência do conversor (AREF) (30 min)

O conversor transforma tensão em número **comparando** com uma tensão de
referência: 0 V vira 0, e a referência vira 1023. Até agora a referência
foi a alimentação da placa (~5 V). A função `analogReference()` troca essa
referência.

### 3a. As três opções do UNO R3

| `analogReference(...)` | Referência | Faixa que dá para medir | 1 contagem vale |
|---|---|---|---|
| `DEFAULT` | Alimentação da placa (~5 V) | 0 a ~5 V | |
| `INTERNAL` | Tensão interna de ~1,1 V | 0 a ~1,1 V | |
| `EXTERNAL` | Tensão ligada no pino AREF | 0 até a tensão no AREF | depende |

1. 🧮 **Cálculo:** preencha a última coluna para `DEFAULT` e `INTERNAL`
   (em mV). Depois, converta para °C usando a regra do LM35.
2. 🔍 **Datasheet** — abra
   [`datasheets/ATmega328P_Datasheet_Microchip.pdf`](../../datasheets/ATmega328P_Datasheet_Microchip.pdf)
   e, na tabela de características do conversor (*ADC Characteristics*),
   encontre:
   - o valor mínimo, típico e máximo da referência interna (`Vint`);
   - a faixa permitida para a tensão de referência (`VREF`).

### 3b. LM35 com a referência INTERNAL

0. **Antes de mudar a referência**, anote na tabela do passo 6 a linha
   `DEFAULT`: o `cru` e a temperatura que o seu sketch do Bloco 2 mostra
   agora, com o LM35 parado.
1. No sketch do Bloco 2, na linha marcada `ETAPA 3b` do `setup()`,
   escreva `analogReference(INTERNAL);`.
2. Troque `TENSAO_REFERENCIA` de `5.0` para `1.1`. (Por que a conta precisa
   mudar junto?)
3. 🧮 **Cálculo:** com 1,1 V de referência, quantas contagens o LM35 deve
   dar a 25 °C? Compare com o seu cálculo do Bloco 2.
4. Para enxergar o que acontece logo depois da troca, deixe o programa
   rápido **só neste passo**: no `loop()`, troque o `delay(500)` por
   `delay(20)`, e na `lerTemperatura()` comente o `delay(100)` e a média
   (use uma leitura só). Carregue, abra o Plotter e **aperte o botão RESET**
   do shield com o Plotter já aberto. Olhe os primeiros instantes: a leitura
   começa no valor certo?
5. O que aconteceu: a placa tem um capacitor no pino AREF, que precisa de
   um tempo para descarregar de ~5 V até 1,1 V. O próprio datasheet avisa
   que *a primeira conversão depois de trocar a referência pode sair
   imprecisa*. Detalhe importante: o `analogReference()` só **anota** a
   referência escolhida; a troca só acontece de verdade no próximo `analogRead()`.
   Então, no `setup()`, logo depois do `analogReference(INTERNAL)`: faça
   **primeiro** uma leitura descartada (é ela que troca a referência) e
   **depois** espere cerca de meio segundo. Aperte RESET de novo e compare.
   Por fim, volte o `delay(500)`, o `delay(100)` e a média.
6. Preencha a tabela, com o LM35 parado na mesma bancada:

| Referência | `cru` (contagens) | Temperatura (°C) |
|---|---|---|
| DEFAULT (5 V) | | |
| INTERNAL (1,1 V) | | |

> 🔁 **Duas instabilidades, mesma cura.** No Bloco 2, o capacitor *de
> dentro* do conversor "lembrava" o pino lido antes. Aqui, o capacitor *do
> pino AREF* "lembra" a referência anterior. Nos dois casos: descartar a
> primeira leitura e esperar.

### 3c. O preço da precisão

1. 🔮 **Previsão:** ainda com `INTERNAL`, o que acontece se você ler o LDR
   (A1) ou o potenciômetro (A0)?
2. Teste: troque `PINO_SENSOR` para `A0` e gire o potenciômetro devagar,
   de uma ponta à outra. Em que parte do giro a leitura ainda muda?
3. Conclusão para anotar: a referência vale para **todos** os pinos
   analógicos ao mesmo tempo. Mais precisão (contagens menores) significa
   **menos faixa** de tensão.

Volte `PINO_SENSOR` para `A2`.

### 3d. EXTERNAL: só na teoria

Com `EXTERNAL`, você escolhe a referência ligando uma tensão no pino AREF.
Por exemplo, 3,3 V daria ao LM35 uma precisão entre a do `DEFAULT` e a do
`INTERNAL`. **Não vamos fazer na prática**: o shield cobre o pino AREF do
UNO e não tem um conector para ele.

> ⚠️ **Segurança — se um dia usar EXTERNAL**
> 1. Chame `analogReference(EXTERNAL)` **antes** de qualquer
>    `analogRead()`. Com uma tensão ligada no AREF, as outras referências
>    ficam **em curto** com ela dentro do chip (aviso do datasheet).
> 2. Ligue a tensão externa ao AREF através de um resistor em série
>    (~5 kΩ). Ele limita a corrente caso alguém esqueça o passo 1. Veja a
>    [referência de `analogReference()`](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReference/).

**Bônus (opcional): medir a tensão da própria placa.** Com a referência
`DEFAULT`, o conversor também consegue ler a referência interna de 1,1 V.
Então: `Vcc ≈ 1,1 × 1023 / leitura`. A sua placa recebe exatamente 5,0 V
pela USB? O que isso faz com as contas que usam `5.0` fixo? (Pesquise como
ler a referência interna no UNO: não é um pino `A0`–`A5`.)

> ⛔ **Antes do bloco 4: apague a linha `analogReference(INTERNAL)` e volte
> `TENSAO_REFERENCIA` para `5.0`.**

---

## Bloco 4 — O alarme de temperatura (50 min)

> ✅ **Confira antes:** você apagou o `analogReference(INTERNAL)` e voltou
> `TENSAO_REFERENCIA` para `5.0` (fim do Bloco 3)? Este bloco usa a
> referência `DEFAULT`. Por quê? Você vai entender no passo 4d.

### 4a. Montar o alarme com o LM35

Abra o sketch [`codigo_base/b4_alarme`](codigo_base/b4_alarme/b4_alarme.ino).
Ele compila e roda, mas o alarme ainda não decide nada.

1. Copie o **corpo** da sua `lerTemperatura()` do Bloco 2 (com descarte e
   média) para dentro da `lerTemperatura()` deste sketch. Mantenha a
   primeira linha como está: `float lerTemperatura() {`. Se a sua função
   usa alguma constante criada fora dela (por exemplo, o número de
   amostras da média), copie também as constantes que a função usa para o
   topo deste sketch.
2. Complete a função `atualizarSaidas()` seguindo esta especificação:
   - **LED RGB por faixa:** azul abaixo de uma faixa "confortável", verde
     dentro dela, vermelho acima do `LIMIAR` (30 °C). Você escolhe os
     limites da faixa confortável e cria constantes para eles.
   - **Buzzer (D5):** ligado acima do `LIMIAR`, desligado abaixo. Use
     `digitalWrite`, **não** `tone()`: o buzzer deste shield já apita
     sozinho, e o `tone()` usa o mesmo temporizador que faz o PWM do pino
     D11 (o verde do RGB).
   - **Estado:** atualize a variável `estado` com um texto curto para cada
     situação (por exemplo `FRIO`, `OK`, `ALARME`).
3. **Critério de aceite:** o painel no Monitor
   (`temp=26.3 lim=30.0 estado=OK`) mostra um `estado` coerente com a cor
   do LED e com o buzzer.

### 4b. Agora prove que funciona

Desafio: **mostre o alarme disparando acima de 30 °C e desligando quando
a temperatura volta a cair.** Mostre também as três cores.

Use o LM35 de verdade. Anote **quanto tempo** levou para testar tudo.

### 4c. Pare e pense

🔮 **Previsão:** como você testaria se o alarme dispara em 35 °C **sem**
esperar o sensor esquentar?

Discuta com a dupla e depois com a turma **antes de seguir**. Vale qualquer
ideia.

<details>
<summary>Travou? Uma pista</summary>

O que o potenciômetro do Bloco 0, o LDR do Bloco 1 e o LM35 têm em comum,
do ponto de vista do `analogRead`?

</details>

### 4d. Trocar o sensor em uma linha

**Só comece depois da discussão do 4c.**

1. No topo do sketch, troque `PINO_SENSOR` de `A2` para `A0`. Carregue e
   gire o potenciômetro.
2. Gire até o fim. Que "temperatura" aparece no painel? Faz sentido? Em
   que parte do giro estão os valores que importam para o seu alarme
   (perto de 30 °C)?
3. Ajuste a escala para o potenciômetro "fingir" uma faixa de temperatura
   realista, por exemplo de 15 °C a 45 °C.

   <details>
   <summary>Pista</summary>

   No Bloco 1 você já usou uma função para ajustar a faixa de um sensor.

   </details>

4. **Onde** esse ajuste deve ficar para o resto do programa nem perceber
   que o sensor mudou? (Pense na `lerTemperatura()` do Bloco 2.)
5. Por que este bloco usa `DEFAULT` e não `INTERNAL`? (Lembre do 3c.)
6. **Critério de aceite:** girando o potenciômetro, você mostra as três
   cores, o buzzer ligando e desligando e o painel acompanhando, em menos
   de um minuto.

### 4e. De volta ao sensor real

1. Volte `PINO_SENSOR` para `A2` (e desfaça o ajuste de escala do
   potenciômetro). O alarme continua funcionando com o LM35, agora com a
   lógica já testada.
2. Responda no caderno: **o que o teste com o potenciômetro NÃO valida?**

**Isso tem nome.** Trocar uma peça difícil de controlar (o sensor) por
outra que você controla (o potenciômetro), só para testar a lógica, é
usar um **dublê de teste**. Em software isso se chama *test double* ou
*mock*. Na indústria, a versão grande da mesma ideia é o *hardware-in-the-loop*
(HIL): o controlador real é testado com um simulador no lugar da máquina.

**Bônus (opcional): histerese.** Com o LM35 parado perto de 30 °C, o
buzzer pode ficar ligando e desligando sem parar. Por quê? (Lembre do
Bloco 2.) Como evitar? Pista: e se o alarme ligasse em 30 °C, mas só
desligasse em 29 °C?

---

## Se der errado

| Problema | O que fazer |
|---|---|
| O LM35 lê ≈ 0 °C ou um valor absurdo, mesmo com a média | Avise o professor: ele vai indicar como a sua bancada segue. Os valores das tabelas e dos cálculos não vão bater com a temperatura da sala. |
| A sala está acima de 30 °C e o alarme já começa disparado | Mude o `LIMIAR` para alguns graus acima da temperatura que aparece no painel. |
| O Plotter não mostra os nomes das curvas | Versão antiga da IDE. Use o Monitor Serial: o formato `nome:valor` continua legível. |
| No Bloco 4, o potenciômetro só muda a leitura num pedacinho do giro | Sobrou um `analogReference(INTERNAL)` no código. Apague a linha e volte `TENSAO_REFERENCIA` para `5.0`. |
| O Plotter ou o Monitor mostra caracteres estranhos | Confira a velocidade no canto da janela: 9600 baud, a mesma do `Serial.begin`. |

---

## Fechamento

Responda no caderno, uma pergunta por bloco:

1. **LDR:** por que é preciso medir a faixa do sensor antes de usar o
   `map()`? O que o `constrain()` resolve que o `map()` não resolve?
2. **LM35:** por que imprimir 2 casas decimais não significa medir com
   precisão de 0,01 °C?
3. **AREF:** em que situação vale a pena trocar para `INTERNAL`? E quando
   isso atrapalha?
4. **Dublê:** o que o teste com o potenciômetro valida, e o que ele não
   valida?

### Fontes

- Datasheet do LM35 (Texas Instruments):
  [`datasheets/sensores/TI_LM35_Temperatura.pdf`](../../datasheets/sensores/TI_LM35_Temperatura.pdf)
- Datasheet do ATmega328P (Microchip), seção do conversor A/D (*ADC*):
  [`datasheets/ATmega328P_Datasheet_Microchip.pdf`](../../datasheets/ATmega328P_Datasheet_Microchip.pdf)
- Referência Arduino:
  [`analogRead()`](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/),
  [`analogReference()`](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReference/),
  [`map()`](https://docs.arduino.cc/language-reference/en/functions/math/map/),
  [`constrain()`](https://docs.arduino.cc/language-reference/en/functions/math/constrain/)
