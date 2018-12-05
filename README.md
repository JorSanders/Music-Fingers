# Music Fingers

The idea of this project is to have a glove with capacative touch sensors connected on the fingertips to an aruino board.
If the sensors detect anything print a character to the serial port.

With processing we listen to the serial port. If the character we are looking for apears we play a sound.

## Dependencies
1. arduino:  https://www.arduino.cc/en/Main/Software
2. arduino library CapacitiveSensor: https://github.com/PaulStoffregen/CapacitiveSensor
	1. Add in arduino IDE sketch->Include Library->Add .ZIP Library...
3. processing https://github.com/PaulStoffregen/CapacitiveSensor
4. processing library sound 
	1. In processing IDE Tools->Add Tool...->Libraries 
	2. Then add Sound by "The Processing Foundation"

## Getting started
Run the Aruino sketch
Run the processing sketch (Make sure you dont have the serial monitor in Arduino IDE open)

## Modifying
In the arduino sketch you can add fingers be sure to also increase the size for the fingers array.
In processing you can add tones. Also you might have to configure the serial port.

## Questions or Problems
Feel free to contact me
