# lilypad
# revisited Mon 14 Oct 2019 19:42:05 
# revisited Sun Dec 15 18:21:10 2019 
perform a spell check using  
<code>
aspell --mode=ccpp -c shiftReg1.ino
</code>
collection of example programs for Arduino Lilypad (USB) as 
inspired by WIE

Aim is to have a progression of files for training development.

Modification on 13 July 2015
really a git change test 
see Blink1Array4PBMH.ino for details

20.08.2015 13:11:37
added PWM but strange effects when using it in conjunction with ON/OFF

21.08.2015 10:55:14   Friday after Blackburn meeting

integration of Arduino and Git: thoughts:
git seems happy to work in one chosen directory with any subdirectories
 created

Arduino wants to create it's own directory 
e.g. to be tested : have an .ino file in git repo directory and open
 it in Arduino 
	saving it seems to create  directory elsewhere 
	
	
21.08.2015 14:25:15
remember to checkout File Preferences in Arduino IDE for sketchbook location
remember that if your Linux installation does not easily
 allow permissions for using the USB port, sudo arduino from command
line will provide a temporary fix. The Arduino 1.6.6 builds and thereabouts
do a good job of auto-detecting the Lilypad and setting the port for uploads.
====
the history files are included as reminders of CL activity at the time of building
====
soon to add git sync with SSH a.o.t. email & password



	

