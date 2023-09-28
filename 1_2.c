/*C script demos
Scripted by Juan Medina, mail to juansth@gmail.com Espacio en memoria segun tipo de datos
______________________________________________________________________________________
    //--->#include <limits.h> <---//
    printf("Espacio de char en bits: %d\n", CHAR_BIT);
    printf("Rango de int: %d a %d\n", INT_MIN, INT_MAX);
    printf("Rango de long: %ld a %ld\n", LONG_MIN, LONG_MAX);
    printf("Espacio de float en bytes: %lu\n", sizeof(float));
    printf("Espacio de double en bytes: %lu\n", sizeof(double));
    printf("Espacio de long double en bytes: %lu\n", sizeof(long double));
______________________________________________________________________________________*/

#include <stdio.h>

int main() {
    // Integer Data Types
    int integerVariable = 42;
    unsigned int unsignedIntegerVariable = 123;
    short shortVariable = 32767;
    unsigned short unsignedShortVariable = 65535;
    long longVariable = 2147483647;
    unsigned long unsignedLongVariable = 4294967295;
    long long longLongVariable = 9223372036854775807;
    unsigned long long unsignedLongLongVariable = 18446744073709551615;
  

    // Character Data Types
    char characterVariable = 'A';
    unsigned char unsignedCharVariable = 128;
    char miCadena[20] = "MUCs!"; 

    // Floating-Point Data Types
    float floatVariable = 3.14159;
    double doubleVariable = 2.71828;

    // Boolean Data Type
    _Bool booleanVariable = 1; // 1 represents true, 0 represents false

    // Enumerated Data Type
    enum Color { RED, GREEN, BLUE };
    enum Color colorVariable = BLUE;

    // Pointers and Addresses
    int *pointerToInt;
    char *pointerToChar;
    int variable = 100;
    pointerToInt = &variable;

    printf("Integer: %d\n", integerVariable);
    printf("Unsigned Integer: %u\n", unsignedIntegerVariable);
    printf("Short: %hd\n", shortVariable);
    printf("Unsigned Short: %hu\n", unsignedShortVariable);
    printf("Long: %ld\n", longVariable);
    printf("Unsigned Long: %lu\n", unsignedLongVariable);
    printf("Long Long: %lld\n", longLongVariable);
    printf("Unsigned Long Long: %llu\n", unsignedLongLongVariable);

    printf("Character: %c\n", characterVariable);
    printf("Unsigned Character: %u\n", unsignedCharVariable);
    printf("Salida: %s\n", miCadena);

    printf("Float: %f\n", floatVariable);
    printf("Double: %lf\n", doubleVariable);

    printf("Boolean: %d\n", booleanVariable);

    printf("Enum Color: %d\n", colorVariable);

    printf("Pointer to Int: %p\n", (void *)pointerToInt);

    return 0;
}
