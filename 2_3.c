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
                trafficState = 0; //  // Switch al siguiente estado inicial 0 y break
                break;
        }
    }
}
