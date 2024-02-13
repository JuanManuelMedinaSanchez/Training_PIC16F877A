#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 8000000 // Frecuencia de oscilador del microcontrolador

void I2C_init(uint32_t clock) {
    SSPADD = (_XTAL_FREQ / (4 * clock)) - 1;  // BR/clock speed
    SSPCON = 0b00101000;     // Modo maestro I2C, habilitar SDA y SCL
    SSPSTAT = 0;
    TRISC3 = 1; // SDA como entrada
    TRISC4 = 1; // SCL como entrada
}

void I2C_wait(void) {
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); // Esperar a que se despeje el bit de inicio en SSPSTAT y los bits 0 a 4 en SSPCON2
}

void I2C_start(void) {
    I2C_wait();
    SSPCON2bits.SEN = 1; // SEN=1 -> iniciar la condición de inicio en los pines SDA y SCL
}

void I2C_stop(void) {
    I2C_wait();
    SSPCON2bits.PEN = 1; // PEN=1 -> iniciar la condición de parada en los pines SDA y SCL
}

void I2C_write(uint8_t data) {
    I2C_wait();
    SSPBUF = data;  // Cargar datos en el registro SSPBUF
}

void main(void) {
    // Inicializar el módulo I2C
    I2C_init(100000); // Inicializar I2C @ 100 KHz

    while (1) {
        // Iniciar la comunicación I2C
        I2C_start();

        // Enviar la dirección del dispositivo esclavo (EEPROM) y el bit de escritura
        I2C_write(0xA0); // Dirección del dispositivo esclavo + bit de escritura
        I2C_write(0x01); // Escribir en el registro 0x01

        // Escribir datos en el EEPROM
        I2C_write('X'); // Escribir datos ('f') en el registro 0x01

        // Detener la comunicación I2C
        I2C_stop();

        // Esperar un tiempo antes de la próxima escritura
        __delay_ms(2000); // 2 segundos de delay
    }

    return;
}
