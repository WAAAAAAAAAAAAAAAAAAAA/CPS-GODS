/*
   arduino-osc-animals

   Listens for serial messages and controls
   the robotic arm according to the message

   To be used with the Processing sketch
   processing_osc_to_arduino.pde

   Written by CPS Gods
*/

// import library to control servos
#include <Servo.h>

// create servo objects to control the servos
Servo base;
Servo vertical1;  
Servo vertical2;
Servo mouth;

// creates integer variable to act on different cases 
int number = 0;

// Function to move the servos slowly and wait for a short time between one and another;
void SlowWrite (Servo S,int angle, int speed){
  int start = S.read();    //Records current position of servo
  if(start <= angle){      //Checks if it should rotate clockwise or anticlockwise
    for(int a = start; a <= angle; a += 1 ){ //rotates motor by 1 degree at a set speed
      S.write(a);              
      delay(speed);   
    }
    Serial.println("");
  }else{
    for(int a = start; a >= angle; a -= 1 ){
      S.write(a);             
      delay(speed);
    }
    delay(50);
  }  
}

// attaches the servos to the corresponding pins and starts serial communication
void setup() {
  base.attach(9);  
  vertical1.attach(10);
  vertical2.attach(11);
  mouth.attach(12);
  Serial.begin(9600);
}

void loop() {
   
  // wait for a message to arrive
  if (Serial.available()) {
    // save the message when it arrives
    number = Serial.read();
  }

  switch (number) {
   // Giraffe position
   case 1:
      SlowWrite(base, 100, 20);
      SlowWrite(vertical1, 80, 20);
      SlowWrite(vertical2, 180, 20);
      SlowWrite(mouth, 100, 20);
      break;
     
   // Snake position
   case 2:
      SlowWrite(base, 50, 20);
      SlowWrite(vertical1, 150, 20);
      SlowWrite(vertical2, 180, 20);
      SlowWrite(mouth, 80, 20);
      break;

   // Beetle position
   case 3:
      SlowWrite(base, 150, 20);
      SlowWrite(vertical1, 0, 20);
      SlowWrite(vertical2, 140, 20);
      SlowWrite(mouth, 60, 20);
      break;
     
   // Reset position, all motors at half range
   default:
      SlowWrite(base, 93, 20);
      SlowWrite(vertical1, 93, 20);
      SlowWrite(vertical2, 93, 20);
      SlowWrite(mouth, 93, 20);
      break;
    }
}
