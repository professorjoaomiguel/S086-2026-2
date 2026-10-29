# Doc 2 de 3 — Muitos dígitos, poucos fios
*LAB02-D2 · v1.0 · 2026-10-22*

**UC S086 — Sistemas Microprocessados** · Tinkercad Circuits (Arduino UNO R3 simulado)
*Este documento é o roteiro **e** o relatório. Um arquivo por dupla: os dois alunos entregam o mesmo arquivo.*

No Doc 1, um display gastou **7 pinos** do Arduino. Quatro displays gastariam 28, e o UNO não tem tantos. Aqui as **7 linhas de segmento serão compartilhadas** por todos os displays, e o Arduino vai acender **um dígito de cada vez**, tão rápido que o olho vê todos acesos.

## Identificação

| Campo | Preencha |
|---|---|
| Aluno 1 (piloto) | |
| Aluno 2 (navegador) | |
| Turma / bancada | |
| Data | |

## Componentes utilizados neste documento

Tudo aqui é **no Tinkercad**. Continue no circuito do Doc 1 (Etapa 1B).

| Componente (Tinkercad) | Usou? (S ou N) | Anote |
|---|---|---|
| Arduino Uno R3 | | |
| Placa de ensaio (protoboard) | | |
| Displays de 7 segmentos (2 no 2A, 4 no 2B) | | Todos em cátodo? |
| 7 resistores 220 Ω (um por segmento, do Doc 1) | | |
| Transistores NPN (1 por dígito) | | Quantos? |
| Resistores 1 kΩ (1 na base de cada NPN) | | |

## Como trabalhar

Igual ao Doc 1 (veja lá a tabela **piloto e navegador** e os combinados). Resumo: **piloto** opera o Tinkercad, um passo por vez, dizendo o que faz; **navegador** lê em voz alta, confere e registra aqui, sem digitar o código. Os dois pensam juntos nas perguntas. **Vale trocar de papel** ao começar cada etapa (2A, 2B, 2C); antes de trocar, mande o código pelo Telegram. ⚡ para quem já domina; itens *(se sobrar tempo)* podem ficar em branco.

**Mudou o código ou um fio?** **Pare e inicie** a simulação de novo. **Erro no código?** Leia a **primeira** mensagem de erro: ela diz a linha.

| Selo | Significa |
|---|---|
| 🔮 | **Previsão:** responda *antes* de testar. Não precisa acertar. |
| 🧮 | **Cálculo:** faça a conta antes de conferir. |
| 🔍 | **Pesquisa** na web: anote a fonte (link). |
| ☑️ | **Múltipla escolha:** escreva a letra da resposta. |
| 🔒 | **Fechada:** responda por extenso, ligando teoria e o que você viu. |
| 💭 | **Aberta:** sem resposta certa; opine e justifique. |
| 📸 | **Mídia:** **foto, print de tela ou GIF** (vídeo não cola no Docs). |

> **Perdeu a tabela `SEG[10]` do Doc 1?** Não refaça agora: peça ao professor ou a outra dupla pelo Telegram e cole no seu código.

### Glossário rápido

| Palavra | Quer dizer |
|---|---|
| **multiplexação** | usar as **mesmas linhas** (aqui: a–g) para vários dispositivos, um de cada vez |
| **varredura** | passar pelos dígitos em sequência: acende o 1º, apaga, acende o 2º, … e recomeça |
| **persistência da visão** | o olho "segura" a imagem por uma fração de segundo; se a troca for rápida, vemos tudo aceso ao mesmo tempo |
| **frequência de varredura** | quantas **voltas completas** pelos dígitos acontecem por segundo (em Hz) |
| **`millis()`** | função que diz há quantos milissegundos o Arduino está ligado; serve para medir tempo **sem parar** o programa |

### Referências

