/**********************************************************************************
**                                                                               **
**                             USB-PIC'SCHOOL                                    **
**                            Entrades Digitals                                  **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int E[8]={3,4,5,6,7,8,9,10};
const int S[8]={11,12,13,A0,A1,A2,A3,A4};

int valE[8];       

//********** Setup ****************************************************************
void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(E[i], INPUT);
    pinMode(S[i], OUTPUT);
  }
  Serial.begin(9600);
}

//********** Loop *****************************************************************
void loop()
{
  for (int i = 0; i < 8; i++)
  {
    valE[i] = digitalRead(E[i]);
    Serial.print(valE[i]);
    digitalWrite(S[i], valE[i]);
  }
  Serial.println();
  delay(500);
}

//********** Funcions *************************************************************