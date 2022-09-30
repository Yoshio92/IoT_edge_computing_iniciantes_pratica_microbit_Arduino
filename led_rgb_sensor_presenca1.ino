// C++ code
//
#define Led_R A1
#define Led_G A2
#define Led_B A3
#define Sensor_Presenca 4
#define Piezo 6

void Mudar_Cor(int Pot_R, int Pot_G, int Pot_B);


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Sensor_Presenca, INPUT);
  pinMode(Piezo, OUTPUT);
}

void loop()
{
  String cor;
  int contadorTempo = 0;
  digitalWrite(Sensor_Presenca, LOW);
  Mudar_Cor(0, 255, 0);
  cor = "verde";
  delay(1000);
  Mudar_Cor (255, 255, 0);
  cor = "amarelo";
  delay(1000);
  Mudar_Cor (255, 0, 0);
  cor = "vermelho";
  while(cor == "vermelho" && contadorTempo < 10){
    if(digitalRead(Sensor_Presenca) == HIGH){
      digitalWrite(Piezo, HIGH);
    }
    delay(100);
    digitalWrite(Piezo, LOW);
    contadorTempo++;
  }
  Mudar_Cor(0, 0, 0);
  delay(1000); 
}

void Mudar_Cor(int Pot_R, int Pot_G, int Pot_B){
  analogWrite(Led_R, Pot_R);
  analogWrite(Led_G, Pot_G);
  analogWrite(Led_B, Pot_B);
}