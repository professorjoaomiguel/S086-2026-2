# Parte 1 de 3 — Do bit ao segmento
*LAB02-P1 · v1.8 · 2026-11-05*

**UC S086 — Sistemas Microprocessados** · Tinkercad Circuits (Arduino UNO R3 simulado)
*Este documento é o roteiro **e** o relatório. Um arquivo por dupla: os dois alunos entregam o mesmo arquivo.*

# 🧰 PREPARAÇÃO — leia antes de começar

> **Esta parte é só leitura e combinados**: o relógio da atividade **ainda não começou**. Preencha a **Identificação** e a tabela de componentes à medida que avançar. Quando terminar de ler, desça até a faixa verde **🚀 ATIVIDADE**.

> **📝 Como preencher este documento (leia antes de começar)**
>
> 1. Este arquivo é um **Google Docs**. Abra-o pelo Classroom com a sua **conta Google educacional** e **digite direto nele**. A dupla edita **um único arquivo**.
> 2. Onde houver uma linha **______** ou uma tabela vazia, **escreva a resposta ali**, no lugar do traço.
> 3. Nas questões **☑️ (múltipla escolha)**, escolha **uma só alternativa** e **escreva a letra** no campo **"Sua resposta (letra): ______"**, logo abaixo das alternativas. Exemplo: `Sua resposta (letra): c`.
> 4. Não apague as perguntas nem os quadros: responda **por cima** deles.

## Identificação

| Campo | Preencha |
|---|---|
| Aluno 1 (piloto) | |
| Aluno 2 (navegador) | |
| Turma / bancada | |
| Data | |

## Componentes utilizados neste documento

Marque o que a dupla usou e anote o que for pedido. Tudo aqui é **no Tinkercad**, não na bancada.

| Componente (Tinkercad) | Usou? (S ou N) | Anote |
|---|---|---|
| Arduino Uno R3 | | |
| Protoboard | | |
| LED + resistor 220 Ω (Etapa 0) | | |
| Display de 7 segmentos | | Comum: cátodo ou ânodo? |
| CD4511 (Etapa 1A) | | |
| 7 resistores 220 Ω (um por segmento) | | |

## Como trabalhar

### Piloto e navegador

A dupla trabalha com **dois PCs e dois papéis**.

| | **Piloto** | **Navegador** |
|---|---|---|
| **Faz** | Opera o **Tinkercad**: monta o circuito, liga os fios, escreve e edita o código, inicia a simulação. | Conduz **este roteiro**: lê cada passo em voz alta, confere se foi feito, e **registra** aqui (respostas, prints, GIFs, código). |
| **Espera-se** | Executar **um passo por vez**, só depois que o navegador ler. Avisar o que está fazendo e o que está vendo (ex.: "liguei o D2 no A do CI, o display mostra 1"). | Ler com calma, **não pular passos**, cobrar o registro e só avançar quando o piloto confirmar. Chamar o professor se algo não bater. |
| **Não faz** | Não avança sozinho sem o roteiro. | Não digita o código nem mexe no circuito, mas **orienta e questiona**. |

- Os dois **pensam juntos** nas perguntas 🔮 🧮 🔒 💭. Quem não está com a mão no teclado raciocina em voz alta.
- **Podem trocar de papel durante a prática.** É convite, não obrigação. Boas horas de trocar: ao começar cada etapa (0, 1A, 1B) ou quando um dos dois estiver perdido. Quem só pilotou aprende outra coisa navegando.
- **Antes de trocar:** copie o código do Tinkercad, mande-o pelo Telegram e passe o registro para o PC de quem vai navegar. Para o circuito, use *Compartilhar* ou entre com a mesma conta.
- **Dica:** o relatório é um arquivo só, então combinem quem o mantém aberto (o navegador) e mandem o código pelo Telegram para colar nele.

### Demais combinados

