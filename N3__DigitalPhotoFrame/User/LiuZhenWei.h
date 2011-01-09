/**
  ******************************************************************************
  * @file    ./N3__DigitalPhotoFrame/User/liuliu_LED.h 
  * @author  刘振伟
  * @version 0.1
  * @date    07/01/2011
  * @brief   LED_LIGHT（）的参数有关的宏定义.以及函数声明
  ******************************************************************************
 */

#ifndef __LIUZHENWEI_H
#define __LIUZHENWEI_H

#include "stm32f10x.h"

/*===亮灯参数的宏定义====*/
#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4
#define ALLON 5
#define ALLOFF 6

/*====函数声明====*/
void  Delay (u32 nCount);
void LED_Light(u32 i);
void WindowBlinds(void);
void Shdow(void);

#endif /* __LIUZHENWEI_H */
