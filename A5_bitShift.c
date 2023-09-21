  #include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 800000

void main() {
    TRISB = 0x00; // Set all pins of PORTB as outputs
    uint8_t bitShift = 0b00000001; // Initialize a single bit at the rightmost position

    while (1) {
        // Shift the bit to the right
        bitShift >>= 1;

        // Wrap around to the leftmost position if all bits are shifted out
        if (bitShift == 0) {
            bitShift = 0b10000000;
        }

        // Update PORTB to reflect the new bit position
        PORTB = bitShift;

        __delay_ms(500); // Delay for 500 milliseconds
    }
}
