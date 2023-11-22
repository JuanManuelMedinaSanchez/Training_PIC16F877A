
#include <xc.h>

#define _XTAL_FREQ  20000000
#define LED_PIN RD0

unsigned char count = 0;

void __interrupt() isr(void) {
    if (TMR0IF == 1) {
        TMR0 = 100;  // Ajusta este valor para lograr el intervalo deseado
        TMR0IF = 0;  // Restablecer la bandera de desbordamiento del temporizador
        count++;     // Incrementar el contador
    }
    return;
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
    T0IF = 0;   // Limpiar la bandera de desbordamiento del Timer0
}

void main(void) {
    TRISD = 0; // Configurar LED_PIN como salida
    __init_interrupt__();
    __init_timer__();

    while (1) {
        // Se ejecuta indefinidamente
        if (count >= 100) { // Intervalo deseado de 2 segundos (20 * 100 ms)
            count = 0;
            PORTD = !PORTD;
        }
    }
}
