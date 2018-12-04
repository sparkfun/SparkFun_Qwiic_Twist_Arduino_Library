/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to make the knob change color as the user turns the device.
  We don't have to send a setColor() or setRed() command each time, Qwiic Twist can
  change its color independently of the master.

  By connecting a -10 value to red, the red LED will go down 10 in brightness with 
  each encoder tick. Connecting 10 to blue will increase the blue value with each tick.
  These values are stored in the Qwiic Twist and will be loaded after each power-on.
  
  Feel like supporting open source hardware?
  Buy a board from SparkFun! https://www.sparkfun.com/products/15083

  Hardware Connections:
  Plug a Qwiic cable into the Qwiic Twist and a BlackBoard
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 9600 baud to see the output
*/

#include "SparkFun_Qwiic_Twist_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_Twist
TWIST twist; //Create instance of this object

void setup() {
  Serial.begin(9600);
  Serial.println("Qwiic Twist Example");

  if(twist.begin() == false)
  {
    Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }

  twist.setColor(255/2, 0, 255/2); //Set Red and Blue LED brightnesses to half of max.

  twist.connectRed(-10); //Red LED will go down 10 in brightness with each encoder tick
  twist.connectBlue(10); //Blue LED will go up 10 in brightness with each encoder tick
}

void loop() {
  Serial.print("Count: ");
  Serial.print(twist.getCount());

  if(twist.isPressed()) Serial.print(" Pressed!");

  Serial.println();

  delay(100);
}
