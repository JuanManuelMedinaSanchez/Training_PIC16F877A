#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Para usleep

int main(void) {
    uint8_t PORTA = 0x00;
       while (1) {
        // Parpadeo rápido de los LEDs del bit 0 al 3
        int i = 0;
        while (i < 4) {
            PORTA = 1 << i; // Enciende el LED correspondiente
            printf("Bit shifting %08b\n", PORTA);
            usleep(100000); // Espera 1 segundo en el estado seguro
            PORTA = 0x00; // Apaga todos los LEDs
            usleep(100000); // Espera 1 segundo en el estado seguro
            i++;
        }
        // Parpadeo lento de los LEDs del bit 4 al 7
        int j = 4;
        while (j < 8) {
            PORTA = 1 << j; // Enciende el LED correspondiente
            printf("Bit shifting %08b\n", PORTA);
            usleep(100000); // Espera 1 segundo en el estado seguro
            PORTA = 0x00; // Apaga todos los LEDs
            usleep(100000); // Espera 1 segundo en el estado seguro
            j++;
        }
    }
}

