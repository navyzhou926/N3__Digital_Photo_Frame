/**
  ******************************************************************************
  * @file    ./N3__DigitalPhotoFrame/User/liuliu_LED.h 
  * @author  ����ΰ
  * @version 0.1
  * @date    07/01/2011
  * @brief   LED_LIGHT�����Ĳ����йصĺ궨��.�Լ���������
  ******************************************************************************
 */

#ifndef __LIUZHENWEI_H
#define __LIUZHENWEI_H

#include "stm32f10x.h"

/*===���Ʋ����ĺ궨��====*/
#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4
#define ALLON 5
#define ALLOFF 6

/*====��������====*/
void  Delay (u32 nCount);
void LED_Light(u32 i);
void WindowBlinds(void);
void Shdow(void);

#endif /* __LIUZHENWEI_H */
