/**
  ******************************************************************************
  * @file    ./N3__DigitalPhotoFrame/User/liuliu_LED.c 
  * @author  ����ΰ
  * @version 0.1
  * @date    07/01/2011
  * @brief   LED��������
  ******************************************************************************
 */


#include "LiuZhenWei.h"

#define GPIO_Pin_8                 ((u16)0x0100)  /* Pin 8 selected */
#define GPIO_Pin_9                 ((u16)0x0200)  /* Pin 9 selected */
#define GPIO_Pin_0                 ((u16)0x0001)  /* Pin 0 selected */
#define GPIO_Pin_1                 ((u16)0x0002)  /* Pin 1 selected */


extern void GPIO_SetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
extern void GPIO_ResetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
extern void LCD_WriteRAM(unsigned int val);
extern void address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
extern const unsigned char girl_2[];
extern void LCD_Clear(u16 Color);



/**
  * @brief  :����LED
  * @param  :i��������LED��ָ��������ȡֵΪ1-6���ֱ��Ӧ�ĸ�������ȫ��ȫ��
  * @retval : None
  */
void LED_Light(u32 i)
{
	switch(i)
	{
		/*====LED1-ON=======*/
		case LED1:
			GPIO_ResetBits(GPIOB , GPIO_Pin_8);
			GPIO_SetBits(GPIOB , GPIO_Pin_9);
			GPIO_SetBits(GPIOE , GPIO_Pin_0);
			GPIO_SetBits(GPIOE , GPIO_Pin_1);		
			break;

		/*====LED2-ON=======*/
		case LED2:
			GPIO_SetBits(GPIOB , GPIO_Pin_8);
			GPIO_ResetBits(GPIOB , GPIO_Pin_9);
			GPIO_SetBits(GPIOE , GPIO_Pin_0);
			GPIO_SetBits(GPIOE , GPIO_Pin_1);
			break;

		/*====LED3-ON=======*/
		case LED3:
			GPIO_SetBits(GPIOB , GPIO_Pin_8);
			GPIO_SetBits(GPIOB , GPIO_Pin_9);
			GPIO_ResetBits(GPIOE , GPIO_Pin_0);
			GPIO_SetBits(GPIOE , GPIO_Pin_1);
			break;

		/*====LED4-ON=======*/
		case LED4:
			GPIO_SetBits(GPIOB , GPIO_Pin_8);
			GPIO_SetBits(GPIOB , GPIO_Pin_9);
			GPIO_SetBits(GPIOE , GPIO_Pin_0);
			GPIO_ResetBits(GPIOE , GPIO_Pin_1);
			break;

		  /*====ALL-ON=======*/
		case ALLON:
			GPIO_ResetBits(GPIOB , GPIO_Pin_8);
			GPIO_ResetBits(GPIOB , GPIO_Pin_9);
			GPIO_ResetBits(GPIOE , GPIO_Pin_0);
			GPIO_ResetBits(GPIOE , GPIO_Pin_1);
			break;

		 /*====ALL-OFF=======*/
		default:
			GPIO_SetBits(GPIOB , GPIO_Pin_8);
			GPIO_SetBits(GPIOB , GPIO_Pin_9);
			GPIO_SetBits(GPIOE , GPIO_Pin_0);
			GPIO_SetBits(GPIOE , GPIO_Pin_1);
			break;
	}
}

/**
  * @brief  : ��Ҷ��Ч��
  * @param  : None
  * @retval : None
  */
void WindowBlinds(void)
{
	int i = 0, j = 0, kk = 0, t = 0;
	unsigned int dd = 0;

	LCD_Clear(0xFFFF);

	for(j = 0; j < 40; j++)				  //ÿһҶд40��
	{
		for(kk = 0; kk < 6; kk++)			  //д��Ҷ��ÿһ��
		{
			address_set(kk*40 + j,0,(kk + 1)*40 + j-1,319);
			for(i = 0; i < 320 ; i++)       //дһ��
			{
				t = i + kk*40*320 + j*320;
				dd = (0x00|girl_2[t*2 + 1])<<8;
				dd = dd|girl_2[t*2];	   //��8λ�ϲ���16λ�ġ�
				LCD_WriteRAM(dd);	
			}	
		}
		Delay(0x0ffff);
	}								
}
