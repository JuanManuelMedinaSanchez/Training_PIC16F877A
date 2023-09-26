#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
/* _________________________________________________________________________________________
uint8_t bit1= 0b0000;
uint8_t bit2= 0b0010;
---> uint8_t es un tipo de dato entero sin signo (unsigned integer) que se utiliza para representar numeros
enteros de 8 bits (1 byte) en C y C++. El nombre "uint8_t" proviene de la especificacion de tipos enteros 
definidos en C99 y posteriores, uint8_t garantiza la ocupancia exactamente 8 bits, sirve cuando se necesita 
un tamaño de datos específico y conocido, como en la programacion de microcontroladores o en la manipulación 
de datos binarios, manipulación de bits y conservacion de memoria. uint8_t es siempre sin signo,
lo que significa que solo puede representar números no negativos, desde 0 hasta 255 en el caso de 8 bits.
*/ _________________________________________________________________________________________

#include<stdio.h>

//Operaciones con numeros binarios, inclusion de caracteres tipo uint8_t y relacionados
int main() {
/*antes -> int bit1= 0b0000;
unsigned int bit2= 0b0010;*/
	//Implementacion de uint8_t
	uint8_t bit1= 0b0000;
	uint8_t bit2= 0b0010;
	unsigned boolOp;
	boolOp = bit1 & bit2;
	printf("resultado %04b", boolOp);
	return 0;
}
