# Ficha 00 — Ponte: potenciômetro e `map()` (15 min)

**Objetivo:** ver o `map()` funcionando antes de usá-lo com sensores.
**Placa:** UNO R3 + Shield 9-em-1 · **Pino:** A0 (potenciômetro), D9 (LED vermelho)

## Passos

1. *Arquivo → Exemplos → 03.Analog → AnalogInOutSerial*. Carregue na placa.
2. Abra o Monitor Serial (9600) e gire o potenciômetro.
   Você deve ver `sensor = 812	output = 202` e o LED vermelho mudando de brilho.
3. Ache a linha do `map()` no código. Ela diz: "o que vai de 0 a 1023 passa a ir de 0 a 255".

## ✅ Entrega

Mostre ao professor o LED variando de brilho enquanto o número muda no Monitor.

## 🔮 Pergunta para a turma (sem resposta ainda)

E se o sensor **nunca** chegar a 0 nem a 1023 (só varia entre 300 e 700)?
O que acontece com o brilho? A próxima ficha responde.

---
**Fica para depois:** trocar o `map()` por `sensorValue / 4` e comparar.

➡️ Próxima: [01 — LDR: ler e calibrar](01_ldr_calibrar.md)
