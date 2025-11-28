#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "Servo.h"
#include "Fan.h"


uint8_t KeyNum;
float Angle;
int main(void)
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "Angle:");
 
	
	while(1)
	{   
		
		KeyNum = Key_GetNum();
		if (KeyNum != 0)
		{
			Fan_HandleKey(KeyNum);
		}

		Fan_Update();
		//OLED_ShowNum(1, 7, Angle, 3);
	}
}
