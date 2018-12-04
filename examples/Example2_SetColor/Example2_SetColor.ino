/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to set the knob color to purple. This value is stored in the 
  Qwiic Twist and will be loaded after each power-on.

  Also - the max I2C datarate for Qwiic Twist is 400kHz
  
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

  Wire.setClock(400000); //Optional: After Twist begin(), increase I2C speed to max, 400kHz

  //Set the knob color to purple
  twist.setColor(100, 10, 50); //Set the Red, Green, and Blue LED brightnesses

  //Set the know color to white
  //twist.setColor(255, 255, 255); //Set the Red, Green, and Blue LED brightnesses
}

void loop() {
  Serial.print("Count: ");
  Serial.print(twist.getCount());

  if(twist.isPressed()) Serial.print(" Pressed!");

  Serial.println();

  delay(10);
}
