#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define COLOR(r, g, b) (((uint32_t) r << 16) + ((uint32_t) g << 8) + b)

int neoPix = 8, // pin used for the neopixel
    numbPix = 9, // number of neopixels
    scoreButt = 4, // pin for the makeshift scoring
    lvl = 1,  // variable for keeping track of current level
    makeshiftScore,  // checking if button has been pressed
    scoreLocation = numbPix - 1; // variable kkeping track of where to put new colour in
    
const int buttonPin = 2; 
int buttonState = 0;

// Colours that I'll be using for each lvl
uint32_t lvl1Col = COLOR(255, 0, 0),
         lvl2Col = COLOR(0, 255, 0),
         lvl3Col = COLOR(0, 0, 255),
         blk = COLOR(0, 0, 0);
    

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numbPix, neoPix, NEO_GRB + NEO_KHZ800); // declaring neopixel
Servo flipper;

void setup() {
  //making the pin controlling the button an input
  pinMode(scoreButt, INPUT_PULLUP); 
  // beging the neopixels
  pixels.begin();
  // making sure the strip for the stress o' meter is red at the begining
  if(lvl == 1){
    for(int i = 0; i < numbPix; i++){
      pixels.setPixelColor(i,lvl1Col);
    }
    pixels.show();
  }

  pinMode(buttonPin, INPUT_PULLUP); 
  flipper.attach(9);
}

void loop() {
  //reading the the state of the button
  makeshiftScore = digitalRead(scoreButt);
  // if button has been pressed
  if (makeshiftScore == LOW) {    
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

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {     
     flipper.write(90);
  } 
  else if(buttonState == HIGH && flipper.read() == 90){
    flipper.write(10);
  }

}
