#include <xc.h>

void main(void) {
    TRISA = 0xFF;       // Configure Port A as input
    TRISB = 0x00;       // Configure Port B as output
    TRISD = 0x00;       // Configure Port D as output

    ADCON0bits.ADCS0 = 0;
    ADCON0bits.ADCS1 = 0;
    ADCON0bits.ADCS2 = 1;   // Fosc/4
    ADCON0bits.CHS0 = 0;
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS2 = 0;

    ADCON1bits.ADFM = 1;
    ADCON1bits.PCFG0 = 0;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG3 = 1;

    ADCON0bits.ADON = 1;    // Enable ADC module

    while (1) {
        ADCON0bits.GO_DONE = 1; // Start ADC conversion

        while (ADCON0bits.GO_DONE); // Wait for conversion to complete

        PORTB = ADRESL; // Output ADC result to Port B (assuming 8-bit result)
        PORTD = ADRESH; // Output higher bits of ADC result to Port D
    }

    return;
}
