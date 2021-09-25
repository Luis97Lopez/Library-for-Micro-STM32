#include "stm32f10x.h"
#include "../../MesDrivers/Include/MyTimer.h"

int main(void)
{
	MyTimer_Struct_TypeDef t;
	
	t.Timer = TIM2; //Initializing TIM2 with a period of 500ms
	t.ARR = 6000-1;
	t.PSC = 6000-1;
	MyTimer_Base_Init(&t);
	
	MyTimer_ActiveIT(t.Timer,0); //Enabling interruptions
	MyTimer_Base_Start(t.Timer); //Starting counter

	while(1);
}
