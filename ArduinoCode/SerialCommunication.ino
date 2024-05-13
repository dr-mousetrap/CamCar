char Char;
boolean newData = false;
const int LED = 3;


void setup() {
  pinMode(LED, OUTPUT);
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

    if(Char == '1')
    {
      
    } 

    if(Char == '2')
    {
      
    }

    newData = false;
 }
}
