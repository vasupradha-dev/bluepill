
#pragma once
#include "stm32f103xb.h"

#include <cstdint>

enum class GpioMode : uint32_t {
    Input = 0b00U,
    OutSpeed10Mhz = 0b01U,
    OutSpeed2Mhz = 0b10U,
    OutSpeed50Mhz = 0b11U
};

enum class GpioCnf : uint32_t {
    Analog = 0b00U,
    Floating = 0b01U,
    PullUpDown = 0b10U,
    IOPushPull = 0b00U,
    IOOpenDrain = 0b01U,
    AltPushPull = 0b10U,
    AltOpenDrain = 0b11U,
};

class Gpio {

    private:
        GPIO_TypeDef* port;
        uint8_t pin;
        GpioMode mode;
        GpioCnf cnf;

        typedef struct {
            volatile uint32_t * reg;
            uint8_t pin;
            uint32_t mode_mask;
            uint32_t cnf_mask;
        } GpioConfig;

        GpioConfig get_gpio_config_registers(GPIO_TypeDef* port, uint8_t pin);
        void gpio_configure_mode(GpioConfig config, GpioMode mode);
        void gpio_configure_cnf(GpioConfig config, GpioCnf cnf);

    public:
        Gpio(GPIO_TypeDef* port, uint8_t pin, GpioMode mode, GpioCnf cnf);
        void gpio_set(GPIO_TypeDef* port, uint8_t pin);
        void gpio_clear(GPIO_TypeDef* port, uint8_t pin);
};