const int LED =  13;
int ledState = LOW; 
long previousMillis = 0;
long interval = 1000;
void setup() {
  // set the digital pin as output:
  pinMode(LED, OUTPUT);      
}

void loop()
{
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;   
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(LED, ledState);
  }
}
