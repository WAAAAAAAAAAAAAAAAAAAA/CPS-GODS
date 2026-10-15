/*
This code sweeps all 4 motors 180 degrees to check they are functioning
*/

#include <Servo.h>
Servo base;
Servo vertical1; 
Servo vertical2;
Servo mouth;

// Sweep function: moves servo from 0 to 180 and back.
void Sweep (Servo S){
  int pos = 0;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    S.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(100);
} 

void setup() {
  base.attach(9);  // attaches the servo on pin 9 to the servo object
  vertical1.attach(10);  // attaches the servo on pin 10 to the servo object
  vertical2.attach(11);  // attaches the servo on pin 11 to the servo object
  mouth.attach(12);  // attaches the servo on pin 12 to the servo object
}

void loop() {
  Sweep(base);
  Sweep(vertical1);
  Sweep(vertical2);
  Sweep(mouth);
}
