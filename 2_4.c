/* 
 * Desarrollo / Autoria, Juan Manuel Medina, mail to juansth@gmail.com
 * Processor: PIC16F877A
 * Compiler:  MPLAB XC8
 */
//Ciclo For
#include <xc.h>

#define _XTAL_FREQ 800000

void main() {
    TRISA = 0x00;
    unsigned char trafficState = 0; // Control de estado

    while (1) {
        for (trafficState = 0; trafficState < 3; trafficState++) {
            if (trafficState == 0) { // Red
                PORTA = 0b00000001; // ON RA0 (Semaforo en rojo)
                __delay_ms(500); // Espera
            } else if (trafficState == 1) { // Green
                PORTA = 0b00000010; // ON RA1 (Amarillo)
                __delay_ms(500); // Espera
            } else if (trafficState == 2) { // Yellow
                PORTA = 0b00000100; // ON RA2 (Verde)
                __delay_ms(500); // Espera
            }

            // All lights off (safe state)
            PORTA = 0x00;
            __delay_ms(1000); // Wait for 1 second in the safe state
        }
    }
}

