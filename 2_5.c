//Ciclo while
#include <xc.h>

#define _XTAL_FREQ 800000

void main() {
    TRISA = 0b11111110; // Configura RA0 como salida
    PORTA = 0x00; // Inicializa el puerto A en bajo

    while (1) {
        // Enciende el LED en RA0
        PORTA = 0b00000001;
        
        // Espera un momento (puedes ajustar el valor para cambiar la velocidad del parpadeo)
        __delay_ms(500); // Espera 500 milisegundos

        // Apaga el LED en RA0
        PORTA = 0x00;
        
        // Espera un momento
        __delay_ms(500); // Espera 500 milisegundos
    }
}
