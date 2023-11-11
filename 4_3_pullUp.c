
/* 
						OPTION_REG
BIT 7.
pull-up -> RB0/INT (NOT_RBPU = 0) y 
BIT 6.
RB0/INT (INTEDG = 0) -> falling edge of the signal
RB0/INT (INTEDG = 1) -> Rising edge of the signal

*/

#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000


void main(void) {
   //OPTION_REG = 0b00000000;
   TRISD  = 0x00;
   RD2 = 0;
    while (1) {
		if(RB0 == 0){
			RD2 = 1;
			__delay_ms(100);
			RD2 = 0;
		}
    }
}


