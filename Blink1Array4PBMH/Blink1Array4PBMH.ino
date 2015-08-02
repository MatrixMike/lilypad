/*
  Blink   modified for Lilypad  
 My board identifies as a Lilypad Arduino USB 
 Modified 6th July 2015 Mike Hewitt - used for training purposes
 
 Turns on an LED on for one second, then off for one second, repeatedly.
 Time period controlled with delay1
 
 This example code is in the public domain.
 Mike 9-July-2015
 13-July-2015 fixed silly bug in loop() where 
 - lp was being incremented forever and delayvalue was being checked but never incremented/changed
 - so re-enabled the for loop and uploaded AND updated in git 
 14-July-2015 - prettier sequence
 20-July-2015 - fixed a modulus error added fancy loops
 */

// Pin 13 has an LED connected on most Arduino boards. Not always RED but often found on the PCB
// give it a name   e.g. a colour:
// int leda = 10;
//int ledb = 9;
//int led13 = 13;

#define serialDebug 0
#define debugDelayMult 1  // use 100
#define delay1   50
#include "/home/mike/lilypad/leddefinitions.h"
//  https://www.arduino.cc/en/Hacking/BuildProcess


// leds on lilypad USB are on pins 2,3,9,10,11,13  i.e. these are the output pins 
// which of these can do PWM? 


void ledFlash (int whichLED, int numTimes, int delayv) {
  for (int n=0;n<numTimes;n++){

    if (serialDebug) {
      Serial.print("whichLED=: ");
      Serial.println(whichLED);
    }

    digitalWrite(whichLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(delayv*debugDelayMult);
    digitalWrite(whichLED, LOW);   // turn the LED on (HIGH is the voltage level) 
    //   digitalWrite(led13, LOW);   // turn the LED on (HIGH is the voltage level)

    delay(delayv*debugDelayMult);               // wait for a second
  }
}
void allOn () {   // turn all LEDs on
  for (int n=0;n<numLEDS;n++){
    digitalWrite(ledarray[n], HIGH);   // turn the LED on (HIGH is the voltage level)
  }
}
void allOff () {   // turn all LEDs on
  for (int n=0;n<numLEDS;n++){
    digitalWrite(ledarray[n], LOW);   // turn the LED on (HIGH is the voltage level)
  }
}
void setup()  { 
  if (serialDebug) {
    Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
  }
  // ledarray[0] = 9;
  // ledarray[1] = 10;
  //ledarray[2] = 2; 
  // ledarray[3] = 3; 
  // ledarray[4] = 13; 
  // declare pin 9 to be an output:
  for (int s=0; s<numLEDS; s++) {
    pinMode(ledarray[s], OUTPUT);
  }
} 

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("loop() starting ");
  static int lp = 0; // 600;
  static int delayvalue  = 20;

  for (int lp1=0;lp1<4; lp1++){

    for (int lp=0;lp< numLEDS; lp++){
      ledFlash (ledarray[lp], 4, delayvalue);
      // lp++;
      if (delayvalue >= 600 )  {
        delayvalue=0; 
      }
    }

    //  delay(1000); 
    // allOn();    
    // delay(1000);
    // allOff ();
    //delay(1000);


    for (int lp=numLEDS;lp>=0; lp--){
      ledFlash (ledarray[lp], 4, delayvalue);  // lp % numLEDS at ends of range
      // lp++;
      if (delayvalue >= 600 )  {
        delayvalue=0; 
      }
    }
  }
  for (int lp=numLEDS;lp>0; lp--){
    delay(1000); 
    allOn();    
    delay(1000);
    allOff ();
  }

  /*  for (int s=6;s>0; s--){
   for (int lp=s;lp> 0; lp--){
   ledFlash (ledarray[lp % numLEDS], 4, delayvalue);
   if (delayvalue >= 600 )  {
   delayvalue=0; 
   }   
   allOn();    
   delay(1000);  
   } 
   }  
   */
  //  delayvalue= delayvalue + 5;      // slow the blinking down over time
  if (serialDebug) {
    Serial.print("delayvalue=: ");
    Serial.println(delayvalue);
  }
}
























