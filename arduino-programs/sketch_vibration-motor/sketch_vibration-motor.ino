// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

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
  
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop()
{
  Wire.beginTransmission(4);  // transmit to device #4
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();     // stop transmitting

  x++;
  delay(500);

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
