# CPS-GODS: Geraff🦒, Snake🐍, Beetle🪲!

A Wekinator and Arduino controlled robot arm (based on the DE-Arm / MeArm) that strikes animal poses depending on where the mouse is on screen. Made for the IDE programme in the Dyson School of Design Engineering at Imperial College London.

![Photo of the finished robot arm](Media/arm-photo.jpg)

## Summary

The arm has 4 servo motors (base, two vertical joints and a mouth) controlled by an Arduino. We trained a classifier in Wekinator to recognise where the mouse is on the screen. Wekinator sends its result as an OSC message to a Processing sketch, which passes it to the Arduino over serial. The Arduino then moves the servos into the matching pose.

| Mouse position | Pose | Message sent to Arduino |
|---|---|---|
| Top left | Giraffe | 1 |
| Top right | Snake | 2 |
| Bottom left | Beetle | 3 |
| Bottom right | Reset | 4 (any other value also triggers rest) |

## How it works

Mouse position -> Wekinator -> OSC -> Processing -> Serial (USB) -> Arduino -> 4 servos

1. **Wekinator** takes the mouse position as input and outputs one class (1 to 4) to `/wek/outputs`.
2. **Processing** listens for the OSC message on port 12000 and writes the class number to the Arduino at 9600 baud. It only sends when the value changes.
3. **Arduino** reads the number and moves each servo to the angles for that pose, one degree at a time so the movement is smooth.

## Hardware

- Laser-cut DE-Arm with 4 servo motors
- Arduino board and USB cable
- Laptop running Wekinator and Processing

| Servo | Arduino pin |
|---|---|
| Base | 9 |
| Vertical 1 | 10 |
| Vertical 2 | 11 |
| Mouth | 12 |

## Directory of Resources

| Folder | Filename | Description |
|---|---|---|
| Codee | `processing_osc_to_arduino.pde` | Processing sketch which listens for OSC messages from Wekinator and sends them to the Arduino over serial |
| Codee | `wekinator_to_animal.ino` | Arduino sketch which moves the servos into the giraffe, snake, beetle or rest pose |
| Codee | `WEK_INPUT_FILENAME` | Wekinator input file (mouse position sent to Wekinator) |
| Codee | `WEK_MODEL_FILENAME` | Trained Wekinator model for the 4 mouse regions |
| Debug | `debugging.md` | What went wrong while building this and how we fixed it |
| Media | | Photos and videos of the arm |
| data | | Data files |

## How to run it

1. Build the arm and connect the servos to pins 9, 10, 11 and 12.
2. Upload `wekinator_to_animal.ino` to the Arduino, then close the Serial Monitor (only one program can use the port at a time).
3. Open `processing_osc_to_arduino.pde` in Processing. Run it once, check the console for the list of serial ports, and change `Serial.list()[1]` to your Arduino's number. Run it again.
4. Open Wekinator and load the trained model (`WEK_MODEL_FILENAME`), or train your own: 1 classifier output with 4 classes, sending to port 12000 at `/wek/outputs`.
5. Run the Wekinator input file so it sends the mouse position.
6. Move the mouse into a corner and the arm moves into that pose.

## Debugging

See [`Debug/debugging.md`](Debug/debugging.md) for the problems we ran into and how we solved them.

## Development History

Built on the DE-Arm, remastered by Tong Zhang and Dr Rebecca Stewart from the open source MeArm V3 from MeArm Robotics Lab. The Processing sketch was written by Becky Stewart (2022) and adapted by us.

## Team

CPS-GODS: Giulio, Indiana, Roxane 
