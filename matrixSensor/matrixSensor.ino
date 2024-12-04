/*
Code for reading a Matrix Preassure Sensor fabricated with conductive copper tape and velostat for the Skil Electronics Class 2023-2024, 2025.
Adapted using a FLORA by Roger Pibernat & Citlali Hernández from Axolot.cat
The circuit: 
2x2 Matrix using Copper Tape and Velostat (it could be bigger, depending on the number of pins available in your microcontroller PCB).
Each Analog Input + 220 Ohms Resistor // The resistor depends on the resistivity of the sensor
*/

#define numRows 2  // Number of columns in your sensor
#define numCols 2 // Number of columns in your sensor
#define sensorPoints numRows* numCols // Number of points in the matrix sensor

int rows[] = { A7, A11 }; // An array of Analog pins
int cols[] = { 9,10 };  // An array of Digital Pins
int incomingValues[sensorPoints] = {}; // An array to store  the values of each point in the matrix

void setup() {

 for (int i = 0; i < numRows; i++) { pinMode(rows[i], INPUT); }   
  for (int i = 0; i < numCols; i++) { pinMode(cols[i], OUTPUT); }  
  Serial.begin(9600); 
  
}
void loop() {
  for (int colCount = 0; colCount < numCols; colCount++)  {
    digitalWrite(cols[colCount], HIGH);  // 5V
    for (int rowCount = 0; rowCount < numRows; rowCount++) {
      incomingValues[colCount * numRows + rowCount] = analogRead(rows[rowCount]);  // read INPUT
    }                                                                              // end row Count

    digitalWrite(cols[colCount], LOW);  // set back to LOW 0V (-)
  }                                     // end colCount

  // Print the incoming values of the grid:
  for (int i = 0; i < sensorPoints; i++) {
    Serial.print(incomingValues[i]); // Prints the value of the sensor stored in the array "incomingValues"
    if (i < sensorPoints - 1)
      Serial.print("\t"); // \t means "tab", which will create a space between de values
  }
  delay(10);
}
