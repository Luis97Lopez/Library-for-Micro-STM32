#include "stm32f10x.h"
#include "../../MesDrivers/Include/MyTimer.h"

int main(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	MyTimer_Struct_TypeDef t;
	t.Timer = TIM4;
	t.ARR = 6000;
	t.PSC = 6000;
	
	MyTimer_Base_Init(&t);
	MyTimer_Base_Start(t.Timer);
	
	while(1);
}
