// Simple example application that shows how to read four Arduino
// digital pins and map them to the USB Joystick library.
//
// Ground digital pins 9, 10, 11, and 12 to press the joystick 
// buttons 0, 1, 2, and 3.
//
// NOTE: This sketch file is for use with Arduino Leonardo and Arduino Pro Micro.
//
// by Matthew Heironimus	2015-11-20
// Updated by Raymond		2019-11-17
//--------------------------------------------------------------------

#include <Joystick.h>

uint8_t buttonCount = 14;
bool includeXAxis = false;
bool includeYAxis = false;
bool includeZAxis = false;
bool includeRxAxis = false;
bool includeRudder = false;
bool includeThrottle = false;
bool includeAccelerator = false;
bool includeBrake = false;
bool includeSteering = false;

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  //Below 4 digital pins mapped to analog
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
//const int NumButtons = 11;
const int buttonToPinMap[18] = {0,1,2,3,4,5,6,7,8,9,10,14,15,16,18,19,20,21};

// Last state of the button
int lastButtonState[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < 18; index++)
  {
    int currentButtonState = !digitalRead(buttonToPinMap[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}
