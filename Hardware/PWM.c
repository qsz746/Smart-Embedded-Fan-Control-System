#include "stm32f10x.h"                  // Device header

///////////////////////////////////////
//code for Servo
///////////////////////////////////////

void PWM_Init_Servo(void)
{
    //Enable RCC
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//Init GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
	//Choose internal clock using TIM2
	//default is internal, this line can be omitted
	TIM_InternalClockConfig(TIM2);
	
	
	//Time base unit
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 20000 - 1;      //ARR
	TIM_TimeBaseInitStruct.TIM_Prescaler = 72 -1 ;    //PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);  
 

	//output compare
	//initiate struct
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	//change part of members in the struct
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0;         //CCR
	TIM_OC2Init(TIM2, &TIM_OCInitStruct);
	
	
	TIM_Cmd(TIM2, ENABLE);
}

void PWM_Set_Servo_Compare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);
}




///////////////////////////////////////
//code for Motor
///////////////////////////////////////
void PWM_Init_Motor(void)
{
    //Enable RCC
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//Init GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
	//Choose internal clock using TIM3
	//default is internal, this line can be omitted
	TIM_InternalClockConfig(TIM3);
	
	
	//Time base unit
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 100 - 1;      //ARR
	TIM_TimeBaseInitStruct.TIM_Prescaler = 36 -1 ;    //PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);  
 

	//output compare
	//initiate struct
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	//change part of members in the struct
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 90;         //CCR
	TIM_OC2Init(TIM3, &TIM_OCInitStruct);
	
	
	TIM_Cmd(TIM3, ENABLE);
}

void PWM_Set_Motor_Compare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM3, Compare);
}



 

