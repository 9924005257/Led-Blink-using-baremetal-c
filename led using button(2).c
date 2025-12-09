#include "stm32f1xx.h"

void delay_ms(int ms){
    for(int i=0;i<ms*8000;i++);
}

int main(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |=  (0x8 << 20);
    GPIOC->ODR  |=  (1 << 13);

    GPIOC->CRH &= ~(0xF << 24);
    GPIOC->CRH |=  (0x1 << 24);

    while (1)
    {
        while(!(GPIOC->IDR & (1 << 13))){
            delay_ms(20);
            if(!(GPIOC->IDR & (1 << 13))){
                GPIOC->ODR ^= (1 << 14);
                while(!(GPIOC->IDR & (1 << 13)));
                delay_ms(20);
            }
        }
    }
}
