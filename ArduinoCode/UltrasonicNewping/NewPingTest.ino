#include <NewPing.h>

int arrivingdatabyte;  
#define PingPin  12 
#define MAX_DISTANCE 50 
NewPing sonar(PingPin, PingPin, MAX_DISTANCE);

void setup( )  
{  
  Serial.begin(9600);  

}  
void loop( )  
{  
if(Serial.available( ) > 0)  
{  
  arrivingdatabyte = Serial.read( );  // It will read the incoming or arriving data byte  

  if (arrivingdatabyte == 49){
    Serial.print("cm = ");
    Serial.println(sonar.ping_cm());
  }

  if (arrivingdatabyte == 50){
    
  }

}  
}  
