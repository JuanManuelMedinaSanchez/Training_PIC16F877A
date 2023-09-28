/*C script demos
Scripted by Juan Medina, mail to juansth@gmail.com/*
#include <stdio.h>

int main() {
    int intValue;
    float floatValue;
    char charValue;
    char stringValue[50]; // Assuming a maximum string length of 49 characters
    double doubleValue;

    // Input
    printf("Enter an integer: ");
    scanf("%d", &intValue);

    printf("Enter a floating-point number: ");
    scanf("%f", &floatValue);

    printf("Enter a character: ");
    scanf(" %c", &charValue); // Note the space before %c to skip whitespace

    printf("Enter a string (no spaces): ");
    scanf("%49s", stringValue); // Limit input to 49 characters to avoid buffer overflow

    printf("Enter a double-precision number: ");
    scanf("%lf", &doubleValue);

    // Output
    printf("\n----- Output -----\n");
    printf("Integer: %d\n", intValue);
    printf("Float: %f\n", floatValue);
    printf("Character: %c\n", charValue);
    printf("String: %s\n", stringValue);
    printf("Double: %lf\n", doubleValue);

    // Demonstrating different newline characters
    printf("\n----- Newline Formats -----\n");
    printf("This is a line with a standard newline.\n");

    printf("This is a line with a Windows-style newline (\\r\\n).\r\n");

    printf("This is a line with a Mac-style newline (\\r).\r");

    printf("This is a line with a Unix-style newline (\\n).\n");

    return 0;
}
