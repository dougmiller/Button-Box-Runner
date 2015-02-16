int greenLED = 0;
int redLED = 1;

const int redButton1 = 5;
const int redButton2 = 3;
const int blackButton1 = 4;
const int blackButton2 = 6;
const int safetyToggle = 2;

const int pins[] = {2,3,4,5,6};

int buttonState = HIGH;
int lastButtonState = HIGH;

void setup() {
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);

    pinMode(redButton1, INPUT_PULLUP);
    pinMode(redButton2, INPUT_PULLUP);
    pinMode(blackButton1, INPUT_PULLUP);
    pinMode(blackButton2, INPUT_PULLUP);
    pinMode(safetyToggle, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(redButton1);
    
    if (buttonState != lastButtonState) {
         if (buttonState == LOW) {
           Serial.println("redButton1");
           digitalWrite(greenLED, HIGH);
           digitalWrite(redLED, HIGH);
           delay(50);
           digitalWrite(greenLED, LOW);
           digitalWrite(redLED, LOW);
           delay(50);
           digitalWrite(greenLED, HIGH);
           digitalWrite(redLED, HIGH);
           delay(50);
           digitalWrite(greenLED, LOW);
           digitalWrite(redLED, LOW);
       }
    }
    lastButtonState = buttonState;
}

