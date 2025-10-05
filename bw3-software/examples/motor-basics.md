```c++
int GPIO_PIN = 10; int val = 128;
void setup() {
// Ihr Code }
void loop() {
// Beispielhaft hier der GPIO10
analogWrite(GPIO_PIN, val); // Der Motor läuft nun mit theoretisch der halben Geschwindigkeit.
}
```