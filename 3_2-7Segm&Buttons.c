/*_______________________________________________________________________________________________ 
Seven segment control with ext toggle 
_________________________________________________________________________________________________*/


#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

void main() {
    // Configure Port A as inputs for the buttons (1, 2, 4, and 8)
    TRISD= 0xFF; // All bits as inputs
    // Configure Port B as outputs for the 7-segment display
    TRISB = 0x00; // All bits as outputs
    PORTB = 0x00; // Initialize Port B to 0
       PORTD = 0x00; // Initialize Port B to 0


    while (1) {
        uint8_t buttonState = PORTD; // Read the state of Port A with buttons
        // Check which button is pressed and display the corresponding number on Port B
        switch (buttonState) {
            case 0b00000001: // Button 1
               PORTB = 0b00000110; // Display 1
                break;
            case 0b00000010: // Button 2
  PORTB = 0b01011011; // Display 2
                break;
            case 0b00000100: // Button 4
        PORTB = 0b01001111; // Display 3
                break;
            case 0b00001000: // Button 8
                PORTB = 0b01001111; // Display 3
                break;
            default:
                   PORTB = 0b00111111; // Display 0
                break;
        }
    }
}
