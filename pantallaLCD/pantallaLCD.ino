/**********************************************************************************
**                                                                               **
**                             USB-PIC'SCHOOL                                    **
**                              Pantalla LCD                                     **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <LiquidCrystal.h>

//********** Variables ************************************************************
const int rs = 12;
const int rw = 11; 
const int enable = 10;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
const int P1 = A0;

int valP1 = 0;
float voltage = 0;     

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2) A la placa les d són L, p.e. d4 es L4
LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7); 

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  lcd.createChar(0, smiley);
  lcd.begin(16,2);

  pinMode(P1, INPUT);


  lcd.print("Hi, I'm USB-PIC");
  lcd.setCursor(5, 1);
  lcd.print("SCHOOL!");
 
  for (int i = 0; i < 2; i++)
  {
    lcd.noDisplay();
    delay(1000);
    lcd.display();
    delay(1000); 
  }
  
  lcd.cursor();
  delay(3000);
  lcd.noCursor();
  delay(1000);
  
  lcd.blink();
  delay(3000);
  lcd.noBlink();
  delay(1000);

  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.write(byte(0));
  delay(2000);

  lcd.clear();
  // set the cursor to (0,0): 
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // set the autoscroll left
  lcd.leftToRight();
  // set the cursor to (16,1):
  lcd.setCursor(16, 1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();
  // clear screen for the next loop:
 
  lcd.clear();
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 48; thisChar < 78; thisChar++) {
    lcd.print((char)thisChar);
    delay(500);
  }
}

//********** Loop *****************************************************************
void loop()
{
  valP1 = analogRead(P1);
  voltage = ((float)valP1 * 5.0) / 1023;   //convertir la lectura a voltatge

  lcd.clear();
  lcd.print(voltage);
  lcd.print("V");
  delay(400);
  for (int i = 0; i < 11; i++)
  {
    lcd.scrollDisplayRight();
    delay(400);
  }
  for (int i = 0; i < 11; i++)
  {
    lcd.scrollDisplayLeft();
    delay(400);
  }
    
  if (Serial.available())
  {
    lcd.clear();
    lcd.write(Serial.read());
    delay(2000);
  }
}

//********** Funcions *************************************************************
