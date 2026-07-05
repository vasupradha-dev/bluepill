
#include "stm32f103xb.h"
#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t*)(RCC_BASE + 0x18))
#define GPIOA_CRL   (*(volatile uint32_t*)(GPIOA_BASE + 0x0))
#define GPIOA_ODR  (*(volatile uint32_t*)((GPIOA_BASE + 0x0C)))

int main()
{
    RCC_APB2ENR |= RCC_APB2ENR_IOPAEN;

    GPIOA_CRL &= ~GPIO_CRL_MODE0_Msk;
    GPIOA_CRL |=  GPIO_CRL_MODE0_1;      // MODE0 = 10 (output, 2MHz)
    GPIOA_CRL &= ~GPIO_CRL_CNF0_Msk;     // CNF0 = 00 (push-pull)

    while (1)
    {
        GPIOA_ODR |=  (1 << GPIO_ODR_ODR0_Pos);   // PA0 high
        for (volatile int i = 0; i < 50000; i++);
        GPIOA_ODR &= ~(1 << GPIO_ODR_ODR0_Pos);   // PA0 low
        for (volatile int i = 0; i < 50000; i++);
    }
}
