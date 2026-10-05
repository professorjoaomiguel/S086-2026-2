// Lab 01 - Bloco 4: alarme de temperatura
// UNO R3 + Shield 9-em-1. Monitor Serial a 9600 baud.
//
// Este sketch compila e roda, mas o alarme ainda não decide nada.
// Você completa as etapas marcadas com "ETAPA".
// Referência do ADC: DEFAULT (5 V). NÃO use analogReference(INTERNAL) aqui.

const uint8_t PINO_SENSOR = A2;   // ETAPA 4d
const float TENSAO_REFERENCIA = 5.0;
const float ADC_MAXIMO = 1023.0;

const float LIMIAR = 30.0;        // °C: acima disto, alarme
// ETAPA 4a: crie aqui as constantes da sua faixa "confortável".

const uint8_t PINO_VERMELHO = 9;  // LED RGB (cátodo comum: HIGH acende)
const uint8_t PINO_AZUL = 10;
const uint8_t PINO_VERDE = 11;
const uint8_t PINO_BUZZER = 5;    // buzzer ativo: HIGH liga. Não use tone().

String estado = "?";              // aparece no painel serial

void setup() {
  Serial.begin(9600);
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_AZUL, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
}

// Cole aqui DENTRO o corpo da sua lerTemperatura() do bloco 2
// (com descarte e média). Mantenha o nome e o "float" da primeira linha.
float lerTemperatura() {
  int leitura = analogRead(PINO_SENSOR);
  float tensao = leitura * (TENSAO_REFERENCIA / ADC_MAXIMO);
  return tensao * 100.0;  // LM35: 10 mV por °C
}

// Decide a cor do RGB, o buzzer e o texto de "estado".
void atualizarSaidas(float tempC) {
  // ETAPA 4a: azul abaixo da faixa, verde dentro, vermelho acima do LIMIAR.
  // ETAPA 4a: buzzer ligado acima do LIMIAR (digitalWrite).
  // ETAPA 4a: atualize a variável estado (ex.: "FRIO", "OK", "ALARME").
}

void loop() {
  float tempC = lerTemperatura();
  atualizarSaidas(tempC);

  // Painel de estado: é por aqui que o professor confere seu alarme.
  Serial.print("temp=");
  Serial.print(tempC, 1);
  Serial.print(" lim=");
  Serial.print(LIMIAR, 1);
  Serial.print(" estado=");
  Serial.println(estado);

  delay(500);
}
