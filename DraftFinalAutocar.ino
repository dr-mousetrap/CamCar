#include <NewPing.h>
#include <FastLED.h>

//Pin Registry
const int PingPin = 8;
const int LedPin = 9; //pwm
const int In1 = 2;
const int In2 = 3;
const int In3 = 4;
const int In4 = 7;
const int ENA1 = 5;
const int ENA2 = 6;

//Const Variables
const int MaxDis = 50;
const int NUM_LEDS = 12;

//Other Variables
int Command;

//Library Setups
NewPing sonar(PingPin, PingPin, MaxDis);
CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(ENA2, OUTPUT);

  FastLED.addLeds<WS2812, LedPin, GRB>(leds, NUM_LEDS);

  Serial.begin(9600);

  ArdCommence();
  Serial.println("Begin");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Begin2");
  
  if (Command == 49){
    SonicSensor();
  }
 
}

void Gyro() {

}

void SonicSensor(){
  delay(50);
  Serial.println(sonar.ping_cm());
}

void MoveF(){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);

  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);

  delay(2000);

  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW); 
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW); 
}

void MoveL(){

}

void MoveR(){

}

void ErrorArd(){
  FastLED.setBrightness(0);
   for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
  }
  FastLED.setBrightness(100);
}

void ErrorRasp(){
  FastLED.setBrightness(0);
   for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB ( 255, 165, 0);
    FastLED.show();
  }
  FastLED.setBrightness(100);
}

void ErrorNI()/*No Instruction*/{
  Serial.println("ERROR");
  FastLED.setBrightness(0);
   for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB ( 255, 192, 203);
    FastLED.show();
  }
  FastLED.setBrightness(100);
}

void ArdCommence(){
  FastLED.setBrightness(0);
   for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB ( 0, 255, 0);
    FastLED.show();
  }
  FastLED.setBrightness(100);
}
