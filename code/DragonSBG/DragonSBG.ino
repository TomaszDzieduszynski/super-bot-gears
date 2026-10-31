#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
int x=0;
int y=0;
int z=180;
int posx=0;
int posy=0;
int posz=0;
int z2=180;
int u=0;
int v=0;

void setup() {

    Serial.begin(9600);
    pinMode(A5,INPUT_PULLUP);
myservo1.attach(9);
myservo2.attach(10);
myservo3.attach(11);
}

void loop() {

u=map(analogRead(A0),0,1023,0,6);

if(z2<posz-3){
  z2=z2+u+1;
}
else if (z2>posz+3){
  z2=z2-u-1;
}
else{
  int ran=random(0,2);
  z=(map(ran,0,1,150,180));
  digitalWrite(13,!ran);
  posz=random(130,180);
}


if(x<posx-3){
  x=x+u;
}
else if (x>posx+3){
  x=x-u;
}
else{
  x=posx;
  posx=random(0,180);
}
myservo1.write(x);
myservo2.write(y);
myservo3.write(z);


delay(60);
Serial.println();
Serial.println(posx);
Serial.println(x);
Serial.println(posz);
Serial.println(z);

}
