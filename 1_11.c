#include <stdio.h>

int main() {
    unsigned int value = 0b1100;  // Binary: 1100

    printf("Original Value: %08b\n", value);

    // Toggle the bits using ^=
    value ^= 0xFFFF;  // Invert all bits to toggle

    printf("Toggled Value: %08b\n", value);

    return 0;
}

