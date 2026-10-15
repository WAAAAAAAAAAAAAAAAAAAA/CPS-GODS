/*
   arduino-osc-blink

   Listens for serial messages and controls the
   the on-board LED according to the message.

   To be used with the Processing sketch
   processing_osc_to_arduino.pde

   Written by CPS Gods
*/
#include <Servo.h>

Servo base;
Servo vertical1;  // create servo object to control a servo
Servo vertical2;
Servo mouth;

int number = 0;

void SlowWrite (Servo S,int angle, int speed){
  int start = S.read();
  if(start <= angle){
    for(int a = start; a <= angle; a += 1 ){
      S.write(a);              // tell servo to go to position in variable 'pos'
      // Serial.print(a);
      // Serial.print(" ");
      delay(speed);   
    }
    Serial.println("");
  }else{
    for(int a = start; a >= angle; a -= 1 ){
      S.write(a);              // tell servo to go to position in variable 'pos'
      // Serial.print(a);
      // Serial.print(" ");
      delay(speed);
    }
    // Serial.println("");
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
  // wait for a message to arrive
  if (Serial.available()) {
    // save the message when it arrives
    number = Serial.read();
  }

  switch (number) {
    case 1:
      SlowWrite(base, 100, 20);
      SlowWrite(vertical1, 80, 20);
      SlowWrite(vertical2, 180, 20);
      SlowWrite(mouth, 100, 20);
      // Serial.print(base.read());
      // Serial.print("\t");
      // Serial.print(vertical1.read());
      // Serial.print("\t");
      // Serial.print(vertical2.read());
      // Serial.print("\t");
      // Serial.print(mouth.read());
      // Serial.print("\t");
      // base.write(152);   
      // vertical1.write(80);   
      // vertical2.write(180);   
      // mouth.write(100);   
      break;
      
    case 2:
      SlowWrite(base, 50, 20);
        SlowWrite(vertical1, 150, 20);
        SlowWrite(vertical2, 180, 20);
        SlowWrite(mouth, 80, 20);
        // Serial.print(base.read());
        // Serial.print("\t");
        // Serial.print(vertical1.read());
        // Serial.print("\t");
        // Serial.print(vertical2.read());
        // Serial.print("\t");
        // Serial.print(mouth.read());
        // Serial.print("\t");
        // base.write(152)   ;
        // vertical1.write(180);   
        // vertical2.write(180);   
        // mouth.write(80);  
      break;

    case 3:
      SlowWrite(base, 150, 20);
      SlowWrite(vertical1, 0, 20);
      SlowWrite(vertical2, 140, 20);
      SlowWrite(mouth, 60, 20);
      // Serial.print(base.read());
      // Serial.print("\t");
      // Serial.print(vertical1.read());
      // Serial.print("\t");
      // Serial.print(vertical2.read());
      // Serial.print("\t");
      // Serial.print(mouth.read());
      // Serial.print("\t");
      // base.write(152);   
      // vertical1.write(0);   
      // vertical2.write(0);   
      // mouth.write(60);  
      break;
    default:
      SlowWrite(base, 93, 20);
      SlowWrite(vertical1, 93, 20);
      SlowWrite(vertical2, 93, 20);
      SlowWrite(mouth, 93, 20);
      break;
    }                  // wait for the delayed time
}

/*

#include <Servo.h>

Servo base;
Servo vertical1;  // create servo object to control a servo
Servo vertical2;
Servo mouth;

char letter = 'a';


void SlowWrite (Servo S,int angle, int speed){
  int start = S.read();
  if(start <= angle){
    for(int a = start; a <= angle; a += 1 ){
      S.write(a);              // tell servo to go to position in variable 'pos'
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
      // base.write(152);   
      // vertical1.write(80);   
      // vertical2.write(180);   
      // mouth.write(100);   
    } 
    if(letter == 's'){
        SlowWrite(base, 50, 20);
        delay(50);
        SlowWrite(vertical1, 150, 20);
        delay(50);
        SlowWrite(vertical2, 180, 20);
        delay(50);
        SlowWrite(mouth, 80, 20);
        delay(50);
        Serial.print(base.read());
        Serial.print("\t");
        Serial.print(vertical1.read());
        Serial.print("\t");
        Serial.print(vertical2.read());
        Serial.print("\t");
        Serial.print(mouth.read());
        Serial.print("\t");
        // base.write(152)   ;
        // vertical1.write(180);   
        // vertical2.write(180);   
        // mouth.write(80);   
      }
    if(letter == 'b'){
      SlowWrite(base, 150, 20);
      delay(50);
      SlowWrite(vertical1, 0, 20);
      delay(50);
      SlowWrite(vertical2, 140, 20);
      delay(50);
      SlowWrite(mouth, 60, 20);
      delay(50);
      Serial.print(base.read());
      Serial.print("\t");
      Serial.print(vertical1.read());
      Serial.print("\t");
      Serial.print(vertical2.read());
      Serial.print("\t");
      Serial.print(mouth.read());
      Serial.print("\t");
      // base.write(152);   
      // vertical1.write(0);   
      // vertical2.write(0);   
      // mouth.write(60);   
    } 
    if(letter == 'q'){
      SlowWrite(base, 93, 20);
      delay(50);
      SlowWrite(vertical1, 93, 20);
      delay(50);
      SlowWrite(vertical2, 93, 20);
      delay(50);
      SlowWrite(mouth, 93, 20);
      delay(50);
      Serial.print(base.read());
      Serial.print("\t");
      Serial.print(vertical1.read());
      Serial.print("\t");
      Serial.print(vertical2.read());
      Serial.print("\t");
      Serial.print(mouth.read());
      Serial.print("\t");
      // base.write(152);   
      // vertical1.write(0);   
      // vertical2.write(0);   
      // mouth.write(60);   
    } 
  Serial.println(letter);
  }
  
}
*/
