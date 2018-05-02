/**********************************************************************************
**                                                                               **
**                              CatSkills                                        **
**                                                                               **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <SparkFunDS1307RTC.h>
#include <Wire.h>

//********** Variables LCD ********************************************************
const int rs = 12;
const int rw = 11; 
const int enable = 10;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2) A la placa les d són L, p.e. d4 es L4
LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7); 

//********** Variables EEPROM *****************************************************
int addr = 0;
int val = 0;     //Per escriure o llegir un byte de la EEPROM
float valF = 0;  //Per escriure o llegir un float de la EEPROM

//********** Variables DS1307 *****************************************************
const int SQW_INPUT_PIN = 6;  // Input pin to read SQW
const int SQW_OUTPUT_PIN = 13; // LED to indicate SQW's state
// Alerta **A4 és SDA** i **A5 és SCL** no és poden fer servir quan utiitzem I2C
byte lastSecond = -1;
// Set to 13:37:42 (1:37:42 PM)
byte hour = 13;
byte minute = 37;
byte second = 42;
// Set to Monday October 31, 2016:
byte day = 2; // Sunday=1, Monday=2, ..., Saturday=7.
byte date = 31; 
byte month = 10;
byte year = 16;
// Read the time:
byte s;
byte m;
byte h;
// Read the day/date:
byte dy;
byte da;
byte mo;
byte yr;

//********** Variables ************************************************************


//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16,2);
  
  pinMode(SQW_INPUT_PIN, INPUT_PULLUP);
  pinMode(SQW_OUTPUT_PIN, OUTPUT);
  rtc.begin(); 
  rtc.writeSQW(SQW_SQUARE_1); 
  //rtc.autoTime(); 
  //rtc.setTime(second, minute, hour, day, date, month, year);
}

//********** Loop *****************************************************************
void loop()
{
  //readTime();
}

//********** Funcions *************************************************************
void readTime()
{
  rtc.update();
  s = rtc.second();
  m = rtc.minute();
  h = rtc.hour();  
  dy = rtc.day();
  da = rtc.date();
  mo = rtc.month();
  yr = rtc.year();
}
