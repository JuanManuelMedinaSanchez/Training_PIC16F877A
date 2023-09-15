#include <stdio.h>

// Macro for setting a single bit
#define SET_BIT(number, position) ((number) |= (1 << (position)))

int main() {
    unsigned int flags = 0; // Initialize flags variable with all bits set to 0

    // Set bit at position 2 (0-based index)
    SET_BIT(flags, 2);

    // Output the updated value of 'flags'
    printf("Updated flags: %u\n", flags);

    return 0;
}
