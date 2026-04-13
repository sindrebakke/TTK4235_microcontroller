#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

#include "gpio.h"
#include "uart.h"


#define UART_RX_PIN 8
#define UART_TX_PIN 6

#define Baud9600 0x00275000
#define DISCONNECTED 0xFFFFFFFF

void uart_init() {
    GPIO->PIN_CNF[UART_TX_PIN] = 1;
    GPIO->PIN_CNF[UART_RX_PIN] = 0;

    UART->PSELTXD = UART_TX_PIN;
    UART->PSELRXD = UART_RX_PIN;

    UART->BAUDRATE = Baud9600;

    UART->PSELRTS = DISCONNECTED;
    UART->PSELCTS = DISCONNECTED;

    UART->ENABLE = 8;
    UART->TASKS_STARTTX = 1;
}

void uart_send(char letter){
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;
    while (!UART->EVENTS_TXDRDY){
    }
    UART->TASKS_STOPTX = 1;
    UART->TASKS_STARTTX = 0;
    UART->EVENTS_TXDRDY = 0;
}

char uart_read(){
    UART->TASKS_STARTRX = 1;
    if (UART->EVENTS_RXDRDY != 0) {
        UART->EVENTS_RXDRDY = 0;
        char letter = UART->RXD;
        return letter;
    } else {
        return '\0';
    }
}

// Redirect printf to UART
ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}