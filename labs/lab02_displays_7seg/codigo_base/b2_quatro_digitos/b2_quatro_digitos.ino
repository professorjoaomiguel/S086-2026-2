// Lab 02 - Etapa 2B (quatro dígitos)
// Objetivo: varrer 4 dígitos com os mesmos 7 fios de segmento. O que mostrar
// fica no vetor exibir[]; como atualizar o display fica em varrer().
// Status: não testado em bancada.
//
// Ligação: segmentos a..g em D2..D8 (em paralelo nos 4 displays, um resistor
// por segmento). D9..D12 vão à base de um NPN por dígito (via resistor);
// o NPN liga o cátodo comum do dígito ao GND. HIGH = dígito habilitado.

const byte PINOS_SEG[7] = {2, 3, 4, 5, 6, 7, 8};      // a..g
const byte PINOS_DIG[4] = {9, 10, 11, 12};            // 0 = milhar ... 3 = unidade

// bit0 = a ... bit6 = g, 1 = aceso (cátodo comum)
const byte SEG[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

const unsigned int TEMPO_DIGITO_MS = 2;   // varie e observe pisca/fantasma

// O QUE mostrar: um algarismo (0 a 9) por posição.
byte exibir[4] = {1, 2, 3, 4};

void mostrarDigito(byte posicao, byte valor) {
  for (byte d = 0; d < 4; d++) {
    digitalWrite(PINOS_DIG[d], LOW);
  }
  for (byte i = 0; i < 7; i++) {
    digitalWrite(PINOS_SEG[i], (SEG[valor] >> i) & 1);
  }
  digitalWrite(PINOS_DIG[posicao], HIGH);
}

// COMO atualizar: uma passada pelos 4 dígitos, lendo exibir[].
void varrer() {
  for (byte p = 0; p < 4; p++) {
    mostrarDigito(p, exibir[p]);
    delay(TEMPO_DIGITO_MS);
  }
}

void setup() {
  for (byte i = 0; i < 7; i++) pinMode(PINOS_SEG[i], OUTPUT);
  for (byte d = 0; d < 4; d++) pinMode(PINOS_DIG[d], OUTPUT);
}

void loop() {
  varrer();
}
