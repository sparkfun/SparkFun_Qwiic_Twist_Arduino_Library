/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to set the encoder count. There are times when it's necessary
  encoder count to a specific value. Useful when the encoder value is mapped directly
  onto a volume setting, FM freq, etc.

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

  if (twist.begin() == false)
  {
    Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
    while (1);
  }

  twist.setCount(1000); //Set initial value to 1000. Not stored to non-volatile memory.
}

void loop() {
  Serial.print("Count: ");
  Serial.print(twist.getCount());

  Serial.print(" Difference: ");
  Serial.print(twist.getDiff());

  Serial.println();

  delay(250);
}
