#include <xc.h>                    // Processor specific header file
#include <stdio.h>              // Standard I/O - required for printf() function

int main(void)
{
    /*-----------------------------------------------------------------------
      Print out various data types with different format settings
    -----------------------------------------------------------------------*/
    printf("25 as decimal (d): %d\n", 25);                   // %d = decimal int
    printf("'a' as character (c): %c\n", 'a');               // %c = character
    printf("'a' as decimal (d): %d\n", 'a');                 // %d = decimal int
    printf("2.55 as float (f): %f\n", 2.55);                 // %f = float
    printf("2.55 as decimal (d): %d\n", (int)2.55);         // %d = decimal int
    printf("6.02e23 as exponent (e): %e\n", 6.02e23);        // %e = float exp
    printf("6.02e23 as decimal (d): %f\n", 6.02e23);         // %f = decimal float
    printf("'Microchip' as string (s): %s\n", "Microchip");  // %s = string
    printf("'Microchip' as decimal (d): %s\n", "Microchip"); // %s = string

    /*-----------------------------------------------------------------------
      Loop Forever
    -----------------------------------------------------------------------*/
    while(1);
}
