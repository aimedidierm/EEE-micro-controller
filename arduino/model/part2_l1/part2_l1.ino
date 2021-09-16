#define  LED_pin 9 
#define sensor_pin 0 
int sensor_data; 
int max_value=1023; 
int min_value=0;  
void setup()  {   
  pinMode(LED_pin, OUTPUT);    
  while (millis()<5000)   {     
    sensor_data=analogRead(sensor_pin);        
    if(sensor_data>max_value)     max_value=sensor_data;      
    if(sensor_data<min_value)     min_value=sensor_data;   
    } 
    }   
    void loop() {   
      sensor_data=analogRead(sensor_pin);   
      sensor_data=map(sensor_data, min_value, max_value, 0, 255);   
      sensor_data=constrain(sensor_data, 0, 255);   
      analogWrite(LED_pin, sensor_data); 
      } 
