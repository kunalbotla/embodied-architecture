void setup() {
  pinMode(13, OUTPUT);    // sets the digital pin 13 as output
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);  // sets the pin ouputs
}

void loop() {
  digitalWrite(13, HIGH); // A on
  delay(900);             // 
  digitalWrite(12, HIGH); // B on
  delay(100);             // 
  digitalWrite(13, LOW);  // A off
  delay(900);             // 
  digitalWrite(11, HIGH); // C on
  delay(100);             // 
  digitalWrite(12, LOW);  // B off
  delay(900);             //
  digitalWrite(10, HIGH); // D on
  delay(100);             // 
  digitalWrite(11, LOW);  // C off
  delay(900);             //
  digitalWrite(9, HIGH);  // E on
  delay(100);             // 
  digitalWrite(10, LOW);  // D off
}
