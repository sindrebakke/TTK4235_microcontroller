#include "gpio.h"

#define BUTTON1 13
#define BUTTON2 14

void gpio_init(void) {
    GPIO->PIN_CNF[BUTTON1] = (3 << 2); //Pullup
    GPIO->PIN_CNF[BUTTON2] = (3 << 2); 

    for(int i = 17; i <= 20; i++){
        GPIO->DIRSET = (1 << i);  
        GPIO->OUTSET = (1 << i);   
    } //LED off, and set pin as output
}