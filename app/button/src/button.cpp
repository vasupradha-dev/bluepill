
#include "button.hpp"

Button::Button(GPIO_TypeDef* port, uint8_t pin) 
    : port(port), pin(pin), button_gpio(port, pin, GpioMode::Input, GpioCnf::PullUpDown) {
        button_gpio.gpio_set(port, pin);
}

bool Button::is_pressed() {
    return !(port->IDR & (1 << pin));
}