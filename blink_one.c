#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 8000000 // Frecuencia del oscilador de cristal: 8MHz

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


void main() {
    TRISA &= ~(1 << 5); // Configurar RA5 como pin de salida

    while (1) {
        // Encender RA5
        PORTA |= (1 << 5);

        // Retardo de 500 milisegundos
        __delay_ms(500);

        // Apagar RA5
        PORTA &= ~(1 << 5);

        // Retardo de 500 milisegundos
        __delay_ms(500);
    }
}
