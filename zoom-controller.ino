#include <Keyboard.h>

// It is recommended that you enable global shortcuts in Zoom
// for mute/unmute (cmd/ctrl + shift + A) and start/stop video 
// (cmd/ctrl + shift + V).
// Enabling global shortcuts will allow you to mute/unmute or start/stop
// video even when Zoom is just running in the background.
// This can be done by going to Zoom's settings, selecting the "Keyboard
// Shortcuts" section and clicking the "Global Shortcuts" checkbox for the
// shortcuts mentioned above.

// use this option for OSX:
char ctrlKey = KEY_LEFT_GUI;
// use this option for Windows and Linux:
//  char ctrlKey = KEY_LEFT_CTRL;

char shiftKey = KEY_LEFT_SHIFT;

// define pin locations
const int audPin = 8;
const int vidPin = 5;

// initialize state variables
int audCurrState = 0;
int audPrevState = 0;
int vidCurrState = 0;
int vidPrevState = 0;

void setup() {
  // set pins to be inputs
  pinMode(audPin, INPUT);
  pinMode(vidPin, INPUT);

  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read state of audio pin
  audPrevState = audCurrState;
  audCurrState = digitalRead(audPin);

  // read state of video pin
  vidPrevState = vidCurrState;
  vidCurrState = digitalRead(vidPin);

  // check if the audio button is pressed
  // also, only execute if previous state is LOW so that this is code is
  // executed once per press, even if the button is held for multiple loops
  if ((audCurrState == HIGH) && (audPrevState == LOW)) {
    // Zoom shortcut to turn mute/unmute is cmd/ctrl + shift + A
    Keyboard.press(ctrlKey);
    Keyboard.press(shiftKey);
    Keyboard.press('a');
    delay(5);
    Keyboard.releaseAll();
  }

  // check if the video button is pressed
  // also, only execute if previous state is LOW so that this is code is
  // executed once per press, even if the button is held for multiple loops
  if ((vidCurrState == HIGH) && (vidPrevState == LOW)) {
    // Zoom shortcut to turn mute/unmute is cmd/ctrl + shift + V
    Keyboard.press(ctrlKey);
    Keyboard.press(shiftKey);
    Keyboard.press('v');
    delay(5);
    Keyboard.releaseAll();
  } 

  delay(5);
}