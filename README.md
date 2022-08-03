
# Brainwork for Watchy

A simple framework containing a handful of my watchfaces with a dark/light mode switch.

### How to install

1. First, setup your Watchy with Arduino according to the [Getting Started](https://watchy.sqfmi.com/docs/getting-started) guide.
2. Open the file *watchy.h* in the folder *Arduino\\libraries\\Watchy\\src\\*.
3. Find the line *void handleButtonPress();* and change it to *virtual void handleButtonPress();* .
4. Download this project and open the file *Brainwork-for-Watchy.ino* in Arduino.
5. Connect your watchy to your computer and press ctrl-u to compile and upload the watchfaces.

### How to use

Use the up and down buttons (on the right side) to cycle through the watchfaces. Use the back button (top left) to switch between light and dark mode.

Have fun!
