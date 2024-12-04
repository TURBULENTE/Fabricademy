/*
Skin Electronics class - 2024
Citlali Hernández

Potentiometer
Materials:
Velostat
3 Cocodrile Clamps
FLORA

*/

int potentiometer=A9;
int value;

void setup() {
  // put your setup code here, to run once:
pinMode(potentiometer, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(potentiometer);
Serial.println(value);
}
