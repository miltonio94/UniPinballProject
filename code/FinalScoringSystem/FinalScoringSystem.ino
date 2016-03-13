#import <FastLED>

#define PIX_PIN 9
#define NUM_PIX 25

#include <Servo.h>

Servo flipper;

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

CRGB leds[NUM_PIX];  // array object that is used by the FastLED library to manipulate the neopixels
uint8_t hue = 0;  // Variable for controlling the hue of the light

int piezo0 = 0;
int piezo1 = 0;
int piezo2 = 0;
int piezo3 = 0;
int threshHold4 = 500;
int val = 0;

void setup() {
        FastLED.addLeds<NEOPIXEL, PIX_PIN>(leds, NUM_PIX);
         // initialize the pushbutton pin as an input:
         pinMode(buttonPin, INPUT_PULLUP);
         // begining Serial for debugging
         Serial.begin(9600);
         flipper.attach(9);
}

void loop() {
        sensePiezo(piezo0);
        sensePiezo(piezo1);
        sensePiezo(piezo2);
        sensePiezo(piezo3);
        FastLED.showColor(CHSV(hue, 255, 128));  // pased values are hue, saturation and value (or brightness)
        flip();
}

void sensePiezo(anlogNum){
        val = analogRead(anlogNum);

        if(val > threshHold){
                Serial.println(val);
                statePin = !statePin;
                digitalWrite(led, statePin);
                hue++;
        }
}

void flip(){
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
}
