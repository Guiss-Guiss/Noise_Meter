# Noise_Meter
 This Arduino project uses red, green, and blue LEDs to visually indicate environmental noise levels based on sound intensity.
At its core, the project measures ambient noise via an analog input, calculates the sound's peak-to-peak amplitude, and converts this into a voltage that determines which LED lights up.
The setup effectively captures analog values from a microphone, identifying the amplitude of sound waves and translating these figures into voltage levels.

Sound levels are calibrated using white noise and a Digital Sound Level Meter, with specific voltage ranges tied to decibel levels. Voltages below 1.0V trigger the blue LED, signaling a quiet setting.
Voltages between 1.0V and 3.0V light up the green LED, indicating moderate noise levels, while voltages of 3.0V and above activate the red LED, warning of high noise levels that may be harmful or disruptive.

This project serves a practical purpose in environments where it's crucial to monitor and manage noise levels, such as classrooms, libraries, or hospitals.
