/* 
 * Desarrollo / Autoria, Juan Manuel Medina, mail to juansth@gmail.com
 * Processor: PIC16F877A
 * Compiler:  MPLAB XC8
 */
#define _XTAL_FREQ 800000
#include <xc.h>

void main() {
    TRISA = 0x00;
    unsigned char trafficState = 0; // Control de estado
    while (1) {
        switch (trafficState) {
            case 0: // Red
                PORTA = 0b00000001; // ON RA0 (Semaforo en rojo)
                __delay_ms(500); // Espera
                trafficState = 1; // Switch al siguiente estado y break
                break;

            case 1: // Green
                PORTA = 0b00000010; // ON RA1 (Amarillo)
                __delay_ms(500); // Espera
                trafficState = 2; // Switch al siguiente estado y break
                break;

            case 2: // Yellow
                PORTA = 0b00000100; // ON RA2 (Verde)
                __delay_ms(500); // Espera
                trafficState = 0; // Switch al siguiente estado inicial 0 y break
                break;
                default:
    /*La variable trafficState puede caer en un estado indeterminado ni 
    es 0, ni 1, o 2 luego debemos llevar las luces a un estado seguro:
    All lights off.*/
    PORTA = 0x00; // All lights off (safe state)
    __delay_ms(1000); // Wait for 1 second in the safe state
    trafficState = 0; // Return to the initial state
    break;
        }
    }
}

