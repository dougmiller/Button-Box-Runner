int greenLED = 0;
int redLED = 1;

const int redButton1 = 5;
const int redButton2 = 3;
const int blackButton1 = 4;
const int blackButton2 = 6;
const int safetyToggle = 2;

const int buttonPins[] = {2,3,4,5,6};

int buttonState = HIGH;
int lastButtonState = HIGH;

void turnOn(int pin) {
    digitalWrite(pin, HIGH);
}

void turnOff(int pin) {
    digitalWrite(pin, LOW);
}

void startFlash() {
    turnOn(greenLED);
    turnOn(redLED);
    delay(50);
    turnOff(greenLED);
    turnOff(redLED);
    delay(50);
    turnOn(greenLED);
    turnOn(redLED);
    delay(50);
    turnOff(greenLED);
    turnOff(redLED);
}

void successFlash() {
    turnOn(greenLED);
    delay(50);
    turnOff(greenLED);
    delay(50);
    turnOn(greenLED);
    delay(50);
    turnOff(greenLED);
}

void failureFlash() {
    turnOn(redLED);
    delay(50);
    turnOff(redLED);
    delay(50);
    turnOn(redLED);
    delay(50);
    turnOff(redLED);
}

void setup() {
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    
    pinMode(redButton1, INPUT_PULLUP);
    pinMode(redButton2, INPUT_PULLUP);
    pinMode(blackButton1, INPUT_PULLUP);
    pinMode(blackButton2, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(redButton1);
    
    if (buttonState != lastButtonState) {
        if (buttonState == LOW) {
            startFlash();
        }
    }
    lastButtonState = buttonState;
}

