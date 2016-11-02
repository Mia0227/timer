#include "LPC11xx.h"
#include "timer16.h"
#define LED1_ON LPC_GPIO1->DATA &= ~(1<<8)
#define LED1_OFF LPC_GPIO1->DATA |= (1<<8)

void led_init()
{
   LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);
   LPC_IOCON->PIO1_8 &= ~0x07;
   LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); 
   LPC_GPIO1->DIR |= (1<<8); 
   LPC_GPIO1->DATA |= (1<<8); 
  
}
int main()
{
   led_init();
   T16B0_init();
   while(1)
   { 
      LED1_ON;
      T16B0_delay_ms(1000);//1s
      
      LED1_OFF;
      T16B0_delay_ms(250);//0.25s
   }
}
