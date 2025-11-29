#ifndef __PWM_H
#define __PWM_H

void PWM_Init_Servo(void);
void PWM_Set_Servo_Compare2(uint16_t Compare);


void PWM_Init_Motor(void);
void PWM_Set_Motor_Compare2(uint16_t Compare);
 
#endif

