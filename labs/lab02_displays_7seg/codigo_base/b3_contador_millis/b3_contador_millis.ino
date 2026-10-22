// Lab 02 - Etapa 2C (contador 0000 a 9999 com millis())
// Objetivo: contar a cada 1 s sem travar a varredura. Nada de delay():
// tanto a varredura quanto a contagem usam millis() e rodam "ao mesmo tempo".
// Status: não testado em bancada.
//
// Ligação: igual à etapa 2B (segmentos D2..D8, seleção de dígito D9..D12
// por NPN, HIGH = dígito habilitado).

const byte PINOS_SEG[7] = {2, 3, 4, 5, 6, 7, 8};      // a..g
const byte PINOS_DIG[4] = {9, 10, 11, 12};            // 0 = milhar ... 3 = unidade

// bit0 = a ... bit6 = g, 1 = aceso (cátodo comum)
const byte SEG[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

const unsigned long TEMPO_DIGITO_MS = 2;        // quanto cada dígito fica aceso
const unsigned long INTERVALO_CONTA_MS = 1000;  // passo da contagem

byte exibir[4] = {0, 0, 0, 0};   // O QUE mostrar

unsigned int contador = 0;       // 0 a 9999
byte digitoAtual = 0;            // posição da varredura
unsigned long ultimaTroca = 0;
unsigned long ultimaConta = 0;

void mostrarDigito(byte posicao, byte valor) {
  for (byte d = 0; d < 4; d++) {
    digitalWrite(PINOS_DIG[d], LOW);
  }
  for (byte i = 0; i < 7; i++) {
    digitalWrite(PINOS_SEG[i], (SEG[valor] >> i) & 1);
  }
  digitalWrite(PINOS_DIG[posicao], HIGH);
}

// Separa o contador em 4 algarismos (com zeros à esquerda: 0007).
void atualizarExibir() {
  exibir[0] = (contador / 1000) % 10;
  exibir[1] = (contador / 100) % 10;
  exibir[2] = (contador / 10) % 10;
  exibir[3] = contador % 10;
}

// Um passo da varredura: só troca de dígito quando o tempo venceu.
// Não bloqueia: se ainda não deu o tempo, retorna na hora.
void varrer() {
  unsigned long agora = millis();
  if (agora - ultimaTroca >= TEMPO_DIGITO_MS) {
    ultimaTroca = agora;
    mostrarDigito(digitoAtual, exibir[digitoAtual]);
    digitoAtual = (digitoAtual + 1) % 4;
  }
}

void setup() {
  for (byte i = 0; i < 7; i++) pinMode(PINOS_SEG[i], OUTPUT);
  for (byte d = 0; d < 4; d++) pinMode(PINOS_DIG[d], OUTPUT);
  atualizarExibir();
}

void loop() {
  varrer();

  unsigned long agora = millis();
  if (agora - ultimaConta >= INTERVALO_CONTA_MS) {
    ultimaConta = agora;
    contador++;
    if (contador > 9999) contador = 0;   // 9999 -> 0000
    atualizarExibir();
  }
}
