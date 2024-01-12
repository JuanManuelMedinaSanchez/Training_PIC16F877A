#include <xc.h>

// Definición de la estructura para representar los pines GPIO
struct GPIO {
    unsigned char pin0 : 1;
    unsigned char pin1 : 1;
    unsigned char pin2 : 1;
    unsigned char pin3 : 1;
    unsigned char pin4 : 1;
    unsigned char pin5 : 1;
    unsigned char pin6 : 1;
    unsigned char pin7 : 1;
};

void configurarPuertoB(struct GPIO *puertoB) {
    // Configurar todos los pines del puerto B como salidas
    TRISB = 0x00;

    // Asignar el estado de los pines del puerto B a través de la estructura
    PORTB = (puertoB->pin7 << 7) | (puertoB->pin6 << 6) | (puertoB->pin5 << 5) |
            (puertoB->pin4 << 4) | (puertoB->pin3 << 3) | (puertoB->pin2 << 2) |
            (puertoB->pin1 << 1) | (puertoB->pin0 << 0);
}

int main() {
    // Declaración e inicialización de una estructura para representar los pines GPIO
    struct GPIO puertoB = {{0}}; // Inicialización con todos los bits en 0

    // Establecer el estado del pin3 en alto a través del operador ->
    puertoB.pin3 = 1;

    // Configurar y actualizar el puerto B con el nuevo estado de los pines
    configurarPuertoB(&puertoB);

    while (1) {
        // Tu código principal aquí
    }

    return 0;
}
