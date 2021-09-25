#include "../Include/MyTimer.h"

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * TimerStruct){
	
	if (TimerStruct->Timer == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	if (TimerStruct->Timer == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	if (TimerStruct->Timer == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	if (TimerStruct->Timer == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
	TimerStruct->Timer->ARR = TimerStruct->ARR;
	TimerStruct->Timer->PSC = TimerStruct->PSC;
}

void MyTimer_ActiveIT (TIM_TypeDef * Timer , char Prio ) {
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_SetPriority(TIM2_IRQn , Prio);
	NVIC_EnableIRQ(TIM2_IRQn );
}

void TIM2_IRQHandler ( void ){
	TIM2->SR &= ~(TIM_SR_UIF);
}


