#include "stm32f10x.h"

// CHECK IF KTH BIT OF N NUMBER IS SET OR NOT
int bit_is_set(int n, int k){
	return n & (1 << k);
}

int main(void)
{
	
	// TURN ON REGISTERS GPIO A, B and C
 	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	
	// INPUT PULL UP
	GPIOC->CRH &= ~(0xF);
	GPIOC->CRH |= 0x8;
	GPIOC->ODR |= GPIO_ODR_ODR8;
	
	// OUTPUT 
	GPIOC->CRH &= ~(GPIO_CRH_CNF10);
	GPIOC->CRH &= ~(GPIO_CRH_MODE10);
	GPIOC->CRH |= GPIO_CRH_MODE10_0;
	
	do{
		if(!bit_is_set(GPIOC->IDR, 8)){
			// IF IS TRUE WE TURN ON THE OUTPUT BIT
				GPIOC->ODR |= GPIO_ODR_ODR10;
		}else{
				// IF IS NOT WE TURN OFF THE OUTPUT BIT
				GPIOC->ODR &= ~(GPIO_ODR_ODR10);
		}
	}while(1) ;
}
