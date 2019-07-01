/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to set the max encoder value. For example,
  setting the limit to 359 will not allow the encoder read values to
  go above 359, looping back to zero instead. Useful when the encoder
  value is mapped directly onto a volume setting, FM freq, etc.

  This feature is available on Qwiic Twist firmware v1.2 and above.

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

  int currentVersion = twist.getVersion();

  if (currentVersion < 0x0201) //v1.2 in two byte form
  {
    Serial.print("The current firmware version is: ");
    Serial.print(currentVersion & 0xFF);
    Serial.print(".");
    Serial.println(currentVersion >> 8);

    Serial.println("This feature is not supported. Please consider upgrading the firmware on your Qwiic Twist. Freezing.");
    while (1); //Freeze
  }

  twist.setLimit(40); //Set max encoder to 40. It will loop to zero after 11 ticks.
  //twist.setLimit(0); //Disable this feature

  int currentLimit = twist.getLimit();
  Serial.print("The current limit is: ");
  Serial.println(currentLimit);
}

void loop() {
  Serial.print("Count: ");
  Serial.print(twist.getCount());

  Serial.print(" Difference: ");
  Serial.print(twist.getDiff());

  Serial.println();

  delay(250);
}
