## Piano Button Music Performer 🎹
An interactive embedded system that allows users to play music using piano-style buttons with real-time audio and visual feedback. Developed for the NMJ32404 Embedded System Design course.

## Features
8 piano buttons (Do-Re-Mi-Fa-So-La-Ti-Do)
Piezo speaker for sound output
LCD display with status messages
Auto-play mode with LED visualizer
Servo-controlled secure box for coin collection

## Components
-STC89C52RC microcontroller
-Piezo speaker, LCD, LED, servo motor
-8+ buttons and basic wiring (total cost: ~RM55)

## How It Works
Pressing a button plays a note and updates the LCD. Auto-play mode plays a song with synced LED effects. After the performance, the secure box opens to collect coins safely.

## Upload Instructions (Arduino IDE)
⚠️ Note: Although this project uses the 8051 (STC89C52RC) microcontroller, you can write, compile, and test your code in Arduino IDE with adaptations if needed.
1. Install the Arduino IDE (if not already).
2. Set up 8051 support (you may need external tools or use Proteus for simulation as Arduino doesn’t natively support 8051).
3. Write your code using C language syntax (similar to Arduino sketches but tailored for 8051 registers).
4. Compile and upload the HEX file using an external flasher (like STC-ISP) for the STC89C52RC chip.
5. Test using Proteus simulation or your actual hardware.
💡 Tip: For actual Arduino boards (like UNO/Nano), you can adapt the circuit and code to match Arduino pinouts if needed.

## Team
Me, Sak, Au, Chang
