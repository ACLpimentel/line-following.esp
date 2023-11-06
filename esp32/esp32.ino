#include <Adafruit_ADS1X15.h>
#include <Adafruit_I2CDevice.h>

Adafruit_ADS1115 ads;


float infra[4];

/*#define in1 9
#define in2 8
#define in3 11
#define in4 10
#define mot_l 5
#define mot_r 6
*/


float vel_l = 0x80;
float vel_r = 0x69;



void setup(void){
  
  Serial.beging(9600);

  pinMode(infra_1,INPUT);
  pinMode(infra_2,INPUT);
  pinMode(infra_3,INPUT);
  pinMode(infra_4,INPUT);

  if(!ads.begin())
  {
    Serial.println("Failed to initialize");
     while (1);
  }
  // Wait for connection
  
}

void loop(void){

  infra[0] = ads.readADC_SingleEnnded(0);
  infra[1] = ads.readADC_SingleEnnded(1);
  infra[2] = ads.readADC_SingleEnnded(2);
  infra[3] = ads.readADC_SingleEnnded(3);


  if (infra[3] == 0 && infra[2] == 1 &&  infra[1] == 0 &&infra[0] == 0  )
  {
    Serial.println("curva leve esquerda");
    andar(0.55, 0.75);
  }
  else if ( infra[3] == 0 && infra[2] == 0 && infra[1] == 1 && infra[0] == 0 )
  {
     Serial.println("curva leve direita");
    andar(0.75, 0.55);
  }
  else if ( infra[3] == 1 && infra[2] == 1 && infra[1] == 0 && infra[0] == 0)
  {
     Serial.println("curva esquerda");
    andar(0.35, 0.8);
  }
  else if ( infra[3] == 0 && infra[2] == 0 && infra[1] == 1 && infra[0] == 1)
  {
     Serial.println("curva direita");
    andar(0.8 , 0.35);
  }
  else if (infra[3] == 0 && infra[2] == 0 && infra[1] == 0 && infra[0] == 0 )
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

