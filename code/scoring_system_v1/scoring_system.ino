#include <Adafruit_NeoPixel.h>

#define COLOR(r, g, b) (((uint32_t) r << 16) + ((uint32_t) g << 8) + b)

int neoPix = 8, // pin used for the neopixel
numbPix = 9, // number of neopixels
scoreButt = 4, // pin for the makeshift scoring
lvl = 1,  // variable for keeping track of current level
buttonState,  // checking if button has been pressed
scoreLocation = numbPix - 1; // variable kkeping track of where to put new colour in

// Colours that I'll be using for each lvl
uint32_t lvl1Col = COLOR(255, 0, 0),
lvl2Col = COLOR(0, 255, 0),
lvl3Col = COLOR(0, 0, 255),
blk = COLOR(0, 0, 0);


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numbPix, neoPix, NEO_GRB + NEO_KHZ800); // declaring neopixel

void setup() {
        //making the pin controlling the button an input
        pinMode(scoreButt, INPUT);
        // beging the neopixels
        pixels.begin();
        // making sure the strip for the stress o' meter is red at the begining
        if(lvl == 1){
                for(int i = 0; i < numbPix; i++){
                        pixels.setPixelColor(i,lvl1Col);
                }
                pixels.show();
        }
}

void loop() {
        //reading the the state of the button
        buttonState = digitalRead(scoreButt);
        // if button has been pressed
        if (buttonState == LOW) {
                // switch to check the current lvl
                switch(lvl){
                        //in charge of drawing the new level with each score made
                        case 1:
                        pixels.setPixelColor(scoreLocation, lvl2Col);
                        scoreLocation -= 1;
                        break;

                        case 2:
                        pixels.setPixelColor(scoreLocation, lvl3Col);
                        scoreLocation -= 1;
                        break;

                        case 3:
                        pixels.setPixelColor(scoreLocation, blk);
                        scoreLocation -= 1;
                        break;
                }
        }
        // in charge of chaging the lvl
        if(scoreLocation == -1){
                lvl = (lvl + 1) % 4;
                scoreLocation = 8;
        }
        //making sure the pixs isn't too bright and making it show the changes
        pixels.setBrightness(50);
        pixels.show();
}
