#include <Servo.h>

Servo flipper;

const int buttonPin = 2;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
        while(!Serial); //redundent unless debugging and using an intel based arduino  (so the 101 or edison)
        // initialize the pushbutton pin as an input:
        pinMode(buttonPin, INPUT_PULLUP);
        // begining Serial for debugging
        Serial.begin(9600);
        flipper.attach(9);
}

void loop(){
        // read the state of the pushbutton value:
        buttonState = digitalRead(buttonPin);

        // check if the pushbutton is pressed.
        // if it is, the buttonState is HIGH:
        if (buttonState == LOW) {
                // make the servo go at a 90 degree angle
                flipper.write(90);
                Serial.println(flipper.read()); // debugging the location of the servo
        }
        else if(buttonState == HIGH && flipper.read() == 90){
                // iff the button is not being pressed we will keep writing it to 10 degree angle
                flipper.write(10);
                Serial.println(flipper.read());
        }

        Serial.println(digitalRead(buttonPin));
}
