// Lab 02 - Etapa 1B (ESQUELETO: este código está INCOMPLETO de propósito)
// Objetivo: mostrar 0 a 9 no display, sem o CD4511, usando a tabela SEG[]
// que a dupla escreveu no roteiro.
//
// >>> VOCÊS PRECISAM MODIFICAR ESTE CÓDIGO EM 2 LUGARES: <<<
//   SUA VEZ 1: preencher a tabela SEG[] com os valores do roteiro (1B.2)
//   SUA VEZ 2: escrever o corpo da função loop() (1B.3, passo 2)
// Procurem por "SUA VEZ" no código. Se não modificarem, o display fica apagado.
//
// Ligação: segmentos a..g nos pinos D2..D8, um resistor de 220 ohms por
// segmento, cátodo comum (pino comum) no GND.

const byte PINOS_SEG[7] = {2, 3, 4, 5, 6, 7, 8};   // a, b, c, d, e, f, g

// bit0 = a ... bit6 = g; 1 = aceso (cátodo comum)
// >>> SUA VEZ 1: troquem cada 0b0000000 pelo valor da linha de mesmo número
// >>> da SUA tabela. Mantenham a vírgula no fim de cada linha, menos na do 9.
const byte SEG[10] = {
  0b0000000,  // 0  <- SUA VEZ 1
  0b0000000,  // 1  <- SUA VEZ 1
  0b0000000,  // 2  <- SUA VEZ 1
  0b0000000,  // 3  <- SUA VEZ 1
  0b0000000,  // 4  <- SUA VEZ 1
  0b0000000,  // 5  <- SUA VEZ 1
  0b0000000,  // 6  <- SUA VEZ 1
  0b0000000,  // 7  <- SUA VEZ 1
  0b0000000,  // 8  <- SUA VEZ 1
  0b0000000   // 9  <- SUA VEZ 1
};

void setup() {
  // Esta parte já está pronta: NÃO precisa mexer.
  for (byte i = 0; i < 7; i++) {
    pinMode(PINOS_SEG[i], OUTPUT);
  }
}

void loop() {
  // >>> SUA VEZ 2: escrevam o loop() aqui dentro.
  // Para cada número n de 0 a 9:
  //   para cada segmento i de 0 a 6, mande ao pino PINOS_SEG[i] o bit i de SEG[n]
  //   (dica: bitRead(valor, numeroDoBit)); depois do for dos segmentos, delay(1000).
}
