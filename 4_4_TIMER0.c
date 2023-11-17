
#include <xc.h>

#define _XTAL_FREQ 20000000  // Definir la frecuencia del cristal (20 MHz)
#define LED_PIN 1             // Definir el pin del LED como el pin RC1

char state = 0;               // Variable para el estado (no utilizada en este código)
int count = 0;                // Variable para contar el tiempo

void __interrupt() isr(void) {
    if (TMR0IF == 1) {          // Si se produce la interrupción de desbordamiento del temporizador 0
        TMR0 = 61;              // Cargar el valor de tiempo para un retardo de 100 milisegundos (256 - 195)
        TMR0IF = 0;             // Restablecer la bandera de desbordamiento
        count++;                // Incrementar el contador cada 100 milisegundos
    }
    return;
}

void __init_interrupt__() {
    // Configuración del registro INTCON
    GIE = 1;                    // Habilitar interrupciones globales
    PEIE = 1;                   // Habilitar interrupciones periféricas
    // Configuración del registro INTCON para Timer0
    TMR0IE = 1;                 // Habilitar la interrupción por desbordamiento de Timer0
    TMR0IF = 0;                 // Limpiar la bandera de interrupción por desbordamiento de Timer0
}

void __init_timer__() {
    // Configuración del registro OPTION_REG para Timer0
    T0CS = 0;                   // Seleccionar reloj de ciclo de instrucción interno (Fosc/4)
    PSA = 0;                    // Asignar el preescalador a Timer0
    PS2 = 1;                    // Configurar el preescalador a 1:128
    PS1 = 1;
    PS0 = 1;
    TMR0 = 61;                  // Cargar el valor de tiempo para un retardo de 100 milisegundos (256 - 195)
    T0IF = 0;                   // Limpiar la bandera de interrupción por desbordamiento de Timer0
}

void main(void) {
    TRISC &= ~(1 << LED_PIN);   // Configurar el LED_PIN como salida
    __init_interrupt__();       // Inicializar las configuraciones de interrupción
    __init_timer__();           // Inicializar las configuraciones del temporizador

    while (1) {
        if (count == 5) {        // Cada 500 milisegundos
            count = 0;
            PORTC ^= (1 << LED_PIN);  // Alternar el estado del LED
        }
    }
}

