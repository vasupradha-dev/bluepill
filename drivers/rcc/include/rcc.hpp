#pragma once

#include "stm32f103xb.h"

class Rcc {

    private:
        GPIO_TypeDef* port;

    public:
        static void enable_gpio_clock(GPIO_TypeDef* port);

};