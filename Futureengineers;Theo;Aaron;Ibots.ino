#include <Servo.h>

Servo servoblau;

int GSM1 = 6;
int in1 = 9;
int in2 = 10;

void setup()
{
  pinMode(GSM1, OUTPUT);    
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  servoblau.attach(4); //gibt dem Servo den Pin 4.
  servoblau.write(95); //Setzt den Servo zurück.
}
void loop()
{
  digitalWrite(in1, LOW);  
  digitalWrite(in2, HIGH);

  analogWrite(GSM1, 80); //setzt die Geschwindigkeit des Motors auf 80 Umdrehungen (Max 255).

  delay(900); //Bestimmt die länge der zeit in der der Bot eine Kurve fahren soll.

  servoblau.write(95);

  delay(1750); //Bestimmt die länge der Zeit in der der Bot gerdeaus fahren soll.

  servoblau.write(130);
}