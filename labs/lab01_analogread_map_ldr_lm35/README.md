# Lab 01 — analogRead, map() e AREF: LDR, LM35 e o potenciômetro como dublê

**UC S086 — Sistemas Microprocessados** · Arduino UNO R3 + Shield 9-em-1 · ~3 h

## Objetivos

Ao final deste laboratório, você vai saber:

1. **Calibrar** um sensor (medir a faixa real dele) e usar `map()` e
   `constrain()` com essa faixa.
2. **Converter** a leitura do LM35 em graus Celsius e **reduzir o ruído**
   da leitura.
3. **Comparar** as referências do conversor `DEFAULT` e `INTERNAL`:
   o que você ganha e o que você perde.
4. **Validar** a lógica de um alarme **trocando o sensor por um
   potenciômetro**, sem esperar o sensor esquentar.

## Antes de começar

Encaixe o Shield 9-em-1 no UNO R3 e ligue o cabo USB. Os componentes que
você vai usar:

| Componente | Pino | Detalhe importante |
|---|---|---|
| Potenciômetro | A0 | Gira de 0 V até 5 V |
| LDR (sensor de luz) | A1 | Neste shield, **a leitura SOBE com mais luz** |
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
   - **Resolução:** cada contagem do conversor vale alguns décimos de grau.
     Uma oscilação de ±1 contagem já aparece como ±meio grau, mais ou menos.
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
