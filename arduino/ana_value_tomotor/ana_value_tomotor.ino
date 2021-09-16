int moteri = 9;      
int analogPin = A2;   
int val = 0;         
int out = 0;

void setup() {
  Serial.begin(9600);
  pinMode(moteri, OUTPUT);
}

void loop() {
  val = analogRead(analogPin);
  
  out = map(val,0,1023,0,255);
  Serial.println(out);
  analogWrite(moteri, out);
}
