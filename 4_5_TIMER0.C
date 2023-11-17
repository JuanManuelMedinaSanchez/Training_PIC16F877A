
#include <xc.h>
#define _XTAL_FREQ 20000000 // Assuming a 20MHz oscillator frequency

void configureTimer0() {
    OPTION_REG = 0b11010111; // Set Timer0 with 1:256 prescaler
    TMR0 = 100; // Load initial value for a 1ms interrupt
    INTCONbits.T0IE = 1; // Enable Timer0 overflow interrupt
    INTCONbits.GIE = 1; // Enable global interrupts
}

void __interrupt() isr(void) {
    if (T0IF) {
        T0IF = 0; // Clear Timer0 overflow flag
        TMR0 = 100; // Reload initial value for a 1ms interrupt
        // Toggle RD0 (Assuming RD0 is connected to an LED)
        PORTDbits.RD0 = !PORTDbits.RD0;
    }
}

void main() {
    TRISD0 = 0; // Set RD0 as output
    configureTimer0(); // Configure Timer0 for a 1ms interrupt

    while(1) {
        // Your main code here
    }
}
