#include <stdio.h>

int main() {
    
    unsigned char value = 0b0000;  // Binary: 1100

    printf("Original Value: %08b\n", value);

    // Toggle the bits using ^=
    value ^= 0xFFFF;  // Invert all bits to toggle

    printf("Toggled Value:  %04b\n", value);

    return 0;
}