- [Documentação da linguagem Arduino (português)](https://docs.arduino.cc/language-reference/pt/): [`digitalWrite()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/digital-io/digitalWrite/) · [`delay()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/delay/) · [`millis()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/millis/) · [`bitRead()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/bits-and-bytes/bitRead/)
- Esquemas de ligação desta atividade: [2A dois dígitos](../../imagens/lab02_2a_dois_digitos.png) · [2B quatro dígitos](../../imagens/lab02_2b_quatro_digitos.png) (use **depois de tentar sozinho**, para conferir, não para copiar).
- Sketches de referência na pasta `labs/lab02_displays_7seg/codigo_base` do repositório: `b1_dois_digitos`, `b2_quatro_digitos`, `b3_contador_millis`. **Só para conferir depois** que o seu funcionar (ou se travar de vez).

**Tempo deste documento: ~30 min.** Ao terminar, entregue pelo Classroom e abra o **Doc 3 de 3**.

---

# Etapa 2A — Dois displays, os mesmos 7 fios (11 min)

> 🧭 **Orientação:** um segundo display entra **pendurado nas mesmas linhas a–g**. Sozinho, isso só copia o número. O truque é ligar **um dígito de cada vez**. **Ao final desta etapa os dois displays mostram 42, e você viu a troca ficar rápida demais para o olho.**

**Pinos:** a–g = D2–D8 (como no Doc 1) · seleção: D9 = dezena (display 1), D10 = unidade (display 2).

## 2A.1 Segundo display em paralelo (3 min)

1. **Piloto:** arraste um **segundo display** ao lado do primeiro. Clique nele e **confira que o comum está em "cátodo"**.
2. Ligue cada segmento a–g do display 2 **no mesmo ponto** do segmento de mesmo nome do display 1 (depois do resistor, do lado do display). **Não** acrescente resistores: os 7 do Doc 1 servem aos dois.
3. Ligue o comum do display 2 no **GND**, como o do display 1.
4. 🔮 Com o código do Doc 1 (contagem de 0 a 9) ainda no Arduino, o que os dois displays vão mostrar? ______________________
5. Inicie a simulação. Acertou? (S ou N): ______

> 🔎 **Se não funcionou, olhe nesta ordem:**
> 1. A simulação está **rodando**, com o código do Doc 1 (1B) no editor?
> 2. Display 2 apagado: o **comum** dele vai ao GND? A propriedade está em **cátodo**?
> 3. Display 2 com segmentos faltando: o fio desse segmento sai do **mesmo ponto** do display 1, **depois** do resistor (do lado do display)?

## 2A.2 Uma chave por dígito (4 min)

Para escolher **qual** display acende, o comum de cada um passa por um **transistor NPN**, que funciona como chave: **nível ALTO na base = dígito ligado**. *(Por que um transistor e não o pino direto: fica para o 2B.)*

1. **Piloto:** pare a simulação. **Tire os dois fios** que ligam os comuns ao GND.
2. Arraste **dois transistores NPN**. Passe o mouse sobre os terminais: o Tinkercad mostra **base**, **coletor** e **emissor**.
3. Em cada NPN: **emissor no GND** e **coletor no comum** do seu display. *(A ordem importa: invertido, o dígito não acende.)*
4. Agora só os fios de controle: **D9 → resistor de 1 kΩ → base do NPN do display 1**; **D10 → 1 kΩ → base do NPN do display 2**.
5. Confira com o esquema [lab02_2a_dois_digitos.png](../../imagens/lab02_2a_dois_digitos.png) **depois** de montar. Achou alguma diferença? Qual? ______________________

## 2A.3 Varredura lenta, à mão (3 min)

1. **Piloto:** no editor, apague tudo e escreva este esqueleto, colando a **sua** tabela `SEG` do Doc 1:

   ```cpp
   const byte PINOS_SEG[7] = {2, 3, 4, 5, 6, 7, 8};   // a, b, c, d, e, f, g
   const byte PINOS_DIG[2] = {9, 10};                 // 0 = dezena, 1 = unidade

   const byte SEG[10] = { /* cole aqui a sua tabela do Doc 1 */ };

   const unsigned int TEMPO_DIGITO_MS = 500;          // quanto cada dígito fica aceso

   // Acende UM dígito: o display "posicao" mostra o algarismo "valor".
   void mostrarDigito(byte posicao, byte valor) {
     // 1) desligue TODOS os pinos de seleção (LOW)
     // 2) escreva os 7 segmentos de SEG[valor] (como no loop do Doc 1)
     // 3) ligue (HIGH) só o pino de seleção de "posicao"
   }

   void setup() {
     for (byte i = 0; i < 7; i++) pinMode(PINOS_SEG[i], OUTPUT);
     for (byte d = 0; d < 2; d++) pinMode(PINOS_DIG[d], OUTPUT);
   }

   void loop() {
     // ETAPA 2A.3: mostre 4 na dezena, espere; mostre 2 na unidade, espere
   }
   ```

   - **Onde colar:** só os **10 valores** da sua tabela, entre as chaves de `const byte SEG[10] = { … };`, no lugar do comentário `/* cole aqui a sua tabela do Doc 1 */`.
   - **Se não funcionou, olhe:**
     1. Erro `redefinition of 'const byte SEG [10]'`: você colou a declaração inteira do Doc 1 **além** da linha do esqueleto. Fica uma só.
     2. Erro `expected primary-expression before 'const'`: a linha `const byte SEG[10] = {` foi colada **dentro** das chaves. Deixe só os valores.

2. Escreva o corpo de `mostrarDigito` seguindo os 3 comentários.
   - **Onde escrever:** dentro de `mostrarDigito`, um trecho **embaixo** de cada comentário 1), 2) e 3), nessa ordem.
