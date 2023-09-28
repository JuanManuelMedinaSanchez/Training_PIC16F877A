//Do while
#include <stdio.h>
#include <xc.h>

#define _XTAL_FREQ 800000

void main() {
    TRISB = 0x00; // Set all pins of PORTB as outputs
    unsigned char toggle = 0;
    
    do {
        PORTB = toggle; // Set PORTB based on the toggle state
        __delay_ms(500); // Delay for 500 milliseconds
        toggle ^= 0xFF; // Toggle the variable between 0x00 and 0xFF
    } while (PORTB != 0x0F); // Continue looping until all pins are set (0x0F)
}


