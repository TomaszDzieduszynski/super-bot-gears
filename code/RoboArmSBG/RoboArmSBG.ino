#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
int x=180;
int y=120;
int z=180;

void setup() {

    Serial.begin(9600);
    pinMode(2,INPUT_PULLUP);
myservo1.attach(9);
myservo2.attach(10);
myservo3.attach(11);
}

void loop() {

int dx=map((analogRead(A6)-512), -512, 512, -3, 4);
int dy=map((analogRead(A5)-512), -512, 512, -3, 4);

x=x+dx;
y=y+dy;


if(x<2){
  x=2;
}
if(x>178){
  x=178;
}
if(y<65){
  y=65;
}
if(y>150){
  y=150;
}

if (digitalRead(2)==LOW) {
  if(z==180){
    z=120;
  }
  else{
    z=180;
  }
  delay(150);
}


myservo1.write(x);
myservo2.write(y);
myservo3.write(z);
delay(50);
Serial.println();
Serial.println(x);
Serial.println(dx);
Serial.println(y);
Serial.println(dy);
Serial.println(z);
Serial.println(digitalRead(2));

}
