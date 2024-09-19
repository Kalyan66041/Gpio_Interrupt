#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
int count = 0 ;
void GpioInit(void);
void GpioIntHandler(void);
void delayMs(int n);
int main(void) {
    GpioInit();
    while(1) {

    }
}


void GpioInit(void) {

    SYSCTL_RCGCGPIO_R |= 0x20;
    while((SYSCTL_PRGPIO_R & 0x20) == 0) {}
    GPIO_PORTF_DIR_R &= ~0x10;
    GPIO_PORTF_DEN_R |= 0x10;
    GPIO_PORTF_PUR_R |= 0x10;
    GPIO_PORTF_DIR_R |= 0x02;
    GPIO_PORTF_DEN_R |= 0x02;
    NVIC_EN0_R |= (1 << 30);
    GPIO_PORTF_IS_R &= ~0x10;
    GPIO_PORTF_IBE_R &= ~0x10;
    GPIO_PORTF_IEV_R &= ~0x10;
    GPIO_PORTF_ICR_R = 0x10;
    GPIO_PORTF_IM_R |= 0x10;

}


void GpioIntHandler(void) {
              delayMs(100);
              count++;
        GPIO_PORTF_ICR_R = 0x10;
        GPIO_PORTF_DATA_R ^= 0x02;

}
void delayMs(int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3180; j++){}
}
