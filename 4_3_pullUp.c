
 
// PIC16F877A Configuration Bit Settings
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
 
 #include <xc.h>
 #include <stdint.h>
#define _XTAL_FREQ 8000000
 
void rutina(void){    
		if(RB0 == 0){
			RD0 = 1;
			__delay_ms(100);
			RD0 = 0;
		}
}
   
void main(){
OPTION_REG = 0x80;
    PORTB=0x00;
    PORTD=0x00;
    TRISB=0xFF;
    TRISD=0x00;

while(1){
   rutina();
}
      }
