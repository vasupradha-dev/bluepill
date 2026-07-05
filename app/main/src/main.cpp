
#include "stm32f103xb.h"
#include <stdint.h>

int main()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    GPIOA->CRL &= ~GPIO_CRL_MODE0_Msk;
    GPIOA->CRL |=  GPIO_CRL_MODE0_1;      // MODE0 = 10 (output, 2MHz)
    GPIOA->CRL &= ~GPIO_CRL_CNF0_Msk;     // CNF0 = 00 (push-pull)

    while (1)
    {
        GPIOA->ODR |=  (1 << GPIO_ODR_ODR0_Pos);   // PA0 high
        for (volatile int i = 0; i < 500000; i++);
        GPIOA->ODR &= ~(1 << GPIO_ODR_ODR0_Pos);   // PA0 low
        for (volatile int i = 0; i < 500000; i++);
    }
}
