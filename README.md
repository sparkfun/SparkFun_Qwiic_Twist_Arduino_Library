SparkFun Qwiic Twist Arduino Library
===========================================================

![SparkFun Qwiic Twist](https://cdn.sparkfun.com//assets/parts/1/3/4/3/3/Qwiic_Twist_Hookup_Guide.jpg)

[*SparkFun Qwiic Twist (DEV-15083)*](https://www.sparkfun.com/products/15083)

Sometimes you just need a volume knob. The Qwiic Twist is a digital RGB encoder. What does that mean? The Twist takes care of all the various interrupts, switches, PWM'ing of LEDs and presents all those features over an easy-to-use I<sup>2</sup>C interface. The Qwiic Twist was designed to get rid of the large mass of wires that are needed to implement an RGB encoder in a breadboard. Stop messing around with interrupt debugging and get back to your project!

One rotation in the clockwise direction increases the overall count by 24 and -24 in the counter clockwise direction. The number of 'ticks' or steps the user has turned the knob are transmitted over I2C. Additionally, the red, green, and blue LEDs are all set via software commands and can be digitally mixed to achieve over 16 million colors. 

We designed Qwiic Twist with an indent encoder which gives the user a great 'clicky' feel. Additionally, the encoder has a built in button so the user can select an GUI menu or element by pressing on the encoder.

The I2C address of Qwiic Twist is software configurable which means you can hookup over 100 on a single I2C bus!

Repository Contents
-------------------

* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE. 
* **/src** - Source files for the library (.cpp, .h).
* **keywords.txt** - Keywords from this library that will be highlighted in the Arduino IDE. 
* **library.properties** - General library properties for the Arduino package manager. 

Documentation
--------------
* **[Qwiic Twist Hookup Guide](https://learn.sparkfun.com/tutorials/qwiic-twist-hookup-guide)** - Hookup guide for the Qwiic Twist
* **[Installing an Arduino Library Guide](https://learn.sparkfun.com/tutorials/installing-an-arduino-library)** - Basic information on how to install an Arduino library.
* **[Product Repository](https://github.com/sparkfun/Qwiic_Twist)** - Main repository (including hardware files)

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Please use, reuse, and modify these files as you see fit. Please maintain attribution to SparkFun Electronics and release any derivative under the same license.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.
