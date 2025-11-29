#include "stm32f10x.h"                  // Device header

#include "Servo.h"
#include "Motor.h"
#include "delay.h"

#define SERVO_MIN_ANGLE   30.0f    // Minimum swing angle (degrees) 
#define SERVO_MAX_ANGLE  150.0f    // Maximum swing angle (degrees)
#define SERVO_STEP         2.0f    // Angle step per update (degrees)

//the static variables cannot be accessed from other files in the program
static uint8_t g_SwingOn   = 0;      // Auto swing on/off flag
static float   g_Angle     = 90.0f;  // Current servo angle 
static int8_t  g_Direction = 1;      // 1: increasing angle, -1: decreasing angle

static int8_t  g_Speed     = 0;      // motor speed 0..100

void Fan_Init(void)
{
	Servo_Init();
	Motor_Init();
	
    g_SwingOn   = 0;
    g_Angle     = 90.0f;  // Center position
    g_Direction = 1;
	
	g_Speed     = 0;
	
    Servo_SetAngle(g_Angle);       
	Motor_SetSpeed(g_Speed);  	
}

void Fan_HandleKey(uint8_t keyNum)
{	
	switch(keyNum)
	{
		case 1: 
			g_Speed += 20;
			if (g_Speed > 100) g_Speed = 100;
			Motor_SetSpeed(g_Speed);
			break;
		
		case 2: 
			g_Speed -= 20;
			if (g_Speed < 0) g_Speed = 0;
			Motor_SetSpeed(g_Speed);
			break;
		
		case 3:
			g_SwingOn = !g_SwingOn;
		
		default:
			break;
	}
}

void Fan_Update(void)
{
    if (g_SwingOn)
    {
        g_Angle += g_Direction * SERVO_STEP;

        if (g_Angle >= SERVO_MAX_ANGLE)
        {
            g_Angle = SERVO_MAX_ANGLE;
            g_Direction = -1;
        }
        else if (g_Angle <= SERVO_MIN_ANGLE)
        {
            g_Angle = SERVO_MIN_ANGLE;
            g_Direction = 1;
        }

        Servo_SetAngle(g_Angle);
        Delay_ms(80);   // swing speed
    }
    else
    {
         // idle a bit when swing is off
        Delay_ms(10);
    }
}

int8_t Fan_GetSpeed(void)
{
    return g_Speed;
}