   #pragma config OSC = IntRC 
   #pragma config WDT = OFF 
   #pragma config CP = OFF 
   #pragma config MCLRE = OFF
   #include <xc.h>
   #define _XTAL_FREQ  4000000

   void blinkLED() {
	 GP0 = 1;     // Turn on the LED
       __delay_ms(500);   // Wait for a while (adjust as needed)
	 GP0 = 0;         // Turn off the LED
       __delay_ms(500);   // Wait for a while
      
     
   }

   void main(void) {
TRISGPIO   = 0b11000000;
 GPIO = 0x00000000;

       while (1) {
	   blinkLED();
       }
   }



