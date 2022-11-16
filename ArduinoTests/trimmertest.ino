/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int sensorPin = A4;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int shifter = 0;

int smartTrimmer();

void setup() {
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
}

void loop() {
  // read the value from the sensor:
  sensorValue=analogRead(sensorPin);
  smartTrimmer();
  Serial.print(sensorValue);
  Serial.print(" - ");
  Serial.print(shifter);
  Serial.print("\n");
  delay(500);
}

int smartTrimmer()
{
  if(shifter>=0 && shifter<=117)
  {
    switch(map(analogRead(sensorPin), 0, 1023, 1, 5))
    {
      case 1:
        if(shifter<3)
          shifter=0;
        else
          shifter-=3;
        break;
      case 2:
        if(shifter>0)
          shifter--;
        break;
      case 4:
        if (shifter<117)
        shifter++;
        break;
      case 5:
        if(shifter>114)
          shifter=117;
        else
          shifter+=3;
        break;
    }
  }
}
