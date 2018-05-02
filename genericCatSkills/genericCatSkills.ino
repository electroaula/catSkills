/**********************************************************************************
**                                                                               **
**                              CatSkills                                        **
**                                                                               **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <LiquidCrystal.h>
#include <EEPROM.h>

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

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

//********** Loop *****************************************************************
void loop()
{

}

//********** Funcions *************************************************************
