void setup() {
  // put your setup code here, to run once:
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
  digitalWrite(0,HIGH);
  delay(120000);
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  delay(6000);
  digitalWrite(1,LOW);
  digitalWrite(5,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  delay(120000);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(6000);
  digitalWrite(4,LOW);
  digitalWrite(2,LOW);
}