- **Foto, print ou GIF no Google Docs:** *Inserir → Imagem*, ou cole com `Ctrl+V`. Print de tela no Windows: `Win + Shift + S`. **Vídeo não cola no Docs; GIF cola** (como imagem).
- **Telegram Web** aberto nos dois PCs: o piloto envia o código, o navegador cola no relatório.
- Um passo de cada vez, na ordem em que aparecem.
- **Mudou o código ou um fio?** **Pare e inicie** a simulação de novo.
- **Erro no código?** Leia a **primeira** mensagem de erro: ela diz a linha.
- ⚡ **Já domina?** Faça só o que o selo pede e siga.
- Estourou o tempo? **Siga adiante** e volte depois. As seções **⭐ EXTRA** são opcionais e podem ficar em branco.
- **Trocar de documento conta no tempo** (~2 min): entregue pelo Classroom e abra o próximo.
- **Código no Tinkercad:** botão **Código** → troque *Blocos* por **Texto**. O Tinkercad não abre arquivo `.ino`: abra o sketch no navegador ou no Telegram, copie o texto e cole no editor.
- **Os sketches** estão no repositório
  <https://github.com/professorjoaomiguel/S086-2026-2>, nos sketches `a1_bcd_cd4511` (1A) e `a2_tabela_segmentos_esqueleto` (1B) (pasta `labs/lab02_displays_7seg/codigo_base`), ou no link que o professor enviar no Telegram.

| Selo | Significa |
|---|---|
| 🔮 | **Previsão:** responda *antes* de testar. Não precisa acertar. |
| 🧮 | **Cálculo:** faça a conta antes de conferir. |
| 🔍 | **Pesquisa** na web: anote a fonte (link). |
| ☑️ | **Múltipla escolha:** escreva a letra da resposta. |
| 🔒 | **Fechada:** responda por extenso, ligando teoria e o que você viu. |
| 💭 | **Aberta:** sem resposta certa; opine e justifique. |
| ⭐ | **EXTRA:** opcional, só se sobrar tempo; pode ficar em branco. |
| 📸 | **Mídia:** **foto, print de tela ou GIF** (vídeo não cola no Docs). |

### Glossário rápido

| Palavra | Quer dizer |
|---|---|
| **segmento** | cada um dos 7 traços do display (a, b, c, d, e, f, g). **Cada segmento é um LED** |
| **cátodo comum** | display em que os cátodos (−) dos 7 LEDs estão ligados num pino só, que vai ao GND. O segmento acende com nível **ALTO** |
| **peso** | o valor que um algarismo ou bit tem por causa do **lugar** onde está (decimal: 100, 10, 1; binário: 8, 4, 2, 1) |
| **MSB** / **LSB** | bit mais significativo (maior peso, à esquerda) / menos significativo (menor peso, à direita) |
| **BCD** | *decimal codificado em binário*: cada algarismo de 0 a 9 escrito com 4 bits (ex.: 6 = `0110`) |
| **CD4511** | circuito integrado que recebe 4 bits BCD e acende os segmentos certos do display |
| **tabela de consulta** | um vetor em que a posição é o símbolo e o valor guardado diz o que fazer (aqui: quais segmentos acender) |

### Referências

