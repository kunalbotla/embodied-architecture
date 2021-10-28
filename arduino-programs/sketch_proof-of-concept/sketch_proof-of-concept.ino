void setup() {
  pinMode(12, OUTPUT);  // sets the digital pin 13 as output
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);  // sets the pin ouputs
}

void loop() {
  digitalWrite(12, HIGH); // A on
  delay(400);            // 
  digitalWrite(12, LOW);  // A off
  digitalWrite(11, HIGH); // B on
  delay(1000);            // 
  digitalWrite(11, LOW);  // B off
  digitalWrite(10, HIGH); // C on
  delay(900);            // 
  digitalWrite(10, LOW);  // C off
  digitalWrite(9, HIGH); // D on
  delay(600);            //
  digitalWrite(9, LOW);  // D off
  delay(400);            // 
  digitalWrite(8, HIGH);  // E on
  delay(200);            // 
  digitalWrite(8, LOW);   // E off
}
