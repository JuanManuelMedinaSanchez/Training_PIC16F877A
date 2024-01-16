// CONFIG
#pragma config FOSC = HS       
#pragma config WDTE = OFF      
#pragma config PWRTE = OFF      
#pragma config BOREN = OFF     
#pragma config LVP = OFF       
#pragma config CPD = OFF      
#pragma config WRT = OFF     
#pragma config CP = OFF      
#include <xc.h>
#define _XTAL_FREQ 20000000
#define Baud_rate 9600

// Function to initialize the UART module
void Initialize_UART(void) {
    // Setting I/O pins for UART
    TRISC6 = 0; // TX Pin set as output
    TRISC7 = 1; // RX Pin set as input

    // Initialize SPBRG register for the required baud rate and set BRGH for fast baud_rate
    SPBRG = ((_XTAL_FREQ/16)/Baud_rate) - 1;
    BRGH  = 1;  // for high baud_rate

    // Enable Asynchronous serial port
    SYNC  = 0;  // Asynchronous
    SPEN  = 1;  // Enable serial port pins

    // Prepare for transmission & reception
    TXEN  = 1;  // Enable transmission
    CREN  = 1;  // Enable reception

    // Select 8-bit mode
    TX9   = 0;  // 8-bit reception selected
    RX9   = 0;  // 8-bit reception mode selected
}

// Function to send one byte of data to UART
void UART_send_char(char bt) {
    while(!TXIF);  // Hold the program until TX buffer is free
    TXREG = bt;     // Load the transmitter buffer with the received value
}

// Function to get one byte of data from UART
char UART_get_char() {
    if(OERR) {  // Check for Error
        CREN = 0; // If error -> Reset
        CREN = 1; // If error -> Reset
    }

    while(!RCIF);  // Hold the program until RX buffer is free
    return RCREG;  // Receive the value and send it to the main function
}

// Function to convert string to byte
void UART_send_string(const char* st_pt) {
    while(*st_pt) // If there is a char
        UART_send_char(*st_pt++); // Process it as a byte data
}

// Main Function
void main(void) {
    int get_value;

    TRISB = 0x00; // Initialize PortB as output
    Initialize_UART(); // Initialize UART module

    UART_send_string("UART Module Initialized and active"); // Introductory Text

    while(1) { // Infinite loop
        get_value = UART_get_char();

        if (get_value == '1') { // If the user sends "1"
            RB3 = 1; // Turn on LED
            UART_send_string("RED LED -> ON"); // Send notification to the computer
            UART_send_char(10);
	}
     }
  }
