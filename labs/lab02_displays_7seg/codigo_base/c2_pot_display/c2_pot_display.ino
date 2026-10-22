// Lab 02 - Etapa 3B (potenciômetro no display)
// Objetivo: mostrar no display o valor bruto lido do potenciômetro (0 a 1023).
// Status: não testado em bancada.
//
// Ligação (a confirmar na bancada): CLK -> D7, DIO -> D8; potenciômetro no A0.

#include <TM1637Display.h>

const byte PINO_CLK = 7;
const byte PINO_DIO = 8;
const byte PINO_POT = A0;

TM1637Display display(PINO_CLK, PINO_DIO);

void setup() {
  display.setBrightness(5);
}

void loop() {
  int leitura = analogRead(PINO_POT);   // 0 a 1023
  // Sem zeros à esquerda: 7 aparece como "   7", não "0007".
  display.showNumberDec(leitura, false);
  delay(100);
}
