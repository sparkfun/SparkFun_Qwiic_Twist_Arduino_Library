/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to enable the button and twist interrupts. Once an interrupt is read, it is cleared
  by the library. For this example you will need to connect the INT pin on Qwiic to pin 4 on the Arduino.

  The interrupt will not fire until 250ms after the user has stopped turning the encoder. This is so the master
  is not overwhelmed with interrupts while the user is still turning the dial.

  The timeout is configurable via setIntTimeout() and is stored in NVM.

  Feel like supporting open source hardware?
  Buy a board from SparkFun! https://www.sparkfun.com/products/15083

  Hardware Connections:
  Plug a Qwiic cable into the Qwiic Twist and a BlackBoard
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 115200 baud to see the output
*/

#include "SparkFun_Qwiic_Twist_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_Twist
TWIST twist;                                      //Create instance of this object

const byte twistInterruptPin = 4; //Can be any GPIO

void setup()
{
  Serial.begin(115200);
  Serial.println("Qwiic Twist Example");

  pinMode(twistInterruptPin, INPUT_PULLUP);

  if (twist.begin() == false)
  {
    Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
    while (1)
      ;
  }

  //Optional: You can modify the time between when the user has stopped turning and when interrupt is raised
  //twist.setIntTimeout(500); //Set twist timeout to 500ms before interrupt assertion
}

void loop()
{
  if (digitalRead(twistInterruptPin) == LOW)
  {
    Serial.print("Interrupt: ");

    if (twist.isMoved())
    {
      Serial.print("Count:");
      Serial.print(twist.getCount());
    }

    if (twist.isPressed())
    {
      Serial.print("Pressed");
    }

    if (twist.isClicked())
    {
      Serial.print("Clicked!");
    }

    Serial.println();

    twist.clearInterrupts(); //Clear any interrupt bits
  }
}
