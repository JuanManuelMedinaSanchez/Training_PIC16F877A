/* 
 * Desarrollo / Autoria, Juan Manuel Medina, mail to juansth@gmail.com
 * Processor: PIC16F877A
 * Compiler:  MPLAB XC8
 */

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 800000 // Frecuencia del oscilador de cristal: 8MHz

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


void main() {
    // Configure all pins of PORTA and PORTB as outputs
    TRISA = 0x00;
    TRISB = 0x00;

    while (1) {
        // Turn on all the LEDs connected to PORTA
        PORTA = 0xFF;

        // Turn on all the LEDs connected to PORTB
        PORTB = 0xFF;

        __delay_ms(500); // Delay for 500 milliseconds

        // Turn off all the LEDs connected to PORTA
        PORTA = 0x00;

        // Turn off all the LEDs connected to PORTB
        PORTB = 0x00;

        __delay_ms(500); // Delay for 500 milliseconds
    }
}


