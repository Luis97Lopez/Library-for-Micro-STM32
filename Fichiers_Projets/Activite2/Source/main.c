#include "stm32f10x.h"
#include "../../MesDrivers/Include/MyTimer.h"

int cnt=0;
void Ma_Fonction_IT (void){
	cnt++;
}

void Callback (void) {
	// OUTPUT 
	GPIOC->ODR = GPIOC->ODR ^ GPIO_ODR_ODR10;
}


int main(void)
{
	
	
	//TIMERS
	MyTimer_Struct_TypeDef t;
	
   // TURN ON REGISTERS GPIO C
 	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN ;
	
	//GPIO
	GPIOC->CRH &= ~(GPIO_CRH_CNF10);
	GPIOC->CRH &= ~(GPIO_CRH_MODE10);
	GPIOC->CRH |= GPIO_CRH_MODE10_0;
	
	t.Timer = TIM2; //Initializing TIM2 with a period of 500ms
	t.ARR = 6000-1;
	t.PSC = 6000-1;
	MyTimer_Base_Init(&t);
	
	MyTimer_PWM(t.Timer,1); //Put BEFORE counter starts
	
	MyTimer_ActiveIT(t.Timer,1, Callback); //Enabling interruptions
	MyTimer_Base_Start(t.Timer); //Starting counter



	while(1);
}
