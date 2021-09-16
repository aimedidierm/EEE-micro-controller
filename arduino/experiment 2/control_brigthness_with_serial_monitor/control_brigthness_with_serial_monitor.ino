int LED_PIN = 8;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  //analogWrite(pin, value); 
  //pin: 3, 5, 6, 9, 10, 11
  //value: 0 (always off) - 255 (always on)
  analogWrite(LED_PIN, 127); // middle value
  Serial.println("Control LED brightness by Serial monitor");
  Serial.println("Send 0 or 9 to control LED brightness");
}

void loop() {
  if (Serial.available() > 0) {
    char led_brightness = Serial.read();

    Serial.print("You send: ");
    Serial.print(led_brightness);
    Serial.println();

    switch(led_brightness) {
      case '0':
        analogWrite(LED_PIN, 0);
        break;
      case '1':
        analogWrite(LED_PIN, 100);       
        break;
      case '2':
        analogWrite(LED_PIN, 150);       
        break;
      case '3':
        analogWrite(LED_PIN, 200);       
        break;
      case '4':
        analogWrite(LED_PIN, 250);       
        break;
      case '5':
        analogWrite(LED_PIN, 300);       
        break;
      case '6':
        analogWrite(LED_PIN, 350);       
        break;
      case '7':
        analogWrite(LED_PIN, 400);       
        break;
      case '8':
        analogWrite(LED_PIN, 450);       
        break;
      case '9':
        analogWrite(LED_PIN, 500);       
        break;
    }
  }
}
