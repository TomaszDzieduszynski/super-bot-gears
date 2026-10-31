void setup() {

  pinMode(13, OUTPUT);
}


void loop() {
  digitalWrite(13, HIGH);
  delay(map(analogRead(A0),0,1023,0,15));
  digitalWrite(13, LOW);
  delay(map(analogRead(A0)+31,0,1023,15,0));

}
