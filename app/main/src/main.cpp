
#include "led.hpp"

void wait() {
    for (volatile int i = 0; i < 50000; i++);
}

int main()
{
    
    Led led_blue(GPIOC, 15);
    Led led_red(GPIOB, 15);
    Led led_yellow(GPIOA, 5);

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
