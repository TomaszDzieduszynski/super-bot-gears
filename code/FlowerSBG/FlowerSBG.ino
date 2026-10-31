#include <Servo.h>
Servo myservox;
Servo myservoy;
int x=180;
int y=180;
void setup() {


    Serial.begin(9600);
myservox.attach(9);
myservoy.attach(10);
}

void loop() {


if(analogRead(A1)>analogRead(A2)&&abs(analogRead(A1)-analogRead(A2))>20){

  x=x+1;
}
else if(analogRead(A1)<analogRead(A2)&&abs(analogRead(A1)-analogRead(A2))>20){
  x=x-1;
}
else{
  x=x;
  delay(100);
}

if(analogRead(A3)>analogRead(A4)&&abs(analogRead(A3)-analogRead(A4))>20){
  y=y+1;
}
else if(analogRead(A3)<analogRead(A4)&&abs(analogRead(A3)-analogRead(A4))>20){
  y=y-1;
}
else{
  y=y;
  delay(100);
}


if(x<0){
  x=0;
}
if(x>180){
  x=180;
}
if(y<0){
  y=0;
}
if(y>180){
  y=180;
}
Serial.println(180-x);
Serial.println(y);
Serial.println();
Serial.println(analogRead(A1));
Serial.println(analogRead(A2));
Serial.println(analogRead(A3));
Serial.println(analogRead(A4));
Serial.println();
myservox.write(180-x);
myservoy.write(y);
delay(25);
}
