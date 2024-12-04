/* Skin Electronics Exercise: Capacitive Sensor and NeoPixel
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


// Including Capacitive Sensor Library
#include <CapacitiveSensor.h>
// capacitive sensing constant
CapacitiveSensor sensor = CapacitiveSensor(10, 9);  // 1M resistor between pins 10 & 9, pin 9 is sensor pin


// Including Adafruit Neopixel Library
#include <Adafruit_NeoPixel.h>
// Which pin on the FLORA is connected to the NeoPixels?
#define PIN 8  // On Trinket or Gemma, suggest changing this to 1
// How many NeoPixels are attached to the FLORA?
#define NUMPIXELS 1  // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500  // Time (in milliseconds) to pause between pixels

/*
******************************************************************************
*/

void setup() {
  Serial.begin(115200);
  pixels.begin();  // INITIALIZE NeoPixel object (REQUIRED)
}

void loop() {
  long measurement = sensor.capacitiveSensor(30);

  Serial.println(measurement); // Check the Serial Monitor to see how the values changes when touching or not touching
  delay(10);

  if (measurement > 1100) { // This threshold will depend on your measured values
    pixels.clear();  // Set my pixel colors to 'off'
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.show();    // Send the updated pixel colors to the hardware.
    //delay(DELAYVAL);  // Pause before next pass through loop
  }else{
  pixels.clear();  // Set my pixel colors to 'off'
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // r,g,b in 0 means black - off
  pixels.show();    // Send the updated pixel colors to the hardware.
  }
}
