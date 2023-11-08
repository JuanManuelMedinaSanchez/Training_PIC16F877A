#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

volatile uint8_t pauseFlag = 0; // Bandera de pausa

void __interrupt() ISR(void) {
    if (INTF) {
        pauseFlag = !pauseFlag; // Alterna la bandera de pausa
        INTF = 0; // Limpia la bandera de interrupción de INT
    }
}

void main(void) {
    PORTD = 0;
    TRISB0 = 1;
    TRISD = 0;
    OPTION_REG = 0x00; // Interrupción en flanco de bajada en RB0, habilita pull-up en puerto B
    INTCON |= 0x90; // Habilita interrupción global y externa

    while (1) {
        if (!pauseFlag) {
            PORTD ^= 0xFF; 
            __delay_ms(100); // Espera
        } else {
            // El programa está en pausa, puedes realizar otras acciones si es necesario
        }
    }
}
