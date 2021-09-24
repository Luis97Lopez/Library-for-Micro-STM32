#include "stm32f10x.h"
#include "../../MesDrivers/Include/MyTimer.h"

int count = 0;

void TIM2_IRQHandler ( void )
{
	TIM2->SR &= ~(TIM_SR_UIF);
	count++;
}

int main(void)
{
	MyTimer_Struct_TypeDef t;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;


	t.Timer = TIM2;
	t.ARR = 600-1;
	t.PSC = 600-1;
	
	MyTimer_Base_Init(&t);
	MyTimer_Base_Start(t.Timer);
	
	
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_SetPriority(28, 0);
	NVIC_EnableIRQ(28);
	
	while(1);
}
