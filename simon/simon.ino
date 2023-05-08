#include <iostream>
#include <vector>
using namespace std;

const int reset=13;
const int botoes[] = {34, 35, 32, 22}; 
const int leds[] = {25, 26, 27, 14};  
vector<int> jogador;//lista de inputs do jogador
vector<int> computador;//lista de inputs da máquina

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT_PULLUP);
  }
  pinMode(reset,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(reset)==HIGH){
    resetar();
  }
  vez_do_computador(computador);
  vez_do_jogador(computador, jogador);
}
//função para resetar
void resetar() {
  noInterrupts();
  ESP.restart();
  while (true) {}
}


void vez_do_computador(vector<int>& vetor1){
  int aleatorio = random(0, 4);
  vetor1.push_back(aleatorio);
  for(int i=0;i<vetor1.size();i++){
    digitalWrite(leds[vetor1[i]],HIGH);
    delay(400);
    digitalWrite(leds[vetor1[i]],LOW);
    delay(400);
  }
}


void vez_do_jogador(vector<int> vetor1, vector<int> vetor2){
  jogador.clear();
  while(vetor2.size()<vetor1.size()){
    if(digitalRead(botoes[0])==HIGH){
      vetor2.push_back(0);
      digitalWrite(leds[0],HIGH);
      delay(400);
       digitalWrite(leds[0],LOW);
      
    }  
    else if(digitalRead(botoes[1])==HIGH){
      vetor2.push_back(1);
      digitalWrite(leds[1],HIGH);
      delay(400);
       digitalWrite(leds[1],LOW);
    }
    
    else if(digitalRead(botoes[2])==HIGH){
      vetor2.push_back(2);
      digitalWrite(leds[2],HIGH);
      delay(400);
       digitalWrite(leds[2],LOW);
    }
    
    else if(digitalRead(botoes[3])==HIGH){
      vetor2.push_back(3);
      digitalWrite(leds[3],HIGH);
      delay(400);
       digitalWrite(leds[3],LOW);
    }
    else if(digitalRead(reset)==HIGH){
    resetar();
  }
    for(int i=0;i<vetor2.size();i++){
      if(vetor2[i]!=vetor1[i]){
        perdeu();
      }
    }
   
  }
  delay(400);
}

void perdeu(){
  for(int i=0;i<4;i++){
    digitalWrite(leds[i],HIGH);
  }
  delay(2000);
  for(int i=0;i<4;i++){
    digitalWrite(leds[i],LOW);
  }
  delay(2000);
  resetar();

}