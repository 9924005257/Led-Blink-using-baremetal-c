#include "stm32f10x.h"

void delay_ms (uint16_t t)

int main()
{
    RCC->APB2ENR |= (1<<2);
    GPIOA->CRL &=~(0xF << 28);
    GPIOA->CRL |=(0x2 << 28);
    
while(1)
{

GPIOA->BRR=(1<<7);
delay_ms(200);
GPIOA->BSRR =(1<<7);
delay_ms(200);
}
}

void delay_ms (uint16_t t)
{
    for(uint16_t t i=0;i<t;i++)
          for (uint32_t j=0;j<6000;j++)

        __asm("nop");
            
}
