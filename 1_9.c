#include <stdio.h>

int main() {
    unsigned int flags = 0b00000000; // Initialize flags variable with all bits set to 0

    // Set bit at position 2 (0-based index) to 1
    flags |= 0b00000100;  // Binary: 00000100

    // Output the updated value of 'flags' in binary format
    printf("Updated flags (after setting bit 2): %08b\n", flags);

    // Clear the same bit at position 2 (set it to 0)
    flags &= 0b11111011;  // Binary: 11111011

    // Output the updated value of 'flags' in binary format
    printf("Updated flags (after clearing bit 2): %08b\n", flags);

    // Toggle the same bit at position 2
    flags ^= 0b00000100;  // Binary: 00000100

    // Output the updated value of 'flags' in binary format
    printf("Updated flags (after toggling bit 2): %08b\n", flags);

    return 0;
}
