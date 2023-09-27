/*_______________________________________________________________
					     ***Funcion If anidada****
->XC8 compiler
->PIC16f877a
_______________________________________________________________
*/
#define _XTAL_FREQ 800000
#include <xc.h>

void main() {
    TRISB= 0x00; //ESTADO DE PORTB como salidas
    unsigned char ledState = 0x00; // Control del estado de arreglo LED.

    while (1) {
        if (ledState == 0x00) {
            PORTB = 0xFF; // ON todos las salidas del puerto B.
            ledState = 0xFF; // Actualizacion del estado "ledState" ON.
        } else {
            PORTB= 0x00; // ON todos las salidas del puerto B.
            ledState = 0x00; //  Actualizacion del estado "ledState" OFF.
        }
        __delay_ms(500); // Delay for 500 milliseconds (0.5 seconds)
    }
}
