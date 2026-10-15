/*
This version of the code runs the motor based on keyboard input: 
g - giraffe
s - snake
b - beatle
r - reset
*/

#include <Servo.h>

Servo base;
Servo vertical1; 
Servo vertical2;
Servo mouth;

char letter = 'a';


// Modified version of slowrite that prints all values trough wich servos span to pin point where the problem is
void SlowWrite (Servo S,int angle, int speed){
  int start = S.read();
  if(start <= angle){
    for(int a = start; a <= angle; a += 1 ){
      S.write(a);             
      Serial.print(a);
      Serial.print(" ");
      delay(speed);   
    }
    Serial.println("");
  }else{
    for(int a = start; a >= angle; a -= 1 ){
      S.write(a);              // tell servo to go to position in variable 'pos'
      Serial.print(a);
      Serial.print(" ");
      delay(speed);
    }
    Serial.println("");
    delay(50);
  }  
}

void setup() {
  base.attach(9);  // attaches the servo on pin 9 to the servo object
  vertical1.attach(10);  // attaches the servo on pin 10 to the servo object
  vertical2.attach(11);  // attaches the servo on pin 11 to the servo object
  mouth.attach(12);  // attaches the servo on pin 12 to the servo object
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    letter = Serial.read();
    if(letter == 'g'){
      SlowWrite(base, 100, 20);
      delay(50);
      SlowWrite(vertical1, 80, 20);
      delay(50);
      SlowWrite(vertical2, 180, 20);
      delay(50);
      SlowWrite(mouth, 100, 20);
      delay(50);
      Serial.print(base.read());
      Serial.print("\t");
      Serial.print(vertical1.read());
      Serial.print("\t");
      Serial.print(vertical2.read());
      Serial.print("\t");
      Serial.print(mouth.read());
      Serial.print("\t");

      // Use these to check if there is a problem with SlowWrite function
      // base.write(152);   
      // vertical1.write(80);   
      // vertical2.write(180);   
      // mouth.write(100);   
    } 
    if(letter == 's'){
        SlowWrite(base, 50, 20);
        SlowWrite(vertical1, 150, 20);
        SlowWrite(vertical2, 180, 20);
        SlowWrite(mouth, 80, 20);
        Serial.print(base.read());
        Serial.print("\t");
        Serial.print(vertical1.read());
        Serial.print("\t");
        Serial.print(vertical2.read());
        Serial.print("\t");
        Serial.print(mouth.read());
        Serial.print("\t");

        // Use these to check if there is a problem with SlowWrite function
        // base.write(152)   ;
        // vertical1.write(180);   
        // vertical2.write(180);   
        // mouth.write(80);   
      }
    if(letter == 'b'){
      SlowWrite(base, 150, 20);
      SlowWrite(vertical1, 0, 20);
      SlowWrite(vertical2, 140, 20);
      SlowWrite(mouth, 60, 20);
      Serial.print(base.read());
      Serial.print("\t");
      Serial.print(vertical1.read());
      Serial.print("\t");
      Serial.print(vertical2.read());
      Serial.print("\t");
      Serial.print(mouth.read());
      Serial.print("\t");

      // Use these to check if there is a problem with SlowWrite function
      // base.write(152);   
      // vertical1.write(0);   
      // vertical2.write(0);   
      // mouth.write(60);   
    } 
    if(letter == 'r'){
      SlowWrite(base, 93, 20);
      SlowWrite(vertical1, 93, 20);
      SlowWrite(vertical2, 93, 20);
      SlowWrite(mouth, 93, 20);
      Serial.print(base.read());
      Serial.print("\t");
      Serial.print(vertical1.read());
      Serial.print("\t");
      Serial.print(vertical2.read());
      Serial.print("\t");
      Serial.print(mouth.read());
      Serial.print("\t");

      // Use these to check if there is a problem with SlowWrite function
      // base.write(152);   
      // vertical1.write(0);   
      // vertical2.write(0);   
      // mouth.write(60);   
    } 
  Serial.println(letter);
  }
  
}
