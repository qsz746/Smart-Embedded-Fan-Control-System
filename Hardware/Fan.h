#ifndef __FAN_H
#define __FAN_H

void Fan_Init(void);
void Fan_HandleKey(uint8_t keyNum);
void Fan_Update(void);
int8_t Fan_GetSpeed(void);

#endif  
