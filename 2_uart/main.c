#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "gpio.h"

#define BUTTON1_PIN 13
#define BUTTON2_PIN 14

void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);
}


int main() {

    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTSET = (1 << i);  
	} // Configure LED matrix

    uart_init();
    button_init();

	int sleep = 0;
    int just_sent = 0;

    char A = 'A';
    char B = 'B';

	while(1){
        if (!(GPIO->IN & (1 << 13))){
			uart_send(A);
			just_sent = 1;
		}
        if (!(GPIO->IN & (1 << 14))){
			uart_send(B);
			just_sent = 1;
		}

        // Only read if we didn't just send something
        if (!just_sent) {
            char letter = uart_read();
            if (letter != '\0') {

                if (GPIO->OUT & (1 << 17)) {
                    GPIO->OUTCLR = (1 << 17);
                    GPIO->OUTCLR = (1 << 18);
                    GPIO->OUTCLR = (1 << 19);
                    GPIO->OUTCLR = (1 << 20);
                } else {
                    GPIO->OUTSET = (1 << 17);
                    GPIO->OUTSET = (1 << 18);
                    GPIO->OUTSET = (1 << 19);
                    GPIO->OUTSET = (1 << 20);
                }
            }
        }
        just_sent = 0;
        
		sleep = 1000000;
        while(--sleep); // Delay
    } return 0;
};