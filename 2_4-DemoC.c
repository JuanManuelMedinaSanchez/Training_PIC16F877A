#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Para usleep

int main(void) {
    uint8_t PORTA = 0x00;
    uint8_t trafficState;

    while (1) {
        for (trafficState = 0; trafficState < 3; trafficState++) {
            if (trafficState == 0) { // Red
                PORTA = 0b00000001; // ON RA0 (Semaforo en rojo)
                printf("Semaforo en Rojo\n");
                usleep(100000); // Espera
            } else if (trafficState == 1) { // Green
                PORTA = 0b00000010; // ON RA1 (Amarillo)
                printf("Semaforo en Amarillo\n");
                usleep(100000); // Espera
            } else if (trafficState == 2) { // Yellow
                PORTA = 0b00000100; // ON RA2 (Verde)
                printf("Semaforo en Verde\n");
                usleep(100000); // Espera
            }
        }

        // All lights off (safe state)
        PORTA = 0x00;
        printf("Luminaria OFF\n");
        usleep(100000); // Espera 1 segundo en el estado seguro
    }

    return 0;
}