3. Escreva o `loop()`: dezena = 4, espera `TEMPO_DIGITO_MS`; unidade = 2, espera `TEMPO_DIGITO_MS`.
4. Inicie a simulação. Com 500 ms você deve ver **4** e **2** se alternando, com **um display apagado de cada vez**. Isso é o esperado. Funcionou? (S ou N): ______
   - **Se não funcionou, olhe:**
     1. Os dois displays acesos juntos, com o mesmo número: sobrou o fio do comum ao GND do 2A.1 (agora o comum vai **só** ao coletor)? O trecho 1) desliga **os dois** pinos de `PINOS_DIG` **antes** de escrever os segmentos?
     2. Nenhum display (ou um só) acende: o trecho 3) põe **HIGH** em `PINOS_DIG[posicao]`? No NPN apagado: **emissor** no GND, **coletor** no comum e **base** pelo 1 kΩ no D9 (dezena) ou D10 (unidade)?
     3. O 4 não aparece (só o 2): a sua tabela `SEG` tem o 4? Quem pulou 4 a 9 no Doc 1 completa agora (ou pede pelo Telegram).
     4. O 2 quase não aparece: falta a **segunda** espera, depois da unidade.

## 2A.4 Acelerar até enganar o olho (1 min)

1. Troque `TEMPO_DIGITO_MS` e anote o que vê em cada valor (alterna, pisca, parece fixo, "fantasma" do outro dígito, brilho fraco):
   - **Onde mexer:** na linha `const unsigned int TEMPO_DIGITO_MS = 500;`, no começo do código. Pare a simulação, troque o número e inicie de novo.

| `TEMPO_DIGITO_MS` | O que você viu |
|---|---|
| 500 | |
| 20 | |
| 5 | |

| 📸 Cole aqui: **um print** em 5 ms (42 parecendo fixo nos dois displays) |
|---|
| |

2. 🔒 Em 5 ms, **só um** display está aceso em cada instante. Por que você vê os dois acesos? Use **persistência da visão** na resposta. ______________________

| 📝 Cole aqui: o código final (via Telegram) |
|---|
| |

> ⚡ **Já domina?** Monte, escreva `mostrarDigito` e o `loop()` direto em 5 ms, preencha só as linhas 500 e 5 da tabela e responda o 2A.4-2.

**📎 Evidência — Etapa 2A:** confira que tem: previsão 2A.1-4 · diferença com o esquema (2A.2-5) · tabela de tempos · um print · resposta 2A.4-2 · código final

---

# Etapa 2B — Quatro displays: o que mostrar e como atualizar (10 min)

> 🧭 **Orientação:** dobrar para 4 dígitos custa só **2 pinos a mais**. No código, separe **o que mostrar** (um vetor) de **como atualizar** (a varredura). **Ao final desta etapa os quatro displays mostram 1234.**

**Pinos:** a–g = D2–D8 · seleção: D9 = milhar, D10 = centena, D11 = dezena, D12 = unidade.

## 2B.1 Por que o transistor? (1 min)

