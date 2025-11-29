#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "Servo.h"
#include "Fan.h"
#include "Motor.h"

uint8_t KeyNum;
float Angle;
int main(void)
{
	OLED_Init();
	Fan_Init();
	Key_Init();
	
 
    OLED_ShowString(1, 1, "Speed:");
	 
	while(1)
	{   
		
		KeyNum = Key_GetNum();
		if (KeyNum != 0)
		{
			Fan_HandleKey(KeyNum);
		}

		Fan_Update();
		OLED_ShowSignedNum(2, 5, Fan_GetSpeed(), 3);
	}
 
}
