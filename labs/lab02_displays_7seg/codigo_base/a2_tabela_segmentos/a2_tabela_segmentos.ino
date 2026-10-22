// Lab 02 - Etapa 1B (sem CI: o Arduino acende cada segmento direto)
// Objetivo: usar a tabela SEG[] (um bit por segmento) para mostrar 0 a 9
// num display de cátodo comum, sem o CD4511.
// Status: não testado em bancada.
//
// Ligação: segmentos a..g nos pinos D2..D8, um resistor por segmento,
// cátodo comum (pino comum) no GND.

const byte PINOS_SEG[7] = {2, 3, 4, 5, 6, 7, 8};   // a, b, c, d, e, f, g

// bit0 = a, bit1 = b, ..., bit6 = g. 1 = aceso (cátodo comum).
// Exemplo: 0 acende a,b,c,d,e,f -> 0b0111111 = 0x3F.
// Confira cada valor com o desenho do display.
const byte SEG[10] = {
  0x3F,  // 0
  0x06,  // 1
  0x5B,  // 2
  0x4F,  // 3
  0x66,  // 4
  0x6D,  // 5
  0x7D,  // 6
  0x07,  // 7
  0x7F,  // 8
  0x6F   // 9
};

const unsigned int INTERVALO_MS = 1000;

void mostrarSegmentos(byte padrao) {
  for (byte i = 0; i < 7; i++) {
    digitalWrite(PINOS_SEG[i], (padrao >> i) & 1);
  }
}

void setup() {
  for (byte i = 0; i < 7; i++) {
    pinMode(PINOS_SEG[i], OUTPUT);
  }
}

void loop() {
  for (byte n = 0; n <= 9; n++) {
    mostrarSegmentos(SEG[n]);
    delay(INTERVALO_MS);
  }
}
