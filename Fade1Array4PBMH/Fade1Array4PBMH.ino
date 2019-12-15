// 11:53 / 12 Jun 2015  
// 12:19
// 13 jun 2015 @ 11:55
// original simple code by Arduino team
// the extra parts here were written by Michael Hewitt around 12 July 2015
// added const and tidied next-LED routine 
/*
 Fade
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 */

int firstloop = 1;    // use for an initial LED test
int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int ledarray [] {9,10,11,2,3,13}; // 13 is on-board
const int numLEDS =  6; // 4 ;

// mod to 4 LEDS which covers both the lily-pad and the RGB LED
// #define numLEDS 4   // also size of array and therefore modulus base
#define serialDebug 0
int l  ;    // exp with 9 and get no error : diff between value and index

/* int nextLED(int i    ) {
 return ( i % 3);  // m = i % 3;
 }
 */

int nextLED( int led, int numberOfLEDS  ) {  // returns next in modulus cycle 
  return ( led % numberOfLEDS);  // m = i % 3;
}
// the setup routine runs once when you press reset:
void setup()  { 
  if (serialDebug) {
    Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
  }
 // ledarray[0] = 2;
//
 // ledarray[2] = 9; 
 // ledarray[3] = 10; 
  // declare pin 9 to be an output:
  for (int s=0; s<numLEDS; s++) {
    pinMode(ledarray[s], OUTPUT);
  }
} 
void loop()  { 

  analogWrite(ledarray[l % numLEDS], brightness);    // this effect - all three together same 
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade: 
  // if (brightness <= 0) {fadeAmount = +fadeAmount;   l++; l = nextLED( l  , numLEDS   ) ; }// next LED but wrap around }
  // if (brightness >= 0) {fadeAmount = -fadeAmount;   l++; l = nextLED( l  , numLEDS   ) ; }// next LED but wrap around }

  if (brightness <= 0 || brightness >= 255) {  //  equality changed to < > 
    fadeAmount = -fadeAmount ; // reverse fade Up>Down>Up  etc

    l = nextLED( l  , numLEDS   ) ; // next LED but wrap around 
    l++;
  } 
  if (serialDebug) {  
    Serial.print("l: ");
    Serial.println(l );
  }
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);         
  //}  
}









