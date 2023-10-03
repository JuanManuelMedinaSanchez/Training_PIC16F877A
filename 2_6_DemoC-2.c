#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Para usleep

int main(void) {
    uint8_t PORTA = 0x01; // Comienza con el LSB encendido (1)
    int direction = 1; // Dirección inicial: izquierda a derecha

    while (1) {
        for (int i = 0; i < 7; i++) {
            PORTA = PORTA << 1; // Desplaza el "1" hacia la izquierda
            printf("Bit shifting %08b\n", PORTA);
            usleep(100000); // Espera 100,000 microsegundos (0.1 segundos)
        }

        for (int i = 0; i < 7; i++) {
            PORTA = PORTA >> 1; // Desplaza el "1" hacia la derecha
            printf("Bit shifting %08b\n", PORTA);
            usleep(100000); // Espera 100,000 microsegundos (0.1 segundos)
        }
    }

    return 0;
}
