
/* working test code for 8 LEDs controlled from an array
   good for test ing your understanding of arrays and generating patterns
   for LED light painting activities
   April 7 2017

   glove1 on 14-Aug-2015
   17-aug-2015
   19.08.2015 23:10:03      mod to add light sensor
   */
#define delaybase 6
// explain what delaybase is for

// glove use pins 13,3,9,10,11
int ledCount = 6;
int ledPins[] = { 13, 3, 9, 10, 11, 13 };

int   LsensorValue;
int   XsensorValue;
int   YsensorValue;
int   ZsensorValue;

const int lightPin = A2;                  // light sensor
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A4;// A2;            // y-axis
const int zpin = A5;  //A1;           // z-axis (only on 3-axis models)
#define ledDelay 100
#define debugging 0         // a logical => true for serial o/p 

void setup() {  // maybe add a serial connection here to avoid the hangs
  // actually fixed the reloading refusal by double clicking on reset switch before uploading
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
  if (debugging) {
    // initialize the serial communications:
    Serial.begin(9600);
  }
}

void loop() {
  // print the sensor values:
  LsensorValue = analogRead(lightPin);  // remove later
  XsensorValue = analogRead(xpin);      // remove later
  YsensorValue = analogRead(ypin);      // remove later
  ZsensorValue = analogRead(zpin);      // remove later
  if (debugging) {
    Serial.print(XsensorValue);
    //   XsensorValue = analogRead(xpin);   // remove later
    // print a tab between values:
    Serial.print("\t");
    Serial.print(YsensorValue);
    // Serial.print(analogRead(ypin));
    Serial.print("\t");
    Serial.print(ZsensorValue);
    //  Serial.print(analogRead(zpin));
    Serial.print("\t");
    Serial.print(LsensorValue);
    //  Serial.print(analogRead(zpin));
    Serial.println();
    // delay before next reading:
  }
  if (XsensorValue < 450) { // glove tips UP
    pattern6();
  }
  if (YsensorValue < 450) { // thumb UP
    pattern1a();
  }
  if (ZsensorValue < 450) { // palm UP
    pattern3();
  }
  if (LsensorValue < 10) { // darkness
    pattern7();
  }
  delay(100);
  //  pattern1a();
  //  pattern2();
  //  pattern3();
  //pattern4();   // looks odd - unbalanced
  //pattern5();
}


// need new patterns - like two middle fingers flashing    pins 3,9
// need new patterns - like two outer  fingers flashing


void pattern7() {   // middle two fingers
  for (int lp = 0; lp < delaybase; lp++) {
    for (int thisLed = 3; thisLed < ledCount; thisLed++) {
      digitalWrite(ledPins[thisLed], HIGH);
      delay(ledDelay);
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}




void pattern6() {
  for (int lp = 0; lp < delaybase; lp++) {
    for (int thisLed = 2; thisLed < 4; thisLed++) {
      digitalWrite(ledPins[thisLed], HIGH);
      delay(ledDelay);
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}



void pattern1() {
  for (int lp = 0; lp < delaybase; lp++) {
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
      digitalWrite(ledPins[thisLed], HIGH);
      delay(ledDelay);
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
void pattern1a() {
  for (int lp = 0; lp < delaybase; lp++) {
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
      digitalWrite(ledPins[ledCount - thisLed], HIGH);
      delay(ledDelay);
      digitalWrite(ledPins[ledCount - thisLed], LOW);
    }
  }
}
void pattern2() {
  for (int lp = 0; lp < delaybase; lp++) {
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
      digitalWrite(ledPins[thisLed], HIGH);
      delay(ledDelay / 3);
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}

void pattern3() {
  for (int lp = 0; lp < 10; lp++) {
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
      digitalWrite(ledPins[thisLed], HIGH);   // all high
    }

    delay(ledDelay * 2);                    // wait

    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
      digitalWrite(ledPins[thisLed], LOW);    // now all low
    }
    delay(ledDelay * 2);                    // wait

  }
}
void pattern4() {
  for (int lp = 0; lp < 10; lp++) {
    for (int thisLed = 0; thisLed <= ledCount; thisLed = thisLed + 2) { // sort of alternate LED
      digitalWrite(ledPins[thisLed], HIGH);   // all high
    }

    delay(ledDelay * 2);                    // wait

    for (int thisLed = 0; thisLed < ledCount; thisLed = thisLed + 1) {
      digitalWrite(ledPins[thisLed], HIGH);   // all high
    }
    for (int thisLed = 0; thisLed < ledCount; thisLed = thisLed + 2) {
      digitalWrite(ledPins[thisLed], LOW);    // now all low
    }
    delay(ledDelay * 2);                    // wait

  }
}

void pattern5() {
  for (int lp = 0; lp < 10; lp++) {
    for (int thisLed = 1; thisLed <= ledCount; thisLed = thisLed + 2) { // sort of alternate LED
      digitalWrite(ledPins[thisLed], HIGH);   // all high
    }

    delay(ledDelay * 2);                    // wait

    for (int thisLed = 0; thisLed < ledCount; thisLed = thisLed + 1) {
      digitalWrite(ledPins[thisLed], HIGH);   // all high
    }
    for (int thisLed = 0; thisLed < ledCount; thisLed = thisLed + 2) {
      digitalWrite(ledPins[thisLed], LOW);    // now all low
    }
    delay(ledDelay * 2);                    // wait

  }
}
