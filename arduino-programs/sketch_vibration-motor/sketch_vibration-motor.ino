// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{

  pinMode(13, OUTPUT);  // sets the digital pin 13 as output
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);  // sets the pin ouputs
  
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

byte x = 0;

void loop()
{
  digitalWrite(13, HIGH); // A on
  delay(1000);            // 
  digitalWrite(13, LOW);  // A off
  digitalWrite(12, HIGH); // B on
  delay(1000);            // 
  digitalWrite(12, LOW);  // B off
  digitalWrite(11, HIGH); // C on
  delay(1000);            // 
  digitalWrite(11, LOW);  // C off
  digitalWrite(10, HIGH); // D on
  delay(1000);            //
  digitalWrite(10, LOW);  // D off
  delay(1000);            // 
  digitalWrite(9, HIGH);  // E on
  delay(1000);            // 
  digitalWrite(9, LOW);   // E off
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    float beatsPerMinute = Wire.read();    // receive byte as an integer
    Serial.println(beatsPerMinute);         // print the integer
  }
  
}
