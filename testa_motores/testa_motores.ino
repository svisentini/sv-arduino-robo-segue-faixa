// Definição dos pinos do Arduino para a Ponte H L298N
#define ENA 6   // Pino de Habilitação do Motor A (PWM)
#define IN1 7   // Pino de controle 1 do Motor A
#define IN2 8   // Pino de controle 2 do Motor A

#define ENB 11  // Pino de Habilitação do Motor B (PWM)
#define IN3 9   // Pino de controle 1 do Motor B
#define IN4 10  // Pino de controle 2 do Motor B

#define VELOCIDADE 150

void setup() {
  // Configura todos os pinos como SAÍDA
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Inicia a comunicação serial para monitorar a velocidade (opcional)
  Serial.begin(9600);
}

void loop() {
  anda_frente();
  delay(3000); // Aguarda 3 segundos

  para_motores();
  delay(2000); // Aguarda 2 segundos

  anda_tras();  
  delay(3000); // Aguarda 3 segundos
  
  para_motores();
  delay(2000); // Aguarda 2 segundos antes de repetir o loop
}

void anda_tras(){
  // === Teste: Motores para frente ===
  Serial.println("Movendo para Tras...");
  digitalWrite(IN1, HIGH);  // Motor A: Liga para frente
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  // Motor B: Liga para frente
  digitalWrite(IN4, HIGH);
  
  // Define a velocidade dos motores (0 a 255)
  // 255 é velocidade máxima. Você pode diminuir para testar
  analogWrite(ENA, VELOCIDADE); 
  analogWrite(ENB, VELOCIDADE);
}

void anda_frente(){
    // === Teste: Motores para trás ===
  Serial.println("Movendo para Frente...");
  digitalWrite(IN1, LOW);   // Motor A: Liga para trás
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);   // Motor B: Liga para trás
  digitalWrite(IN4, LOW);
  
  // Define a velocidade novamente
  analogWrite(ENA, VELOCIDADE); 
  analogWrite(ENB, VELOCIDADE);
}

void para_motores(){
    // === Teste: Motores param ===
  Serial.println("Parando...");
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // Parada total
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0);
}

