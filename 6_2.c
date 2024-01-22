#include <xc.h>
#define _XTAL_FREQ 20000000
#define Baud_rate 31250

void Initialize_UART(void) {
    // Configurar pines para UART
    TRISC6 = 0; // TX como salida
    TRISC7 = 1; // RX como entrada

    // Inicializar registro SPBRG para la velocidad de baudios y configurar BRGH
    SPBRG = ((_XTAL_FREQ/16)/Baud_rate) - 1;
    BRGH  = 0;  // Para velocidad de baudios baja (31250)

    // Habilitar puerto serial asíncrono
    SYNC  = 0;  // Asíncrono
    SPEN  = 1;  // Habilitar pines del puerto serial

    // Preparar para transmisión y recepción
    TXEN  = 1;  // Habilitar transmisión
    CREN  = 1;  // Habilitar recepción

    // Seleccionar modo de 8 bits
    TX9   = 0;  // Modo de recepción de 8 bits seleccionado
    RX9   = 0;  // Modo de recepción de 8 bits seleccionado
}

void UART_send_byte(char data) {
    while(!TXIF);  // Esperar hasta que el búfer TX esté libre
    TXREG = data;   // Cargar el búfer de transmisión con el valor recibido
}

void sendMIDIMessage(char status, char data1, char data2) {
    UART_send_byte(status);
    UART_send_byte(data1);
    UART_send_byte(data2);
}

void main(void) {
    Initialize_UART();

    while(1) {
        if(RB1 == 1) { // Si la tecla 1 está presionada
            sendMIDIMessage(0x90, 60, 64); // "Note On" en el canal 1, nota 60, velocidad 64
            __delay_ms(100); // Esperar 100 ms (ajusta según sea necesario)
            sendMIDIMessage(0x80, 60, 64); // "Note Off" en el canal 1, nota 60, velocidad 64
            while(RB1 == 1); // Esperar hasta que se libere la tecla 1
        }
    }
return;
 }
