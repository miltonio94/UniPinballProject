#include <FastLED.h> // Library FastLED got from http://fastled.io/ - used for controlling neopixels

#define PIX_PIN 9
#define NUM_PIX 25

CRGB leds[NUM_PIX];  // array object that is used by the FastLED library to manipulate the neopixels
uint8_t hue = 0;  // Variable for controlling the hue of the light

void setup() {
        while(!Serial);
        // Initializing the FastLED object
        FastLED.addLeds<NEOPIXEL, PIX_PIN>(leds, NUM_PIX);
         Serial.begin();
}

void loop() {

        FastLED.showColor(CHSV(hue, 255, 128));  // pased values are hue, saturation and value (or brightness)
        delay(250);
        hue += 3; // Adding three to the hue value
}
