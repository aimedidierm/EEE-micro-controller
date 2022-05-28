#include<Keypad.h>
#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
int lamp = 12;
char keys[4][3]={
{‘1′,’2′,’3’},
{‘4′,’5′,’6’},
{‘7′,’8′,’9’},
{‘*’,’0′,’#’}};
byte rowPin[4]={6,7,8,9};
byte colPin[3]={3,4,5};
String password = “123”; // The Pin Code.
int position = 0;
int wrong = 0; // Variable to calculate the wrong inputs.
int redPin = 10;
int greenPin = 11;
Keypad keypad=Keypad(makeKeymap(keys),rowPin,colPin,4,3);
// MAPPING THE KEYPAD.
int total = 0; // Variable to determine the number of wrong attempts.
Servo myservo;
void setup()
{
myservo.attach(2);
myservo.write(0);
pinMode(lamp, OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
lcd.init(); //lcd startup
lcd.init();
lcd.backlight();
lcd.print(” welcome “);
lcd.setCursor(0,1);
lcd.print(“Smart Door Lock”);
delay(3000);
lcd.clear();
setLocked(true);
delay(20);
}


//On LCD message will be displayed that Enter your Password. Users have to enter the password through the keypad. If the input password does not match, LCD will display the message “Wrong Password “ to notify with 1 second of delay and remains in its lock position and again ask for a password.

void loop()
{
lcd.clear();
lcd.print(“Enter your Password”);
delay(100);
char pressed=keypad.getKey();
String key[3];
if(pressed)
{
lcd.clear();
lcd.print(“Enter your Password”);
lcd.setCursor(position,2);
lcd.print(pressed);
delay(500);
if(pressed == ‘*’ || pressed == ‘#’)
{
position = 0;
setLocked(true);
lcd.clear();
}
else if(pressed == password[position])
{
key[position]=pressed;
position++;
}
else if (pressed != password[position] )
{
wrong++;
position ++;
}
if(position == 3){
if( wrong >0)
{
total++;
wrong = 0;
position = 0;
lcd.clear();
lcd.setCursor(0,2);
lcd.print(” Incorrect Password!”);
delay(1000);
setLocked(true);
}
else if(position == 3 && wrong == 0)
{
position = 0;
wrong = 0;
lcd.clear();
lcd.setCursor(0,1);
lcd.print(” Welcome! “);
lcd.setCursor(5,2);
lcd.print(” Door Open”);
delay(2000);
setLocked(false);
}
if(total ==3)
{
total=0;
delay(500);
}
}
}
}
//If the entered password will be correct then the green LED will turn on and message will be displayed on LCD. If the entered password will be wrong then Red LED will remain on.

void setLocked(int locked)
{
if (locked)
{
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
delay(1000);
}
else
{
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
digitalWrite(lamp,HIGH);
myservo.write(90);
delay(2000);
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
myservo.write(0);
}
}
