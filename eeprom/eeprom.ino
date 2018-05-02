/**********************************************************************************
**                                                                               **
**                             USB-PIC'SCHOOL                                    **
**                                 EEPROM                                        **
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
const int P1 = A0;
//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2) A la placa les d són L, p.e. d4 es L4
LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7); 

//********** Variables ************************************************************
int valP1 = 0;
float voltage = 0, voltageRead = 0;   
int addr = 0;
int val = 20;

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(P1, INPUT);

  EEPROM.write(addr, val);
  addr = addr + 1;
  val = 68;
  EEPROM[addr] = val;
  addr = addr + 1;

  lcd.print(EEPROM.read(0));
  lcd.setCursor(0, 1);
  lcd.print((char)EEPROM[1]);
  delay(3000);
}

//********** Loop *****************************************************************
void loop()
{
  valP1 = analogRead(P1);
  voltage = ((float)valP1 * 5.0) / 1023;   //convertir la lectura a voltatge

  lcd.clear();
  lcd.print(voltage);
  lcd.print("V");
  delay(2000); 

  EEPROM.put(addr, voltage);
  lcd.clear();
  lcd.setCursor(0, 1);
  EEPROM.get(addr,voltageRead);
  lcd.print(voltageRead);
  lcd.print("V");
  addr += sizeof(float);
  
  EEPROM.put(addr, voltage+2);
  lcd.setCursor(0, 0);
  EEPROM.get(addr,voltageRead);
  lcd.print(voltageRead);
  lcd.print("V sumant 2V");
  addr += sizeof(float);
  delay(2000);
}

//********** Funcions *************************************************************
