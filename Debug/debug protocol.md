Q1: does the wek read the input? 
How to check: 
  Run the [animal files](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/blob/main/Codee/Arduino/Animals.ino). 
  Run Wekinator and open the [Wekinator training folder](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/tree/main/Codee/Wek%20%3A%20GSB/WekinatorProject). The ouput number on wek should change when we hover over different animals.

<img width="1280" height="832" alt="PHOTO-2026-10-15-15-37-25" src="https://github.com/user-attachments/assets/55c722c4-9e79-42a7-b693-cd9c7d02b846" />
<img width="1280" height="832" alt="PHOTO-2026-10-15-15-41-07" src="https://github.com/user-attachments/assets/67e8d9e1-f7ea-4872-bb87-9484105b7ec3" />
    
Q2: does the processing ouput the same number?
How to check:
  Repeat Q1. Open and run [processing_osc_to_arduino.pde](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/blob/main/Codee/processing_osc_to_arduino.pde). and check if it's printing the same number.

    
Q3: does the robot arm move to the right postiion? 
How to check:
  1. check arduino is set up correctly <img width="1536" height="2048" alt="PHOTO-2026-10-15-16-25-07" src="https://github.com/user-attachments/assets/9b4808ef-5eed-4f30-b3be-5a9531a1907a" />

  2. run keyboard for manual tuning 

    
Q4: does arduino recive the right input?
How to check:
  Check that the port indicated in line 39 of [processing_osc_to_arduino.pde](https://github.com/WAAAAAAAAAAAAAAAAAAAA/CPS-GODS/blob/main/Codee/processing_osc_to_arduino.pde) corespond to the /dev/cu.usbmodem101 port indicated in the serial monitor of processing. 
 

