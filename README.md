# Tomato Time
Tomato Time is a pomodoro timer that you can use to track your productivity! It features a tomato-shaped case for the electronic components and tracks your time through a 2.25in display. This is my first hardware project, and I'm really proud of how it came out. Excited to build and make more changes!

### Draft Ideas:
##### 1 hour
I drafted some ideas (designs, features, etc.) of things I wanted to try out in this project. I iterated with some sketches first, messing around with a food theme. In terms of features, I originally wanted to create an alarm clock but decided that a pomodoro timer would allow me to explore more on the software side of things while also learning more CAD. From there, I narrowed down my ideas and sketched out a more 3D design to lay out my project more. [Sketch below]

<img width="300" alt="sketch" src="https://github.com/user-attachments/assets/c0a066c5-f25c-4f05-b03e-79ec2c373f0f" />

### Components:
##### 4 hours
* Keyboard Switch
* Lolin C3 Mini ESP32 Devboard
* 2.25in TFT LCD Display
* 3.3v Piezo Buzzer
* <a href="https://handsontec.com/index.php/product/ky040-rotary-encoder-module-for-arduinoraspberry/">KY-040 Rotary Encoder Module</a> -- $1.20
* <a href="https://www.digikey.com/en/products/detail/e-switch/EG1218/101726">SPDT Slide Switch</a> -- $0.72
* <a href="https://www.aliexpress.us/item/3256808547528857.html?src=google&gatewayAdapt=glo2usa#nav-specification">TP4056 Battery Charger & 5v Boost Module</a> -- $1.42
* <a href="https://ydlbattery.com/products/3-7v-2000mah-654065-lithium-polymer-ion-battery">3.7v 2000mah 654065 Rechargeable Lithium Polymer Battery</a> -- $5.87

The project is fully powered by a rechargeable lipo battery. Power is managed through an integrated TP4056 charger/booster module and controlled by a physical SPDT slide switch. When powered, the Lolin C3 Mini controls a display, buzzer, keyboard switch button, and a rotary encoder.

<img width="600" alt="wiring diagram" src="https://github.com/user-attachments/assets/e199f518-aae7-405d-9a40-60cfeb21088e" />

### Firmware:
##### 2 hours
The timer operates with a statemachine that manages the different user interactions. Through this, users can set a certain amount of time to be productive and wait for the alarm! This was my first time using C++, but I was happy to find some similarities to Java.

### CAD:
##### 9 hours
I spent a majority of my time working on the case! The case for this timer is a spherical tomato-shaped case with a custom star-shaped key cap and circular knob cap. Since this was my first time properly using Onshape, I was learning as I modeled the case, but I got the hang of it around the halfway mark, and I'm excited to see other applications. I had a lot of fun trying to figure out how to work with the unique shaping.

<img height="300" alt="main case" src="https://github.com/user-attachments/assets/89c9e652-fda4-4b1c-84e9-a05bb82ebb91" />
<img height="300" alt="bottom lid" src="https://github.com/user-attachments/assets/22c006a4-4a9b-4699-b927-c6a1c5806337" />
<img height="300" alt="interior" src="https://github.com/user-attachments/assets/261afb97-cc46-499c-8e62-62e23889e5c1" />
<img height="300" alt="printed parts" src="https://github.com/user-attachments/assets/3308af18-a784-4b97-8a72-dbce8f1bea73" />
<img height="300" alt="final" src="https://github.com/user-attachments/assets/b4061498-5818-4707-a4e9-7c0cd186d1de" />

### Total Time Spent: 16 hours
** Note: Some of the components in the STEP file aren't exactly the ones I'll be using, since I couldn't find any models of them. The actual battery is taller and less wide, and the charger is wider.
