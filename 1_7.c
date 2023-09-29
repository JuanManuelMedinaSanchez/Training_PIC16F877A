/*C script demos
Scripted by Juan Medina, mail to juansth@gmail.com*/

#include <stdio.h>
#include <stdint.h>

int
main ()
{
  uint8_t bandera = 0b1100;
  uint8_t leftShiftedValue = bandera << 2;
  uint8_t rightShiftedValue = bandera >> 2;
  printf ("original Binary: %08b\n", bandera);
  printf ("Left shift Binary: %08b\n", leftShiftedValue);
  printf ("Right Shifted Binary: %08b\n", rightShiftedValue);
  return 0;
}
