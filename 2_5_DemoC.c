#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Para usleep

int main(void) {
    uint8_t PORTA = 0x00;
    while (1) {
        // Enciende el LED en RA0 (o configura el puerto adecuadamente según el microcontrolador)
        PORTA = 0xFF;
        printf("Led light ON\n"); // Agrega "\n" para una nueva línea
        usleep(100000); // Espera 1 segundo en el estado seguro
        PORTA = 0x00;
        printf("Led light OFF\n"); // Agrega "\n" para una nueva línea
        usleep(100000); // Espera 1 segundo en el estado seguro
    }
    return 0;
}
