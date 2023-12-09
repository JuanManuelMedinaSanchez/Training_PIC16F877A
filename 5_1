#include <xc.h>
#define _XTAL_FREQ  20000000

void init(){
       TRISBbits.TRISB1 = 0; // Configurar RB1 como pin de salida
   }
void turnOn(){
      PORTBbits.RB1 = 1;
}
void turnOff(){	
	 PORTBbits.RB1 = 0;
}
void main() {
init();
    while (1) {
	 turnOn();
        __delay_ms(100);
	 turnOff();
        __delay_ms(100);
    }
}
