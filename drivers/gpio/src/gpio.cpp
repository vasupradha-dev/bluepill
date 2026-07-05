
#include "gpio.hpp"
#include "rcc.hpp"

Gpio::Gpio(GPIO_TypeDef* port, uint8_t pin, GpioMode mode, GpioCnf cnf) 
    : port(port), pin(pin), mode(mode), cnf(cnf) { 

    Rcc::enable_gpio_clock(port);

    Gpio::GpioConfig config;
    config = Gpio::get_gpio_config_registers(port, pin);

    Gpio::gpio_configure_mode(config, mode);
    Gpio::gpio_configure_cnf(config, cnf);
}

// Public methods
Gpio::GpioConfig Gpio::get_gpio_config_registers(GPIO_TypeDef* port, uint8_t pin) {
    Gpio::GpioConfig config;

    if(pin >= 8) {
        config.reg = &port->CRH;
        config.pin = pin - 8;
        config.mode_mask = 0x3U;
        config.cnf_mask = 0x3U;
    } else {
        config.reg = &port->CRL;
        config.pin = pin;
        config.mode_mask = 0x3U;
        config.cnf_mask = 0x3U;
    }

    return config;

}

void Gpio::gpio_set(GPIO_TypeDef* port, uint8_t pin) {
    port->ODR |= (1 << pin);
}

void Gpio::gpio_clear(GPIO_TypeDef* port, uint8_t pin) {
    port->ODR &= ~(1 << pin);
}

// Private methods
void Gpio::gpio_configure_mode(Gpio::GpioConfig config, GpioMode mode) {
    uint8_t shift = config.pin * 4;

    *config.reg &= ~(config.mode_mask << shift);
    *config.reg |= ((uint32_t) mode << shift);
}

void Gpio::gpio_configure_cnf(Gpio::GpioConfig config, GpioCnf cnf) {
    uint8_t shift = (config.pin * 4) + 2;

    *config.reg &= ~(config.cnf_mask << shift);
    *config.reg |= ((uint32_t) cnf << shift);
}

