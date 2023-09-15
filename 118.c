#include <stdio.h>

int main() {
    unsigned int flags = 0; // Initialize flags variable with all bits set to 0

    // Set bit at position 2 (0-based index)
    flags |= (1 << 2);

    // Check if bit at position 2 is set
    if ((flags & (1 << 2)) != 0) {
        printf("Bit at position 2 is set.\n");
    } else {
        printf("Bit at position 2 is not set.\n");
    }

    // Clear bit at position 2
    flags &= ~(1 << 2);

    // Check again if bit at position 2 is set
    if ((flags & (1 << 2)) != 0) {
        printf("Bit at position 2 is set.\n");
    } else {
        printf("Bit at position 2 is not set.\n");
    }

    return 0;
}

