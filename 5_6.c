/*  Trabajo directo sobre registros para el PIC16F877A
TRISA = 0x85 (85h)  
PORTA = 0x5 (05h)
*/
#include <xc.h>
#include <stdint.h>

void main(void) {
    uint8_t *ptr0;
    uint8_t *ptr1;
    ptr0 = (uint8_t *)0x85;
   *ptr0 = 0x00;
    ptr1 = (uint8_t *)0x5;
   *ptr1 = 0x00;
    while (1) {
    }
    return;
}
