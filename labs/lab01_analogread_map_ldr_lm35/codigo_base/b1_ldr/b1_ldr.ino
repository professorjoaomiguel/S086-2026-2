// Lab 01 - Bloco 1 (LDR no A1 controlando o LED vermelho no D9)
// UNO R3 + Shield 9-em-1. Abra o Plotter Serial (9600 baud).
//
// Este sketch JÁ COMPILA e roda, mas os valores de calibração são
// provisórios. Você vai ajustá-lo nas etapas marcadas com "ETAPA".

const uint8_t PINO_LDR = A1;   // LDR (o número SOBE com a luz)
const uint8_t PINO_LED = 9;    // LED vermelho (PWM)

// ETAPA 2.2-1: troque pelos valores que VOCÊ mediu na tabela do 2.1.
const int MINIMO_MEDIDO = 0;     // leitura com o LDR coberto (escuro)
const int MAXIMO_MEDIDO = 1023;  // leitura com a lanterna (claro)

void setup() {
  Serial.begin(9600);
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  int leitura = analogRead(PINO_LDR);

  // ETAPA 2.2-2: converta a faixa medida para 0-255 com map().
  int brilho = map(leitura, MINIMO_MEDIDO, MAXIMO_MEDIDO, 0, 255);

  // ETAPA 2.2-6: limite o resultado a 0-255 com constrain().

  analogWrite(PINO_LED, brilho);

  // Formato do Plotter Serial: nome:valor,nome:valor
  Serial.print("ldr:");
  Serial.print(leitura);
  Serial.print(",brilho:");
  Serial.println(brilho);

  delay(50);
}
