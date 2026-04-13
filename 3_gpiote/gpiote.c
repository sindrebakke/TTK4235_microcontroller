#include "gpiote.h"
#include "gpio.h"

#define BUTTON_1_PIN 13
#define LED_MATRIX_PIN1 17
#define LED_MATRIX_PIN2 18
#define LED_MATRIX_PIN3 19
#define LED_MATRIX_PIN4 20

// GPIOTE channel assignments
#define BUTTON_1_CHANNEL 0
#define LED_PIN1_CHANNEL 1
#define LED_PIN2_CHANNEL 2
#define LED_PIN3_CHANNEL 3
#define LED_PIN4_CHANNEL 4

void gpiote_init(void) {
    GPIOTE->CONFIG[BUTTON_1_CHANNEL] = (BUTTON_1_PIN << 8) |  
                                       (2 << 16) |                  //HiToLo
                                       (1);                         //Event                

    GPIOTE->CONFIG[LED_PIN1_CHANNEL] = (LED_MATRIX_PIN1 << 8) | 
                                       (3 << 16) |                  
                                       (1 << 20) |                  //Init value high
                                       (3);                         //Task          

    GPIOTE->CONFIG[LED_PIN2_CHANNEL] = (LED_MATRIX_PIN2 << 8) |
                                       (3 << 16) |
                                       (1 << 20) |
                                       (3);

    GPIOTE->CONFIG[LED_PIN3_CHANNEL] = (LED_MATRIX_PIN3 << 8) |
                                       (3 << 16) |
                                       (1 << 20) |
                                       (3);

    GPIOTE->CONFIG[LED_PIN4_CHANNEL] = (LED_MATRIX_PIN4 << 8) |
                                       (3 << 16) |
                                       (1 << 20) |
                                       (3);
}

void gpiote_enable_interrupt(uint32_t channel) {
    GPIOTE->INTENSET = (1 << channel);
}

int gpiote_event_check(uint32_t channel) {
    return (GPIOTE->EVENTS_IN[channel] != 0);
}

void gpiote_event_clear(uint32_t channel) {
    GPIOTE->EVENTS_IN[channel] = 0;
}

void gpiote_task_trigger(uint32_t channel) {
    GPIOTE->TASKS_OUT[channel] = 1;
}

