#include <stdio.h>

// Definición de la estructura PixelRGB
struct PixelRGB {
    int rojo;
    int verde;
    int azul;
};

int main() {
    // Declaración de una variable de tipo PixelRGB y un puntero a PixelRGB
    struct PixelRGB pixel, *punteroPixel;

    // Asignación de valores a los miembros de la estructura usando el operador -> a través del puntero
    punteroPixel = &pixel;
    punteroPixel->rojo = 255;
    punteroPixel->verde = 128;
    punteroPixel->azul = 0;

    // Mostrar en pantalla los valores de los miembros usando el operador ->
    printf("Color RGB: R=%d, G=%d, B=%d\n", punteroPixel->rojo, punteroPixel->verde, punteroPixel->azul);

    return 0;
}
