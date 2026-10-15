# Debugging

Work through these checks in order. They follow the information from the mouse to the arm, so the first check that fails tells you where the problem is.

Mouse position -> Wekinator -> Processing -> Arduino -> servos

## Q1: Does Wekinator read the input?

**How to check:**
1. Run [`GSB_Process.pde`](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/blob/main/Code/Input/GSB_Process.pde).
2. Open Wekinator and load the [Wekinator training folder](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/tree/main/Code/Wek%20%3A%20GSB/Trained%20Model).
3. The output number in Wekinator should change when you hover over different animals.

<img width="1280" height="832" alt="Wekinator output changing with mouse position" src="https://github.com/user-attachments/assets/55c722c4-9e79-42a7-b693-cd9c7d02b846" />

## Q2: Does Processing output the same number?

**How to check:**
1. Keep everything from Q1 running.
2. Open and run [`processing_osc_to_arduino.pde`](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/blob/main/Code/Processing/processing_osc_to_arduino.pde).
3. Check that the Processing console prints the same number as Wekinator.

<img width="1280" height="832" alt="Processing console printing the Wekinator output" src="https://github.com/user-attachments/assets/67e8d9e1-f7ea-4872-bb87-9484105b7ec3" />

## Q3: Does the Arduino receive the right input?

**How to check:**
Check that the port on line 39 of [`processing_osc_to_arduino.pde`](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/blob/main/Code/Processing/
