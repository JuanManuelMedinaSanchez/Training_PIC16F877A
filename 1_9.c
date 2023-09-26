#include <stdio.h>

int main() {
    unsigned int flags = 0b00000000; // Incio de Flag en 0

    // Posicion 2 (0-based index) a 1
    flags |= 0b00000100;  // Binary: 00000100

    // Salida
    printf("Updated flags (after setting bit 2): %08b\n", flags);

    // Borrar el bit en la misma posicion
    flags &= 0b11111011;  // Binary: 11111011

    // Salida del Flag
    printf("Updated flags (after clearing bit 2): %08b\n", flags);

    // Toggle
    flags ^= 0b00000100;  // Binary: 00000100

    // Actualizacion del valor en sistema binario
    printf("Updated flags (after toggling bit 2): %08b\n", flags);

    return 0;
}
