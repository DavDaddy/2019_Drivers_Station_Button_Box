
#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(0, INPUT_PULLUP); // Button 0
  pinMode(1, INPUT_PULLUP); //1
  pinMode(2, INPUT_PULLUP); //2
  pinMode(3, INPUT_PULLUP); //3
  pinMode(4, INPUT_PULLUP); //4
  pinMode(5, INPUT_PULLUP); //5
  pinMode(6, INPUT_PULLUP); //6
  pinMode(7, INPUT_PULLUP); //7
  pinMode(8, INPUT_PULLUP); //8
  pinMode(9, INPUT_PULLUP);  //9
  pinMode(10, INPUT_PULLUP);  //10
  pinMode(16, INPUT_PULLUP);  //11


  


  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
  const int pinToButtonMap = 0;

// Last state of the button
int lastButtonState[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int pin16Button = 11;


void loop() {

  // Read pin values
  for (int index = 0; index < 12; index++)
  {
    int currentPin16 = !digitalRead(16);
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    
    if (currentButtonState != lastButtonState[index] && index != 12)
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
    else 
    {
      if (currentPin16 != lastButtonState[12]){
        Joystick.setButton(pin16Button, currentPin16);
        lastButtonState[16] = currentPin16;
      }
    }
  }

  

  delay(50);
}

