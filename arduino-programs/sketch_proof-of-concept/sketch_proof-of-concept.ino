void setup() {
  pinMode(5, OUTPUT);  // sets the digital pin 13 as output
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT); // sets the pin ouputs
}

void loop() {
  digitalWrite(5, HIGH); // A on
  delay(random(150, 200));            // 
  digitalWrite(5, LOW);  // A off
  digitalWrite(4, HIGH); // B on
  delay(random(900, 300));            // 
  digitalWrite(4, LOW);  // B off
  digitalWrite(3, HIGH); // C on
  delay(random(800, 900));            // 
  digitalWrite(3, LOW);  // C off
  digitalWrite(2, HIGH); // D on
  delay(random(500, 600));            //
  digitalWrite(2, LOW);  // D off
  delay(random(300, 400));            //  

  digitalWrite(2, HIGH); // A on
  delay(random(150, 200));            // 
  digitalWrite(2, LOW);  // A off
  digitalWrite(3, HIGH); // B on
  delay(random(900, 300));            // 
  digitalWrite(3, LOW);  // B off
  digitalWrite(4, HIGH); // C on
  delay(random(800, 900));            // 
  digitalWrite(4, LOW);  // C off
  digitalWrite(5, HIGH); // D on
  delay(random(500, 600));            //
  digitalWrite(5, LOW);  // D off
  delay(random(300, 400));            // 
}
