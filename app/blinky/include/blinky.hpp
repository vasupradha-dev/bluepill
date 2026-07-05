
#pragma ince
#include "stm32f103xb.h"

#include <cstdint>

class LedBlinky {

    private:
        GPIO_TypeDef* port;
        uint8_t pin;
        void enable_clock(GPIO_TypeDef* port);
        
        typedef struct gpio_control_regs {
            volatile uint32_t* reg;
            uint8_t pin;
        } GPIO_Control_Reg;

        GPIO_Control_Reg identify_gpio_control_register(GPIO_TypeDef* port, uint8_t pin);
        void set_gpio_mode(GPIO_Control_Reg config);
        void set_gpio_cnf(GPIO_Control_Reg config);
        void set_gpio_output_data(GPIO_TypeDef* port, uint8_t pin);
        void clear_gpio_output_data(GPIO_TypeDef* port, uint8_t pin);


    public:
        LedBlinky(GPIO_TypeDef* port, uint8_t pin);
        void on();
        void off();

};
