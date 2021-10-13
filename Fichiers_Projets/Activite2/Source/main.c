#include "stm32f10x.h"
#include "../../MesDrivers/Include/MyTimer.h"
#include "../../MesDrivers/Include/MyGPIO.h"

// CALLBACK FUNCTION FOR TIMER
MyGPIO_Struct_TypeDef led;
void Callback () {
	MyGPIO_Toggle(led.GPIO, led.GPIO_Pin);
}

int main(void)
{
	// TIMERS
	MyTimer_Struct_TypeDef t;
	MyGPIO_Struct_TypeDef out;
	
  // TURN ON REGISTERS GPIO A and C
 	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN ;
	
	// GPIO OUT PWM
	led.GPIO = GPIOC;
	led.GPIO_Conf = Out_Ppull;
	led.GPIO_Pin = 10;
	MyGPIO_Init(&led);
	
	// GPIO OUT PWM
	out.GPIO = GPIOA;
	out.GPIO_Conf = AltOut_Ppull;
	out.GPIO_Pin = 0;
	MyGPIO_Init(&out);
	
	// CONFIGURE TIM2;
	t.Timer = TIM2; //Initializing TIM2 with a period of 500ms
	t.ARR = 6000-1;
	t.PSC = 6000-1;
	MyTimer_Base_Init(&t);
	
	// CONFIGURE PWM
	MyTimer_PWM_Init(t.Timer,1); //Put BEFORE counter starts
	MyTimer_PWM_ConfigureRatio(t.Timer, 1, 10); // Ratio 50%
	
	// ACTIVATE TIMER AND INTERRUPTIONS
	MyTimer_ActiveIT(t.Timer, 1, Callback); //Enabling interruptions
	MyTimer_Base_Start(t.Timer); //Starting counter

	while(1);
}
