#include <stdint.h>

#include "gpio.h"
#include "uart.h"


#define UART_RX_PIN 8
#define UART_TX_PIN 6

#define Baud9600 0x00275000
#define DISCONNECTED 0xFFFFFFFF

void uart_init() {

    GPIO->PIN_CNF[UART_TX_PIN] = (0 << 1);
    GPIO->PIN_CNF[UART_RX_PIN] = (0 << 1);

    UART->PSELTXD = UART_TX_PIN;
    UART->PSELRXD = UART_RX_PIN;

    UART->PSELCTS = DISCONNECTED;
    UART->PSELRTS = DISCONNECTED;

    UART->BAUDRATE = Baud9600;

    UART->ENABLE = 8;
    UART->TASKS_STARTRX = 1;
}

void uart_send(char letter){
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;

    while (!UART->EVENTS_TXDRDY){

    }
    UART->TASKS_STOPTX = 1;
    UART->EVENTS_TXDRDY = 0;
}

char uart_read(){

    UART->TASKS_STARTRX = 1;

    if (UART->EVENTS_RXDRDY){
        UART->EVENTS_RXDRDY = 0;
        return UART->RXD;
    }
    else{
        return '\0';
    };
}

// Redirect printf to UART
int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        uart_send(ptr[i]);
    }
    return len;
}