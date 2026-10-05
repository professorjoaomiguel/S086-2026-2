// Lab 01 - Bloco 2 (e 3): LM35 no A2
// UNO R3 + Shield 9-em-1. Abra o Plotter Serial (9600 baud).
//
// Este sketch JÁ FUNCIONA: lê o LM35 e imprime a temperatura.
// Você vai melhorá-lo nas etapas marcadas com "ETAPA".

const uint8_t PINO_SENSOR = A2;        // LM35
const float TENSAO_REFERENCIA = 5.0;   // ETAPA 3b: muda quando trocar a referência
const float ADC_MAXIMO = 1023.0;       // 10 bits: 0 a 1023

void setup() {
  Serial.begin(9600);
  // ETAPA 3b: a troca de referência do ADC entra aqui.
}

// Lê o sensor e devolve a temperatura em °C.
// Todo o resto do programa só chama esta função: ele não precisa saber
// qual sensor está ligado nem como a conversão é feita.
float lerTemperatura() {
  // ETAPA 2c: descarte uma leitura, espere e tire a média de várias leituras.
  int leitura = analogRead(PINO_SENSOR);

  float tensao = leitura * (TENSAO_REFERENCIA / ADC_MAXIMO);
  return tensao * 100.0;  // LM35: 10 mV por °C
}

void loop() {
  int cru = analogRead(PINO_SENSOR);
  float tempC = lerTemperatura();

  // ETAPA 2b: calcule a temperatura também com map() e imprima ao lado.

  // Formato do Plotter Serial: nome:valor,nome:valor
  Serial.print("cru:");
  Serial.print(cru);
  Serial.print(",tempC:");
  Serial.println(tempC, 1);

  delay(500);
}
