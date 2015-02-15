int greenLED = 0;
int redLED = 1;

void setup() {                
  pinMode(greenLED, OUTPUT);     
  pinMode(redLED, OUTPUT);     
}

void loop() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  delay(1000);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
  delay(1000);
}
