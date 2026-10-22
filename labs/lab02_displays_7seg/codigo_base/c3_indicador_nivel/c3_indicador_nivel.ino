// Lab 02 - Etapa 3C (indicador de nível 0 a 1000)
// Objetivo: converter a leitura do potenciômetro (0-1023) para um nível de
// 0 a 1000 com map() e mostrá-lo sem estouro nem valor negativo.
// Status: não testado em bancada.
//
// Ligação (a confirmar na bancada): CLK -> D7, DIO -> D8; potenciômetro no A0.

#include <TM1637Display.h>

const byte PINO_CLK = 7;
const byte PINO_DIO = 8;
const byte PINO_POT = A0;

const int NIVEL_MIN = 0;
const int NIVEL_MAX = 1000;

TM1637Display display(PINO_CLK, PINO_DIO);

void setup() {
  display.setBrightness(5);
}

void loop() {
  int leitura = analogRead(PINO_POT);
  int nivel = map(leitura, 0, 1023, NIVEL_MIN, NIVEL_MAX);

  // map() não limita o resultado; constrain() garante 0..1000 (sem negativo
  // e sem passar de 4 dígitos).
  nivel = constrain(nivel, NIVEL_MIN, NIVEL_MAX);

  // true = COM zeros à esquerda: o nível aparece sempre com 4 dígitos
  // (0000, 0042, 0500, 1000), então a largura não muda enquanto gira.
  display.showNumberDec(nivel, true);
  delay(100);
}
