int led = 13;
int sensor = 5;
int var;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  var = analogRead(sensor);
  var = map(var,0,1025,-100,-60);
  if((var <= 82)||(var >=78)){
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
    }
}
