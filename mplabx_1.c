#pragma config FWDTEN = OFF // Compiler directive WDT=OFF stops PIC24 from automatic resets
#include <xc.h>  
#include <stdio.h>
      

#define CONSTANT1 50

int main() {
    /*-----------------------------------------------------------------------
    VARIABLE DECLARATIONS
    -----------------------------------------------------------------------*/
    char charVariable;
    double doubleVariable;
    float floatVariable;
    int intVariable;
    long longVariable;      // Same as "long int"
    short shortVariable;    // Same as "short int"

    /*-----------------------------------------------------------------------
    Initialize Variables
    -----------------------------------------------------------------------*/
    charVariable = CONSTANT1;
    doubleVariable = CONSTANT1;
    floatVariable = CONSTANT1;
    intVariable = CONSTANT1;
    longVariable = CONSTANT1;
    shortVariable = CONSTANT1;

    /*-----------------------------------------------------------------------
    Print out storage size of each variable
    -----------------------------------------------------------------------*/
    printf("A character variable requires %lu byte\n", sizeof(char));
    printf("A short variable requires %lu bytes\n", sizeof(short));
    printf("An integer variable requires %lu bytes\n", sizeof(int));
    printf("A long variable requires %lu bytes\n", sizeof(long));
    printf("A floating-point variable requires %lu bytes\n", sizeof(float));
    printf("A double variable requires %lu bytes\n", sizeof(double));

    /*-----------------------------------------------------------------------
    Loop Forever
    -----------------------------------------------------------------------*/
    while (1);

}
