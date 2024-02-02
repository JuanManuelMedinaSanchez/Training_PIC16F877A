/*PWM + TIMER0 */
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

unsigned char count = 0;
unsigned char pwm_enabled = 1; // Variable para controlar el estado del PWM

void __interrupt() isr(void) {
    if (TMR0IF == 1) {
        TMR0 = 100;  // Ajusta este valor para lograr el intervalo deseado
        TMR0IF = 0;  // Restablecer la bandera de desbordamiento del temporizador
        count++;     // Incrementar el contador
    }
}

void __init_interrupt__() {
    GIE = 1;     // Habilitar interrupciones globales
    PEIE = 1;    // Habilitar interrupciones periféricas
    TMR0IE = 1;  // Habilitar interrupción por desbordamiento del Timer0
    TMR0IF = 0;  // Limpiar la bandera de desbordamiento del Timer0
}

void __init_timer__() {
    T0CS = 0;   // Seleccionar el reloj de ciclo de instrucción interno (Fosc/4)
    PSA = 0;    // Asignar el preescalador al Timer0
    PS2 = 1;    // Configurar el preescalador a 1:128 PS1, 2 y 3. 
    PS1 = 0;
    PS0 = 0;
    TMR0 = 100; // Carga el valor inicial del temporizador
}

void PWM_Disable() {
    TRISCbits.TRISC2 = 0; // Set RC2 as output
    T2CONbits.TMR2ON = 0; // Set timer 2 off
    CCP1CONbits.CCP1M = 0; // Set PWM mode of operation
}

void PWM_Enable() {
    TRISCbits.TRISC2 = 0; // Set RC2 as output
    T2CONbits.TMR2ON = 1; // Set timer 2 on
    T2CONbits.T2CKPS = 0b10; // Set pre scalar of 16
    CCP1CONbits.CCP1M = 0b1100; // Set PWM mode of operation
}

void __set_pwm_freq(int f) {
    PWM_FREQ = f;
    PWM_PERIOD = 1.0 / PWM_FREQ; // Utiliza 1.0 para indicar que es un número de punto flotante
    int PR2_value = (int)((PWM_PERIOD * _XTAL_FREQ) / (4 * PRESCALAR) - 1); // Realiza un casting explícito a int
    PR2 = PR2_value;
}

void __set_duty_cycle(int duty_cycle) {
    float dc = (float)duty_cycle / 100; // Realiza un casting explícito a float
    float dc_period = dc * PWM_PERIOD; 
    int reg_value = (int)((dc_period * _XTAL_FREQ) / PRESCALAR);
    CCPR1L = reg_value >> 2; 
}

void main(void) {
    __set_pwm_freq(1000); // Configura la frecuencia a 1KHz
    __set_duty_cycle(50); // Configura el ciclo de trabajo al 50%
    __init_interrupt__(); // Inicializar interrupciones
    __init_timer__();     // Inicializar temporizador
    PWM_Enable();         // Habilitar PWM

    while(1) {
        if (count >= 100) { // Si ha transcurrido 1 segundo (100 * 10ms)
            if (pwm_enabled) {
                PWM_Disable(); // Deshabilitar el PWM
                pwm_enabled = 0;
            } else {
                PWM_Enable(); // Habilitar el PWM
                pwm_enabled = 1;
            }
            count = 0;     // Reiniciar contador
        }
    }
}