1. 🧮 Cada segmento aceso puxa cerca de **13 mA**. No "8", com os 7 segmentos acesos, quanta corrente passa pelo **comum** do display? ______ mA
2. 🔒 Um pino do Arduino aguenta com segurança cerca de **20 mA**. Por que não ligar o comum direto num pino de seleção, e por que o NPN resolve? *(O Tinkercad não reclama; a placa real, sim.)* ______________________

## 2B.2 Mais dois displays, copiando o bloco (5 min)

> Atalho opcional: o professor pode oferecer um circuito pronto do Tinkercad com os quatro displays já posicionados. Se usar, confira as ligações pelos passos abaixo.

1. **Piloto:** selecione **juntos** o display 2, o seu NPN, o resistor de 1 kΩ da base e os fios entre eles (arraste uma caixa de seleção em volta, ou `Shift` + clique em cada um).
2. `Ctrl+C` / `Ctrl+V` **duas vezes**: surgem os blocos dos **displays 3 e 4**. O Tinkercad costuma manter os fios **internos** do bloco copiado (comum → coletor, resistor → base), mas **confira cada fio do bloco colado**; os fios que iam ao Arduino e às linhas a–g não vêm junto. O bloco colado pode cair **em cima do original**: arraste-o para o lado. Confira **cátodo** em cada display novo.
3. Ligue os segmentos a–g de cada display novo **nos mesmos pontos** das linhas a–g (depois dos resistores, do lado do display). Ainda **7 resistores** de segmento no total.
4. Ligue o **emissor** de cada NPN novo no **GND**.
5. Só os fios de controle: **D11 → resistor** da base do NPN do display 3; **D12 → resistor** da base do NPN do display 4.
6. Confira com o esquema [lab02_2b_quatro_digitos.png](../../imagens/lab02_2b_quatro_digitos.png) **depois** de montar.

## 2B.3 Separar o que mostrar de como atualizar (3 min)

1. **Piloto:** no seu código do 2A, troque `PINOS_DIG` por 4 pinos `{9, 10, 11, 12}`, ajuste os laços de 2 para 4 e `TEMPO_DIGITO_MS` para **2**.
   - **Onde mexer:** na linha `const byte PINOS_DIG[2]` (os pinos **e** o tamanho `[2]`); no trecho 1) de `mostrarDigito` (agora desliga **4** pinos) e no laço `d < 2` do `setup()`; na linha de `TEMPO_DIGITO_MS`.
   - **Se não funcionou, olhe:** erro `too many initializers`? Há 4 pinos, mas o tamanho ainda é `[2]`.
2. Acrescente, antes de `setup()`:

   ```cpp
   byte exibir[4] = {1, 2, 3, 4};   // O QUE mostrar: um algarismo por posição

   // COMO atualizar: uma volta pelos 4 dígitos, lendo exibir[]
   void varrer() {
     // ETAPA 2B.3: para cada posição p de 0 a 3, mostre exibir[p] e espere TEMPO_DIGITO_MS
   }
   ```

   - **Onde colar:** depois da `}` que fecha `mostrarDigito` e **antes** de `void setup()`, fora de qualquer `{ }`.
   - **Se não funcionou, olhe:**
     1. Erro `a function-definition is not allowed here`: o bloco caiu **dentro** de outra função.
     2. Erro `'TEMPO_DIGITO_MS' was not declared in this scope`: o bloco ficou **acima** dessa constante.

3. Escreva o corpo de `varrer()` e deixe o `loop()` só com `varrer();`.
   - **Onde mexer:** dentro de `varrer()`, abaixo do comentário `// ETAPA 2B.3`. No `loop()`, apague as linhas do 2A.
   - **Se não funcionou, olhe:**
     1. Ainda aparece 42, ou algo misturado: sobrou código do 2A no `loop()`.
     2. Aparece **0123**: você mandou a **posição** `p` como algarismo; o algarismo vem de `exibir[p]`.
     3. 1234 fora de ordem: D9 a D12 vão aos displays da esquerda para a direita (D9 = milhar)?
