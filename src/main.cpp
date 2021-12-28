////////////////////////////////////////////////////////////////////////////
// Circuit Playground Capacitive Touch Basic
//
// Print text messages for each touch pad.
//
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   895
#define FLOOR_THRESHOLD 50
#define DEBOUNCE        250

uint8_t pads[] = {1, 2, 3};
uint8_t numberOfPads = sizeof(pads)/sizeof(uint8_t);

////////////////////////////////////////////////////////////////////////////
void logExceedsMaximum(uint8_t pad) {
  Serial.print("pad "); Serial.print(pad); Serial.println(" HIGH");
}

void logBelowMinimum(uint8_t pad) {
  Serial.print("pad "); Serial.print(pad); Serial.println(" LOW");
}

////////////////////////////////////////////////////////////////////////////
boolean ceilingButton(uint8_t pad) {
  // Check if capacitive touch exceeds threshold.
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;  
  } else {
    return false;
  }
}

boolean floorButton(uint8_t pad) {
  // Check if capacitive touch is below threshold.
  if (CircuitPlayground.readCap(pad) < FLOOR_THRESHOLD) {
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
    // Print cap touch reading on serial port.
  Serial.print(CircuitPlayground.readCap(1));
  Serial.print(',');
  Serial.print(CircuitPlayground.readCap(2));
  Serial.print(',');
  Serial.println(CircuitPlayground.readCap(3));

  // Loop over every pad.
  // for (int i=0; i<numberOfPads; i++) {
    

  //   // Check if pad is touched.
  //   if (ceilingButton(pads[i])) {
      
  //     // Do something.
  //     logExceedsMaximum(pads[i]);
      
  //     // But not too often.
  //     // delay(DEBOUNCE);
  //   }

  //   if(floorButton(pads[i])) {
      
  //     // Do something.
  //     logBelowMinimum(pads[i]);
      
  //     // But not too often.
  //     // delay(DEBOUNCE);
  //   }
  // }
}
