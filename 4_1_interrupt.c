
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

// Define macros for LED and button pins


void __interrupt() ISR(void) {

    // Check if the interrupt was caused by RB0 (external falling edge)
    if (INTF ) {
         PORTD ^= 0xFF; // Toggle the LED state (XOR with 0xFF)
        INTF = 0;    // Clear the interrupt flag
    }
}

void main(void) {
   /*Podria ser  /INTCON  = 0x90; tambien*/
   GIE=1;
   INTE = 1;
    TRISD = 0;
     PORTD = 0x01;
   
   
    while (1) {
        // Your main code can run here; the LED state will toggle on interrupt
    }
}
