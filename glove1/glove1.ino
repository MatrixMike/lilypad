
/* working test code for 8 LEDs controlled from an array
   good for test ing your understanding of arrays and generating patterns
   for LED light painting activities
   April 7 2017

   glove1 on 14-Aug-2015
   17-aug-2015
   */
 #define delaybase 6
// explain what delaybase is for

// glove use pins 13,3,9,10,11
int ledCount = 6;
int ledPins[] = { 13, 3,9,10, 11,13 };
#define ledDelay 200

void setup() {  // maybe add a serial connection here to avoid the hangs
  // actually fixed the reloading refusal by double clicking on reset switch before uploading
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
}

void loop() {
pattern1();
pattern1a();
pattern2();
pattern3();
//pattern4();   // looks odd - unbalanced
//pattern5();
}


void pattern1() {
  for(int lp=0; lp<delaybase; lp++){
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(ledPins[thisLed], HIGH);
    delay(ledDelay);
    digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
void pattern1a() {
  for(int lp=0; lp<delaybase; lp++){
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(ledPins[ledCount-thisLed], HIGH);
    delay(ledDelay);
    digitalWrite(ledPins[ledCount-thisLed], LOW);
    }
  }
}
void pattern2() {
  for(int lp=0; lp<delaybase; lp++){
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(ledPins[thisLed], HIGH);
    delay(ledDelay/3);
    digitalWrite(ledPins[thisLed], LOW);
  }
  }
}  
 
 void pattern3() {
  for(int lp=0; lp<10; lp++){
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(ledPins[thisLed], HIGH);   // all high
    }
    
    delay(ledDelay*2);                      // wait

    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(ledPins[thisLed], LOW);    // now all low
    }
    delay(ledDelay*2);                      // wait

  }
}   
 void pattern4() {
  for(int lp=0; lp<10; lp++){
    for (int thisLed = 0; thisLed <= ledCount; thisLed=thisLed+2) {  // sort of alternate LED 
    digitalWrite(ledPins[thisLed], HIGH);   // all high
    }
    
    delay(ledDelay*2);                      // wait
    
    for (int thisLed = 0; thisLed < ledCount; thisLed=thisLed+1) {
    digitalWrite(ledPins[thisLed], HIGH);   // all high
    }
    for (int thisLed = 0; thisLed < ledCount; thisLed=thisLed+2) {
    digitalWrite(ledPins[thisLed], LOW);    // now all low
    }
    delay(ledDelay*2);                      // wait

  }
}  

 void pattern5() {
  for(int lp=0; lp<10; lp++){
    for (int thisLed = 1; thisLed <= ledCount; thisLed=thisLed+2) {  // sort of alternate LED 
    digitalWrite(ledPins[thisLed], HIGH);   // all high
    }
    
    delay(ledDelay*2);                      // wait
    
    for (int thisLed = 0; thisLed < ledCount; thisLed=thisLed+1) {
    digitalWrite(ledPins[thisLed], HIGH);   // all high
    }
    for (int thisLed = 0; thisLed < ledCount; thisLed=thisLed+2) {
    digitalWrite(ledPins[thisLed], LOW);    // now all low
    }
    delay(ledDelay*2);                      // wait

  }
} 
