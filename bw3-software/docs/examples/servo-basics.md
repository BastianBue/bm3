```c++
/*
Project: SG90 Servo am ESP32
Author: GT
Date: Created 04.09.2022
Version: V1.0
*/
#include <ESP32Servo.h>
Servo myservo; //Servo Objekt erstellen
const int servoPin = 19; // GPIO Pin 19 für den Servomotor
int val;
void setup()
{
 myservo.setPeriodHertz(50); // Perioden-Dauer einstellen
 myservo.attach(servoPin); //
 Serial.begin(9600);
}
void loop()
{
 if (Serial.available() > 0)
 {
 val = Serial.parseInt(); // Zahlenwert als Int einlesen
 LOG(val);
 val = map(val,0,4096, 0, 180); // Abbilden des Wertes „val“ aus dem Bereich 0 – 4096 auf 0 - 180
 myservo.write(val); // “val” an den servo ausgeben.
 delay(500);
 }
}
```