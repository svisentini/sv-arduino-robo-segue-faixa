// Definição dos pinos do Arduino para os sensores de linha
#define SENSOR_DIREITA 4
#define SENSOR_ESQUERDA 3 
// Definição dos pinos do Arduino para a Ponte H L298N
#define VELOCIDADE_DIREITA 6   // Pino de Habilitação do Motor A (PWM)
#define IN1 7   // Pino de controle 1 do Motor A
#define IN2 8   // Pino de controle 2 do Motor A
#define VELOCIDADE_ESQUERDO 11  // Pino de Habilitação do Motor B (PWM)
#define IN3 9   // Pino de controle 1 do Motor B
#define IN4 10  // Pino de controle 2 do Motor B
#define VELOCIDADE 100

void setup() {
  // Configura os pinos dos sensores como ENTRADAS
  pinMode(SENSOR_DIREITA, INPUT);
  pinMode(SENSOR_ESQUERDA, INPUT);

  // Configura todos os pinos como SAÍDA
  pinMode(VELOCIDADE_DIREITA, OUTPUT);
  pinMode(VELOCIDADE_ESQUERDO, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Inicia a comunicação serial para mostrar os resultados
  Serial.begin(9600);
  Serial.println("Pronto para ler os sensores...");
}

void loop() {
  // Lê o estado digital de cada sensor
  int leitura_direita = digitalRead(SENSOR_DIREITA);
  int leitura_esquerda = digitalRead(SENSOR_ESQUERDA);


  // Imprime os resultados no Monitor Serial
  //Serial.print("Sensor direita: ");
  //Serial.print(leitura_direita);
  //Serial.print(" | Sensor esquerda: ");
  //Serial.println(leitura_esquerda);


  // Pequeno atraso para a leitura ser mais estável
  // delay(100);

  if (leitura_direita == 0 and leitura_esquerda == 0){
      anda_frente();
  }
  else {
    if (leitura_direita == 0 and leitura_esquerda == 1){
        virarParaEsquerda();
    }
    else {
      if (leitura_direita == 1 and leitura_esquerda == 0){
          virarParaDireita();
      }
      else {
          para_motores();
      }
    }
  }

}

void anda_frente(){
  Serial.println("Movendo para Frente...");
  digitalWrite(IN1, LOW);   // Motor Esquerdo
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);   // Motor Direito
  digitalWrite(IN4, LOW);
  analogWrite(VELOCIDADE_DIREITA, VELOCIDADE); 
  analogWrite(VELOCIDADE_ESQUERDO, VELOCIDADE);
}

void virarParaDireita() {
  Serial.println("Movendo para Esquerda...");
  digitalWrite(IN1, HIGH); // Motor Esquerdo para frente
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);  // Motor Direito para trás
  digitalWrite(IN4, LOW);
  analogWrite(VELOCIDADE_DIREITA, VELOCIDADE);
  analogWrite(VELOCIDADE_ESQUERDO, 0);
}

void virarParaEsquerda() {
  Serial.println("Movendo para Direita...");
  digitalWrite(IN1, LOW);  // Motor Esquerdo para trás
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); // Motor Direito para frente
  digitalWrite(IN4, HIGH);
  analogWrite(VELOCIDADE_DIREITA, 0);
  analogWrite(VELOCIDADE_ESQUERDO, VELOCIDADE);
}

void para_motores(){
  Serial.println("Parando motores...");
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(VELOCIDADE_DIREITA, 0); 
  analogWrite(VELOCIDADE_ESQUERDO, 0);
}