- [Documentação da linguagem Arduino (português)](https://docs.arduino.cc/language-reference/pt/): [`pinMode()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/digital-io/pinMode/) · [`digitalWrite()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/digital-io/digitalWrite/) · [`delay()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/delay/) · [`bitRead()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/bits-and-bytes/bitRead/)
- [Tinkercad Circuits](https://www.tinkercad.com/circuits): entre com a conta indicada pelo professor.
- Esquemas de ligação desta atividade: [1A com CD4511](../../imagens/lab02_1a_cd4511.png) · [1B direto no Arduino](../../imagens/lab02_1b_direto.png) (use **depois de tentar sozinho**, para conferir, não para copiar).

**Tempo da ATIVIDADE: ~30 min** (a preparação é leitura de uns 3 min). Ao terminar, entregue pelo Classroom e abra a **Parte 2 de 3**.

**✅ Antes de descer, confira:** (1) Identificação preenchida · (2) piloto e navegador definidos · (3) Telegram Web aberto nos dois PCs · (4) Tinkercad aberto com a conta indicada pelo professor

---

# 🚀 ATIVIDADE — comece aqui

> **Daqui para baixo é a atividade:** um passo de cada vez, na ordem. O tempo de cada etapa vale a partir deste ponto.

# Etapa 0 — Aquecimento no Tinkercad: um segmento é um LED (7 min)

> 🧭 **Orientação:** antes do display, garanta que a dupla sabe montar e simular no Tinkercad, e veja que o display é só um conjunto de LEDs. **Ao final desta etapa um LED pisca na simulação e você acendeu um segmento do display "na mão".**

## Conhecer a protoboard (leitura, 2 min)

A **protoboard** (placa de ensaio) liga componentes **sem solda**: por baixo dos furos há tiras de metal que unem alguns furos entre si. Quem entende **quais furos estão ligados** monta sem se perder.

```
  trilho +  o o o o o o o o o o   <- todos os furos da linha estão ligados
  trilho -  o o o o o o o o o o   <- todos os furos da linha estão ligados

  coluna    1 2 3 4 5 6 7 8 9 10
      a     o o o o o o o o o o   ┐ em cada coluna, os 5 furos
      b     o o o o o o o o o o   │ de a até e estão ligados
      c     o o o o o o o o o o   │ (um só ponto elétrico)
      d     o o o o o o o o o o   │
      e     o o o o o o o o o o   ┘
   ══════ canal central: NÃO liga cima com baixo ══════
      f     o o o o o o o o o o   ┐ em cada coluna, os 5 furos
      g     o o o o o o o o o o   │ de f até j estão ligados
      h     o o o o o o o o o o   │
      i     o o o o o o o o o o   │
      j     o o o o o o o o o o   ┘

  trilho +  o o o o o o o o o o
  trilho -  o o o o o o o o o o
```

| Regra | O que fazer |
|---|---|
| **Coluna = um ponto** | Tudo o que estiver espetado **na mesma coluna e na mesma metade** (a–e ou f–j) está ligado entre si. |
| **Componente de 2 pernas** (LED, resistor) | Espete **cada perna numa coluna diferente**. Na mesma coluna, a corrente passa pelo metal e **não pelo componente** (curto-circuito). |
| **Trilhos** (linhas com + e −) | Servem para **distribuir** o 5V (+) e o GND (−) a vários pontos. A linha inteira é um ponto só. |
| **Canal central** | Separa a metade de cima da de baixo. **O CI atravessa o canal**: cada perna cai numa coluna própria e não encosta na vizinha. |

No Tinkercad, **passe o mouse sobre um furo**: ele mostra a que está ligado. *(Confira os trilhos na sua protoboard: em algumas eles são interrompidos no meio.)*

🔮 Se você espetar as **duas pernas de um resistor na mesma coluna** (ex.: A5 e C5), a corrente passa **pelo resistor**? Por quê? ______________________

## 0.1 Primeiro circuito (3 min)

1. **Piloto:** em <https://www.tinkercad.com/circuits>, clique em **Criar → Circuito**.
2. Arraste um **Arduino Uno R3** e uma **protoboard**. Ligue um **LED** com um **resistor de 220 Ω** em série entre o pino **13** e o **GND**.
3. Clique em **Iniciar simulação**. O código que já vem pronto pisca o pino 13. O LED pisca? (S ou N): ______

> 🔎 **Se não funcionou, olhe nesta ordem** (vale também para o 0.2):
> 1. A simulação está **rodando**? O botão costuma mudar para **Parar simulação**.
> 2. O LED está virado certo? Passe o mouse nos terminais: o **ânodo** vai para o lado do pino 13 e o **cátodo** para o lado do GND. Invertido, não acende.
> 3. Na protoboard, cada grupo de 5 furos de uma coluna é **um só ponto**. Os dois terminais do LED (ou do resistor) **não** podem ficar no mesmo grupo.
> 4. No 0.2: o display está em **cátodo** e o **comum** vai ao GND?

## 0.2 Conhecer o display (2 min)

1. Pare a simulação. Arraste um **Display de 7 segmentos** para a protoboard. *(Na biblioteca de componentes do Tinkercad, procure por **"Visor de 7 segmentos"** se a interface estiver em **português**, ou por **"Display"** se estiver em **inglês**.)*
2. **Clique no display** e, no quadro de propriedades, **confira que o comum está em "cátodo"**. Se estiver "ânodo", troque para **cátodo**. *Tudo neste documento usa cátodo comum.*
3. Passe o mouse sobre os terminais: o Tinkercad mostra o nome de cada um (a, b, …, g, DP, comum).
4. 🔮 Ligando o **comum no GND** e o terminal **a**, por um resistor de 220 Ω, no **5V**, o que acende? ______________________
5. Faça a ligação e inicie a simulação. Acertou? (S ou N): ______

| 📸 Cole aqui **dois prints**: (1) o LED aceso (0.1); (2) o segmento **a** aceso (0.2) com o quadro de propriedades mostrando **cátodo** |
|---|
| |

> ⚡ **Já domina o Tinkercad?** Faça só o 0.2 (cátodo + segmento a), tire o print e siga.

**📎 Evidência — Etapa 0:** confira que tem: print com o LED, o segmento **a** aceso e a propriedade **cátodo** · previsão 0.2-4

---

# Etapa 1A — O Arduino manda 4 bits, o CD4511 acende o número (13 min)

> 🧭 **Orientação:** o Arduino não "sabe" desenhar um 5. Ele só manda o número em **binário** (4 fios); um CI dedicado, o **CD4511**, decide quais segmentos acender. **Ao final desta etapa o display conta de 0 a 9 sozinho.**

**Pinos:** D2 = bit 0 (entrada **A** do CI) · D3 = bit 1 (**B**) · D4 = bit 2 (**C**) · D5 = bit 3 (**D**).

## 1A.1 Contar em BCD antes de montar (4 min)

1. **Peso dos algarismos (decimal).** No número **123**, cada algarismo vale pelo **lugar** em que está: o **1** é uma **centena** (100), o **2** são **duas dezenas** (20) e o **3** são **três unidades** (3).
   `123 = 1 × 100 + 2 × 10 + 3 × 1` — os pesos são potências de 10: `10²`, `10¹`, `10⁰`.
   🧮 No número **407**, quanto vale o algarismo **4**? E o **0**? ______________________
2. **Peso dos bits (binário).** No binário vale a mesma ideia, só que a base é **2**: cada **bit** tem um **peso** que é uma potência de 2, e o bit só soma o seu peso quando vale **1**.

   | Bit | D (D5) | C (D4) | B (D3) | A (D2) |
   |---|---|---|---|---|
   | Potência | 2³ | 2² | 2¹ | 2⁰ |
   | **Peso** | **8** | **4** | **2** | **1** |
   | Posição | **MSB** (mais significativo) | | | **LSB** (menos significativo) |

   - **MSB** (*Most Significant Bit*): o bit de **maior peso**, o da esquerda (aqui, **D**).
   - **LSB** (*Least Significant Bit*): o bit de **menor peso**, o da direita (aqui, **A**).
   - Exemplo: `0110` = `0 × 8 + 1 × 4 + 1 × 2 + 0 × 1` = **6**.
3. 🧮 Complete a tabela: cada número de 0 a 9 em 4 bits. O 0 já está feito. *Dica: some os pesos dos bits que valem 1 até chegar ao número.*

| Número | D (D5) · MSB · peso 8 | C (D4) · peso 4 | B (D3) · peso 2 | A (D2) · LSB · peso 1 |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 1 | | | | |
| 2 | | | | |
| 3 | | | | |
| 4 | | | | |
| 5 | | | | |
| 6 | | | | |
| 7 | | | | |
| 8 | | | | |
| 9 | | | | |

4. 🔮 Com 4 bits dá para escrever até qual número? Por que o BCD para no 9? ______________________

## Conhecer o CD4511 (leitura e pesquisa, 4 min)

O **CD4511** é um CI de **16 pinos** que faz a **decodificação BCD → 7 segmentos**: recebe o número em binário (4 bits) e acende os segmentos certos do display. Os 16 pinos se dividem em 4 grupos:

| Grupo | Pinos | O que são |
|---|---|---|
| **Alimentação** | **16** (VDD) · **8** (VSS) | energia do chip: VDD no **5V**, VSS no **GND** |
| **Entradas BCD** | **7** (A, LSB) · **1** (B) · **2** (C) · **6** (D, MSB) | recebem os 4 bits vindos do Arduino (D2 a D5) |
| **Controle** | **3** (LT) · **4** (BI) · **5** (LE) | teste, apagamento e trava (tabela no passo 2 do 1A.2) |
| **Saídas** | **13** (a) · **12** (b) · **11** (c) · **10** (d) · **9** (e) · **15** (f) · **14** (g) | ligam aos 7 segmentos do display, cada uma com um resistor |

🔍 **Agora confira no datasheet.** O **datasheet** é a folha de dados do fabricante: é a fonte oficial dos pinos, da tabela de funcionamento e dos limites de tensão. Pesquise na internet por `CD4511 datasheet`, abra um (de um fabricante conhecido, como a Texas Instruments) e:

1. Ache o **diagrama de pinos** (em inglês: *pin diagram* ou *terminal assignments*) e **compare com a tabela acima**: os números dos pinos e as letras (A–D, a–g, LT, BI, LE, VDD, VSS) batem?
2. Ache a **tabela de funcionamento** (*truth table*): o que o CI faz quando as entradas D C B A valem `1010` (10)? ______________________
3. Anote o **link** do datasheet que você usou: ______________________

Guarde o raciocínio: no passo 2 do 1A.2 você vai ligar os pinos usando os **nomes do Tinkercad** (em português), que **não são os do datasheet**. A tabela de lá traduz uns nos outros; o datasheet é o que vale na bancada.

> ⚠️ **Não esqueça de alimentar o CI!** O CD4511 **não** recebe energia pelos pinos de dados do Arduino: os fios D2 a D5 só levam os **bits**. Ele precisa de **VDD (pino 16) no 5V** e **VSS (pino 8) no GND**, como qualquer circuito integrado. Sem isso, mesmo com todo o resto certo, o display fica **apagado**. Esse é o primeiro item a conferir se algo der errado.

## 1A.2 Montar (5 min)

1. **Piloto:** no mesmo circuito (pode apagar o LED), coloque um **CD4511** atravessando o canal central da protoboard.
2. **Ache os pinos do CI.** O pino 1 fica no canto inferior esquerdo, ao lado da bolinha de marcação, e a numeração segue em U (sobe pela direita). Passe o mouse sobre cada pino: o Tinkercad mostra o nome dele, **traduzido e diferente das letras do datasheet**. Use esta tabela:

   | Pino | Nome no Tinkercad (português) | Em inglês | Função |
   |---|---|---|---|
   | 16 | Potência | Power | alimentação (VDD) → **5V** |
   | 8 | Solo | Ground | terra (VSS) → **GND** |
   | 7 | Entrada 1 | Input 1 | entrada BCD **A**, bit 0, peso 1: **LSB** (*bit menos significativo*, *least significant bit*) |
   | 1 | Entrada 2 | Input 2 | entrada BCD **B**, bit 1, peso 2 |
   | 2 | Entrada 3 | Input 3 | entrada BCD **C**, bit 2, peso 4 |
   | 6 | Entrada 4 | Input 4 | entrada BCD **D**, bit 3, peso 8: **MSB** (*bit mais significativo*, *most significant bit*) |
   | 3 | Teste da lâmpada | Lamp Test | **LT**, ativo em nível baixo |
   | 4 | Limpando | Blanking | **BI**, ativo em nível baixo (apaga o display) |
   | 5 | Ativação de trava | Latch Enable | **LE** |
   | 13 · 12 · 11 · 10 · 9 · 15 · 14 | A · B · C · D · E · F · G | A a G | **saídas** para os segmentos a · b · c · d · e · f · g |

   ⚠️ **Cuidado com os nomes:** o Tinkercad traduz do inglês, e a tradução confunde. **"Solo"** é o GND, **"Potência"** é o 5V e **"Limpando"** apaga o display. No pino **12** o nome pode **não aparecer** (a guia de alinhamento do CI cobre a etiqueta): use o **número do pino**. Os pinos que o Tinkercad chama de **A a G** são as **saídas** para os segmentos; as entradas BCD se chamam **Entrada 1 a 4**.

   **Os três pinos de controle: LT, BI e LE.** Guarde as siglas (são as do datasheet) e o que cada uma faz:

   | Pino | Sigla | Significado (inglês) | Nome no Tinkercad (português) | Nome no Tinkercad (inglês) | Em português | Ligar em | Se ligar errado |
   |---|---|---|---|---|---|---|---|
   | 3 | **LT** | *Lamp Test* | Teste da lâmpada | Lamp Test | teste da lâmpada | **5V** (nível alto) | no GND: acende **todos** os segmentos (mostra 8) |
   | 4 | **BI** | *Blanking Input* | Limpando | Blanking | apagamento | **5V** (nível alto) | no GND: **apaga** o display |
   | 5 | **LE** | *Latch Enable* | Ativação de trava | Latch Enable | ativação de trava | **GND** (nível baixo) | no 5V: **congela** o último número |

   LT e BI são *ativos em nível baixo*: só fazem efeito quando recebem 0 (GND). LE é *ativo em nível alto*: só trava quando recebe 1 (5V).
3. Alimente o CI: **Potência (pino 16) → 5V** e **Solo (pino 8) → GND**.
4. Ligue os pinos de controle conforme a tabela acima: **LT (3)** e **BI (4)** no **5V** e **LE (5)** no **GND** (assim o CI fica sempre mostrando).
5. Ligue **D2, D3, D4, D5** nas **Entradas 1, 2, 3, 4** do CI (D2 = Entrada 1 / *Input 1* = A = **LSB** … D5 = Entrada 4 / *Input 4* = D = **MSB**).
6. Ligue cada saída **A … G** do CI ao segmento de mesmo nome do display, **cada uma com seu resistor de 220 Ω**. Comum do display no **GND**.
7. Confira com o esquema [lab02_1a_cd4511.png](../../imagens/lab02_1a_cd4511.png) **depois** de montar. Achou alguma diferença? Qual? ______________________

## 1A.3 Rodar e observar (4 min)

1. ✅ **Aqui vocês NÃO modificam o código:** só copiam e rodam (na 1B vocês vão modificar). Abra o sketch `a1_bcd_cd4511` (pasta `codigo_base`), copie o texto e cole no editor **Código → Texto** do Tinkercad, apagando o que estava lá.
   - **Onde colar:** no lugar de **todo** o código que estava no editor (o pisca-pisca do 0.1). Se o Tinkercad avisar que vai descartar os blocos, confirme.
   - **Se não funcionou, olhe:**
     1. Erro `redefinition of 'void setup()'` (ou de `loop`): sobrou o código antigo. Apague tudo e cole de novo.
     2. Erro apontando para a última linha: a cópia parou antes da última `}`. Copie o sketch inteiro.
2. Leia a função `enviarBCD`. 🧮 Para `valor = 6`, quanto vale `(valor >> bit) & 1` em cada bit? bit 0: ___ · bit 1: ___ · bit 2: ___ · bit 3: ___ *(confira com a linha 6 da sua tabela)*
3. Inicie a simulação. O display conta de 0 a 9?

> 🔎 **Se não funcionou, olhe nesta ordem:**
> 1. Display todo apagado: **Potência** → **5V** e **Solo** → **GND**? **Limpando (BI, pino 4)** no **5V** (no GND ele apaga o display)? Comum do display no GND e propriedade **cátodo**?
> 2. Mostra **8** parado ou não sai do lugar: **Teste da lâmpada (LT, pino 3)** no **5V** (no GND ele acende tudo) e o **pino 5 (LE)** no **GND** (no 5V ele congela o número)?
> 3. Alguns números trocados (no lugar do 1 aparece 8) ou apagados no meio da contagem: **D2, D3, D4, D5** estão em **Entrada 1, 2, 3, 4**, nessa ordem?
> 4. Desenhos estranhos, que não são números: cada saída **A … G** do CI (pinos 13, 12, 11, 10, 9, 15, 14) vai ao segmento de **mesmo nome** do display?

| 📸 Cole aqui: **um GIF** do display contando de 0 a 9 (ou **três prints**: 0, 5 e 9) |
|---|
| |

4. 🔒 O que o **CD4511** faz que o Arduino **não precisa mais fazer**? Sem o CI, quantos fios o Arduino precisaria para acender os segmentos? E com o CI, quantos usa? Quantos pinos o CD4511 economiza? ______________________

> ⚡ **Já domina binário?** Complete a tabela BCD, monte, tire o GIF e responda o 1A.3-4.

**📎 Evidência — Etapa 1A:** confira que tem: link e respostas do datasheet (Conhecer o CD4511) · tabela BCD de 0 a 9 · previsão 1A.1-4 · conta 1A.1-1 · diferença com o esquema (1A.2-7) · conta do 1A.3-2 · GIF ou prints da contagem · resposta 1A.3-4

---

# Etapa 1B — Sem o CI: o Arduino decide os segmentos (13 min)

> 🧭 **Orientação:** agora **você** é o decodificador. Tire o CD4511 e ligue os 7 segmentos direto no Arduino. Para cada símbolo, vocês vão escrever **quais segmentos acendem** e guardar isso numa **tabela de consulta** `SEG[]`. **Ao final desta etapa o display conta de 0 a 9 com a tabela que a dupla escreveu.** ✏️ **Nesta etapa vocês vão modificar o código** (no 1B.3).

**Pinos:** a = D2 · b = D3 · c = D4 · d = D5 · e = D6 · f = D7 · g = D8. Cada segmento com **seu** resistor de 220 Ω. Comum no GND.

> ⚡ **Já domina?** Pule o passo a passo: ligue os 7 segmentos direto (1B.1), escreva a tabela de 0 a 9 e o `loop()` (1B.2 e 1B.3), tire o GIF e vá ao 1B.4.

## 1B.1 Religar sem o CI (3 min)

1. **Piloto:** apague o CD4511. Ligue cada segmento a–g, pelo seu resistor, ao pino da lista acima.
2. Confira com o esquema [lab02_1b_direto.png](../../imagens/lab02_1b_direto.png) **depois** de montar.

## 1B.2 Escrever a tabela (4 min)

Cada símbolo vira **7 bits**, um por segmento: **bit 0 = a**, bit 1 = b, …, **bit 6 = g**; **1 = aceso**. Escrevemos de **g para a** (da esquerda para a direita), com `0b` na frente.

```
     a
   f   b
     g
   e   c
     d
```

🔍📸 **Antes da tabela, ache um display de verdade.** Pesquise na internet uma **imagem de um display de 7 segmentos com os segmentos rotulados a, b, c, d, e, f, g** (sugestão de busca: `7 segment display segments a b c d e f g`). **Cole a imagem aqui no relatório** (*Inserir → Imagem*, ou `Ctrl+V`) e **anote a fonte (link)**. Use-a para conferir a figura acima: o "a" é mesmo o traço de cima?

| 📸 Cole aqui a imagem do display (com a, b, c, d, e, f, g) e escreva o link da fonte |
|---|
| |

1. 🧮 Complete **pelo menos 0, 1, 2 e 3** pela figura acima. O traço "-" já está feito como exemplo (só o g aceso).

| Símbolo | g | f | e | d | c | b | a | Valor (`0b` + 7 bits) |
|---|---|---|---|---|---|---|---|---|
| - (exemplo) | 1 | 0 | 0 | 0 | 0 | 0 | 0 | `0b1000000` |
| 0 | | | | | | | | |
| 1 | | | | | | | | |
| 2 | | | | | | | | |
| 3 | | | | | | | | |
| 4 | | | | | | | | |
| 5 | | | | | | | | |
| 6 | | | | | | | | |
| 7 | | | | | | | | |
| 8 | | | | | | | | |
| 9 | | | | | | | | |

2. Completem 4 a 9. Se o tempo apertar, deixem 4 a 9 para testar depois de o 0 a 3 funcionar. **Atenção:** se pularem os dígitos 4 a 9 por enquanto, o display ficará **apagado** nesses números na contagem do 1B.3. Isso é esperado, não é erro de montagem.

## 1B.3 Programar (5 min)

> ✏️ **ATENÇÃO: aqui é com vocês!** O código desta etapa está **incompleto de propósito**. Se vocês só copiarem e rodarem, o display fica **apagado**. Vocês precisam **modificar o código em 2 lugares**, marcados com `SUA VEZ` no sketch:
> - **SUA VEZ 1:** preencher a tabela `SEG[]` com os valores que **vocês** escreveram no 1B.2 (passo 1 abaixo);
> - **SUA VEZ 2:** escrever o corpo da função `loop()` (passo 2 abaixo).

1. **SUA VEZ 1: a tabela.** Abra o sketch `a2_tabela_segmentos_esqueleto` (pasta `codigo_base`, mesmo repositório do 1A), copie o texto e cole no editor **Código → Texto** do Tinkercad, apagando o que estava lá. Depois **edite** o código, colocando os valores da **sua** tabela em `SEG`.

   - **Onde mexer:** só nas 10 linhas de `SEG`: troque cada `0b0000000` pelo valor da linha de mesmo número da **sua** tabela. Mantenha a vírgula no fim de cada linha, menos na do 9.
   - **Se não funcionou, olhe:**
     1. Erro parecido com `expected '}' before numeric constant` numa linha de `SEG` (a mensagem pode variar): falta a vírgula no fim da linha **de cima**.
     2. Erro num valor `0b…`: depois do `0b` só pode haver **0** e **1**.
     3. Erro `too many initializers`: há mais de 10 valores dentro das chaves.

2. **SUA VEZ 2: o `loop()`.** Escrevam o `loop()`: para cada número `n` de 0 a 9, para cada segmento `i` de 0 a 6, mande ao pino `PINOS_SEG[i]` o **bit `i`** de `SEG[n]` (use `bitRead`); depois espere 1 s.
   - **Onde mexer:** dentro de `void loop() { … }`, no lugar do comentário `>>> SUA VEZ 2`. Não mexa no `setup()`.
   - **Se não funcionou, olhe:**
     1. Erro `'n' was not declared in this scope` (ou `'i'`): a variável se cria **dentro** do `for`, como no `for` do `setup()`.
     2. O número vai se formando um segmento por segundo: a espera de 1 s ficou **dentro** do `for` dos segmentos; ela vem depois dele.
     3. Display sempre apagado, sem erro: a tabela ainda está com `0b0000000`? O `bitRead` recebe primeiro o **valor** e depois o **número do bit**?
3. Inicie a simulação. Algum dígito saiu errado? Qual, e qual segmento estava trocado? ______________________

> 🔎 **Se não funcionou, olhe nesta ordem:**
> 1. A simulação está **rodando**? Sobrou algum fio do CD4511 (1A) nos pinos?
> 2. Um segmento **nunca** acende: o fio dele vai ao pino certo da lista (a = D2 … g = D8) e passa pelo **seu** resistor?
> 3. O **mesmo** segmento errado em **todos** os números: fio trocado. Errado em **um** número só: confira essa linha da tabela.

| 📸 Cole aqui: **um GIF** da contagem (ou prints de 0, 1, 2 e 3) |
|---|
| |

| 📝 Cole aqui: o código final (via Telegram) |
|---|
| |

## 1B.4 Um resistor por segmento? (1 min)

1. 🔮☑️ Alguns tutoriais usam **um único resistor** no pino comum, no lugar dos 7. O que aconteceria com o brilho?\
   **a)** Igual para todos os números.\
   **b)** O "1" mais forte que o "8".\
   **c)** O "8" mais forte que o "1".\
   **d)** O display não acende.\
   **Sua resposta (letra): ______**

