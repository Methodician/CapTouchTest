#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   895
#define DEBOUNCE        250

////////////////////////////////////////////////////////////////////////////
boolean capButton(uint8_t pad) {
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
   // Print cap touch reading on serial port.
  Serial.println(CircuitPlayground.readCap(1));
  
  // Check if capacitive touch exceeds threshold.
  if (capButton(1)) {

      // Print message.
      Serial.println("Touched!");
      
      // But not too often.
      delay(DEBOUNCE); 
  }
}
