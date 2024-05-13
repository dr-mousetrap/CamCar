#include <NewPing.h>


char Char;
boolean newData = false;
const int PingPin = 3;


NewPing sonar(PingPin, PingPin, 70);

void setup() {
  
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
}

void loop() {
  recvOneChar();
  showNewData();
}

void recvOneChar() {
  if (Serial.available() > 0) {
    Char = Serial.read();
    newData = true;
 }
}

void showNewData() {
  if (newData == true) {

    if(Char == '1') //Ultrasonic sensor
    {
      Serial.print("took");
      delay(50);
      Serial.println(sonar.ping_cm());
    } 

    if(Char == '2')
    {
      
    }

    newData = false;
 }
}
