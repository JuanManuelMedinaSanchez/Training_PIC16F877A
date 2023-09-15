#include <stdio.h>

// Macros for bit manipulation
#define SET_BIT(number, position) ((number) |= (1 << (position)))
#define CLEAR_BIT(number, position) ((number) &= ~(1 << (position)))
#define CHECK_BIT(number, position) (((number) & (1 << (position))) != 0)

int main() {
    unsigned int flags = 0; // Initialize flags variable with all bits set to 0

    // Set bit at position 2 (0-based index)
    SET_BIT(flags, 2);

    // Check if bit at position 2 is set
    if (CHECK_BIT(flags, 2)) {
        printf("Bit at position 2 is set.\n");
    } else {
        printf("Bit at position 2 is not set.\n");
    }

    // Clear bit at position 2
    CLEAR_BIT(flags, 2);

    // Check again if bit at position 2 is set
    if (CHECK_BIT(flags, 2)) {
        printf("Bit at position 2 is set.\n");
    } else {
        printf("Bit at position 2 is not set.\n");
    }

    return 0;
}
