const int M1Speed = 9;
const int M1c1 = 4;
const int M1c2 = 5;
const int M2Speed = 10;
const int M2c1 = 6;
const int M2c2 = 7;


char Char;
boolean newData = false;
const int LED = 3;


void setup() {
  pinMode(M1Speed, OUTPUT);
  pinMode(M1c1, OUTPUT);
  pinMode(M1c2, OUTPUT);
  pinMode(M2Speed, OUTPUT);
  pinMode(M2c1, OUTPUT);
  pinMode(M2c2, OUTPUT);

  digitalWrite(M1c1, LOW);
  digitalWrite(M1c2, LOW);
  digitalWrite(M2c1, LOW);
  digitalWrite(M2c2, LOW);

  analogWrite(M1Speed, 0);
  analogWrite(M2Speed, 0);
  
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
    

    if(Char == '0') //Ultrasonic sensor
    {
      Serial.println(Char);
    }
    
    else if(Char == '1') // Forward (slow)
    {
      Serial.println(Char);
    } 

    else if(Char == '2') // Forward (fast)
    {
      Serial.println(Char);
    }

    else if(Char == '3') // Turn Left
    {
      Serial.println(Char);
    }

    else if(Char == '4') // Turn Right
    {
      Serial.println(Char);
    }

    else if(Char == '5') // Reverse
    {
      Serial.println(Char);
    }

    else if(Char == '9') // Stop Moving
    {
      Serial.println(Char);
    }
    
    newData = false;
 }
}




