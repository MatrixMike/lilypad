
/*
 read the readme.txt   file
2015-06-25  Mike  <mike@mike-OptiPlex-GX620>
25.06.2015 22:54:48
14.07.2015 09:11:30
* 
*/
#include "/home/mike/lilypad/leddefinitions.h"
#include <stdio.h>
// #include "mainsub.h"

//  #define number 19

int main() {
int cv;

// for (cv=-3;cv=+3;cv++); {
printf("length of array is %d\n", numLEDS);
for (cv=0;cv < numLEDS;cv=cv+1) {

	//printf("hi mike  %2d\n", cv);
//	printf(" from include file: number = %d\n", number);
//	printf("\n");
	printf(" %d", ledarray[cv] );
	
}
	return 0 ;
}


// int ledarray [] {2,3,9,10,11,13}; // 13 is onboard  {2,3,9,10,11,13}
// const int numLEDS =  6; // 4 ;
