//Continue, break
#include <stdio.h>
#include <xc.h>
#define _XTAL_FREQ 800000

void main() {
    TRISB = 0x00;   // Configure PORTB as outputs
    PORTB = 0x00;   // Initialize PORTB to all zeros
    unsigned char mask = 0b00000001;  // Initialize a mask to set individual bits
    while (1) {
        PORTB = mask;   // Set PORTB based on the mask
        __delay_ms(500);  // Delay for 500 milliseconds
        if (mask == 0b10000000) {
            // If the mask reaches the last bit, reset it and break the loop
            mask = 0b00000001;
            break;  // Exit the loop
        }
        mask <<= 1;  // Shift the mask to the left to set the next bit
        continue;    // Continue to the next iteration of the loop
    }
    // The program continues here after the loop is terminated
    // You can add your main program logic below
    while (1) {
        // main
    }
}

