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

    char A = 'A';
    char B = 'B';

	while(1){
        if (!(GPIO->IN & (1 << 13))){
			uart_send(A);
		}
        if (!(GPIO->IN & (1 << 14))){
			uart_send(B);
		}

        char letter;
        letter = uart_read();

        if (letter == A) {
            printf("A\r\n");
        }
        else if (letter == B) {
            printf("B\r\n");
        }
        
		sleep = 1000000;
        while(--sleep); // Delay
    } return 0;
};