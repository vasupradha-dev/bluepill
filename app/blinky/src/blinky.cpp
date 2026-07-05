
#include "blinky.hpp"

LedBlinky::LedBlinky(GPIO_TypeDef* port, uint8_t pin) : port(port), pin(pin) {

    LedBlinky::enable_clock(port);
    LedBlinky::GPIO_Control_Reg gpio_control_regs = LedBlinky::identify_gpio_control_register(port, pin);
    LedBlinky::set_gpio_mode(gpio_control_regs);
    LedBlinky::set_gpio_cnf(gpio_control_regs);
}

// Public methods
void LedBlinky::on() {
    LedBlinky::set_gpio_output_data(port, pin);
}

void LedBlinky::off() {
    LedBlinky::clear_gpio_output_data(port, pin);
}

// Private methods
void LedBlinky::enable_clock(GPIO_TypeDef* port) {
    if (port == GPIOA)
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    else if (port == GPIOB)
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    else if (port == GPIOC)
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    else if (port == GPIOD)
        RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
    else if (port == GPIOE)
        RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
}

LedBlinky::GPIO_Control_Reg LedBlinky::identify_gpio_control_register(GPIO_TypeDef* port, uint8_t pin) {
    LedBlinky::GPIO_Control_Reg config;

    if(pin > 8) {
        config.reg = &port->CRH;
        config.pin = pin - 8;
    }
    else {
        config.reg = &port->CRL;
        config.pin = pin;
    }

    return config;
    
}

void LedBlinky::set_gpio_mode(GPIO_Control_Reg config) {
    constexpr uint32_t MODE_MASK = 0x3U;
    constexpr uint32_t MODE_OUTPUT_2MHZ = 0b10U;

    uint8_t shift = config.pin * 4;

    *config.reg &= ~(MODE_MASK << shift);
    *config.reg |= MODE_OUTPUT_2MHZ << shift;

}

void LedBlinky::set_gpio_cnf(GPIO_Control_Reg config) {
    constexpr uint32_t CNF_MASK = 0x3U;
    constexpr uint32_t CNF_OUTPUT_PUSH_PULL = 0x0b00U;

    uint8_t shift = (config.pin * 4) + 2;

    *config.reg &= ~(CNF_MASK << shift);
    *config.reg |= CNF_OUTPUT_PUSH_PULL << shift;
}

void LedBlinky::set_gpio_output_data(GPIO_TypeDef* port, uint8_t pin) {
    port->ODR |= 1 << pin;
}

void LedBlinky::clear_gpio_output_data(GPIO_TypeDef* port, uint8_t pin) {
    port->ODR &= ~(1 << pin);
}