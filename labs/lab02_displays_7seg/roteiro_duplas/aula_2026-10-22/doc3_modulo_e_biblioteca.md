# Doc 3 de 3 — Módulo e biblioteca

> RASCUNHO (professor): não testado em bancada. Pinos CLK = D7 e DIO = D8 a confirmar na bancada com o módulo. Apague este quadro antes de entregar aos alunos.

**UC S086 — Sistemas Microprocessados** · **Só na bancada:** Arduino UNO R3 + Shield 9-em-1 + módulo TM1637 de 4 dígitos
*Este documento é o roteiro **e** o relatório. Um arquivo por dupla: os dois alunos entregam o mesmo arquivo.*

No Doc 1 você decidiu **quais segmentos** acendem. No Doc 2 fez a **varredura** à mão: 11 pinos, um dígito de cada vez, com `millis()` para não travar. Agora vem um **módulo real** com um chip, o **TM1637**, que faz isso por dentro. O Arduino só manda o número por **2 fios**, e uma **biblioteca** cuida da conversa.

**Pinos:** CLK = **D7** · DIO = **D8** (a confirmar na bancada) · potenciômetro = **A0**.

## Identificação

| Campo | Preencha |
|---|---|
| Aluno 1 (piloto) | |
| Aluno 2 (navegador) | |
| Turma / bancada | |
| Data | |

## Componentes utilizados neste documento

Tudo aqui é **na bancada**, não no Tinkercad.

| Componente | Usou? (S ou N) | Anote |
|---|---|---|
| Arduino UNO R3 | | Porta COM: |
| Shield 9-em-1 | | |
| Módulo TM1637 (4 dígitos) | | Tem dois-pontos? Pontos decimais? |
| Jumpers (fios) | | Quantos? Tipo (fêmea-fêmea, macho-fêmea)? |
| Cabo USB | | |
| Potenciômetro do shield (A0) | | |

## Como trabalhar

Igual ao Doc 1 (veja lá a tabela **piloto e navegador** e os combinados). Resumo: **piloto** opera a **Arduino IDE** e a placa, um passo por vez, dizendo o que faz; **navegador** lê em voz alta, confere e registra aqui, sem digitar o código. Os dois pensam juntos nas perguntas. **Vale trocar de papel** ao começar cada etapa (3A, 3B, 3C); antes de trocar, mande o código pelo Telegram. ⚡ para quem já domina; itens *(se sobrar tempo)* podem ficar em branco.

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
| **biblioteca** | código pronto, escrito por outra pessoa, que você instala no computador e chama no seu sketch com `#include` |
| **TM1637** | chip do módulo que guarda os 4 algarismos, decide os segmentos e faz a **varredura** sozinho |
| **CLK** | *clock*: o fio em que o Arduino marca o ritmo, um pulso por bit enviado |
| **DIO** | *data in/out*: o fio por onde passam os bits, um de cada vez |
| **protocolo serial** | combinado de como mandar dados **bit a bit** por poucos fios (aqui: CLK + DIO) |
| **brilho** | intensidade dos segmentos; no TM1637 vai de **0** (fraco) a **7** (forte) |

### Referências

