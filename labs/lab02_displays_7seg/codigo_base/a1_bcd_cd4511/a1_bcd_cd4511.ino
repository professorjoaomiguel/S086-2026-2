// Lab 02 - Etapa 1A (CD4511 + display de cátodo comum, Tinkercad)
// Objetivo: contar de 0 a 9 mandando o número em BCD (4 bits) para o CD4511,
// que sozinho acende os segmentos certos do display.
// Status: não testado em bancada.
//
// Ligação: D2 -> A (bit 0), D3 -> B (bit 1), D4 -> C (bit 2), D5 -> D (bit 3)
// nas entradas do CD4511. As saídas a-g do CI vão ao display (um resistor
// por segmento). LT e BI ligados em nível alto, LE em nível baixo.

const byte PINOS_BCD[4] = {2, 3, 4, 5};   // bit 0 ... bit 3

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
