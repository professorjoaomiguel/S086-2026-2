# Ficha 04 — LM35: precisão e ruído (40 min)

**Objetivo:** entender por que a leitura oscila e como deixá-la estável.
**Sketch:** o mesmo da ficha 03 (`b2_lm35_temperatura`)

## Parte A — `float` × `map()` (15 min)

1. No `loop()`, na linha `ETAPA 2b`, acrescente:
   ```cpp
   int tempMap = map(cru, 0, 1023, 0, 500);
   ```
   (0 a 500: com 5 V, 1023 contagens = 5 V = 500 °C pela regra do LM35.)
2. Imprima também `,tempMap:` e o valor. Exemplo: `cru:57,tempC:27.9,tempMap:27`.
3. Os dois discordam. Por quê? (Pista: o `map()` só trabalha com inteiros — ficha 02.)
4. Troque `Serial.println(tempC, 1)` por `(tempC, 2)`. Isso significa precisão de 0,01 °C? Olhe as "escadinhas" no Plotter: de quantos °C é cada degrau?

**✅ Entrega A:** diga em voz alta o tamanho do degrau em °C e por que 2 casas decimais não são precisão.

## Parte B — Estabilizar a leitura (25 min)

1. Deixe o LM35 parado por 1 minuto e veja `cru` no Plotter. Ela oscila.
2. Na `lerTemperatura()`, linha `ETAPA 2c`:
   - faça uma leitura e **jogue fora**;
   - `delay(100)`;
   - faça **16 leituras**, some e divida por 16 (cuidado com o tipo da soma: 16 × 1023 cabe num `int`?).
3. Imprima `cru` e `tempC` juntos e compare as curvas.

**✅ Entrega B:** no Plotter, a curva da média está bem mais lisa que a crua.

> 💡 Por que descartar a primeira leitura? O conversor tem um capacitor que "lembra" o pino lido antes. O LM35 fornece pouca corrente e demora a corrigi-lo.

---
**Fica para depois:** a conversa sobre resolução × memória do conversor, com a dupla.

⬅️ [03 — LM35: ler](03_lm35_ler.md) · ➡️ [05 — AREF](05_aref.md)
