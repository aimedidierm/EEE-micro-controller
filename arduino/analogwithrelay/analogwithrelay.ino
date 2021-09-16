int sensorPin = A2  ;   
int relay = 13;
int sensorValue = 0,value = 0;  

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  value=map(sensorValue,0,1025,0,5);
  Serial.println(value);
  if(value >= 2.5){
    digitalWrite(relay, HIGH);
    } else{
    digitalWrite(relay, LOW);
      }
}
