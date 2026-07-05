
#include "blinky.hpp"


void wait() {
    for (volatile int i = 0; i < 50000; i++);
}

int main()
{
    
    LedBlinky led_blue(GPIOA, 0);
    LedBlinky led_red(GPIOA, 7);
    LedBlinky led_yellow(GPIOB, 12);

    while (1)
    {
        led_blue.on();
        wait();
        led_blue.off();
        wait();

        led_red.on();
        wait();
        led_red.off();
        wait();

        led_yellow.on();
        wait();
        led_yellow.off();
        wait();
    }
}
