// Lab 02 - Etapa 2A (dois dígitos, segmentos em paralelo)
// Objetivo: mostrar um número de 2 dígitos com um só conjunto de 7 fios de
// segmento, acendendo um dígito de cada vez (multiplexação) rápido o bastante
// para parecer que os dois estão acesos.
// Status: não testado em bancada.
//
// Ligação: segmentos a..g em D2..D8 (em paralelo nos 2 displays, um resistor
// por segmento). D9 e D10 vão à base de um NPN por dígito (via resistor);
// o NPN liga o cátodo comum do dígito ao GND. HIGH = dígito habilitado.

const byte PINOS_SEG[7] = {2, 3, 4, 5, 6, 7, 8};   // a..g
const byte PINOS_DIG[2] = {9, 10};                 // 0 = dezena, 1 = unidade

// bit0 = a ... bit6 = g, 1 = aceso (cátodo comum)
const byte SEG[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// Tempo que cada dígito fica aceso. Varie (1, 5, 20, 100 ms) e observe:
// muito curto = brilho fraco; muito longo = pisca.
const unsigned int TEMPO_DIGITO_MS = 5;

const byte NUMERO = 42;   // o que será exibido (0 a 99)

// Acende UM dígito: apaga todos, põe os segmentos, habilita só o escolhido.
// (Apagar antes evita o "fantasma" do dígito anterior.)
void mostrarDigito(byte posicao, byte valor) {
  for (byte d = 0; d < 2; d++) {
    digitalWrite(PINOS_DIG[d], LOW);
  }
  for (byte i = 0; i < 7; i++) {
    digitalWrite(PINOS_SEG[i], (SEG[valor] >> i) & 1);
  }
  digitalWrite(PINOS_DIG[posicao], HIGH);
}

void setup() {
  for (byte i = 0; i < 7; i++) pinMode(PINOS_SEG[i], OUTPUT);
  for (byte d = 0; d < 2; d++) pinMode(PINOS_DIG[d], OUTPUT);
}

void loop() {
  mostrarDigito(0, NUMERO / 10);
  delay(TEMPO_DIGITO_MS);
  mostrarDigito(1, NUMERO % 10);
  delay(TEMPO_DIGITO_MS);
}
