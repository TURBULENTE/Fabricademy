/* Skin Electronics Exercise: Capacitive Sensor 
prepared by Citlali Hernández - 2024,
 based on code by Bare Conductive and  Paul Badger. Originally written by Pascal Loose
 This work is licensed under a MIT license https://opensource.org/licenses/MIT
 Copyright (c) 2020, Bare Conductive
 */

/*
Instructions:
You will need to install the Capacitive Library
https://www.arduino.cc/reference/en/libraries/capacitivesensor/
https://github.com/PaulStoffregen/CapacitiveSensor

Download the library and move it to the library folder of your Arduino folder.
Reopen Arduino and install the library (Sketch→Import Library)
Materials needed:
Skin Capacitive Sensor built in class 
1 M0Hm Resistor
Flora
*/


// capacitive sensing includes
#include <CapacitiveSensor.h>

// capacitive sensing constant
CapacitiveSensor sensor = CapacitiveSensor(10,9);  // 1M resistor between pins 10 & 9, pin 9 is sensor pin

void setup() {
  Serial.begin(115200);
}

void loop() {
  long measurement =  sensor.capacitiveSensor(30);
  
  Serial.println(measurement);
  delay(10);
}
