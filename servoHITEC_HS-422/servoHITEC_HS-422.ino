/**********************************************************************************
**                                                                               **
**                             USB-PIC'SCHOOL                                    **
**                           Servo HITEC HS-422                                  **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************
#include <Servo.h>

//********** Variables HITEC HS-422 ***********************************************
Servo myservo;  // create servo object to control a servo
int pos = 0;

//********** Variables ************************************************************
const int P1 = A0; 
int valP1 = 0;

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  pinMode(P1, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

//********** Loop *****************************************************************
void loop()
{
  valP1 = analogRead(P1);            // reads the value of the potentiometer (value between 0 and 1023)
  pos = map(valP1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(pos);                  // sets the servo position according to the scaled value
  delay(15); 
}

//********** Funcions *************************************************************

