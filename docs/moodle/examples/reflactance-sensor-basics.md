```c++
/* Einlesen des analog-Signals des QTR-1A */ int sensor = 0;
void setup() {
Serial.begin(9600); }
void loop() {
sensor = analogRead(A0); LOG(sensor); delay(200);
}
```