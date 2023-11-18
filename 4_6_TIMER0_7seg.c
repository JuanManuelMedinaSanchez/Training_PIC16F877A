
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

void configureTimer0() {
    OPTION_REG = 0b11010111; // Configura Timer0 con un prescaler de 1:256
    TMR0 = 100;              // Carga el valor inicial para una interrupción de 1 ms
    INTCON = 0b10100000;     // Configura las interrupciones generales y Timer0
}

void displayNumber(uint8_t number) {
    // Configura Port B según el número a mostrar en el display de 7 segmentos
    switch (number) {
        case 1:
            PORTB = 0b00000110; // Display 1
            break;
        case 2:
            PORTB = 0b01011011; // Display 2
            break;
        case 3:
            PORTB = 0b01001111; // Display 3
            break;
        case 4:
            PORTB = 0b01100110; // Display 4
            break;
        case 5:
            PORTB = 0b01101101; // Display 5
            break;
        case 6:
            PORTB = 0b01111101; // Display 6
            break;
        case 7:
            PORTB = 0b00000111; // Display 7
            break;
        case 8:
            PORTB = 0b01111111; // Display 8
            break;
        default:
            PORTB = 0b00111111; // Display 0
            break;
    }
}

void __interrupt() isr(void) {
    if (T0IF) {
        T0IF = 0; // Limpia la bandera de desbordamiento de Timer0
        TMR0 = 10; // Recarga el valor inicial para una interrupción de 1 ms

        // Incrementa la variable para cambiar el número cada segundo
        static uint8_t currentNumber = 0;
       
        currentNumber = (currentNumber + 1 ) % 9 ; // Cambia del 1 al 8, luego vuelve a 1

        // Muestra el número en el display de 7 segmentos
        displayNumber(currentNumber);
    }
}

void main() {
    TRISB = 0x00; // Configura Port B como salidas para el display de 7 segmentos
    PORTB = 0x00; // Inicializa Port B a 0
          configureTimer0(); // Configura Timer0 para una interrupción de 1 ms
   
    while (1) {

    }
}
