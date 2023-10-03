/*_______________________________________________________________________________________
  Implementacion 7 segmentos, conteo ciclo de 0 a 9, Logica positiva.
_______________________________________________________________________________________*/
#include <xc.h>
#define _XTAL_FREQ 800000

void main() {
    // Configurar el puerto B como salida
    TRISB = 0x00;
    unsigned char number;

    while (1) {
        for (number = 0; number <= 9; number++) {
            switch (number) {
                case 0:
                    PORTB = 0b00111111; // Patrón para el número 0
                    break;
                case 1:
                    PORTB = 0b00000110; // Patrón para el número 1
                    break;
                case 2:
                    PORTB = 0b01011011; // Patrón para el número 2
                    break;
                case 3:
                    PORTB = 0b01001111; // Patrón para el número 3
                    break;
                case 4:
                    PORTB = 0b01100110; // Patrón para el número 4
                    break;
                case 5:
                    PORTB = 0b01101101; // Patrón para el número 5
                    break;
                case 6:
                    PORTB = 0b01111101; // Patrón para el número 6
                    break;
                case 7:
                    PORTB = 0b00000111; // Patrón para el número 7
                    break;
                case 8:
                    PORTB = 0b01111111; // Patrón para el número 8
                    break;
                case 9:
                    PORTB = 0b01101111; // Patrón para el número 9
                    break;
                default:
                    PORTB = 0x00; // Apagar todos los segmentos si no se reconoce el número
                    break;
            }

            __delay_ms(1000); // Esperar 1 segundo (ajustar el tiempo según sea necesario)
        }
    }
}
