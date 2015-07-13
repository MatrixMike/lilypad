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
 */

// Pin 13 has an LED connected on most Arduino boards. Not always RED but often found on the PCB
// give it a name   e.g. a colour:
// int leda = 10;
//int ledb = 9;
//int led13 = 13;

#define serialDebug 0
#define delay1   50

// leds on lilypad USB are on pins 2,3,9,10,11,13  i.e. these are the output pins 
// which of these can do PWM? 

int ledarray [] {2,3,9,10,11,13}; // 13 is onboard  {2,3,9,10,11,13}
const int numLEDS =  6; // 4 ;

void ledFlash (int whichLED, int numTimes, int delayv) {
  for (int n=0;n<numTimes;n++){
    digitalWrite(whichLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(delayv);
    digitalWrite(whichLED, LOW);   // turn the LED on (HIGH is the voltage level) 
    //   digitalWrite(led13, LOW);   // turn the LED on (HIGH is the voltage level)

    delay(delayv);               // wait for a second
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
  static int lp = 0; // 600;
  static int delayvalue  = 20;
   for (int lp=0;lp< 6; lp++){
  ledFlash (ledarray[lp % numLEDS], 4, delayvalue);

 // lp++;
  if (delayvalue >= 600 )  {
    delayvalue=0; 
  }

    }
  //  delayvalue= delayvalue + 5;      // slow the blinking down over time
  if (serialDebug) {
    Serial.print("delayvalue=: ");
    Serial.println(delayvalue);
  }
}







