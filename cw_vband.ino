

//#include <HID-Settings.h>
//#include <HID-Project.h>



//#include <unoHID.h>
#include <Keyboard.h>
//#include <KeyboardLayout.h>
//KeyBoard_ Keyboard;

// Change these to suit your wiring - I use these as next to 
// Ground to simplify wiring
#define DIH_PIN 3
#define DAH_PIN 2
#define ledPin LED_BUILTIN

// Vband seems to work best emulating the [] keys
// Also works with vail online code
//#define ditKey '['
//#define dahKey ']'

#define ditKey 0xe1
#define dahKey 0xe2

// setup the pins and HID (device)
void setup() {
  pinMode(DIH_PIN, INPUT_PULLUP);
  pinMode(DAH_PIN, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Keyboard.begin(); // initialise HID library
}

// main loop
// keep code in tidy subroutines
void loop() { action_paddle();  } 

// actually do the work
//
// function:   void action_paddle()
//
// read pins and simulate the keypress depending
void action_paddle(){
  while (digitalRead(DIH_PIN) == HIGH && digitalRead(DAH_PIN) == HIGH)
  { 
    Keyboard.releaseAll();   
    digitalWrite(ledPin, LOW);
  }
  
  if ( digitalRead(DIH_PIN) == LOW)
  {
    Keyboard.press(ditKey);
    digitalWrite(ledPin, HIGH); 
  }
  else
  {
    Keyboard.release(ditKey);   
    digitalWrite(ledPin, LOW);
  }
  
  if ( digitalRead(DAH_PIN) == LOW)
  { 
    Keyboard.press(dahKey); 
    digitalWrite(ledPin, HIGH);
  }
  else{ 
    Keyboard.release(dahKey);  
    digitalWrite(ledPin, LOW); 
  }
  // short delay to stop overloading VBand
  //delay(0);
}
// END  //////////////////////////////////////////////////////
