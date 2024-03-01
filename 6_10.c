//EEPROM pic16f877a
#include <xc.h>
#define _XTAL_FREQ 8000000

void main() {
    unsigned char data_to_write = 0xFF; // Datos que queremos escribir en la EEPROM
    unsigned char data_read; // Variable para almacenar los datos leídos de la EEPROM
    
    // Configuración de puertos
    TRISB = 0x00; // Configura el puerto B como salida para mostrar los resultados
    TRISA = 0xFF; // Configura el puerto A como entrada
    // Escribir en la EEPROM
    EEADR = 0x00; // Dirección en la EEPROM donde queremos escribir
    EEDATA = data_to_write; // Datos que queremos escribir
    EECON1bits.EEPGD = 0; // Seleccionar la EEPROM para escritura/lectura
    EECON1bits.WREN = 1; // Habilitar escritura en la EEPROM
    INTCONbits.GIE = 0; // Deshabilitar interrupciones durante la escritura
    EECON2 = 0x55; // Secuencia requerida para escritura en EEPROM
    EECON2 = 0xAA; // Secuencia requerida para escritura en EEPROM
    EECON1bits.WR = 1; // Iniciar el proceso de escritura
    INTCONbits.GIE = 1; // Habilitar interrupciones nuevamente
    EECON1bits.WREN = 0; // Deshabilitar escritura en la EEPROM
    
    // Leer de la EEPROM
    EEADR = 0x00; // Dirección en la EEPROM de donde queremos leer
    EECON1bits.EEPGD = 0; // Seleccionar la EEPROM para escritura/lectura
    EECON1bits.RD = 1; // Iniciar el proceso de lectura
    data_read = EEDATA; // Leer los datos de la EEPROM
    
    // Utilizar el resultado para cambiar el estado de los pines del puerto B
    PORTB = data_read;
    
    while(1) {
        // Bucle infinito
    }
}
