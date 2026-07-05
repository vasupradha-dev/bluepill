
#include "led.hpp"

Led::Led(GPIO_TypeDef* port, uint8_t pin) 
    : port(port), pin(pin), led_gpio(port, pin, GpioMode::OutSpeed2Mhz, GpioCnf::IOPushPull) { }

// Public methods
void Led::on() {
    led_gpio.gpio_set(port, pin);
}

void Led::off() {
    led_gpio.gpio_clear(port, pin);
}

