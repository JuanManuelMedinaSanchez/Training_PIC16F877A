#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Para usleep

int main(void) {
    uint8_t TRISA = 0x00;
    uint8_t PORTA = 0x00;
    uint8_t trafficState = 0; // Control de estado

    while (1) {
        switch (trafficState) {
            case 0: // Red
                PORTA = 0b00000001; // ON RA0 (Semaforo en rojo)
                printf("Semaforo en rojo\n");
                usleep(1000000); // Espera 1 segundo (en microsegundos)
                trafficState = 1; // Cambia al siguiente estado y rompe el switch
                break;

            case 1: // Green
                PORTA = 0b00000010; // ON RA1 (Amarillo)
                printf("Semaforo en amarillo\n");
                usleep(1000000); // Espera 1 segundo (en microsegundos)
                trafficState = 2; // Cambia al siguiente estado y rompe el switch
                break;

            case 2: // Yellow
                PORTA = 0b00000100; // ON RA2 (Verde)
                printf("Semaforo en verde\n");
                usleep(1000000); // Espera 1 segundo (en microsegundos)
                trafficState = 0; // Cambia al estado inicial 0 y rompe el switch
                break;

            default:
                /* La variable trafficState puede caer en un estado indeterminado que no es 0, 1 o 2.
                En este caso, debemos llevar las luces a un estado seguro: Todas las luces apagadas. */
                PORTA = 0x00; // Todas las luces apagadas (estado seguro)
                usleep(1000000); // Espera 1 segundo en el estado seguro
                trafficState = 0; // Vuelve al estado inicial
                break;
        }
    }

    return 0; // Indica que el programa se ejecutó sin errores
}
