#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

// Function to display a digit on a 7-segment display
void displayDigit(uint8_t digit) {
    // Define the 7-segment display patterns for digits 0-9
    const uint8_t digitPatterns[10] = {
        0b00111111, // 0
        0b00000110, // 1
        0b01011011, // 2
        0b01001111, // 3
        0b01100110, // 4
        0b01101101, // 5
        0b01111101, // 6
        0b00000111, // 7
        0b01111111, // 8
        0b01101111  // 9
    };

    PORTB = digitPatterns[digit]; // Display the specified digit
}

void main() {
    // Configure Port D as inputs for the buttons (1, 2, 4, and 8)
    TRISD = 0xFF; // All bits as inputs

    // Configure Port B as outputs for the 7-segment display
    TRISB = 0x00; // All bits as outputs
    PORTB = 0x00; // Initialize Port B to 0

    // Create variables to keep track of button state
    uint8_t prevButtonState = 0;
    uint8_t currentButtonState = 0;

    // Initialize digit count to 0
    uint8_t digitCount = 0;

    while (1) {
        // Read the state of the push button on RD0
        currentButtonState = PORTD & 0x01;
        // Check if the button was pressed (transition from 0 to 1)
        if (currentButtonState == 1 && prevButtonState == 0) {
            digitCount++; // Increment digit count on button press
            digitCount %= 10; // Ensure it wraps around from 9 to 0

            // Display the current digit on the 7-segment display
            displayDigit(digitCount);
        }
        // Update the previous button state
        prevButtonState = currentButtonState;
    }
}
