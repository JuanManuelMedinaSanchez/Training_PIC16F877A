#include <stdio.h>

// Definición de la estructura OperacionAND
struct OperacionAND {
    int bin1;
    int bin2;
};

// Declaración de la función sin retorno (void)
void mostrarOperacionAND(struct OperacionAND operacion);

int main() {
    // Declaración de una variable de tipo OperacionAND
    struct OperacionAND miOperacion;

    // Asignación de valores a los miembros de la estructura
    miOperacion.bin1 = 1;
    miOperacion.bin2 = 0;

    // Llamada a la función con la estructura como parámetro
    mostrarOperacionAND(miOperacion);

    return 0;
}

// Definición de la función mostrarOperacionAND
void mostrarOperacionAND(struct OperacionAND operacion) {
    // Calcular la operación AND de bin1 y bin2
    int resultado = operacion.bin1 & operacion.bin2;

    // Mostrar en pantalla el resultado de la operación AND
    printf("El resultado de la operación AND entre %d y %d es: %d\n", operacion.bin1, operacion.bin2, resultado);
