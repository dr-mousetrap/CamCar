char Char;
boolean newData = false;

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
    Serial.print("This just in ... ");
    Serial.println(Char);

    if(Char == 1)
    {
      
    } 

    newData = false;
 }
}
