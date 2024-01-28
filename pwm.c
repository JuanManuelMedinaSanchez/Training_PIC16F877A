   #pragma config FOSC = HS       
   #pragma config WDTE = OFF      
   #pragma config PWRTE = OFF      
   #pragma config BOREN = OFF     
   #pragma config LVP = OFF       
   #pragma config CPD = OFF      
   #pragma config WRT = OFF     
   #pragma config CP = OFF      
   #include <xc.h>
   #define _XTAL_FREQ 20000000

   int main() {
       char dutyCycle = 0;

       TRISC = 0x00;   // Configure PORTC as output(RC2-PWM1, RC1-PWM2)

       CCP1CON = 0x0F; // Select the PWM mode.
       PR2 = 100;      // Set the Cycle time to 100 for varying the duty cycle from 0-100
       CCPR1L = 50;    // By default set the dutyCycle to 50
       TMR2ON = 1;     //Start the Timer for PWM generation


       while (1) {
	   for (dutyCycle = 0; dutyCycle < 100; dutyCycle++) // Keep increasing the dutyCyle to increase the brightness of LED
	   {
	       CCPR1L = dutyCycle;
	       __delay_ms(10);
	   }

	   for (dutyCycle = 100; dutyCycle > 0; dutyCycle--) // Keep reducing the dutyCyle to decrease the brightness of LED
	   {
	       CCPR1L = dutyCycle;
			  __delay_ms(10);
	   }
       }
   }
