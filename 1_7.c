/*C script demos
Scripted by Juan Medina, mail to juansth@gmail.com/*
#include <stdio.h>

int main() {
    // Bitwise Shift Operations
    unsigned int originalValue = 0b1100; // Binary: 1100 (12 in decimal)

    // Left Shift (<<) - Shifting left by 2 positions
    unsigned int leftShiftedValue = originalValue << 2; // Binary: 110000 (48 in decimal)

    // Right Shift (>>) - Shifting right by 1 position
    unsigned int rightShiftedValue = originalValue >> 1; // Binary: 0110 (6 in decimal)

    // Output with Explanations
    printf("Original Value: %u (Binary: %04b)\n", originalValue, originalValue);
    printf("Left Shifted by 2: %u (Binary: %08b)\n", leftShiftedValue, leftShiftedValue);
    printf("Right Shifted by 1: %u (Binary: %04b)\n", rightShiftedValue, rightShiftedValue);

    return 0;
}
