/*C script demos
Scripted by Juan Medina, mail to juansth@gmail.com*/

#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t originalValue = 0b1100; 
    uint8_t leftShiftedValue = originalValue << 2; 
    uint8_t rightShiftedValue = originalValue >> 2;

    // Output with Explanations
    printf("Original Value: %u (Binary: %08b)\n", originalValue, originalValue);
    printf("Left Shifted by 2: %u (Binary:%08b)\n", leftShiftedValue, leftShiftedValue);
    printf("Right Shifted by 1: %u (Binary: %08b)\n", rightShiftedValue, rightShiftedValue);
    return 0;
}
