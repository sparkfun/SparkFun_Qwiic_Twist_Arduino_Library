/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example sets the knob color to an endless number of random colors.
  
  Feel like supporting open source hardware?
  Buy a board from SparkFun! https://www.sparkfun.com/products/15083

  Hardware Connections:
  Plug a Qwiic cable into the Qwiic Twist and a BlackBoard
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 115200 baud to see the output
*/

#include "SparkFun_Qwiic_Twist_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_Twist
TWIST twist;                                      //Create instance of this object

void setup()
{
  Serial.begin(115200);
  Serial.println("Qwiic Twist Example");

  if (twist.begin() == false)
  {
    Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }
}

void loop()
{
  Serial.print("Count: ");
  Serial.print(twist.getCount());

  if (twist.isPressed())
    Serial.print(" Pressed!");

  //Pick three random numbers
  byte red = random(0, 256);
  byte green = random(0, 256);
  byte blue = random(0, 256);

  twist.setColor(red, green, blue); //Randomly set the Red, Green, and Blue LED brightnesses

  Serial.println();

  delay(100);
}
