# Doc 1 de 3 — Do bit ao segmento

**UC S086 — Sistemas Microprocessados** · Tinkercad Circuits (Arduino UNO R3 simulado)
*Este documento é o roteiro **e** o relatório. Um arquivo por dupla: os dois alunos entregam o mesmo arquivo.*

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
| Placa de ensaio (protoboard) | | |
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
- ⚡ **Já domina?** Faça só o que o selo pede e siga.
- Estourou o tempo? **Siga adiante** e volte depois. Itens *(se sobrar tempo)* podem ficar em branco.
- **Trocar de documento conta no tempo** (~2 min): entregue pelo Classroom e abra o próximo.
- **Código no Tinkercad:** botão **Código** → troque *Blocos* por **Texto**. O Tinkercad não abre arquivo `.ino`: abra o sketch no navegador ou no Telegram, copie o texto e cole no editor.
- **Os sketches** estão no repositório
  <https://github.com/professorjoaomiguel/S086-2026-2>, no sketch `a1_bcd_cd4511` (pasta `labs/lab02_displays_7seg/codigo_base`), ou no link que o professor enviar no Telegram.

| Selo | Significa |
|---|---|
| 🔮 | **Previsão:** responda *antes* de testar. Não precisa acertar. |
| 🧮 | **Cálculo:** faça a conta antes de conferir. |
| 🔍 | **Pesquisa** na web: anote a fonte (link). |
| ☑️ | **Múltipla escolha:** escreva a letra da resposta. |
| 🔒 | **Fechada:** responda por extenso, ligando teoria e o que você viu. |
| 💭 | **Aberta:** sem resposta certa; opine e justifique. |
| 📸 | **Mídia:** **foto, print de tela ou GIF** (vídeo não cola no Docs). |

### Glossário rápido

| Palavra | Quer dizer |
|---|---|
| **segmento** | cada um dos 7 traços do display (a, b, c, d, e, f, g). **Cada segmento é um LED** |
| **cátodo comum** | display em que os cátodos (−) dos 7 LEDs estão ligados num pino só, que vai ao GND. O segmento acende com nível **ALTO** |
| **BCD** | *decimal codificado em binário*: cada algarismo de 0 a 9 escrito com 4 bits (ex.: 6 = `0110`) |
| **CD4511** | circuito integrado que recebe 4 bits BCD e acende os segmentos certos do display |
| **tabela de consulta** | um vetor em que a posição é o símbolo e o valor guardado diz o que fazer (aqui: quais segmentos acender) |

### Referências

