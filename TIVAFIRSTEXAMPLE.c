#include <stdint.h>
#include "tm4c123gh6pm.h"

void main(void) {
	uint32_t n; 
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)==0) { }
	GPIO_PORTF_DIR_R |= 0x02; 
	GPIO_PORTF_DR8R_R |=0x02; 
	GPIO_PORTF_DEN_R |=0x02; 
	while(1){
		GPIO_PORTF_DATA_R |=0X02; 
		for(n = 0; n < 800000; n++);
		GPIO_PORTF_DATA_R &= ~(0X02);
		for(n = 0; n < 800000; n++);
		} 
	} 