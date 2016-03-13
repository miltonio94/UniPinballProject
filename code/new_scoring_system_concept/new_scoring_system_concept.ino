#include <FastLED.h> // Library FastLED got from http://fastled.io/ - used for controlling neopixels

#define PIX_PIN 6
#define NUM_PIX 82

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

int mill = -1;
int currMilis = 0;

CRGB leds[NUM_PIX];  // array object that is used by the FastLED library to manipulate the neopixels
uint8_t hue = 0;  // Variable for controlling the hue of the light

void setup() {
  //        while(!Serial);
  // Initializing the FastLED object
  FastLED.addLeds<NEOPIXEL, PIX_PIN>(leds, NUM_PIX);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  currMilis = millis();
  buttonState = digitalRead(buttonPin);
  FastLED.showColor(CHSV(hue, 255, 128));  // pased values are hue, saturation and value (or brightness)
  if (buttonState == LOW && currMilis < mill + 500) {
    // make the servo go at a 90 degree angle

    mill = currMilis;
    hue++;
  }

}
