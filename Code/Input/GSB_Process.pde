
import oscP5.*;
import netP5.*;

// IMAGE
PImage backgroundImage;

// MOUSE MARKER
float markerX;
float markerY;
boolean dragging = false;
float markerSize = 28;

// WEKINATOR OSC
OscP5 oscP5;
NetAddress dest;

void setup() {
  size(800, 800);

  // Load the animal image from the data folder
  backgroundImage = loadImage("animals.png");

  // Start the marker in the middle
  markerX = width / 2;
  markerY = height / 2;

  // Start OSC communication
  oscP5 = new OscP5(this, 9000);

  // Send data to Wekinator on port 6448
  dest = new NetAddress("127.0.0.1", 6448);
}

void draw() {

  // Display the animal image
  image(backgroundImage, 0, 0, width, height);

  // Draw the draggable marker
  noStroke();
  fill(255, 80, 80, 210);
  ellipse(markerX, markerY, markerSize, markerSize);

  // Show mouse position
  fill(0);
  textSize(14);
  text("Mouse X: " + mouseX +
       "   Mouse Y: " + mouseY, 12, height - 16);

  // Send mouse data to Wekinator every 10 frames
  if (frameCount % 10 == 0) {
    sendOsc();
  }
}

void sendOsc() {

  // Create a message for Wekinator
  OscMessage msg = new OscMessage("/wek/inputs");

  // Convert X and Y into numbers between 0 and 1
  float inputX = constrain(markerX / width, 0, 1);
  float inputY = constrain(markerY / height, 0, 1);

  // Add the two inputs to the message
  msg.add(inputX);
  msg.add(inputY);

  // Send the message to Wekinator
  oscP5.send(msg, dest);

  // Print values so we can check they are being sent
  println("X: " + inputX + "  Y: " + inputY);
}

void mousePressed() {

  // Start dragging if the marker is clicked
  if (dist(mouseX, mouseY, markerX, markerY) < markerSize) {
    dragging = true;
  }
}

void mouseDragged() {

  // Move the marker while dragging
  if (dragging) {
    markerX = mouseX;
    markerY = mouseY;
  }
}

void mouseReleased() {

  // Stop dragging
  dragging = false;
}
