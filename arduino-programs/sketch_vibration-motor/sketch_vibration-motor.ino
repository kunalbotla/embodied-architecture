// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>


#include "MAX30105.h"

#include "heartRate.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;


void setup()
{
  pinMode(13, OUTPUT);  // sets the digital pin 13 as output
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);  // sets the pin ouputs

  Serial.begin(115200);
  Serial.println("Initializing...");

  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");

  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED

  Wire.begin(1); // join i2c bus (address optional for master)
  
}


void loop()
{
  heartrate();
  digitalWrite(13, HIGH); // A on
  heartrate();
  delay(1000);            // 
  heartrate();
  digitalWrite(13, LOW);  // A off
  heartrate();
  digitalWrite(12, HIGH); // B on
  heartrate();
  delay(1000);            // 
  heartrate();
  digitalWrite(12, LOW);  // B off
  heartrate();
  digitalWrite(11, HIGH); // C on
  heartrate();
  delay(1000);            // 
  heartrate();
  digitalWrite(11, LOW);  // C off
  heartrate();
  digitalWrite(10, HIGH); // D on
  heartrate();
  delay(1000);            //
  heartrate();
  digitalWrite(10, LOW);  // D off
  heartrate();
  delay(1000);            // 
  heartrate();
  digitalWrite(9, HIGH);  // E on
  heartrate();
  delay(1000);            // 
  heartrate();
  digitalWrite(9, LOW);   // E off
  heartrate();
}

void heartrate() {
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }

  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);

  if (irValue < 50000)
    Serial.print(" No finger?");

  Serial.println();
}
