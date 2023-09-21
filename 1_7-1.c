#include <stdio.h>
#include <stdbool.h>


#include<stdio.h>

//Operaciones con numeros binarios, inclusion de caracteres tipo uint8_t y relacionados
int main() {
	unsigned char bit1= 0b0001;
	unsigned char bit2= 0b0001;
	unsigned boolOp= 0;
	boolOp = bit1 && bit2;
	printf("resultado %08b", boolOp);
	return 0;
}
