
/*_____________________________________________________________________________________________________________________________________*/    

/*
  -> OPTION_REG = 0b11010111;
// Detalles de la configuración
// Bit 7: RBPU (PortB Pull-Up Enable)
//        Habilita (0) o deshabilita (1) las resistencias pull-up internas en el puerto B
//        En este caso, están deshabilitadas.

// Bit 6: INTEDG (Interrupt Edge Select bit)
//        Este bit determina si la interrupción por cambio de nivel se activa en flanco de subida (0) o bajada (1).
//        En este caso, está configurado para flanco de bajada.

// Bits 5-3: T0CS, T0SE, PSA (Configuración de Timer0)
//        Estos bits configuran el Timer0. T0CS selecciona la fuente del reloj (0 para F_OSC/4, 1 para T0CKI).
//        T0SE elige el flanco del reloj (0 para flanco ascendente, 1 para flanco descendente).
//        PSA asigna el prescaler a Timer0 (0 para Timer0, 1 para Watchdog Timer).
//        En este caso, están configurados para usar F_OSC/4 como fuente de reloj y flanco descendente.
//        Además, el prescaler está asignado a Timer0.

// Bits 2-0: T0PS (Prescaler Rate Select bits para Timer0)
//        Configuran el divisor del prescaler para Timer0. En este caso, está configurado como 1:256.

// Nota: Esta configuración está específicamente ajustada para generar una interrupción cada 1 ms (aproximadamente) en un sistema con un oscilador de 20MHz.
   */
   
/*_____________________________________________________________________________________________________________________________________*/   

/*->INTCON 

// Bit 7: RBPU (PortB Pull-Up Enable)
// Habilita (0) o deshabilita (1) las resistencias pull-up internas en el puerto B
// En este caso, están deshabilitadas.

// Bit 6: INTEDG (Interrupt Edge Select bit)
// Este bit determina si la interrupción por cambio de nivel se activa en flanco de subida (0) o bajada (1).
// En este caso, está configurado para flanco de bajada.

// Bits 5-3: T0CS, T0SE, PSA (Configuración de Timer0)
// Estos bits configuran el Timer0. T0CS selecciona la fuente del reloj (0 para F_OSC/4, 1 para T0CKI).
// T0SE elige el flanco del reloj (0 para flanco ascendente, 1 para flanco descendente).
// PSA asigna el prescaler a Timer0 (0 para Timer0, 1 para Watchdog Timer).
// En este caso, están configurados para usar F_OSC/4 como fuente de reloj y flanco descendente.
// Además, el prescaler está asignado a Timer0.

En la configuración proporcionada, los bits 5-3 de OPTION_REG corresponden a tres configuraciones relacionadas con el Timer0:

T0CS (Bit 5 - TMR0 Clock Source Select bit):

Valor 0: Selecciona la fuente de reloj interna F_OSC/4 para el Timer0.
Valor 1: Selecciona el pin T0CKI como fuente de reloj para el Timer0.
T0SE (Bit 4 - TMR0 Source Edge Select bit):

Valor 0: Incrementa el contador del Timer0 en flanco de subida del reloj seleccionado.
Valor 1: Incrementa el contador del Timer0 en flanco de bajada del reloj seleccionado.
PSA (Bit 3 - Prescaler Assignment bit):

Valor 0: Asigna el prescaler al Timer0.
Valor 1: Asigna el prescaler al Watchdog Timer.


// Bits 2-0: T0PS (Prescaler Rate Select bits para Timer0)
// Configuran el divisor del prescaler para Timer0. En este caso, está configurado como 1:256.
*/

#include <xc.h>
#define _XTAL_FREQ 20000000 // Se asume una frecuencia de oscilador de 20MHz

void configureTimer0() {
    OPTION_REG = 0b11010111; // Configura Timer0 con un prescaler de 1:256
    TMR0 = 100;              // Carga el valor inicial para una interrupción de 1 ms
    INTCON = 0b10100000;     // Configura las interrupciones generales y Timer0
}

void __interrupt() isr(void) {
    if (T0IF) {
        T0IF = 0;              // Limpia la bandera de desbordamiento del Timer0
        TMR0 = 100;            // Recarga el valor inicial para una interrupción de 1 ms
        // Cambia el estado de RD0 (Suponiendo que RD0 está conectado a un LED)
        RD0 = !RD0;
    }
}

void main() {
    TRISD0 = 0;               // Establece RD0 como salida
    configureTimer0();        // Configura Timer0 para una interrupción de 1 ms

    while(1) {
        // Tu código principal aquí
    }
}

