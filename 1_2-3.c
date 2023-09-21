#include <stdio.h>
#include <stdbool.h>

int main() {
    int booleanVariable = false; // Usamos un entero para representar valores booleanos (0 para false, 1 para true)

    printf("Ingresa el valor correspondiente (0 para false, 1 para true): ");
    scanf("%d", &booleanVariable);

    printf("Boolean: %d\n", booleanVariable);

    return 0;
}
