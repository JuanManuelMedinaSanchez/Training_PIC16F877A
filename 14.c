#include <stdio.h>

int main() {
    // Integer Operations
    int a = 10, b = 5;
    int addition = a + b;        // Addition: 10 + 5 = 15
    int subtraction = a - b;     // Subtraction: 10 - 5 = 5
    int multiplication = a * b;  // Multiplication: 10 * 5 = 50
    int division = a / b;        // Division: 10 / 5 = 2
    int modulus = a % b;         // Modulus (Remainder): 10 % 5 = 0

    // Floating-Point Operations
    float x = 3.5, y = 2.0;
    float faddition = x + y;           // Float Addition: 3.5 + 2.0 = 5.5
    float fsubtraction = x - y;        // Float Subtraction: 3.5 - 2.0 = 1.5
    float fmultiplication = x * y;     // Float Multiplication: 3.5 * 2.0 = 7.0
    float fdivision = x / y;           // Float Division: 3.5 / 2.0 = 1.75

    // Comparison Operations
    int p = 8, q = 8;
    int isEqual = (p == q);            // Equality Comparison: 8 == 8 (True, 1)
    int isNotEqual = (p != q);         // Inequality Comparison: 8 != 8 (False, 0)
    int isGreaterThan = (p > q);       // Greater Than Comparison: 8 > 8 (False, 0)
    int isLessThan = (p < q);          // Less Than Comparison: 8 < 8 (False, 0)

    // Output with Explanations
    printf("Integer Operations:\n");
    printf("a + b = %d (Addition)\n", addition);
    printf("a - b = %d (Subtraction)\n", subtraction);
    printf("a * b = %d (Multiplication)\n", multiplication);
    printf("a / b = %d (Division)\n", division);
    printf("a %% b = %d (Modulus)\n", modulus);

    printf("\nFloating-Point Operations:\n");
    printf("x + y = %f (Float Addition)\n", faddition);
    printf("x - y = %f (Float Subtraction)\n", fsubtraction);
    printf("x * y = %f (Float Multiplication)\n", fmultiplication);
    printf("x / y = %f (Float Division)\n", fdivision);

    printf("\nComparison Operations:\n");
    printf("p == q: %d (Equality Comparison)\n", isEqual);
    printf("p != q: %d (Inequality Comparison)\n", isNotEqual);
    printf("p > q: %d (Greater Than Comparison)\n", isGreaterThan);
    printf("p < q: %d (Less Than Comparison)\n", isLessThan);

    return 0;
}

