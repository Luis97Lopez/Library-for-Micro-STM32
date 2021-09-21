#include "../Include/MyTimer.h"

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * TimerStruct){
	TimerStruct->Timer->ARR = TimerStruct->ARR;
	TimerStruct->Timer->PSC = TimerStruct->PSC;
}