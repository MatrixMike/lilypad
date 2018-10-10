// leddefinitions.h
// 14 July -2015
//  #include "/home/mike/lilypad/leddefinitions.h"

int ledarray [] = {6,7,8,9,10,11,12,13}; // 13 is onboard  {2,3,9,10,11,13}
const int numLEDS =  8; // 4 ;
//int ledarray [] = {2,3,4,5,6,7,8,9,10,11,12,13};
// note about = above => arduino IDE enjoys with or without
// gcc needs the = 
// check what is really happening Mike

//const int numLEDS =  12; // 4 ;
// 19.07.2015 21:59:18

// change ASAP for PB hat with 10 leds

/*
 * Arduino IDE uses this file to define the size and order of IO pins in an array
 * the above values are for Lilypads. Below is a set of values for a standard UNO with a 
 * 10 LED strip attached. Connected  pins are 6 through to 13 ( i.e. 8 pins)
 * 20.07.2015 15:24:56
 * name: unknown
 * @param
 * @return
 * 
 */
//
//int ledarray [] = {13,6,7,8,9,10,11,12,13};
// const int numLEDS =  9; // 4 ;
 // 20.07.2015 22:52:52
 // if both ends are made to be the same then a loop can be created 
 
