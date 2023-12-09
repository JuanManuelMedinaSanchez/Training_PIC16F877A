#include <xc.h>
#define _XTAL_FREQ 20000000

// Estructura para la configuración de un LED
typedef struct {
    unsigned char pin;   // Número de pin del LED
    unsigned char state; // Estado actual del LED (encendido: 1, apagado: 0)
} LEDConfig;

void initLED(LEDConfig *led) {
    TRISCbits.TRISC1 = 0;  // Configura el pin RC1 como salida para el LED
    led->pin = 1;          // Asigna el número de pin del LED
    led->state = 0;        // Inicializa el estado del LED en apagado
}

void turnOnLED(LEDConfig *led) {
    if (led->pin == 1) {
        PORTCbits.RC1 = 1;  // Enciende el LED cambiando el estado del pin RC1
        led->state = 1;     // Actualiza el estado del LED
    }
}

void turnOffLED(LEDConfig *led) {
    if (led->pin == 1) {
        PORTCbits.RC1 = 0;  // Apaga el LED cambiando el estado del pin RC1
        led->state = 0;     // Actualiza el estado del LED
    }
}

void init() {
    TRISBbits.TRISB1 = 0; // Configurar RB1 como pin de salida
}

void turnOn() {
    PORTBbits.RB1 = 1;
}

void turnOff() {
    PORTBbits.RB1 = 0;
}

void main() {
    LEDConfig myLED;      // Instancia de la estructura para un LED
    initLED(&myLED);       // Llama a la función de inicialización del LED

    init();

    while (1) {
        // Tu código principal aquí
        turnOnLED(&myLED);  // Llama a la función para encender el LED
        __delay_ms(100);
        turnOffLED(&myLED); // Llama a la función para apagar el LED
        __delay_ms(100);
    }
}
