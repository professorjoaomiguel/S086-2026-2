// Lab 02 - Etapa 1A (CD4511 + display de cátodo comum, Tinkercad)
// Objetivo: contar de 0 a 9 mandando o número em BCD (4 bits) para o CD4511,
// que sozinho acende os segmentos certos do display.
// Status: não testado em bancada.
//
// Ligação: D5 -> D (bit 3, MSB), D4 -> C (bit 2), D3 -> B (bit 1),
// D2 -> A (bit 0, LSB) nas entradas do CD4511.
// MSB = bit mais significativo (vale 8); LSB = bit menos significativo (vale 1).
//
// Nomes dos pinos de entrada do CD4511 no Tinkercad:
//   Arduino | Tinkercad (português) | Tinkercad (inglês) | Entrada BCD | Peso
//   D5      | Entrada 4             | Input 4            | D (MSB)     | 8
//   D4      | Entrada 3             | Input 3            | C           | 4
//   D3      | Entrada 2             | Input 2            | B           | 2
//   D2      | Entrada 1             | Input 1            | A (LSB)     | 1
// Atenção: no Tinkercad, os pinos chamados A a G são as SAÍDAS para o display.
// As entradas BCD se chamam Entrada 1 a 4 (Input 1 a 4).
//
// As saídas a-g do CI vão ao display (um resistor
// por segmento). LT e BI ligados em nível alto, LE em nível baixo.

// A posição no vetor é o número do bit: [0] = bit 0 (LSB) ... [3] = bit 3 (MSB)
const byte PINOS_BCD[4] = {2, 3, 4, 5};

const unsigned int INTERVALO_MS = 1000;   // tempo entre um dígito e o próximo

void enviarBCD(byte valor) {
  for (byte bit = 0; bit < 4; bit++) {
    digitalWrite(PINOS_BCD[bit], (valor >> bit) & 1);
  }
}

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(PINOS_BCD[i], OUTPUT);
  }
}

void loop() {
  for (byte n = 0; n <= 9; n++) {
    enviarBCD(n);
    delay(INTERVALO_MS);
  }
}