- [Documentação da linguagem Arduino (português)](https://docs.arduino.cc/language-reference/pt/): [`pinMode()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/digital-io/pinMode/) · [`digitalWrite()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/digital-io/digitalWrite/) · [`delay()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/delay/) · [`bitRead()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/bits-and-bytes/bitRead/)
- [Tinkercad Circuits](https://www.tinkercad.com/circuits): entre com a conta indicada pelo professor.
- Esquemas de ligação desta atividade: [1A com CD4511](../../imagens/lab02_1a_cd4511.png) · [1B direto no Arduino](../../imagens/lab02_1b_direto.png) (use **depois de tentar sozinho**, para conferir, não para copiar).

**Tempo deste documento: ~30 min.** Ao terminar, entregue pelo Classroom e abra o **Doc 2 de 3**.

---

# Etapa 0 — Aquecimento no Tinkercad: um segmento é um LED (5 min)

> 🧭 **Orientação:** antes do display, garanta que a dupla sabe montar e simular no Tinkercad, e veja que o display é só um conjunto de LEDs. **Ao final desta etapa um LED pisca na simulação e você acendeu um segmento do display "na mão".**

## 0.1 Primeiro circuito (3 min)

1. **Piloto:** em <https://www.tinkercad.com/circuits>, clique em **Criar → Circuito**.
2. Arraste um **Arduino Uno R3** e uma **placa de ensaio**. Ligue um **LED** com um **resistor de 220 Ω** em série entre o pino **13** e o **GND**.
3. Clique em **Iniciar simulação**. O código que já vem pronto pisca o pino 13. O LED pisca? (S ou N): ______

## 0.2 Conhecer o display (2 min)

1. Pare a simulação. Arraste um **Display de 7 segmentos** para a placa de ensaio.
2. **Clique no display** e, no quadro de propriedades, **confira que o comum está em "cátodo"**. Se estiver "ânodo", troque para **cátodo**. *Tudo neste documento usa cátodo comum.*
3. Passe o mouse sobre os terminais: o Tinkercad mostra o nome de cada um (a, b, …, g, DP, comum).
4. 🔮 Ligando o **comum no GND** e o terminal **a**, por um resistor de 220 Ω, no **5V**, o que acende? ______________________
5. Faça a ligação e inicie a simulação. Acertou? (S ou N): ______

| 📸 Cole aqui: **um print** com o LED aceso (0.1) e o segmento **a** aceso (0.2), e o quadro de propriedades mostrando **cátodo** |
|---|
| |

> ⚡ **Já domina o Tinkercad?** Faça só o 0.2 (cátodo + segmento a), tire o print e siga.

**📎 Evidência — Etapa 0:** confira que tem: print com o LED, o segmento **a** aceso e a propriedade **cátodo** · previsão 0.2-4

---

# Etapa 1A — O Arduino manda 4 bits, o CD4511 acende o número (12 min)

> 🧭 **Orientação:** o Arduino não "sabe" desenhar um 5. Ele só manda o número em **binário** (4 fios); um CI dedicado, o **CD4511**, decide quais segmentos acender. **Ao final desta etapa o display conta de 0 a 9 sozinho.**

**Pinos:** D2 = bit 0 (entrada **A** do CI) · D3 = bit 1 (**B**) · D4 = bit 2 (**C**) · D5 = bit 3 (**D**).

## 1A.1 Contar em BCD antes de montar (3 min)

1. 🧮 Complete a tabela: cada número de 0 a 9 em 4 bits. O 0 já está feito.

| Número | D (D5) | C (D4) | B (D3) | A (D2) |
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

2. 🔮 Com 4 bits dá para escrever até qual número? Por que o BCD para no 9? ______________________

## 1A.2 Montar (5 min)

1. **Piloto:** no mesmo circuito (pode apagar o LED), coloque um **CD4511** atravessando o canal central da placa de ensaio.
2. Alimente o CI: **VDD → 5V** e **VSS → GND**.
3. Ligue os pinos de controle: **LT** e **BI** no **5V** e **LE** no **GND** (assim o CI fica sempre mostrando).
4. Ligue **D2, D3, D4, D5** nas entradas **A, B, C, D** do CI.
5. Ligue cada saída **a … g** do CI ao segmento de mesmo nome do display, **cada uma com seu resistor de 220 Ω**. Comum do display no **GND**.
6. Confira com o esquema [lab02_1a_cd4511.png](../../imagens/lab02_1a_cd4511.png) **depois** de montar. Achou alguma diferença? Qual? ______________________

## 1A.3 Rodar e observar (4 min)

1. Abra o sketch `a1_bcd_cd4511` (pasta `codigo_base`), copie o texto e cole no editor **Código → Texto** do Tinkercad, apagando o que estava lá.
2. Leia a função `enviarBCD`. 🧮 Para `valor = 6`, quanto vale `(valor >> bit) & 1` em cada bit? bit 0: ___ · bit 1: ___ · bit 2: ___ · bit 3: ___ *(confira com a linha 6 da sua tabela)*
3. Inicie a simulação. O display conta de 0 a 9?

| 📸 Cole aqui: **um GIF** do display contando de 0 a 9 (ou **três prints**: 0, 5 e 9) |
|---|
| |

4. 🔒 O que o **CD4511** faz que o Arduino **não precisa mais fazer**? Sem o CI, quantos fios o Arduino precisaria para acender os segmentos? E com o CI, quantos usa? Quantos pinos o CD4511 economiza? ______________________

> ⚡ **Já domina binário?** Complete a tabela BCD, monte, tire o GIF e responda o 1A.3-4.

**📎 Evidência — Etapa 1A:** confira que tem: tabela BCD de 0 a 9 · previsão 1A.1-2 · diferença com o esquema (1A.2-6) · conta do 1A.3-2 · GIF ou prints da contagem · resposta 1A.3-4

---

# Etapa 1B — Sem o CI: o Arduino decide os segmentos (13 min)

> 🧭 **Orientação:** agora **você** é o decodificador. Tire o CD4511 e ligue os 7 segmentos direto no Arduino. Para cada símbolo, vocês vão escrever **quais segmentos acendem** e guardar isso numa **tabela de consulta** `SEG[]`. **Ao final desta etapa o display conta de 0 a 9 com a tabela que a dupla escreveu.**

**Pinos:** a = D2 · b = D3 · c = D4 · d = D5 · e = D6 · f = D7 · g = D8. Cada segmento com **seu** resistor de 220 Ω. Comum no GND.

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

1. **Piloto:** no editor do Tinkercad, apague tudo e escreva este esqueleto, colocando os valores da **sua** tabela em `SEG`:

```cpp
const byte PINOS_SEG[7] = {2, 3, 4, 5, 6, 7, 8};   // a, b, c, d, e, f, g

// bit0 = a ... bit6 = g; 1 = aceso (cátodo comum)
const byte SEG[10] = {
  0b0000000,  // 0  <- troque pelos valores da sua tabela
  0b0000000,  // 1
  0b0000000,  // 2
  0b0000000,  // 3
  0b0000000,  // 4
  0b0000000,  // 5
  0b0000000,  // 6
  0b0000000,  // 7
  0b0000000,  // 8
  0b0000000   // 9
};

void setup() {
  for (byte i = 0; i < 7; i++) {
    pinMode(PINOS_SEG[i], OUTPUT);
  }
}

void loop() {
  // ETAPA 1B.3: mostre SEG[0] ... SEG[9], um por segundo
}
```

2. Escreva o `loop()`: para cada número `n` de 0 a 9, para cada segmento `i` de 0 a 6, mande ao pino `PINOS_SEG[i]` o **bit `i`** de `SEG[n]` (use `bitRead`); depois espere 1 s.
3. Inicie a simulação. Algum dígito saiu errado? Qual, e qual segmento estava trocado? ______________________

| 📸 Cole aqui: **um GIF** da contagem (ou prints de 0, 1, 2 e 3) |
|---|
| |

| 📝 Cole aqui: o código final (via Telegram) |
|---|
| |

## 1B.4 Um resistor por segmento? (1 min)

1. 🔮☑️ Alguns tutoriais usam **um único resistor** no pino comum, no lugar dos 7. O que aconteceria com o brilho?
   - a) Igual para todos os números.
   - b) O "1" (2 segmentos) mais forte que o "8" (7 segmentos).
   - c) O "8" mais forte que o "1".
   - d) O display não acende.
   **Sua resposta (letra): ______**
