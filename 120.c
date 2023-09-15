#include <stdio.h>

// Macro for setting multiple bits
#define SET_BITS(number, mask) ((number) |= (mask))

int main() {
    unsigned int flags = 0; // Initialize flags variable with all bits set to 0

    // Set bits at positions 2 and 4 (0-based index)
    unsigned int bitMask = (1 << 2) | (1 << 4);
    SET_BITS(flags, bitMask);

    // Output the updated value of 'flags'
    printf("Updated flags: %u\n", flags);

    return 0;
}
