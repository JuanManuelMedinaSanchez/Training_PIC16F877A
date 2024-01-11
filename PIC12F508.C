/* 
******PIC12F508********
Blink one led demo. 
*/
#pragma config OSC = IntRC 
#pragma config WDT = OFF 
#pragma config CP = OFF 
#pragma config MCLRE = OFF
#include <xc.h>
#define _XTAL_FREQ  4000000

 void blinkLED (){
GP0 = 1;			
  __delay_ms (500);	
  GP0 = 0;			
  __delay_ms (500);		
} 
 
void main (void){
TRISGPIO = 0 b11000000;
while (1)
    {
        blinkLED ();
    }
return;
}

