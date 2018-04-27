 //Definir os pinos para o microfone e relé
int relay = 8;
int microphone = A0;
 
int contador = 0;  //Contador de palmas
int contador2 = 0; //Contador de tempo para Reset
int teste = 0;
 
void setup() {
Serial.begin(9600); 
 
pinMode(relay,OUTPUT);
pinMode(microphone, INPUT);
 
/*
 Utilizamos a instrução a seguir para,
 quando ligarmos o arduino
 garantirmos que o relay esteja sempre desligado
*/
digitalWrite(relay, LOW);
 
}
 
void loop() {
  teste = analogRead(microphone);
  
  if(teste<500){
    Serial.print("PALMA DETETADA! "); //Esta linha é apenas necessária para testes
    Serial.print("Valor do sensor: "); // Esta linha é apenas necessária para testes
    Serial.println(analogRead(microphone)); // Esta linha é apenas necessária para testes
    contador++; //Incrementar a variável contador
    delay(100);
    if(contador == 1){ 
   digitalWrite(relay, !digitalRead(relay)); //Inverte o valor na saida do relé
   contador2 = 0; // Recomeça o tempo de reset
    }
     
  }
  //Contagem do tempo para dar reset
   contador2++;
   delay(1);
 
 //Quando passam 3 seg sem qualquer tipo de palma
 if(contador2 == 1000){
   
      Serial.println("Tempo Resetado"); // Necessário apenas para testes
      contador = 0; // Reseta a variável de palmas batidas
      contador2 = 0; // Reseta a variável contador2
       
    }
 
}
