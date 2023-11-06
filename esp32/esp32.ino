#include "ADS1X15.h"

int16_t infra[4];

#define in1 9
#define in2 8
#define in3 11
#define in4 10
#define mot_l 5
#define mot_r 6

int x = 10000;

float vel_l = 0x80;
float vel_r = 0x69;

ADS1115 ADS(0x48);


void setup(void){
  
  Serial.begin(115200);
  


  ADS.begin();
  // Wait for connection
  
}

void loop(void){

  infra[0] = ADS.readADC(0);
  infra[1] = ADS.readADC(1);
  infra[2] = ADS.readADC(2);
  infra[3] = ADS.readADC(3);
  /*
  Serial.print(infra[0] );
  Serial.print("\t");
  Serial.print(infra[1] );
  Serial.print("\t");
  Serial.print(infra[2] );
  Serial.print("\t");
  Serial.print(infra[3] );
  Serial.println("\t");
  */



  if (infra[3] < x && infra[2] > x &&  infra[1] < x &&infra[0] < x  )
  {
    Serial.println("curva leve esquerda");
    andar(0.55, 0.75);
  }
  else if ( infra[3] < x && infra[2] < x && infra[1] > x && infra[0] < x )
  {
     Serial.println("curva leve direita");
    andar(0.75, 0.55);
  }
  else if ( infra[3] > x && infra[2] > x && infra[1] < x && infra[0] < x)
  {
     Serial.println("curva esquerda");
    andar(0.35, 0.8);
  }
  else if ( infra[3] < x && infra[2] < x && infra[1] > x && infra[0] > x)
  {
     Serial.println("curva direita");
    andar(0.8 , 0.35);
  }
  else if (infra[3] < x && infra[2] < x && infra[1] < x && infra[0] < x )
  {
    Serial.println("reto");
    andar(0.8, 0.8);
  }

  
}

void andar(float velo1, float velo2)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(mot_l, vel_l);
  analogWrite(mot_l, vel_l * velo1);
  analogWrite(mot_r, vel_r * velo2);
}