2. 🔒 *(se sobrar tempo)* Justifique pela corrente: o que o resistor único divide entre os segmentos acesos? ______________________

> ⚡ **Já domina?** Escreva a tabela de 0 a 9 e o `loop()` direto, tire o GIF e faça o desafio: nas propriedades do display, troque **cátodo** por **ânodo** e ligue o comum no **5V**. 🔮 *Antes de testar:* o que inverte na tabela e na fiação? ______________________ Depois teste e conte o que viu: ______________________

### *(se sobrar tempo)* Letras e símbolos

1. Acrescente à tabela as letras **A, C, E, F, H, L, P, U** (escreva os 7 bits de cada uma) e mostre-as no display.
2. 💭 Tente desenhar **K, M, W** e **X** com 7 segmentos. O que acontece? ______________________
3. 🔒 Por que dizemos que 7 segmentos **não** formam um display alfanumérico completo? ______________________
4. 🔍 Que tipos de display mostram todas as letras? Anote um e a fonte (link). ______________________

**📎 Evidência — Etapa 1B:** confira que tem: tabela de segmentos (pelo menos 0 a 3) · GIF ou prints da contagem · código final com o seu `loop()` · resposta 1B.4-1 · letras e desafio ânodo (se fez)

---

# Você leva para o próximo documento

No **Doc 2**, você vai reusar:

- a **sua tabela `SEG[10]`** (bit 0 = a … bit 6 = g, 1 = aceso) e os pinos **D2–D8** dos segmentos;
- a ideia de que cada segmento é **uma linha** (um fio + **um resistor por segmento**). No Doc 2, essas 7 linhas serão **compartilhadas** por vários displays ao mesmo tempo;
- o display em **cátodo comum**, conferido nas propriedades.

**Entrega:** salve o arquivo, entregue no Classroom e abra o **Doc 2 de 3 — Muitos dígitos, poucos fios**.
