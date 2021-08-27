/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how start the Twist library using a different wire port (ie, Wire1, etc).
  This is handy if you need to connect *a lot* of Twists and have multiple Wire ports on your dev platform.

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

  Wire1.begin(); //Compilation will fail here if your platform doesn't have multiple I2C ports

  if (twist.begin(Wire1) == false)
  {
    Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }

  Wire1.setClock(400000); //Optional
}

void loop()
{
  Serial.print("Count: ");
  Serial.print(twist.getCount());

  if (twist.isPressed())
    Serial.print(" Pressed!");

  Serial.println();

  delay(10);
}
