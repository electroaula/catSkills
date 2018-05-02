/**********************************************************************************
**                                                                               **
**                             USB-PIC'SCHOOL                                    **
**                                 DS1307                                        **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <SparkFunDS1307RTC.h>
#include <Wire.h>

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

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  pinMode(SQW_INPUT_PIN, INPUT_PULLUP);
  pinMode(SQW_OUTPUT_PIN, OUTPUT);
  digitalWrite(SQW_OUTPUT_PIN, digitalRead(SQW_INPUT_PIN));


  rtc.begin(); // Call rtc.begin() to initialize the library
  
  // (Optional) Sets the SQW output to a 1Hz square wave.(Pull-up resistor is required to use the SQW pin.)
  rtc.writeSQW(SQW_SQUARE_1); //SQW_SQUARE_1,SQW_SQUARE_4K,SQW_SQUARE_8K,SQW_SQUARE_32K,SQW_LOW,SQW_HIGH
  
  rtc.autoTime(); // You can use the autoTime() function to set the RTC
  //rtc.setTime(second, minute, hour, day, date, month, year); // Uncomment to manually set time
  
  // rtc.set12Hour(); // Use rtc.set12Hour to set to 12-hour mode
  // rtc.set24Hour();  //to switch back to 24-hour mode
}

//********** Loop *****************************************************************
void loop()
{
  // Call rtc.update() to update all rtc.seconds(), rtc.minutes(),
  // etc. return functions.
  rtc.update();

  if (rtc.second() != lastSecond) // If the second has changed
  {
    printTime(); // Print the new time
    
    lastSecond = rtc.second(); // Update lastSecond value
  }

  // Read the state of the SQW pin and show it on the
  // pin 13 LED. (It should blink at 1Hz.)
  digitalWrite(SQW_OUTPUT_PIN, digitalRead(SQW_INPUT_PIN));
}

//********** Funcions *************************************************************
void printTime()
{
  // Read the time:
  s = rtc.second();
  m = rtc.minute();
  h = rtc.hour();
  
  // Read the day/date:
  dy = rtc.day();
  da = rtc.date();
  mo = rtc.month();
  yr = rtc.year();
  
  Serial.print(String(h) + ":"); // Print hour
  if (m < 10) Serial.print('0'); // Print leading '0' for minute
  Serial.print(String(m) + ":"); // Print minute
  if (s < 10) Serial.print('0'); // Print leading '0' for second
  Serial.print(String(s)); // Print second

  if (rtc.is12Hour()) // If we're in 12-hour mode
  {
    // Use rtc.pm() to read the AM/PM state of the hour
    if (rtc.pm()) Serial.print(" PM"); // Returns true if PM
    else Serial.print(" AM");
  }
  
  Serial.print(" | ");

  // Few options for printing the day, pick one:
  Serial.print(rtc.dayStr()); // Print day string
  //Serial.print(rtc.dayC()); // Print day character
  //Serial.print(rtc.day()); // Print day integer (1-7, Sun-Sat)
  Serial.print(" - ");
  Serial.print(String(da) + "/" + String(mo) + "/"); // Print month
  Serial.println(String(yr));        // Print year
}
