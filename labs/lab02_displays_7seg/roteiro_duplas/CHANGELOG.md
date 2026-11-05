# Changelog — Lab02 (roteiros em dupla)

Versão no formato `LAB02-PN · vM.m · data` (até 2026-10-29 era `LAB02-DN`, "Doc N"), impressa logo abaixo do título de cada documento (e no `.docx`).
Regra: **maior (M)** quando muda o que o aluno faz ou entrega; **menor (m)** para dicas, correção de texto e formatação.
Uma entrada por mudança, citando os documentos atingidos. Mais recente primeiro.

## 2026-11-05 — P1 v1.8, P2 v1.3, P3 v1.2
Alunos se perderam na montagem e no CD4511. "Placa de ensaio" virou **protoboard** (P1 e P2). P1: nova seção **"Conhecer a protoboard"** na Etapa 0 (diagrama de colunas, metades a–e e f–j, trilhos e canal central, 4 regras e uma previsão 🔮; Etapa 0 passou de 5 para 7 min); em **"Conhecer o CD4511"**, passo 🔍 para buscar o datasheet, comparar o diagrama de pinos com a tabela PT/EN, achar na tabela de funcionamento o que acontece com 1010 e anotar o link (4 min; Evidência da 1A atualizada). 0.2: como achar o display na biblioteca (**"Visor de 7 segmentos"** em português, **"Display"** em inglês). 1B.4-2: a pergunta deixou de trazer a resposta ("justifique pela corrente") e passou a pedir que comparem os segmentos acesos no "1" e no "8"; o ⚡ "Já domina?" do fim do 1B.4 foi para o início da Etapa 1B (como nas outras etapas) e o desafio cátodo→ânodo virou uma seção própria *(se sobrar tempo)* com 3 passos. Itens *(se sobrar tempo)* ficavam espalhados e misturados à evidência: agora há o selo **⭐ EXTRA** (tabela de selos, nas 3 partes), e na P1 uma seção própria **"⭐ EXTRA — só se sobrar tempo (opcional)"** depois da Evidência da 1B, com avisos de que pode ficar em branco e os Extras A (explicar o 1B.4-1), B (ânodo) e C (letras). Nas P2 e P3 os itens inline passaram a ⭐ **EXTRA**. Topo de cada parte separado em **🧰 PREPARAÇÃO (leia antes de começar)** e **🚀 ATIVIDADE (comece aqui)**, no mesmo documento, com checklist "✅ Antes de descer, confira" e tempo que vale só para a atividade. Ajustes do revisor didático: concordância ("na Parte 2", "Partes 1 e 2"); ⚠️ no aviso de alimentar o CD4511 (⚡ é só atalho); alternativas da 1B.4 sem os números que entregam a resposta; "mensagem parecida" no erro do compilador; dois prints no 0.2. `build_docx.py` v1.1: bordas em cada célula, título das tabelas em negrito e com fundo, tabelas na largura da página, caixas de orientação sombreadas (o Docs perdia a linha entre o título e a primeira linha). Gabarito com as duas respostas novas.

## 2026-11-05 — P1 v1.6, P2 v1.1, P3 v1.1
Feedback da turma (versão do Classroom): **não ficou claro o que fazer** e os alunos não entenderam que precisavam marcar uma alternativa. Mudanças nos três documentos: (1) **"Doc N de 3" virou "Parte N de 3"** em títulos, chamadas de entrega e referências cruzadas (o selo passou a `LAB02-PN`); (2) nova caixa **"Como preencher este documento"** no topo: o arquivo é um Google Docs, aberto pelo Classroom com a conta Google educacional, respostas escritas direto nele, e nas questões ☑️ o aluno escolhe uma alternativa e **escreve a letra** em "Sua resposta (letra)". P1: 1B.4-1 deixou de ser lista aninhada (o Docs mostrava uma bolinha vazia e alternativas desalinhadas) e as alternativas viraram linhas do mesmo item; 1B.2 ganhou um passo 🔍📸 para buscar na internet uma imagem de display de 7 segmentos rotulado, colar no relatório e anotar a fonte (quadro novo; Evidência da 1B atualizada). Lab01 não foi alterado; o lab03 já nasce com "Parte".

## 2026-10-29 — D1 v1.5
Alunos não perceberam que **eles** precisavam modificar o código na 1B. 1B.3: o código deixou de ficar embutido no roteiro e passou para o repositório, como na 1A (`codigo_base/a2_tabela_segmentos_esqueleto`, com marcas `SUA VEZ 1` e `SUA VEZ 2`). Novo aviso ✏️ no topo do 1B.3 (incompleto de propósito; 2 lugares para modificar), reforço na orientação da 1B e, no 1A.3, um ✅ dizendo que ali **não** se modifica o código.

## 2026-10-29 — D1 v1.4
Nova seção **"Conhecer o CD4511"** (leitura, 2 min) entre 1A.1 e 1A.2, sem numeração para não mexer nas referências do gabarito: o que o CI faz, os 16 pinos em 4 grupos (alimentação, entradas BCD, controle, saídas) e o aviso de que o CI **precisa ser ligado no VDD (5V) e no VSS (GND)**.

## 2026-10-29 — D1 v1.3
1A.2: nova tabela dos pinos de controle **LT (3), BI (4) e LE (5)**, com sigla, significado em inglês, nome no Tinkercad em português e inglês, tradução, onde ligar e o que acontece se ligar errado. O passo 4 passou a remeter a ela. Confirmado no Tinkercad: o pino 5 aparece como **Ativação de trava** (o aviso de nome ausente ficou só para o pino 12).

## 2026-10-29 — D1 v1.2
1A.2: as quatro entradas BCD ganharam uma linha cada na tabela de pinos, com nome em português e em inglês, letra do datasheet, bit e peso, e a indicação de **LSB** (Entrada 1 / Input 1 = A, pino 7) e **MSB** (Entrada 4 / Input 4 = D, pino 6). O passo 5 repete a correspondência D2 a D5.

## 2026-10-29 — D1 v1.1
Feedback do teste no Tinkercad em português: o display de 7 segmentos aparece como **Visor** (aviso no 0.2). Os pinos do CD4511 vêm **traduzidos** (Potência = VDD, Solo = GND, Entrada 1–4 = A–D, Teste da lâmpada = LT, Limpando = BI; saídas A–G; pinos 5 e 12 sem nome visível, pela guia de alinhamento). 1A.2 ganhou a tabela de pinos (português e inglês) e o aviso sobre os nomes confusos, e passou de 6 para 7 passos. Dicas do 1A.3 com os nomes do Tinkercad.

## 2026-10-22 — v1.0 (D1, D2, D3)
Marco inicial do versionamento. D1: do bit ao segmento (com peso dos bits 8-4-2-1); D2: vários dígitos com varredura; D3: módulo TM1637 e biblioteca (**RASCUNHO, não validado em bancada**). Inclui dicas "onde mexer" e "se falhar, olhe".
