
#pragma once

#include "rcc.hpp"
#include "gpio.hpp"

#include <cstdint>

class Led {

    private:
        GPIO_TypeDef* port;
        uint8_t pin;
        Gpio led_gpio;

    public:
        Led(GPIO_TypeDef* port, uint8_t pin);
        void on();
        void off();

};