**📎 Evidência — Etapa 1B:** confira que tem: imagem do display com a fonte (1B.2) · tabela de segmentos (pelo menos 0 a 3) · GIF ou prints da contagem · código final com o seu `loop()` · resposta 1B.4-1

---

## ⭐ EXTRA — só se sobrar tempo (opcional)

> **Tudo daqui até o fim da seção é EXTRA.** Não é obrigatório, **pode ficar em branco** e não atrapalha a entrega. Se já terminou a evidência acima e ainda há tempo, escolha o que quiser, **em qualquer ordem**.

### ⭐ Extra A — Explique a sua resposta do 1B.4-1

🔒 Explique, com as suas palavras, por que você escolheu essa letra. Quantos segmentos acendem no "1"? E no "8"? O que muda no resistor único de um caso para o outro? ______________________

### ⭐ Extra B — Cátodo comum para ânodo comum

1. Nas propriedades do display, troque **cátodo** por **ânodo** e ligue o comum no **5V** (em vez do GND).
2. 🔮 *Antes de testar:* o que inverte na tabela e na fiação? ______________________
3. Teste e conte o que viu: ______________________

### ⭐ Extra C — Letras e símbolos

1. Acrescente à tabela as letras **A, C, E, F, H, L, P, U** (escreva os 7 bits de cada uma) e mostre-as no display.
   - **Onde mexer:** no fim de `SEG`, depois do 9 (ponha a vírgula que faltava nele); aumente o tamanho `[10]` e o limite do `for` do `loop()`. Sem aumentar o tamanho, dá erro `too many initializers`.
2. 💭 Tente desenhar **K, M, W** e **X** com 7 segmentos. O que acontece? ______________________
3. 🔒 Por que dizemos que 7 segmentos **não** formam um display alfanumérico completo? ______________________
4. 🔍 Que tipos de display mostram todas as letras? Anote um e a fonte (link). ______________________

---

# Você leva para o próximo documento

Na **Parte 2**, você vai reusar:

- a **sua tabela `SEG[10]`** (bit 0 = a … bit 6 = g, 1 = aceso) e os pinos **D2–D8** dos segmentos;
- a ideia de que cada segmento é **uma linha** (um fio + **um resistor por segmento**). Na Parte 2, essas 7 linhas serão **compartilhadas** por vários displays ao mesmo tempo;
- o display em **cátodo comum**, conferido nas propriedades.

**Entrega:** salve o arquivo, entregue no Classroom e abra a **Parte 2 de 3 — Muitos dígitos, poucos fios**.
