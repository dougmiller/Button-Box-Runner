
// LED output mappings
int greenLED = 0;
int redLED = 1;

// Pin input mappings
const int redButton1 = 5;
const int redButton2 = 3;
const int blackButton1 = 4;
const int blackButton2 = 6;
const int safetyToggle = 2;

// Button states
int buttonStateR1 = HIGH;
int lastButtonStateR1 = HIGH;

int buttonStateR2 = HIGH;
int lastButtonStateR2 = HIGH;

int buttonStateB1 = HIGH;
int lastButtonStateB1 = HIGH;

int buttonStateB2 = HIGH;
int lastButtonStateB2 = HIGH;

// Serial reading
String inputString = "";
boolean stringComplete = false;

boolean processing = false;

// Helper functions
void turnOn(int pin) {
    digitalWrite(pin, HIGH);
}

void turnOff(int pin) {
    digitalWrite(pin, LOW);
}

void cycleLED(int led, int time){
    turnOn(led);
    delay(time);
    turnOff(led);
    delay(time);
}

void startFlash() {
    cycleLED(greenLED, 50);
    cycleLED(redLED, 50);
    cycleLED(greenLED, 50);
    cycleLED(redLED, 50);
}

void successFlash() {
    cycleLED(greenLED, 50);
    cycleLED(greenLED, 50);
}

void failureFlash() {
    cycleLED(redLED, 50);
    cycleLED(redLED, 50);
}

void setup() {
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);

    // INPUT_PULLUP sets input buttons when unconnected to high
    // this means that the 'pressed' state outputs low
    pinMode(redButton1, INPUT_PULLUP);
    pinMode(redButton2, INPUT_PULLUP);
    pinMode(blackButton1, INPUT_PULLUP);
    pinMode(blackButton2, INPUT_PULLUP);
    pinMode(safetyToggle, INPUT_PULLUP);

    Serial.begin(9600);
    startFlash();
}

void loop() {
    if (digitalRead(safetyToggle) == LOW) { // 'safety' toggle
        // Button Red 1
        buttonStateR1 = digitalRead(redButton1);

        if (buttonStateR1 != lastButtonStateR1) {
            if (buttonStateR1 == LOW) {
                Serial.println("R1");
                startFlash();
            }
        }
        lastButtonStateR1 = buttonStateR1;


        // Button Red 2
        buttonStateR2 = digitalRead(redButton2);

        if (buttonStateR2 != lastButtonStateR2) {
            if (buttonStateR2 == LOW) {
                Serial.println("R2");               
                startFlash();
            }
        }
        lastButtonStateR2 = buttonStateR2;

        // Button Black 1
        buttonStateB1 = digitalRead(blackButton1);

        if (buttonStateB1 != lastButtonStateB1) {
            if (buttonStateB1 == LOW) {
                Serial.println("B1");
                startFlash();
            }
        }
        lastButtonStateB1 = buttonStateB1;

        //Button Black 2
        buttonStateB2 = digitalRead(blackButton2);

        if (buttonStateB2 != lastButtonStateB2) {
            if (buttonStateB2 == LOW) {
                Serial.println("B2");
                startFlash();
            }
        }
        lastButtonStateB2 = buttonStateB2;
    }

    if (stringComplete) {
        boolean processing = false;
        if (inputString.equals("OK\n")) {
            successFlash();
        } 
        else {
            failureFlash();
        };

        inputString = "";
        stringComplete = false;
    }
    
    while (Serial.available()) { // serialEvent not supported on current hardware
        processing = false;
        char inChar = (char)Serial.read();
        inputString += inChar;
        if (inChar == '\n') {
            stringComplete = true;
        }
    }
}

