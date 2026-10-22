# Doc 1 de 3 — Placa pronta

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

Marque o que a dupla usou e anote o que for pedido.

| Componente | Usou? (S ou N) | Anote |
|---|---|---|
| Arduino UNO R3 | | Chip USB (16U2 ou CH340): |
| Shield 9-em-1 | | |
| Cabo USB | | |
| Potenciômetro (A0) | | |
| LED vermelho (D9) | | |
| LED **L** da placa (pino 13) | | |

## Como trabalhar

### Piloto e navegador

A dupla trabalha com **dois PCs e dois papéis**.

| | **Piloto** | **Navegador** |
|---|---|---|
| **Faz** | Opera a **Arduino IDE** e a placa: conecta, carrega o sketch, escreve e edita o código, gira o potenciômetro, cobre o LDR. | Conduz **este roteiro**: lê cada passo em voz alta, confere se foi feito, e **registra** aqui (respostas, fotos, prints, código). |
| **Espera-se** | Executar **um passo por vez**, só depois que o navegador ler. Avisar o que está fazendo e o que está vendo (ex.: "carreguei, a COM é a 5"). | Ler com calma, **não pular passos**, cobrar o registro e só avançar quando o piloto confirmar. Chamar o professor se algo não bater. |
| **Não faz** | Não avança sozinho sem o roteiro. | Não digita o código nem mexe na placa, mas **orienta e questiona**. |

- Os dois **pensam juntos** nas perguntas 🔮 🧮 🔒 💭. Quem não está com a mão no teclado raciocina em voz alta.
- **Podem trocar de papel durante a prática.** É convite, não obrigação. Boas horas de trocar: ao começar cada etapa (0, 1, 2, 3) ou quando um dos dois estiver perdido. Quem só pilotou aprende outra coisa navegando.
- **Antes de trocar:** salve o código, mande-o pelo Telegram e passe o registro para o PC de quem vai navegar.
- **Dica:** o relatório é um arquivo só, então combinem quem o mantém aberto (o navegador) e mandem o código pelo Telegram para colar nele.

### Demais combinados

- **Foto, print ou GIF no Google Docs:** *Inserir → Imagem*, ou cole com `Ctrl+V`. Print de tela no Windows: `Win + Shift + S`. **Vídeo não cola no Docs; GIF cola** (como imagem).
- **Telegram Web** aberto nos dois PCs: o piloto envia o código, o navegador cola no relatório.
- Um passo de cada vez, na ordem em que aparecem.
- ⚡ **Já domina?** Faça só o que o selo pede e siga.
- Estourou o tempo? **Siga adiante** e volte depois. Itens *(se sobrar tempo)* podem ficar em branco.
- **Trocar de documento conta no tempo** (~2 min): entregue pelo Classroom e abra o próximo.
- **Os sketches** (programas prontos) estão no repositório
  <https://github.com/professorjoaomiguel/S086-2026-2>, na pasta `labs/lab01_analogread_map_ldr_lm35/codigo_base`, ou no link que o professor enviar no Telegram. Para abrir: *Arquivo → Abrir…* e escolha o arquivo `.ino` (ele precisa estar numa pasta com o mesmo nome).

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
| **sketch** | o programa que roda na placa |
| **contagem** | o número de 0 a 1023 que o `analogRead` devolve |
| **Monitor Serial** | janela de texto com o que a placa envia (lupa no canto superior direito da IDE) |
| **Plotter Serial** | gráfico do que a placa envia (*Ferramentas → Plotter Serial*). **Feche o Monitor antes de abrir o Plotter** |
| **`map()`** | `map(x, a, b, c, d)` converte `x` da faixa a–b para a faixa c–d |

### Referências

- [Documentação da linguagem Arduino (português)](https://docs.arduino.cc/language-reference/pt/): [`delay()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/delay/) · [`millis()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/time/millis/) · [`map()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/math/map/) · [`analogWrite()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/analog-io/analogWrite/) · [`analogRead()`](https://docs.arduino.cc/language-reference/pt/fun%C3%A7%C3%B5es/analog-io/analogRead/)
- [Repositório lab-boards](https://github.com/professorjoaomiguel/lab-boards): fotos e dados das placas e do shield. Para conferir a localização das peças: [pinout-anotado.jpg](https://github.com/professorjoaomiguel/lab-boards/blob/main/shields/uno-shield-9in1/imagens/pinout-anotado.jpg) (use depois de tentar sozinho, não para copiar).

**Tempo deste documento: ~30 min.** Ao terminar, entregue pelo Classroom e abra o **Doc 2 de 3**.

---

# Etapa 0 — Ligar, conectar e conhecer a placa (20 min)

> 🧭 **Orientação:** antes de programar, garanta que o computador enxerga a placa e que você sabe onde ficam as peças que vai usar. **Ao final desta etapa a placa deve estar piscando e as peças do shield identificadas.**

## 0.1 Ligar e achar a COM (5 min)

1. Conecte o UNO R3 ao PC com o cabo USB e encaixe o Shield 9-em-1.
2. Abra o **Gerenciador de Dispositivos → Portas (COM e LPT)**. Desconecte e reconecte o cabo: a linha que **some e volta** é a sua placa.
3. Veja o que aparece ao lado da porta e escreva a letra no quadro abaixo:
   - **A** = **Arduino Uno (COMx)**: chip USB ATmega16U2
   - **B** = **USB-SERIAL CH340 (COMx)**: clone com chip CH340
   - **C** = **Nada / "Dispositivo desconhecido"**: falta o driver CH340. Chame o professor.

| 📝 Registre aqui: porta **COM ___** · letra (A, B ou C): ___ · texto ao lado da porta |
|---|
| |

4. ☑️ *(se sobrar tempo)* **Como ter certeza de qual COM é a da sua placa?**
   - a) É sempre a de menor número.
   - b) É a que aparece ao plugar e some ao desplugar.
   - c) É sempre a COM1.
   - d) A IDE escolhe sozinha, não preciso conferir.
   **Sua resposta (letra): ______**

