#include <Arduino.h>

// Setup function runs once when the microcontroller starts
void setup() {
    // Initialize serial communication for debugging
    Serial.begin(9600);
    // Add your setup code here
    Serial.println("Enter text:");
}

// Loop function runs repeatedly after setup
void loop() { 
    // Add your main code here
    if (Serial.available() > 0) {
        char input = Serial.read(); // Read input until newline
        Serial.print("You entered: ");
        Serial.println(input); // Echo the input back to the serial monitor
        if (input == ' ') // Check if the input is 'q'
        {
            Serial.println("Pause...");
          
        }
        
    }

   
}