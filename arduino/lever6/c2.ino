#include <Wire.h>
#include <Keypad.h>
#include <Servo.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

int lamp = 0;

const byte numRows = 4;
const byte numCols = 3;

char keymap[numRows][numCols] =
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
char keypressed;
char code[] = {'1', '2', '3', '4'};

char check1[sizeof(code)];
char check2[sizeof(code)];

short a = 0, i = 0, s = 0, j = 0;

byte rowPins[numRows] = {2, 1, A4, A5};
byte colPins[numCols] = {3, 4, 5};
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
Servo myservo;
void setup()
{
  lcd.begin (16, 2);
  lcd.setCursor(0, 0);
  lcd.print("*ENTER THE CODE*");
  lcd.setCursor(1 , 1);

  lcd.print("TO _/_ (Door)!!");
  pinMode(lamp, OUTPUT);
  myservo.attach(A3);
  myservo.write(0);
}


void loop()
{

  keypressed = myKeypad.getKey();
  if (keypressed == '*') {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("*ENTER THE CODE*");
    ReadCode();
    if (a == sizeof(code))
      OpenDoor();
    else {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("CODE");
      lcd.setCursor(6, 0);
      lcd.print("INCORRECT");
      lcd.setCursor(15, 1);
      lcd.print(" ");
      lcd.setCursor(4, 1);
      lcd.print("GET AWAY!!!");
    }
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*ENTER THE CODE*");
    lcd.setCursor(1 , 1);

    lcd.print("TO _/_ (Door)!!");
  }

  if (keypressed == '#') {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*ENTER THE CODE*");
    lcd.setCursor(1 , 1);

    lcd.print("TO _/_ (Door)!!");
  }


}

void ReadCode() {
  i = 0;
  a = 0;
  j = 0;

  while (keypressed != 'A') {
    keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY && keypressed != 'A' ) {
      lcd.setCursor(j, 1);
      lcd.print("*");
      j++;
      if (keypressed == code[i] && i < sizeof(code)) {
        a++;
        i++;
      }
      else
        a--;
    }
  }
  keypressed = NO_KEY;

}

void OpenDoor() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Welcom IN");
  digitalWrite(lamp,HIGH);
  myservo.write(90);
  delay(3000);
  myservo.write(0);
}
