
#pragma once

#include "rcc.hpp"
#include "gpio.hpp"

#include <cstdint>

enum class ButtonState : uint8_t {
    Off = 0b00U,
    BlinkSlow = 0b01U,
    BlinkFast = 0b10U,
    BlinkAll = 0b11U
};

class Button {

    private:
        GPIO_TypeDef* port;
        uint8_t pin;
        Gpio button_gpio;

    public:
        Button(GPIO_TypeDef* port, uint8_t pin);
        bool is_pressed();
};