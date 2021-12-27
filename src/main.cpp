////////////////////////////////////////////////////////////////////////////
// Circuit Playground Capacitive Touch Basic
//
// Print text messages for each touch pad.
//
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   895
#define DEBOUNCE        250

uint8_t pads[] = {3, 2, 0, 1, 12, 6, 9, 10};
uint8_t numberOfPads = sizeof(pads)/sizeof(uint8_t);

////////////////////////////////////////////////////////////////////////////
void takeAction(uint8_t pad) {
  Serial.print("PAD "); Serial.print(pad); Serial.print(" says: ");
  switch (pad) {
    case 3: // A4
      Serial.println("3");
      break;
    case 2: // A5
      Serial.println("2");
      break;
    case 0: // A6
      Serial.println("0");
      break;
    case 1: // A7
      Serial.println("1");
      break;
    case 12:
      Serial.println("12");
      break;
    case 6: // A1
      Serial.println("6");
      break;
    case 9: // A2
      Serial.println("9");
      break;
    case 10: // A3
      Serial.println("10");
      break;
    default:
      Serial.println("THIS SHOULD NEVER HAPPEN.");
  }
}

////////////////////////////////////////////////////////////////////////////
boolean capButton(uint8_t pad) {
  // Check if capacitive touch exceeds threshold.
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;  
  } else {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////
void setup() {
  // Initialize serial.
  Serial.begin(9600); 
  
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
}

////////////////////////////////////////////////////////////////////////////
void loop() {
  // Loop over every pad.
  for (int i=0; i<numberOfPads; i++) {
    
    // Check if pad is touched.
    if (capButton(pads[i])) {
      
      // Do something.
      takeAction(pads[i]);
      
      // But not too often.
      delay(DEBOUNCE);
    }
  }
}
