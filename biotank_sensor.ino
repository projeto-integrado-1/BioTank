/* MQ-4 Methane Sensor module with Arduino */
/* Interfacing with Arduino */

const int AO_Pin=0; // Porta analogica.
const int DO_Pin=8; // Pino digital.
const int Led_Pin=13; // Pino do LED.
const int Buzzer_Pin=14; // Pino do Buzzer.
cont int 
int metano_no_ar; // A variable to store digital output of MQ4.
int AO_Out; // Armazena o output do sensor MQ4.

void setup() {
  Serial.begin(115200);  // Inicializacao da comunicacao serial numa taxa de 115200.
  pinMode(DO_Pin, INPUT); // Configura o pino digital 8 como o pino de entrada.
  pinMode(Led_Pin, OUTPUT); // Configura o pino digital 13 como o pino de saida.
  pinMode(Buzzer_Pin, OUTPUT); // Configura o pino digital 14 como o pino de saida.
}

void loop()
{
  AO_Out= analogRead(AO_Pin); // Pegue a amostra de medição de saída analógica do pino AO do sensor MQ4.
  metano_no_ar= digitalRead(DO_Pin); // Leia a saída digital do sensor MQ4
  
  if (metano_no_ar == HIGH){ // se o metano no ar for identificado, o Buzzer grita.
    tone(14, 261);
  }
  else {
    noTone(Buzzer_Pin); // se o metano no ar nao for identificado, o Buzzer para.
  }
}
