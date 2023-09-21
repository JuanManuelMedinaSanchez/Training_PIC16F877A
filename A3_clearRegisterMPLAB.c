#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 800000

void main() {
    TRISB = 0x00; // Set all pins of PORTB as outputs
    uint8_t flags = 0b00000001; // Initialize flags with the 0th bit set

    while (1) {
        // Clear the 0th bit (turn off the LED)
        flags &= 0b11111110;
        PORTB = flags; // Update PORTB to reflect the changed flags

        __delay_ms(500); // Delay for 500 milliseconds

        // Set the 0th bit (turn on the LED)
        flags |= 0b00000001;
        PORTB = flags; // Update PORTB to reflect the changed flags

        __delay_ms(500); // Delay for 500 milliseconds
    }
}
