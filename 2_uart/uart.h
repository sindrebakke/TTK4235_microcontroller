#include <stdint.h>

void uart_init();
void uart_send(char letter);
char uart_read();

#define UART ((NRF_UART_REG*) 0x40002000)

typedef struct {
    volatile uint32_t TASKS_STARTRX;     // 0x000 Start UART receiver
    volatile uint32_t TASKS_STOPRX;      // 0x004 Stop UART receiver
    volatile uint32_t TASKS_STARTTX;     // 0x008 Start UART transmitter
    volatile uint32_t TASKS_STOPTX;      // 0x00C Stop UART transmitter

    volatile uint32_t RESERVED0[3];
    volatile uint32_t TASKS_SUSPEND;     // 0x01C Suspend UART
    volatile uint32_t RESERVED1[56];
    volatile uint32_t EVENTS_CTS;        // 0x100 CTS is activated (set low). Clear To Send.
    volatile uint32_t EVENTS_NCTS;       // 0x104 CTS is deactivated (set high). Not Clear To Send.
    volatile uint32_t EVENTS_RXDRDY;     // 0x108 Data received in RXD

    volatile uint32_t RESERVED2[4];
    volatile uint32_t EVENTS_TXDRDY;     // 0x11C Data sent from TXD

    volatile uint32_t RESERVED3[1];
    volatile uint32_t EVENTS_ERROR;      // 0x124 Error detected

    volatile uint32_t RESERVED4[7];
    volatile uint32_t EVENTS_RXTO;       // 0x144 Receiver timeout

    volatile uint32_t RESERVED5[46];
    volatile uint32_t SHORTS;            // 0x200 Shortcut register

    volatile uint32_t RESERVED6[64];
    volatile uint32_t INTENSET;          // 0x304 Enable interrupt
    volatile uint32_t INTENCLR;          // 0x308 Disable interrupt

    volatile uint32_t RESERVED7[93];
    volatile uint32_t ERRORSRC;          // 0x480 Error source

    volatile uint32_t RESERVED8[31];
    volatile uint32_t ENABLE;            // 0x500 Enable UART

    volatile uint32_t RESERVED9[1];
    volatile uint32_t PSELRTS;           // 0x508 Pin select for RTS
    volatile uint32_t PSELTXD;           // 0x50C Pin select for TXD
    volatile uint32_t PSELCTS;           // 0x510 Pin select for CTS
    volatile uint32_t PSELRXD;           // 0x514 Pin select for RXD
    volatile uint32_t RXD;               // 0x518 RXD register
    volatile uint32_t TXD;               // 0x51C TXD register

    volatile uint32_t RESERVED10[1];
    volatile uint32_t BAUDRATE;          // 0x524 Baud rate

    volatile uint32_t RESERVED11[17];
    volatile uint32_t CONFIG;
} NRF_UART_REG;