#include <Servo.h>

Servo servoblau;

int GSM1 = 6;
int in1 = 9;
int in2 = 10;

int SENDEN1 = 2;
int ECHO1 = 3;
long Entfernung1 = 0;
int Differenz = 0; 

int SENDEN2 = 8;
int ECHO2 = 5;
long Entfernung2 = 0;
long Zeit = 0;
long Zeit2 = 0;

void setup()
{

  pinMode(SENDEN1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(SENDEN2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(GSM1, OUTPUT);    
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  servoblau.attach(4); //gibt dem Servo den Pin 4.
  servoblau.write(95); //Setzt den Servo zurück.
  Serial.begin(9600); //Sorgt dafür dass dei Sensorwerte angezeigt werden können
}
void loop()
{
  digitalWrite(SENDEN1, LOW);
  delay(5);

  // Signal für 10 Micrsekunden senden, danach wieder ausschalten
  digitalWrite(SENDEN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENDEN1, LOW);

  // pulseIn -> Zeit messen, bis das Signal zurückkommt
  long Zeit = pulseIn(ECHO1, HIGH);

  // Entfernung in cm berechnen
  // Zeit/2 -> nur eine Strecke
  Entfernung1 = (Zeit / 2) * 0.03432;
  delay(500);

  
  digitalWrite(SENDEN2, LOW);
  delay(5);

  // Signal für 10 Micrsekunden senden, danach wieder ausschalten
  digitalWrite(SENDEN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENDEN2, LOW);

  // pulseIn -> Zeit messen, bis das Signal zurückkommt
  Zeit = pulseIn(ECHO2, HIGH);

  // Entfernung in cm berechnen
  // Zeit/2 -> nur eine Strecke
  Entfernung2 = (Zeit2 / 2) * 0.03432;
  delay(500);

  Serial.print("Entfernung1 in cm: ");
  Serial.println(Entfernung1);

  Serial.print("Entfernung2 in cm: ");
  Serial.println(Entfernung2);
  
  Differenz = (Entfernung1 - Entfernung2);
  Serial.print(Differenz);

}
//digitalWrite(in1, LOW);  
  //digitalWrite(in2, HIGH);

  // analogWrite(GSM1, 100); //setzt die Geschwindigkeit des Motors auf 80 Umdrehungen (Max 255).

  // delay(900); //Bestimmt die länge der zeit in der der Bot eine Kurve fahren soll.

  // servoblau.write(95);

  // delay(1750); //Bestimmt die länge der Zeit in der der Bot gerdeaus fahren soll.

  // servoblau.write(130);
