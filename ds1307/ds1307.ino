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

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  pinMode(SQW_INPUT_PIN, INPUT_PULLUP);
  pinMode(SQW_OUTPUT_PIN, OUTPUT);
  digitalWrite(SQW_OUTPUT_PIN, digitalRead(SQW_INPUT_PIN));


  rtc.begin(); // Call rtc.begin() to initialize the library
  // (Optional) Sets the SQW output to a 1Hz square wave.
  // (Pull-up resistor is required to use the SQW pin.)
  rtc.writeSQW(SQW_SQUARE_1);

  // Now set the time...
  // You can use the autoTime() function to set the RTC's clock and
  // date to the compiliers predefined time. (It'll be a few seconds
  // behind, but close!)
  rtc.autoTime();
  // Or you can use the rtc.setTime(s, m, h, day, date, month, year)
  // function to explicitly set the time:
  // e.g. 7:32:16 | Monday October 31, 2016:
  //rtc.setTime(16, 24, 20, 3, 1, 5, 18);  // Uncomment to manually set time
  // rtc.set12Hour(); // Use rtc.set12Hour to set to 12-hour mode
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
  Serial.print(String(rtc.hour()) + ":"); // Print hour
  if (rtc.minute() < 10) Serial.print('0'); // Print leading '0' for minute
  Serial.print(String(rtc.minute()) + ":"); // Print minute
  if (rtc.second() < 10) Serial.print('0'); // Print leading '0' for second
  Serial.print(String(rtc.second())); // Print second

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
  Serial.print(String(rtc.date()) + "/" + String(rtc.month()) + "/"); // Print month
  Serial.println(String(rtc.year()));        // Print year
}
