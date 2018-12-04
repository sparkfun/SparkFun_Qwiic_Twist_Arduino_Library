/*
  Read and interact with the SparkFun Qwiic Twist digital RGB encoder
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 3rd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to change the I2C address of the Qwiic Twist.
  Valid addresses are 0x08 to 0x77 - 111 possible addresses!
  Device's I2C address is stored to memory and loaded on each power-on

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

  byte oldAddress = 0x3F; //The current address of the Twist you want to change. 0x3F is default.
  byte newAddress = 0x45; //Address you want to change to. Valid is 0x08 to 0x77.

  while (Serial.available()) Serial.read(); //Trash any incoming chars
  Serial.print("Press a key to change address to 0x");
  Serial.println(newAddress, HEX);
  while (Serial.available() == false) ; //Wait for user to send character

  //Begin communication with Twist at current address
  if (twist.begin(Wire, oldAddress) == true)
  {
    Serial.print("Twist found at address 0x");
    Serial.println(oldAddress, HEX);

    twist.changeAddress(newAddress); //Change I2C address of this device to 0x56.
    //Valid addresses are 0x08 to 0x77 - 111 possible addresses!
    //Device's I2C address is stored to memory and loaded on each power-on

    delay(10); //Time required for Twist to record address to EEPROM and re-init its I2C

    if (twist.begin(Wire, newAddress) == true)
    {
      Serial.print("Address successfully changed to 0x");
      Serial.println(newAddress, HEX);
      Serial.print("Now load another example sketch using .begin(Wire, 0x");
      Serial.print(newAddress, HEX);
      Serial.println(") to use this Qwiic Twist");
      Serial.println("Freezing...");
      while (1);
    }
  }

  //Something went wrong, begin looking for the I2C device of the attached Twist
  Serial.println("Address change failed. Beginning an I2C scan.");

  Wire.begin();
}

void loop() {
  
  byte address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
     byte error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000);           // wait 5 seconds for next scan
}
