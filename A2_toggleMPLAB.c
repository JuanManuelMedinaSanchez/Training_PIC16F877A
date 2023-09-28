/* 
 * Desarrollo / Autoria, Juan Manuel Medina, mail to juansth@gmail.com
 * Processor: PIC16F877A
 * Compiler:  MPLAB XC8
 */

#define _XTAL_FREQ 800000

#include <xc.h>
#include <stdint.h>

// Configuration settings (similar to previous examples)

void main() {
    TRISB = 0x00; // Set all pins of PORTB as outputs
    unsigned int toggle = 0; // Initialize a variable to track the toggle state

    while (1) {
        // Toggle the state for all pins on PORTB
        PORTB = toggle;

        // Toggle the variable to change the state for the next iteration
        toggle ^= 0xFF;

        __delay_ms(500); // Delay for 500 milliseconds
    }
}
