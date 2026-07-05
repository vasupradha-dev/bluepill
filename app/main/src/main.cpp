
#include "led.hpp"
#include "button.hpp"

void wait_short() {
    for (volatile int i = 0; i < 50000; i++);
}

void wait_long() {
    for (volatile int i = 0; i < 500000; i++);
}

int main()
{
    
    Button button(GPIOA, 0);
    Led led_blue(GPIOB, 0);
    Led led_red(GPIOB, 13);
    Led led_yellow(GPIOA, 8);

    ButtonState currentState = ButtonState::Off;
    bool wasPressed = false;

    while (1)
    {
        bool isPressed = button.is_pressed();

        if(!wasPressed && isPressed) {
            wait_short(); 
            if (button.is_pressed()) {
                switch(currentState) {
                    case ButtonState::Off:
                        currentState = ButtonState::BlinkFast;
                        break;

                    case ButtonState::BlinkFast:
                        currentState = ButtonState::BlinkSlow;
                        break;

                    case ButtonState::BlinkSlow:
                        currentState = ButtonState::BlinkAll;
                        break;

                    case ButtonState::BlinkAll:
                        currentState = ButtonState::Off;
                        break;
                }
            }
        }

        wasPressed = isPressed;

        switch(currentState) {
            case ButtonState::Off:
                led_blue.off();
                led_red.off();
                led_yellow.off();
                break;
                
            
            case ButtonState::BlinkFast:
                led_blue.on();
                wait_short();
                led_blue.off();
                wait_short();

                led_red.on();
                wait_short();
                led_red.off();
                wait_short();

                led_yellow.on();
                wait_short();
                led_yellow.off();
                wait_short();
                break;
            
            case ButtonState::BlinkSlow:
                led_blue.on();
                wait_long();
                led_blue.off();
                wait_long();

                led_red.on();
                wait_long();
                led_red.off();
                wait_long();

                led_yellow.on();
                wait_long();
                led_yellow.off();
                wait_long();
                break;
            
            case ButtonState::BlinkAll:
                led_blue.on();
                led_red.on();
                led_yellow.on();
                wait_long();
                led_blue.off();
                led_red.off();
                led_yellow.off();
                wait_long();
                break;
        }
    }
}
