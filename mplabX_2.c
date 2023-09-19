#pragma config FWDTEN = OFF // Compiler directive WDT=OFF stops PIC24 from automatic resets
/*-------------------------------------------------------------------------------
  HEADER FILES
-------------------------------------------------------------------------------*/
/* #include <xc.h> Include MPLAB library*/
#include <stdio.h>  // Standard I/O - required for printf() function

/*-------------------------------------------------------------------------------
  PROGRAM CONSTANTS
-------------------------------------------------------------------------------*/
#define CONSTANT1 0x33
const int CONSTANT2 = 0xCC;

/*-------------------------------------------------------------------------------
  VARIABLE DECLARATIONS
-------------------------------------------------------------------------------*/
int variable1 = CONSTANT1;
int variable2;

/*-------------------------------------------------------------------------------
  FUNCTION PROTOTYPES
-------------------------------------------------------------------------------*/
int main(void);

/*===============================================================================
  FUNCTION:     main()
  DESCRIPTION:  Prints out the value of the constants
  PARAMETERS:   none
  RETURNS:      nothing
===============================================================================*/
int main(void)
{
    /*-----------------------------------------------------------------------
      Initialize Variables
    -----------------------------------------------------------------------*/
    variable2 = CONSTANT2;

    /*-----------------------------------------------------------------------
      Print out storage size of each variable
    -----------------------------------------------------------------------*/
    printf("The first constant is 0x%X\n", CONSTANT1);
    printf("The second constant is 0x%X\n", CONSTANT2);

    /*-----------------------------------------------------------------------
      Loop Forever
    -----------------------------------------------------------------------*/
    while(1);
    return 0;  // Added return statement for completeness
}
