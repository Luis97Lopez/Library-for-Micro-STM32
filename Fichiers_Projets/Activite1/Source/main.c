#include "stm32f10x.h"
#include "../../MesDrivers/Include/MyGPIO.h"

int main(void)
{
	// GPIO LED and BUTTON
	MyGPIO_Struct_TypeDef led,btn;
	
	// TURN ON REGISTERS GPIO C
 	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	// CONFIGURE LED
	led.GPIO = GPIOC;
	led.GPIO_Pin = 10;
	led.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&led);
	
	// CONFIGURE BUTTON
	btn.GPIO = GPIOC;
	btn.GPIO_Pin = 8;
	btn.GPIO_Conf = In_PullUp;
	MyGPIO_Init(&btn);
		
	
		do{
		if(!MyGPIO_Read(btn.GPIO, btn.GPIO_Pin)){
			// IF IS TRUE WE TURN ON THE OUTPUT BIT
				MyGPIO_Set(led.GPIO, led.GPIO_Pin);
		}else{
				// IF IS NOT WE TURN OFF THE OUTPUT BIT
				MyGPIO_Reset(led.GPIO, led.GPIO_Pin);
		}
	}while(1) ;
	

}
