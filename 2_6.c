/* 
 * Desarrollo / Autoria, Juan Manuel Medina, mail to juansth@gmail.com
 * Processor: PIC16F877A
 * Compiler:  MPLAB XC8
 */
//Ciclo While parte 2. 
#define _XTAL_FREQ 800000

#include <xc.h>

void main() {
    TRISA = 0x00; // Configura todos los pines de PORTA como salidas
    PORTA = 0x00; // Inicializa PORTA en bajo

    while (1) {
        // Parpadeo rápido de los LEDs del bit 0 al 3
        int i = 0;
        while (i < 4) {
            PORTA = 1 << i; // Enciende el LED correspondiente
            __delay_ms(100); // Espera 100 milisegundos
            PORTA = 0x00; // Apaga todos los LEDs
            __delay_ms(100); // Espera 100 milisegundos
            i++;
        }

        // Parpadeo lento de los LEDs del bit 4 al 7
        int j = 4;
        while (j < 8) {
            PORTA = 1 << j; // Enciende el LED correspondiente
            __delay_ms(500); // Espera 500 milisegundos
            PORTA = 0x00; // Apaga todos los LEDs
            __delay_ms(500); // Espera 500 milisegundos
            j++;
        }
    }
}

