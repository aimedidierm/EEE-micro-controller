#define Buzzer_pin 13
#define speedometer_pin 5
int speed_reading;
int max_value=1023;
int min_value=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  speed_reading = analogRead(speedometer_pin);
  speed_reading = map(speed_reading, min_value, max_value,0,140);
  constrain(speed_reading,0,140);
  if(speed_reading>100){
    digitalWrite(Buzzer_pin,HIGH);
    delay(250);
    digitalWrite(Buzzer_pin,LOW);
    delay(250);
    }

}
