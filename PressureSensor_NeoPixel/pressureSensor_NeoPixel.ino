/*
Example for Fabricademy Class - Skin Electronics 2024
Materials Needed:
FLORA
Skin electronics custo preassure sensor
Resistor
Cocodrile Clamps
Velostat
*/

// Including Adafruit Neopixel Library
#include <Adafruit_NeoPixel.h>
// Which pin on the FLORA is connected to the NeoPixels?
#define PIN 8  // On Trinket or Gemma, suggest changing this to 1
// How many NeoPixels are attached to the FLORA?
#define NUMPIXELS 1  // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500  // Time (in milliseconds) to pause between pixels


int sensorPin= A10;
  int sensorValue;
  int valMap;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
    pixels.begin();  // INITIALIZE NeoPixel object (REQUIRED)

}
// the loop routine runs over and over again forever:
void loop() {
 sensorValue = analogRead(sensorPin);
 valMap=map(sensorValue, 50, 400, 0, 255);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);  // delay in between reads for stability
    pixels.clear();  // Set my pixel colors to 'off'
    pixels.setPixelColor(0, pixels.Color(0, valMap, 0));
    pixels.show();    // Send the updated pixel colors to the hardware.
  }

