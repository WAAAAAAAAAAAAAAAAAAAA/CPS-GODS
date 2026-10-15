# Giraffe🦒, Snake🐍, Beetle🪲!

A Wekinator and Arduino controlled robot arm (based on the DE-Arm / MeArm) that plays a version of rock, paper, scissors with animals: it strikes a giraffe, snake or beetle pose depending on where the mouse is on screen. Made for the IDE programme in the Dyson School of Design Engineering at Imperial College London.

<img width="1101" height="653" alt="The robot arm" src="https://github.com/user-attachments/assets/fc388e02-480e-4e9c-b691-2fa40ded8455" />

## How to play

Like rock, paper, scissors, each animal beats one and loses to the other:

- 🦒 **Giraffe** beats 🐍 **Snake** (stomps on it)
- 🐍 **Snake** beats 🪲 **Beetle** (eats it)
- 🪲 **Beetle** beats 🦒 **Giraffe** (eats its leaves)

## Summary

The arm has 4 servo motors (base, two vertical joints and a mouth) controlled by an Arduino. We trained a classifier in Wekinator to recognise where the mouse is on the screen. Wekinator sends its result as an OSC message to a Processing sketch, which passes it to the Arduino over serial. The Arduino then moves the servos into the matching pose.

| Mouse position | Pose | Message sent to Arduino |
|---|---|---|
| Top left | Giraffe | 1 |
| Top right | Snake | 2 |
| Bottom left | Beetle | 3 |
| Bottom right | Reset | 4 (any other value also triggers reset) |

## How it works

Mouse position -> Wekinator -> OSC -> Processing -> Serial (USB) -> Arduino -> 4 servos

1. **Input sketch** (`GSB_Process.pde`) shows the four corners and sends the position of the red dot, dragged with the mouse, to Wekinator at `/wek/inputs` on port 6448.
2. **Wekinator** classifies the position and outputs one class (1 to 4) to `/wek/outputs`.
3. **Processing** (`processing_osc_to_arduino.pde`) listens for the OSC message on port 12000 and writes the class number to the Arduino at 9600 baud. It only sends when the value changes.
4. **Arduino** (`Animals.ino`) reads the number and moves each servo to the angles for that pose, one degree at a time so the movement is smooth.

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

Listed in the order the information travels through the system.

| Step | Folder | Filename | Description |
|---|---|---|---|
| 1 | `Code/Input` | `GSB_Process.pde` | Processing sketch showing the giraffe, snake, beetle and RESET corners. Sends the position of the green box to Wekinator (`/wek/inputs`, port 6448) |
| 1 | `Code/Input/data` | `animals.png` | Image used by `GSB_Process.pde` |
| 2 | `Code/Wek : GSB/Trained Model` | `WekinatorProject.wekproj` | Trained Wekinator project: classifies the box position into 4 classes (1 to 4) and sends the result to `/wek/outputs` on port 12000 |
| 3 | `Code/Processing` | `processing_osc_to_arduino.pde` | Processing sketch which listens for OSC messages from Wekinator and sends them to the Arduino over serial |
| 4 | `Code/Arduino` | `Animals.ino` | Arduino sketch which moves the servos into the giraffe, snake, beetle or reset pose |
| – | `Debug` | `debug protocol.md` | Step-by-step checks to find where the system fails, following the information from the mouse to the arm |
| – | `Debug` | `debug.ino` | Arduino sketch for fine-tuning the servo angles |
| – | `Media` | | Photos and videos of the arm |

## How to run it

1. Build the arm and connect the servos to pins 9, 10, 11 and 12.
2. Upload `Code/Arduino/Animals.ino` to the Arduino, then close the Serial Monitor (only one program can use the port at a time).
3. Open `Code/Processing/processing_osc_to_arduino.pde` in Processing. Run it once, check the console for the list of serial ports, and change `Serial.list()[1]` to your Arduino's number. Run it again.
4. Open Wekinator and load `Code/Wek : GSB/Trained Model/WekinatorProject.wekproj`, or train your own: 1 classifier output with 4 classes, sending to port 12000 at `/wek/outputs`.
5. Run `Code/Input/GSB_Process.pde` so it sends the box position to Wekinator.
6. Drag the green box into a corner and the arm moves into that pose.

## Debugging

See [`debug protocol.md`](Debug/debug%20protocol.md) for step-by-step checks to find where the system fails, and use [`debug.ino`](Debug/debug.ino) to fine-tune the servo angles.

## Development History

Built on the DE-Arm, remastered by Tong Zhang and Dr Rebecca Stewart from the open source MeArm V3 from MeArm Robotics Lab. The Processing sketch was written by Becky Stewart (2022) and adapted by us.

## Team

CPS-GODS: Giulio, Indiana, Roxane