- [Documentação da linguagem Arduino (português)](https://docs.arduino.cc/language-reference/pt/): [`analogRead()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/analog-io/analogRead/) · [`map()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/math/map/) · [`constrain()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/math/constrain/) · [`delay()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/delay/)
- Biblioteca **TM1637** (Avishay Orpaz), página no GitHub: <https://github.com/avishorp/TM1637>. Lá está a lista das funções (`showNumberDec`, `showNumberDecEx`, `setBrightness`, `setSegments`).
- [Repositório lab-boards](https://github.com/professorjoaomiguel/lab-boards): fotos do shield. Para achar as barras D7 e D8: [pinout-anotado.jpg](https://github.com/professorjoaomiguel/lab-boards/blob/main/shields/uno-shield-9in1/imagens/pinout-anotado.jpg).
- Esquema de ligação desta atividade: [3A módulo TM1637 no shield](../../imagens/lab02_3a_tm1637_shield.png) (use **depois de tentar sozinho**, para conferir, não para copiar).
- Sketches de referência na pasta `labs/lab02_displays_7seg/codigo_base` do repositório: `c1_tm1637_ola`, `c2_pot_display`, `c3_indicador_nivel`. **Só para conferir depois** que o seu funcionar (ou se travar de vez).

**Tempo deste documento: ~30 min.** Ao terminar, entregue pelo Classroom: é o último do bloco.

---

# Etapa 3A — Primeiro contato: biblioteca, fios e 1234 (13 min)

> 🧭 **Orientação:** antes de ligar fios, o computador precisa **ter a biblioteca**. Depois, 4 fios: dois de alimentação e dois de sinal. **Ao final desta etapa o módulo mostra 1234 e a dupla sabe instalar uma biblioteca na IDE.**

## 3A.1 Sem a biblioteca, a IDE reclama (2 min)

1. **Piloto:** conecte o UNO (com o shield) ao PC. Na Arduino IDE, escolha a placa **Arduino Uno** e a sua **porta COM**, como no lab01.
2. Crie um sketch novo (*Arquivo → Novo*), apague tudo e escreva este esqueleto:

```cpp
#include <TM1637Display.h>      // a biblioteca do módulo

const byte PINO_CLK = 7;
const byte PINO_DIO = 8;

TM1637Display display(PINO_CLK, PINO_DIO);   // "display" conversa pelo D7 e D8

void setup() {
  // ETAPA 3A.4: brilho e o número 1234
}

void loop() {
}
```

- **Onde colar:** no sketch **novo**, no lugar de tudo o que a IDE já escreveu (o `setup()` e o `loop()` vazios dela).

3. Clique em **Verificar** (✓), **sem** carregar. Se aparecer `fatal error: TM1637Display.h: No such file or directory`, é o esperado: falta a biblioteca. Copie a linha do erro:

| 📝 Registre aqui: a mensagem de erro (ou "compilou sem erro") |
|---|
| |

*Compilou sem erro?* Alguém já instalou a biblioteca neste PC. Vá direto ao passo 4 do 3A.2 (o print do TM1637Test), só para conferir.

## 3A.2 Como instalar uma biblioteca (3 min)

Os nomes dos menus podem mudar um pouco entre versões da IDE (2.x e 1.8). Procure pelo nome mais parecido.

1. **Piloto:** *Sketch → Incluir Biblioteca → Gerenciar Bibliotecas…* (na IDE 2.x, o mesmo painel abre pelo ícone de livros na barra da esquerda).
2. Na busca, escreva **TM1637**. Aparecem várias. Escolha a chamada **TM1637**, do autor **Avishay Orpaz**, e clique em **Instalar**. Versão instalada: ______
3. **Plano B, sem o Gerenciador** (rede bloqueada, por exemplo): em <https://github.com/avishorp/TM1637>, *Code → Download ZIP*. Na IDE: *Sketch → Incluir Biblioteca → Adicionar biblioteca .ZIP…* e escolha o arquivo baixado.
4. **Confira que instalou:** *Arquivo → Exemplos → TM1637 → TM1637Test* deve aparecer (na lista, as bibliotecas instaladas costumam ficar mais para baixo). Abra o exemplo, **sem carregar**.

| 📸 Cole aqui: **um print** da IDE com o exemplo **TM1637Test** aberto |
|---|
| |

5. Volte ao seu sketch e clique em **Verificar** de novo. Compilou? (S ou N): ______
   - **Se não funcionou, olhe:**
     1. Ainda `No such file or directory`: a biblioteca não instalou. O **TM1637Test** aparece no passo 4?
     2. Erro **novo**, em outra linha: agora a IDE leu o resto do esqueleto. Leia a linha indicada: costuma ser `;` faltando ou um nome digitado diferente.
6. 🔒 No 3A.1 você só clicou em **Verificar**: nada foi para a placa, e mesmo assim deu erro. Por que o `#include` precisa da biblioteca instalada **no computador**, e não na placa? *Dica: onde o código é compilado, e o que vai para o Arduino?* ______________________

## 3A.3 Ligar o módulo no shield (4 min)

> ⚠️ **Desconecte o cabo USB antes de mexer nos fios.** VCC e GND trocados podem danificar o módulo.

1. **Piloto:** olhe a **serigrafia** (as letras impressas) ao lado dos 4 pinos do módulo e escreva a ordem, da esquerda para a direita: ______ · ______ · ______ · ______
2. No shield, ache as **barras de pinos D7 e D8**. Cada uma tem 3 pinos: o sinal (D7 ou D8), **VCC** (5 V) e **GND**. Leia a serigrafia da barra para saber qual é qual.
3. **Primeiro, a alimentação:** um fio do **GND** da barra D7 ao **GND** do módulo; outro do **VCC** da barra D7 ao **VCC** do módulo. Confira os dois com o navegador antes de seguir. *(Se os pinos do módulo e da barra forem ambos macho, use jumpers fêmea-fêmea.)*
4. **Depois, os sinais:** o pino de sinal da barra **D7** ao **CLK** do módulo; o pino de sinal da barra **D8** ao **DIO**.
5. 🔮 Se a dupla trocar **CLK** e **DIO**, o que você espera ver no módulo? ______________________
6. Confira com o esquema [lab02_3a_tm1637_shield.png](../../imagens/lab02_3a_tm1637_shield.png) **depois** de ligar. Achou alguma diferença? Qual? ______________________

## 3A.4 Mostrar 1234 (3 min)

1. **Piloto:** reconecte o USB. No `setup()`, escreva duas linhas: uma que ajusta o **brilho** em 5 e outra que mostra o número **1234**. Os nomes das funções estão na página da biblioteca (veja **Referências**) e no exemplo TM1637Test.
   - **Onde mexer:** dentro de `setup()`, no lugar do comentário `// ETAPA 3A.4`. As duas linhas começam com `display.`, o nome que o esqueleto deu ao módulo.
   - **Se não funcionou, olhe:**
     1. Erro `… was not declared in this scope` na sua linha: faltou `display.` antes do nome da função.
     2. Erro `… has no member named …`: o nome da função está diferente do da página da biblioteca (maiúsculas contam).
     3. Carregou, mas o módulo ficou apagado: a linha do brilho vem **antes** da do número? Pela página da biblioteca, o brilho só vale a partir do próximo número mostrado.
2. **Carregar** (→). Aparece **1234**? (S ou N): ______

> 🔎 **Se não funcionou, olhe nesta ordem:**
> 1. A IDE mostrou **"Carregado"**? Se deu erro, leia a **primeira** linha vermelha. `TM1637Display.h: No such file or directory` = biblioteca não instalada (volte ao 3A.2).
> 2. Erro ao carregar: a placa é **Arduino Uno** e a **porta COM** é a sua?
> 3. Módulo todo apagado: o USB está conectado? **VCC** e **GND** do módulo estão nos pinos VCC e GND da **barra**?
> 4. Apagado ou com lixo: **CLK** no sinal da barra **D7** e **DIO** no sinal da **D8**, como `PINO_CLK` e `PINO_DIO`? Jumpers bem encaixados?
> 5. O shield está bem encaixado no UNO? Ainda nada: **avise o professor** e diga o que já conferiu.

| 📸 Cole aqui: **uma foto** do módulo mostrando 1234, com os fios até o shield aparecendo |
|---|
| |

| 📝 Cole aqui: o seu `setup()` (via Telegram) |
|---|
| |

3. *(se sobrar tempo)* Teste a previsão do 3A.3-5 **sem mexer nos fios**: troque no código para `TM1637Display display(PINO_DIO, PINO_CLK);`, carregue e conte o que viu. Depois desfaça. ______________________
   - **Onde mexer:** na linha `TM1637Display display(PINO_CLK, PINO_DIO);`, acima do `setup()`. Troque só a ordem dos dois nomes.

> ⚡ **Já domina?** Instale a biblioteca, confira pelo exemplo (print), ligue, mostre 1234 (foto) e responda o 3A.2-6.

**📎 Evidência — Etapa 3A:** confira que tem: mensagem do 3A.1 · print do TM1637Test · resposta 3A.2-6 · ordem dos pinos e previsão 3A.3-5 · foto com 1234 · `setup()`

---

# Etapa 3B — O potenciômetro no display (7 min)

> 🧭 **Orientação:** é a cadeia do lab01, **entrada analógica → processamento → saída**, só que a saída agora é um número no display. **Ao final desta etapa o display mostra a leitura do potenciômetro enquanto você gira.**

*Lembrete do lab01:* `analogRead(A0)` devolve uma **contagem** de **0 a 1023** para uma tensão de 0 a 5 V. No shield, potenciômetro **todo à esquerda = 5 V**; **todo à direita = GND**.

## 3B.1 Prever os extremos (2 min)

1. 🔮 Com o potenciômetro **todo à esquerda**, que número o display vai mostrar? ______ E **todo à direita**? ______
2. 🧮 Uma contagem de **512** corresponde a qual tensão em A0, aproximadamente? *(5 V ↔ 1023)* ______ V

## 3B.2 Ler e mostrar (5 min)

1. **Piloto:** no seu sketch do 3A, escreva o `loop()`: leia `analogRead(A0)` numa variável e mostre-a no display com a mesma função do 1234.
   - **Onde mexer:** dentro de `void loop() { }`, que no esqueleto está vazio. O `setup()` fica como está.
   - **Se não funcionou, olhe:**
     1. Ainda aparece 1234 parado: você clicou em **Carregar** de novo? Salvar não manda o programa para a placa.
     2. Erro `… was not declared in this scope` com o nome da sua variável: ela precisa de um tipo (ex.: `int`) na linha em que é criada, e do **mesmo nome** nas duas linhas.
     3. O número muda com a **luz**, e não com o potenciômetro: você está lendo o **A1** (o LDR do lab01). O potenciômetro é o **A0**.
2. Carregue e gire o potenciômetro devagar. Acertou os extremos do 3B.1? (S ou N): ______ Valores vistos: esquerda ______ · direita ______
3. Pare o potenciômetro no meio. O último dígito fica parado ou "treme"? ______ Acrescente um `delay(100);` no fim do `loop()`. Mudou? ______
   - **Onde mexer:** última linha **dentro** do `loop()`, antes da `}` que o fecha.

> 🔎 **Se não funcionou, olhe nesta ordem:**
> 1. A IDE mostrou **"Carregado"**? Se deu erro, leia a **primeira** linha vermelha.
> 2. Módulo apagado de repente: algum jumper soltou? Confira os 4 fios do 3A.3.
> 3. O número não muda ao girar: o shield está **bem encaixado** no UNO? O código lê o **A0**?

| 📸 Cole aqui: **duas fotos** (potenciômetro numa ponta e na outra) **ou um GIF** girando |
|---|
| |

| 📝 Cole aqui: o seu `loop()` (via Telegram) |
|---|
| |

> ⚡ **Já domina?** Responda o 3B.1, escreva o `loop()` e registre os extremos e a foto.

**📎 Evidência — Etapa 3B:** confira que tem: previsões e conta do 3B.1 · extremos vistos · resposta sobre o dígito que treme · fotos ou GIF · `loop()`

---

# Etapa 3C — Um pequeno instrumento: indicador de nível (7 min)

> 🧭 **Orientação:** a leitura bruta (0–1023) não diz nada para quem olha. Um instrumento mostra uma escala que faz sentido: aqui, um **nível de 0 a 1000**. **Ao final desta etapa o display mostra 0 numa ponta do potenciômetro e 1000 na outra.**

*Lembrete do lab01:* `map(x, a, b, c, d)` converte `x` da faixa a–b para a faixa c–d, e `constrain()` segura o resultado dentro da faixa.

## 3C.1 Converter para 0–1000 (4 min)

1. 🧮 Com `map(leitura, 0, 1023, 0, 1000)`, quanto vale o nível para `leitura = 512`? ______ *(O `map()` faz conta com inteiros: corta a parte depois da vírgula.)*
2. **Piloto:** mude o `loop()`: converta a leitura para o nível com `map()`, proteja com `constrain()` e mostre o **nível** em vez da leitura.
   - **Onde mexer:** dentro de `loop()`, entre a linha do `analogRead` e a linha que mostra no display. Nessa última, troque a leitura pelo nível.
   - **Se não funcionou, olhe:**
     1. Ainda chega a 1023: a linha que mostra ainda usa a **leitura**, e não o nível.
     2. O `constrain()` **devolve** o valor limitado: guarde o resultado numa variável. Sozinho na linha, ele não muda nada.
     3. Erro na linha do `map()`: são **5** valores entre parênteses, separados por vírgula.
3. Carregue. Nas pontas aparecem **0** e **1000**? ______ Em qual ponta está o 1000? ______

> 🔎 **Se não funcionou, olhe nesta ordem:**
> 1. A IDE mostrou **"Carregado"**? Se deu erro, leia a **primeira** linha vermelha.
> 2. Ainda aparece a leitura de 0 a 1023: o código **novo** foi carregado?
> 3. A fiação é a mesma do 3B: se a leitura aparecia lá, o problema está no código.
4. 💭 *(se sobrar tempo)* Para quem usa o instrumento, faz mais sentido o 1000 na esquerda ou na direita? Como inverter só trocando dois números no `map()`? ______________________

## 3C.2 Zeros à esquerda: sim ou não? (3 min)

1. 🔮 Com o nível em **7**, o display mostra `   7` (só o último dígito aceso) ou `0007`? ______
2. Gire até um nível pequeno e confira. Acertou? ______
3. A função que você usa tem um **segundo argumento**, `true` ou `false`, que liga os zeros à esquerda. Procure na página da biblioteca (**Referências**) e teste os dois. Qual é o padrão quando você não escreve nada? ______
   - **Onde mexer:** na linha que mostra o número, dentro de `loop()`: o `true` ou `false` entra **depois** do valor, separado por vírgula, antes do `)`.
   - **Se não funcionou, olhe:**
     1. Erro `'True' was not declared in this scope`: em C++ é `true` e `false`, tudo minúsculo.
     2. Não viu diferença: gire até um nível **pequeno**. Com 4 algarismos (1000) não sobra lugar para zeros.
4. 💭 Para um indicador que muda o tempo todo, qual você escolhe, com ou sem zeros? Por quê? *(Pense em como fica a leitura quando o número passa de 99 para 100.)* ______________________

| 📸 Cole aqui: **uma foto** do indicador com a opção que a dupla escolheu |
|---|
| |

| 📝 Cole aqui: o código final (via Telegram) |
|---|
| |

> ⚡ **Já domina?** Faça o 3C.1 e o 3C.2 direto e escolha um desafio *(se sobrar tempo)*:
> - **Brilho:** use `setBrightness()` para o brilho seguir o nível (0 a 7). Lembre: o brilho novo só vale **na próxima vez** que você mostrar um número. 🔮 O que acontece se você chamar `setBrightness()` e não mostrar nada depois? ______________________
> - **Dois-pontos:** se o seu módulo tem dois-pontos no meio, use `showNumberDecEx(valor, 0b01000000, true)` para acendê-los e mostre o nível de **00:00 a 10:00**. Se o módulo não tem dois-pontos nem pontos decimais, pule este ⚡.
> - **Pontos decimais:** se o seu módulo tem pontos decimais, mostre a porcentagem **0,0 a 100,0 %** (o segundo argumento muda: veja a lista no comentário de `showNumberDecEx` na página da biblioteca). 🔒 Por que o mesmo `map()` de 0 a 1000 serve para 0,0 a 100,0 %? ______________________
> - **Volta ao Doc 1:** a função `setSegments()` recebe os segmentos de cada dígito com **bit 0 = a … bit 6 = g**, como a sua tabela `SEG[10]`. Mostre um símbolo seu (ex.: `-` ou uma letra do Doc 1) num dos dígitos.

**📎 Evidência — Etapa 3C:** confira que tem: conta do 3C.1 · 0 e 1000 nas pontas · previsão e resposta dos zeros à esquerda · foto · código final · desafio ⚡ (se fez)

---

# Fechamento do bloco (3 min)

1. 💭 No Doc 2, o **seu** código fazia a varredura: `exibir[4]`, `varrer()`, `mostrarDigito()`, a frequência de varredura e o `millis()`, com **11 pinos**. Aqui foram **2 pinos** e duas linhas de código (brilho e número). O que **saiu do seu software e foi para dentro do chip TM1637**? E o que a **biblioteca** faz entre o seu `showNumberDec()` e o chip? ______________________
2. 🔒 Nos Docs 1 e 2 você usou o simulador; aqui, a bancada. Cite **duas coisas** que a bancada mostrou (ou poderia mostrar) e o simulador esconde. *Ideias: corrente nos pinos, fio solto ou trocado, instalar biblioteca, brilho real, leitura que "treme".* ______________________

## O que levei do bloco

Os três documentos foram um caminho só, de baixo para cima:

| Elo | Onde você viu |
|---|---|
| **bit** | 4 bits BCD e a tabela `SEG[10]` (Doc 1) |
| **sinal** | nível ALTO acende o segmento; nível ALTO na base liga o dígito (Docs 1 e 2) |
| **circuito** | um resistor por segmento, um NPN por dígito (Docs 1 e 2) |
| **software** | `mostrarDigito()`, `exibir[4]`, `varrer()` (Doc 2) |
| **temporização** | persistência da visão, frequência de varredura, `millis()` (Doc 2) |
| **protocolo** | CLK + DIO: o número vai bit a bit por 2 fios (Doc 3) |
| **biblioteca** | `TM1637Display`: esconde o protocolo atrás de `showNumberDec()` (Doc 3) |
| **aplicação** | potenciômetro → `map()` → indicador de nível (Doc 3) |

3. 💭 Qual elo foi o mais difícil para a dupla, e qual você acha que mais vai usar daqui para a frente? ______________________

**Entrega:** salve o arquivo e entregue no Classroom. Este é o último documento do bloco **do bit à biblioteca**.

> RASCUNHO (professor): não testado em bancada. Pinos CLK = D7 e DIO = D8 a confirmar na bancada com o módulo. Apague este quadro antes de entregar aos alunos.
