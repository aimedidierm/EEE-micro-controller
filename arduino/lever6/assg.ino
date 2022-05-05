#include <Wire.h>
#include <Keypad.h>
#include <Servo.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

int Button = 6;
int lamp = 5;

const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', '*'},
  {'7', '8', '9', '-'},
  {'*', '0', '#', '+'}
};
char keypressed;
char code[] = {'1', '2', '3', '4'};

char check1[sizeof(code)];
char check2[sizeof(code)];

short a = 0, i = 0, s = 0, j = 0;

byte rowPins[numRows] = {A0, A1, A2, A3};
byte colPins[numCols] = {2, 3, 4, 5};
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
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
  pinMode(Button, INPUT);
  pinMode(lamp, OUTPUT);
  myservo.attach(11);
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

  if (digitalRead(Button) == HIGH) {
    myservo.write(0);
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
}
