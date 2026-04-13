#include "gpio.h"
#include "gpiote.h"

int main(){

    gpio_init();
    gpiote_init();

    while(1){
        if (gpiote_event_check(0)) { 

            gpiote_event_clear(0);

            gpiote_task_trigger(1); 
            gpiote_task_trigger(2); 
            gpiote_task_trigger(3); 
            gpiote_task_trigger(4);
        }

        for(volatile int i = 0; i < 1000000; i++);
    }

    return 0;
}