
#include "rcc.hpp"

void Rcc::enable_gpio_clock(GPIO_TypeDef* port) {
    if (port == GPIOA)
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    else if (port == GPIOB)
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    else if (port == GPIOC)
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
}