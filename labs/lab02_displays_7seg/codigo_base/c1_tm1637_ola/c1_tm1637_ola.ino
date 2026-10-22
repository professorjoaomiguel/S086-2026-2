// Lab 02 - Etapa 3A (módulo TM1637 + biblioteca TM1637Display)
// Objetivo: confirmar que o módulo e a biblioteca funcionam mostrando um
// número fixo. O módulo faz a varredura sozinho: o Arduino só envia o valor.
// Status: não testado em bancada.
//
// Ligação (a confirmar na bancada): CLK -> D7, DIO -> D8, VCC -> 5V, GND -> GND.
// Biblioteca: "TM1637" (Avishay Orpaz) pelo Gerenciador de Bibliotecas.

#include <TM1637Display.h>

const byte PINO_CLK = 7;
const byte PINO_DIO = 8;

TM1637Display display(PINO_CLK, PINO_DIO);

void setup() {
  display.setBrightness(5);        // 0 (fraco) a 7 (forte)
  display.showNumberDec(1234);     // mostra 1234
}

void loop() {
}
