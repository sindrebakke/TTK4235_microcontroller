#include <stdint.h>

void uart_init();
void uart_send(char letter);
char uart_read();

#define UART ((NRF_UART_REG*) 0x40002000)

typedef struct {
    volatile uint32_t TASKS_STARTRX;   // 0x000
    volatile uint32_t TASKS_STOPRX;    // 0x004
    volatile uint32_t TASKS_STARTTX;   // 0x008
    volatile uint32_t TASKS_STOPTX;    // 0x00C
    uint32_t RESERVED0[2];             // 0x010
    volatile uint32_t TASKS_SUSPEND;   // 0x01C

    uint32_t RESERVED1[56];            // 0x020

    volatile uint32_t EVENTS_CTS;      // 0x100
    volatile uint32_t EVENTS_NCTS;     // 0x104
    volatile uint32_t EVENTS_RXDRDY;   // 0x108
    uint32_t RESERVED2[4];             // 0x10C
    volatile uint32_t EVENTS_TXDRDY;   // 0x11C
    uint32_t RESERVED3[1];             // 0x120
    volatile uint32_t EVENTS_ERROR;    // 0x124
    uint32_t RESERVED4[7];             // 0x128
    volatile uint32_t EVENTS_RXTO;     // 0x144

    uint32_t RESERVED5[46];            // 0x148

    volatile uint32_t SHORTS;          // 0x200

    uint32_t RESERVED6[65];            // 0x204

    volatile uint32_t INTENSET;        // 0x304
    volatile uint32_t INTENCLR;        // 0x308

    uint32_t RESERVED7[94];            // 0x30C

    volatile uint32_t ERRORSRC;        // 0x480

    uint32_t RESERVED8[31];            // 0x484

    volatile uint32_t ENABLE;          // 0x500
    uint32_t RESERVED9;                // 0x504
    volatile uint32_t PSELRTS;         // 0x508
    volatile uint32_t PSELTXD;         // 0x50C
    volatile uint32_t PSELCTS;         // 0x510
    volatile uint32_t PSELRXD;         // 0x514
    volatile uint32_t RXD;             // 0x518
    volatile uint32_t TXD;             // 0x51C
    uint32_t RESERVED10;               // 0x520
    volatile uint32_t BAUDRATE;        // 0x524

    uint32_t RESERVED11[17];           // 0x528

    volatile uint32_t CONFIG;          // 0x56C

} NRF_UART_REG;