4. Inicie a simulação. Aparece **1234**? (S ou N): ______ Troque `exibir` para `{9, 8, 7, 6}` **sem mexer em `varrer()`**. Mudou? ______
   - **Se não funcionou, olhe:**
     1. Displays 3 e 4 sempre acesos, com algarismos misturados: o trecho 1) de `mostrarDigito` ainda desliga só 2 pinos.
     2. Displays 3 e 4 apagados ou fracos: o laço do `setup()` ainda vai só até 2 (os pinos 11 e 12 não viraram saída).
     3. Display novo apagado ou com segmentos faltando, com o código certo: está em **cátodo**? No NPN dele, **emissor** no GND, **coletor** no comum e **base** pelo 1 kΩ no D11 ou D12? a–g nos **mesmos pontos** das linhas a–g?

| 📸 Cole aqui: **um print** com 1234 (ou 9876) nos quatro displays |
|---|
| |

## 2B.4 Linhas compartilhadas (1 min)

1. 🧮 Quantos pinos do Arduino o circuito usa (segmentos + seleção)? ______ E quantos usaria com 4 displays **sem** multiplexar? ______
2. 🔒 No Doc 1 você viu que **um resistor no comum** deixa o brilho variando com o número. Aqui há **7 resistores** para **4 displays**. Por que um resistor **por segmento** (e não por dígito) funciona com a varredura? *Dica: quantos dígitos estão acesos de cada vez?* ______________________

> ⚡ **Já domina?** Faça 2B.1, monte, escreva `varrer()` e responda 2B.4. Desafio *(se sobrar tempo)*: 🔍 o CI **74HC595** (existe no Tinkercad) economiza ainda mais pinos. Quantos pinos ele usa e como? Anote a fonte (link). ______________________

**📎 Evidência — Etapa 2B:** confira que tem: conta e resposta 2B.1 · print com 1234 · troca de `exibir` sem mexer em `varrer()` · respostas 2B.4

---

# Etapa 2C — Contador 0000–9999 sem travar a varredura (9 min)

> 🧭 **Orientação:** agora o número muda sozinho, uma vez por segundo, enquanto a varredura não pode parar. Duas tarefas com ritmos diferentes no mesmo `loop()`. **Ao final desta etapa o display conta 0000, 0001, 0002… sem piscar.**

## 2C.1 Do número aos quatro algarismos (2 min)

1. **Piloto:** acrescente uma variável `unsigned int contador = 2026;` e a função `void atualizarExibir()`, que separa `contador` em milhar, centena, dezena e unidade e guarda em `exibir[0]` … `exibir[3]`. *(Use `/ 1000`, `/ 100`, `/ 10` e `% 10`.)*
   - **Onde escrever:** `contador` logo abaixo da linha `byte exibir[4]`; a função `atualizarExibir()` logo abaixo de `contador`, antes de `void setup()`.
   - **Se não funcionou, olhe:**
     1. Erro `'contador' was not declared in this scope`: a variável ficou **abaixo** da função que a usa.
     2. Um dígito com desenho estranho (ou apagado): quanto dá `2026 / 100`? Cada posição de `exibir` só pode guardar de 0 a 9.
2. Chame `atualizarExibir()` no fim do `setup()`. Aparece **2026**? ______ Troque para `contador = 7;`. Aparece **0007**? ______ *(Os zeros à esquerda são esperados.)*
   - **Onde mexer:** a chamada vai na **última** linha dentro de `setup()`, antes da `}`. O 7 entra na própria linha de `contador`.
   - **Se não funcionou, olhe:** ainda aparece 1234? A chamada está **dentro** do `setup()`? O circuito é o do 2B: se o 1234 apareceu lá, a fiação está certa e o problema está no código.

> 🛑 **PONTO DE PARADA:** se 2026 e 0007 aparecem certos, a etapa já vale a entrega. Faltando menos de 5 min, pule para **"Você leva"** e entregue; o resto fica *(se sobrar tempo)*.

## 2C.2 E se usar `delay(1000)`? (2 min)

1. 🔮 Alguém escreve o `loop()` assim:

   ```cpp
   void loop() {
     varrer();
     delay(1000);
     contador++;
     atualizarExibir();
   }
   ```

   O que você vai ver nos displays? ______________________

2. Teste. O que viu? ______________________
   - Deve sobrar **um** só `void loop()`: dois dão erro `redefinition of 'void loop()'`.
