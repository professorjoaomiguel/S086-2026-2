# Ficha 03 — LM35: o Arduino vira termômetro (30 min)

**Objetivo:** ir de **contagens** (0–1023) a **graus Celsius**.
**Pino:** A2 (LM35) · **Sketch pronto:** [`b2_lm35_temperatura`](../codigo_base/b2_lm35_temperatura/b2_lm35_temperatura.ino)

O LM35 entrega **10 mV por °C**. O caminho é sempre:

**contagens (0–1023) → tensão (V) → temperatura (°C)**

## Passos

1. Abra o sketch `b2_lm35_temperatura`, carregue na placa e abra o **Plotter Serial** (9600).
2. Compare `tempC` com a temperatura da sala.
3. Segure o LM35 entre os dedos: a curva deve subir devagar.
4. Em `lerTemperatura()`, ache as duas contas: contagens → volts e volts → °C.
5. 🧮 No caderno: a 25 °C, quantos volts o LM35 entrega? Quantas contagens o `analogRead` devolve (referência 5 V)?

## ✅ Entrega

Mostre o gráfico de `tempC` subindo quando você segura o sensor.

## 🔍 Datasheet (2 min)

[`TI_LM35_Temperatura.pdf`](../../../datasheets/sensores/TI_LM35_Temperatura.pdf): quantos mV por °C (primeira página)? Qual a exatidão do **LM35D** a 25 °C (tabela *Electrical Characteristics*)?

---
**Se o LM35 ler ≈ 0 °C:** avise o professor e trabalhe com a dupla.

⬅️ [02 — LDR: mapear](02_ldr_mapear.md) · ➡️ [04 — LM35: precisão e ruído](04_lm35_precisao_ruido.md)