## 0.2 Gravar o primeiro sketch (5 min)

1. **Piloto:** abra a Arduino IDE. Em *Ferramentas → Placa → Arduino AVR Boards*, escolha **Arduino Uno**. Em *Ferramentas → Porta*, escolha a sua COM. Se a porta não aparece, reconecte o USB e abra o menu de novo.
2. Abra *Arquivo → Exemplos → 01.Basics → Blink* e clique em **Carregar** (→). Espere a mensagem "Carregado".
3. 🔮 Antes de mudar: se você trocar os dois `delay(1000);` por `delay(250);`, o que muda? ______________________
4. Os exemplos da IDE são somente leitura: use *Arquivo → Salvar como…* para criar a sua cópia. Troque as duas linhas `delay(1000);` por `delay(250);`, carregue de novo e confira. Acertou a previsão? (S ou N): ______

| 📸 Cole aqui: **duas fotos** do Blink: (1) a placa com o LED **L** aceso; (2) o print da IDE mostrando `delay(250)` e a mensagem "Carregado". **Ou um GIF** do LED piscando |
|---|
| |

5. 🔒 No Blink original (1 s ligado, 1 s desligado), qual o **período** completo e quantas piscadas em 10 s? ______________________

> ⚡ **Já domina 0.1 e 0.2?** Anote a COM, tire as duas fotos do Blink em `delay(250)` e responda o 0.2-5. Pule para 0.3.

## 0.3 Localizar as peças (10 min)

1. 📸 Tire **uma foto do Shield 9-em-1** e **marque com setas ou números** (no Docs ou no celular):
   1. **potenciômetro** (A0) · 2. **LDR** (A1) · 3. **LM35** (A2) · 4. **LED RGB** (D9/D10/D11) · 5. **buzzer** (D5)

| 📸 Cole aqui: foto do shield com as 5 marcações |
|---|
| |

2. 🔒 *(se sobrar tempo)* O ATmega328P tem 32 KB de Flash e 2 KB de SRAM. Em qual memória o **seu sketch** fica gravado? Por que a placa continua funcionando depois de desligar o USB e religar? ______________________
3. *(se sobrar tempo)* 📸 Foto do UNO R3 marcando: USB · ATmega328P · jack de alimentação · RESET · LEDs ON e L · pinos AREF, A0–A5, 5V, GND.

**📎 Evidência — Etapa 0:** confira que tem: COM e texto ao lado · fotos do Blink · foto do shield marcada · respostas 0.2-5 (período), 0.1-4 e 0.3-2 (se fez)

---

# Etapa 1 — Ponte: potenciômetro e `map()` (10 min)

> 🧭 **Orientação:** o potenciômetro é o sensor mais simples: você controla o valor com a mão. Use-o para **ver o `map()` funcionando** antes de aplicá-lo a sensores de verdade. Não altere o código: leia, rode, observe e responda. **Ao final desta etapa você sabe dizer o que o `map()` faz com a faixa de entrada e a de saída.**

**Pinos:** A0 (potenciômetro), D9 (LED vermelho).

1. **Piloto:** *Exemplos → 03.Analog → AnalogInOutSerial*. Carregue.
2. Abra o **Monitor Serial** (9600) e gire o potenciômetro. O LED muda de brilho e aparecem linhas como `sensor = 812  output = 202`.

| 📸 Cole aqui: **duas fotos**, cada uma com o LED e a tela do Monitor na mesma imagem: (1) potenciômetro no mínimo; (2) potenciômetro no máximo. **Ou um GIF** girando o potenciômetro |
|---|
| |

3. No editor, dentro do `loop()`, ache a linha do `map()` e copie:

| 📝 Registre aqui: a linha do `map()` |
|---|
| |

4. 🔮 Suponha que o sensor só variasse de **300 a 700** (e o `map()` fosse de 0–1023 para 0–255). O que aconteceria com o brilho?
   - a) O LED apaga totalmente e chega ao brilho máximo.
   - b) O LED nunca apaga totalmente e nunca chega ao brilho máximo.
   - c) O LED pisca.
   - d) Dá erro de compilação.
   **Sua resposta (letra): ______**
5. 🧮 **Confira a previsão com a conta:** quanto vale `output` para `sensor = 300` e para `sensor = 700`? ______ e ______

> ⚡ **Já domina?** Tire as duas fotos do passo 2 e responda o passo 4.

**📎 Evidência — Etapa 1:** confira que tem: fotos do potenciômetro (mínimo e máximo) · linha do `map()` · previsão (passo 4) e conta (passo 5)

---

> 🏆 **Desafio opcional (não entra na evidência):** faça o Blink piscar **sem `delay()`**, usando `millis()`.

# Você leva para o próximo documento

No **Doc 2**, você vai reusar:

- a sua **porta COM** e o jeito de carregar um sketch;
- a ideia do `map()` (faixa de entrada → faixa de saída), agora com uma faixa **que você mede**.

**Entrega:** salve o arquivo, entregue no Classroom e abra o **Doc 2 de 3 — Luz vira brilho**.