3. 🔒 Por que o `delay(1000)` estraga a varredura? ______________________

## 2C.3 Contar com `millis()` (3 min)

A ideia: em vez de **esperar** 1 s, o `loop()` **pergunta** a cada volta se já passou 1 s desde a última contagem. Se não passou, segue varrendo.

1. **Piloto:** no `loop()` do 2C.2, apague o `delay(1000)` **e** as linhas `contador++;` e `atualizarExibir();` (elas voltam no passo 3, dentro do `if`). Acrescente antes de `setup()`: `unsigned long ultimaConta = 0;`
2. Use este molde no `loop()`, depois de `varrer();`:

   ```cpp
     if (millis() - ultimaConta >= 1000) {
       ultimaConta = millis();
       // ETAPA 2C.3: conte +1, volte a 0 depois de 9999, atualize exibir[]
     }
   ```

3. Escreva as linhas que faltam. **Volte o início para `contador = 0;`** (no 2C.1 estava em 2026 e depois em 7).
   - **Onde escrever:** no lugar do comentário `// ETAPA 2C.3`; o `0` vai na linha de `contador`.
   - **Se não funcionou, olhe:**
     1. O número não muda: depois de contar, chamou `atualizarExibir()`?
     2. Ainda pisca a cada segundo: sobrou o `delay(1000)` no `loop()`.
     3. A contagem dispara: as duas linhas do 2C.2 ficaram **fora** do `if`.
     4. Depois de 9999 aparece um desenho estranho (ou apagado) no milhar: o `contador` passou de 9999 sem voltar a 0.
4. Inicie a simulação. Conta 0000, 0001, 0002… sem piscar? ______ Para testar a volta, comece em `contador = 9995`. Depois de 9999 vem **0000**? ______

| 📸 Cole aqui: **um GIF** da contagem (ou **dois prints** com números diferentes) |
|---|
| |

| 📝 Cole aqui: o código final (via Telegram) |
|---|
| |

## 2C.4 Qual a varredura mínima? (2 min)

1. 🧮 Exemplo com `TEMPO_DIGITO_MS = 10`: 10 ms × 4 dígitos = **40 ms por volta**; 1000 ms ÷ 40 ms = **25 voltas por segundo (25 Hz)**. Agora faça com `TEMPO_DIGITO_MS = 2`: uma volta leva ______ ms, ou seja, ______ Hz
2. Aumente `TEMPO_DIGITO_MS` (5, 10, 15, 20…) até começar a piscar. Em qual valor começou? ______ Qual a frequência? ______ Hz *(O Tinkercad pode simular mais devagar que o tempo real; anote o que viu.)*
3. 💭 Qual frequência de varredura mínima você escolheria para não piscar, e por quê? ______________________

> ⚡ **Já domina?** Faça 2C.1, vá direto ao `millis()` (2C.3) e responda 2C.4. Desafio *(se sobrar tempo)*: o seu `varrer()` ainda usa `delay(2)`. Reescreva-o com `millis()`, acendendo **um dígito por chamada**, sem nenhum `delay()`.

*Extensão futura (não nesta atividade): a varredura pode ser feita por um **timer com interrupção**, sem depender do `loop()`.*

**📎 Evidência — Etapa 2C:** confira que tem: 2026 e 0007 · previsão e resposta 2C.2 · GIF ou prints da contagem · código final com `millis()` · contas e resposta 2C.4 (se fez)

---

# Você leva para o próximo documento

No **Doc 3** (na bancada, com um módulo de 4 dígitos real), compare o que o chip faz com o que **você fez à mão** aqui:

- o vetor **`exibir[4]`**: **o que** mostrar, um algarismo por posição;
- a **varredura**: `varrer()` chamando `mostrarDigito(posicao, valor)`, um dígito de cada vez;
- a **frequência de varredura**: rápida o bastante para a persistência da visão esconder a troca;
- o **`millis()`**: medir tempo sem parar o programa, para a contagem não travar a varredura.

**Entrega:** salve o arquivo, entregue no Classroom e abra o **Doc 3 de 3 — Módulo e biblioteca**, que é feito **só na bancada**.
