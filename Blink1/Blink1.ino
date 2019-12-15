/*
  Blink   modified for Lily-pad  
  My board identifies as a Lily-pad Arduino USB 
  
  
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int leda = 10;
int ledb = 9;
int led13 = 13;


#define delay1   50

// LED's on lily-pad are on pins 2,3,9,10,11,13  

int ledarray [3] ; 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
   ledarray[0] = 13;
  ledarray[1] = 9;
   ledarray[2] = 10; 
   
   
  pinMode(leda, OUTPUT);  

  pinMode(ledb, OUTPUT);   
  pinMode(led13, OUTPUT);   
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(leda, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledb, LOW);   // turn the LED on (HIGH is the voltage level)
  
    digitalWrite(led13, LOW);   // turn the LED on (HIGH is the voltage level)
    
  delay(delay1);               // wait for a second
  
  
  digitalWrite(leda, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledb, HIGH);    // turn the LED off by making the voltage LOW
  
    digitalWrite(led13, HIGH);   // turn the LED on (HIGH is the voltage level)
    
  delay(delay1 * 5);               // wait for a second
}
