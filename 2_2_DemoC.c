#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Para usleep

void main() {
    uint8_t PORTA = 0x00;
    uint8_t ledState = 0x00;
    while (1) {
        if (ledState == 0x00) {
            PORTA = 0xFF; // Enciende todas las salidas del puerto B.
            ledState = 0xFF; // Actualización del estado "ledState" a ON.
            printf("LED ON\n"); // Agrega "\n" para una nueva línea
            usleep(500000); 
        } else {
            PORTA = 0x00; // Apaga todas las salidas del puerto B.
            ledState = 0x00; // Actualización del estado "ledState" a OFF.
            printf("LED OFF\n"); // Agrega "\n" para una nueva línea
            usleep(500000); 
        }
    }
}
