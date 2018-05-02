/**********************************************************************************
**                                                                               **
**                             USB-PIC'SCHOOL                                    **
**                            Temperature TC74                                   **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <Wire.h>

//********** Variables TC74 *******************************************************
int temperatura1;
int address1 = B10010000;  //binary address of sensor 1

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  Wire.begin();     // create a wire object
}

//********** Loop *****************************************************************
void loop()
{
  temperatura1 = readTemp(address1);
}

//********** Funcions *************************************************************
int readTemp(int address)
{  
  Wire.beginTransmission(address); 
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(address, 1);
  while(Wire.available() == 0);
  int c = Wire.read();   
  return c;
}
