# Tomato Time

### Draft Ideas:
I drafted some ideas (designs, features, etc.) of things I wanted to try out in this project. I iterated with some sketches first, messing around with a food theme. In terms of features, I originally wanted to create an alarm clock but decided that a pomodoro timer would allow me to explore more on the software side of things while also learning more CAD. From there, I narrowed down my ideas and sketched out a more 3D design to lay out my project more. [Sketch below]

<img width="300" alt="sketch" src="https://github.com/user-attachments/assets/c0a066c5-f25c-4f05-b03e-79ec2c373f0f" />

### Components:
* Keyboard Switch
* KY-040 Rotary Encoder Module
* Lolin C3 Mini ESP32 Devboard
* 2.25in TFT LCD Display
* 3.3v Piezo Buzzer
* SPDT Slide Switch
* TP4056 Battery Charger & 5v Boost Module
* 3.7v 2000mah 654065 Rechargeable Lithium Polymer Battery

The project is fully powered by a rechargeable lipo battery. Power is managed through an integrated TP4056 charger/booster module and controlled by a physical SPDT slide switch. When powered, the Lolin C3 Mini controls a display, buzzer, keyboard switch button, and a rotary encoder.

<img width="600" alt="wiring diagram" src="https://github.com/user-attachments/assets/e199f518-aae7-405d-9a40-60cfeb21088e" />
