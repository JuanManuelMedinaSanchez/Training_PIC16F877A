#include <stdio.h>
#include <stdbool.h>
/* _________________________________________________________________________________________
uint8_t bit1= 0b0000;
uint8_t bit2= 0b0010;
*/ _________________________________________________________________________________________

#include<stdio.h>

//Operaciones con numeros binarios, inclusion de caracteres tipo uint8_t y relacionados
int main() {
	unsigned int bit1= 0b0000;
	unsigned int bit2= 0b0010;
	unsigned boolOp;
	boolOp = bit1 & bit2;
	printf("resultado %04b", boolOp);
	return 0;
}
