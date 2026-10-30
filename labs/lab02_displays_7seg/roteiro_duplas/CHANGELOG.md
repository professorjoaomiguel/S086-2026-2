# Changelog — Lab02 (roteiros em dupla)

Versão no formato `LAB02-DN · vM.m · data`, impressa logo abaixo do título de cada documento (e no `.docx`).
Regra: **maior (M)** quando muda o que o aluno faz ou entrega; **menor (m)** para dicas, correção de texto e formatação.
Uma entrada por mudança, citando os documentos atingidos. Mais recente primeiro.

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
