/**********************************************************************************
**                                                                               **
**                             USB-PIC'SCHOOL                                    **
**                          Entrades Analògiques                                 **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int P1 = A0;
const int S0 = 3; 
int valP1 = 0, valS0 = 0;
float voltage = 0;

//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  pinMode(P1, INPUT);
  pinMode(S0, OUTPUT);
}

//********** Loop *****************************************************************
void loop()
{
  valP1 = analogRead(P1);
  voltage = ((float)valP1 * 5.0) / 1023;   //convertir la lectura a voltatge
  valS0 = map(valP1, 0, 1023, 0, 255);     // mapejar valor de 0-1023 a 0-255
  analogWrite(S0, valS0);

  Serial.print("Valor del potenciometre P1 ");
  Serial.println(valP1);
  Serial.print("Valor en tensio del potenciometre P1 ");
  Serial.print(voltage);
  Serial.println("V");
  Serial.println();
  delay(500);
}

//********** Funcions *************************************************************
