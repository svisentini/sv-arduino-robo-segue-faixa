// Definição dos pinos do Arduino para os sensores de linha
#define SENSOR_DIREITA 2 
#define SENSOR_ESQUERDA 3 


void setup() {
  // Configura os pinos dos sensores como ENTRADAS
  pinMode(SENSOR_DIREITA, INPUT);
  pinMode(SENSOR_ESQUERDA, INPUT);


  // Inicia a comunicação serial para mostrar os resultados
  Serial.begin(9600);
  Serial.println("Pronto para ler os sensores...");
}

void loop() {
  // Lê o estado digital de cada sensor
  int leitura_direita = digitalRead(SENSOR_DIREITA);
  int leitura_esquerda = digitalRead(SENSOR_ESQUERDA);


  // Imprime os resultados no Monitor Serial
  Serial.print("Sensor direita: ");
  Serial.print(leitura_direita);
  Serial.print(" | Sensor esquerda: ");
  Serial.println(leitura_esquerda);


  // Pequeno atraso para a leitura ser mais estável
  delay(500);
}