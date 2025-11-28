#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void)
{
	PWM_Init_Servo();
}



void Servo_SetAngle(float Angle) {
	PWM_Set_Servo_Compare2(Angle / 180 * 2000 + 500);
}
