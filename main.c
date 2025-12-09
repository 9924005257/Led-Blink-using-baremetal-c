#include "stm32f1xx.h"

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; 
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |=  (0x1 << 20);

    while (1) {
        GPIOC->ODR ^= (1 << 13);
        for (int i=0; i<500000; i++);
    }
}