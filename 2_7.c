#include <xc.h>
#define _XTAL_FREQ 800000

void main() {
    TRISA = 0x00; // Configura todos los pines de PORTA como salidas
    PORTA = 0x00; // Inicializa PORTA en bajo

    while (1) {
        // Parpadeo rápido de los LEDs del bit 0 al 3 usando un bucle for
        for (int i = 0; i < 4; i++) {
            PORTA = 1 << i; // Enciende el LED correspondiente
            __delay_ms(100); // Espera 100 milisegundos
            PORTA = 0x00; // Apaga todos los LEDs
            __delay_ms(100); // Espera 100 milisegundos
        }

        // Parpadeo lento de los LEDs del bit 4 al 7 usando un bucle while
        int j = 4;
        while (j < 8) {
            PORTA = 1 << j; // Enciende el LED correspondiente
            __delay_ms(500); // Espera 500 milisegundos
            PORTA = 0x00; // Apaga todos los LEDs
            __delay_ms(500); // Espera 500 milisegundos
            j++;
        }

        // Alternar el estado de los LEDs con una estructura condicional if-else
        if (PORTA == 0x00) {
            PORTA = 0xFF; // Enciende todos los LEDs
        } else {
            PORTA = 0x00; // Apaga todos los LEDs
        }

        // Cambiar el patrón de parpadeo usando una estructura condicional switch
        int pattern = 1;
        switch (pattern) {
            case 1:
                // Parpadeo de todos los LEDs en secuencia
                for (int k = 0; k < 8; k++) {
                    PORTA = 1 << k; // Enciende el LED correspondiente
                    __delay_ms(200); // Espera 200 milisegundos
                    PORTA = 0x00; // Apaga todos los LEDs
                    __delay_ms(200); // Espera 200 milisegundos
                }
                break;

            case 2:
                // Parpadeo de los LEDs pares
                for (int k = 0; k < 8; k += 2) {
                    PORTA = 1 << k; // Enciende el LED correspondiente
                    __delay_ms(300); // Espera 300 milisegundos
                    PORTA = 0x00; // Apaga todos los LEDs
                    __delay_ms(300); // Espera 300 milisegundos
                }
                break;
        }
    }
}

