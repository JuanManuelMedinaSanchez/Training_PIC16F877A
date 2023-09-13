#include <stdio.h>

// Function declarations
int add(int a, int b);

int main() {
    // Variable declarations and initialization
    int operand1 = 10;
    int operand2 = 5;
    int result;

    // Calculate the sum using the 'add' function
    result = add(operand1, operand2);

    // Output the result
    printf("The sum of %d and %d is: %d\n", operand1, operand2, result);

    return 0; // Return 0 to indicate successful execution
}

// Function definition for addition
int add(int a, int b) {
    // Perform addition
    int sum = a + b;
    return sum;
}
