#include <xc.h>
#include <stdint.h>

#define LED_PIN RB1     // Asigna el pin del LED al puerto B, pin 1
#define _XTAL_FREQ 4000000 //
// Definición de la estructura para representar la configuración de un pin del MCU
struct PinConfig {
    uint8_t pinNumber;  // Número del pin del MCU
    uint8_t state;      // Estado del pin (encendido: 1, apagado: 0)
};

// Configuración específica para el PIC16F877A y MPLAB X IDE con XC8

// Función para inicializar la configuración de un pin
void initPin(struct PinConfig *pin) {
    // Configuración específica para el PIC16F877A
    TRISB &= ~(1 << pin->pinNumber); // Configura el pin como salida
    pin->state = 0;
}

// Función para cambiar el estado del pin a encendido
void turnOnPin(struct PinConfig *pin) {
    // Configuración específica para el PIC16F877A
    PORTB |= (1 << pin->pinNumber); // Establece el pin en alto (encendido)
    pin->state = 1;
}

// Función para cambiar el estado del pin a apagado
void turnOffPin(struct PinConfig *pin) {
    // Configuración específica para el PIC16F877A
    PORTB &= ~(1 << pin->pinNumber); // Establece el pin en bajo (apagado)
    pin->state = 0;
}

int main(void) {
    // Configuración del pin para un LED
    struct PinConfig myLEDPin;
    myLEDPin.pinNumber = 1; // RB1 en el PIC16F877A

    // Inicializa la configuración del pin
    initPin(&myLEDPin);

    while (1) {
        // Tu código principal aquí
        turnOnPin(&myLEDPin);   // Enciende el LED
        __delay_ms(500); // Pausa de 500 ms
        turnOffPin(&myLEDPin);  // Apaga el LED
        __delay_ms(500); // Pausa de 500 ms
    }

    return 0;
}
