
#pragma config FOSC = HS       
#pragma config WDTE = OFF      
#pragma config PWRTE = OFF      
#pragma config BOREN = OFF     
#pragma config LVP = OFF       
#pragma config CPD = OFF      
#pragma config WRT = OFF     
#pragma config CP = OFF     
#include <xc.h>
#define _XTAL_FREQ 16000000
#define PRESCALAR 16

float PWM_FREQ;
float PWM_PERIOD;
int counter;

void __set_pwm_freq(int f) {
    PWM_FREQ = f;
    PWM_PERIOD = 1.0 / PWM_FREQ; // Utiliza 1.0 para indicar que es un número de punto flotante
    int PR2_value = (int)((PWM_PERIOD * _XTAL_FREQ) / (4 * PRESCALAR) - 1); // Realiza un casting explícito a int
    PR2 = PR2_value;
}

void __init_pwm() {
    TRISCbits.TRISC2 = 0; // Set RC2 as output
    T2CONbits.TMR2ON = 1; // Set timer 2 on
    T2CONbits.T2CKPS = 0b10; // Set pre scalar of 16
    CCP1CONbits.CCP1M = 0b1100; // Set PWM mode of operation
}

void __set_duty_cycle(int duty_cycle) {
    float dc = (float)duty_cycle / 100; // Realiza un casting explícito a float
    float dc_period = dc * PWM_PERIOD; 
    int reg_value = (int)((dc_period * _XTAL_FREQ) / PRESCALAR);
    CCPR1L = reg_value >> 2; 

}

void main(void) {
    __set_pwm_freq(1000); // Configura la frecuencia a 1KHz
    __init_pwm();
    __set_duty_cycle(0);
    
    // Continuamente incrementa y disminuye el brillo del LED
    while(1) {
        __set_duty_cycle(50);
    }
}
