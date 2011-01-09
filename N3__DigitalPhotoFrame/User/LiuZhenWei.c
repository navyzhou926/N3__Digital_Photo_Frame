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
extern const unsigned char girl_1[];
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

//	LCD_Clear(0xFFFF);
	for(j = 0; j < 40; j++)				  //ÿһҶд40��
	{
		for(kk = 0; kk < 6; kk++)			  //д��Ҷ��ÿһ��
		{
			address_set(kk*40 + j, 0, (kk + 1)*40 + j-1, 319);
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

/*======��ɫ����=========*/
unsigned int modify_liu(unsigned char a,unsigned b,int k)
{
	unsigned char blue = 0, red = 0, green = 0, test, test1;
	unsigned int dd, tt;
	unsigned char aa = a, bb = b;

	
			test = aa;
			blue = test&0x1f;           //�Ѹ���λ����---ȡ��ɫ��ֵ
			blue >>= k;			        //��ɫ����
			blue &= 0x3f;
	
			test = bb;
			test >>= 3;
			red = test&0x1f;	    	//ȡ��ɫ��ֵ��
			red >>= k;	 		     	//��ɫ����
			red &= 0x3f;
	 
			test = aa;
			test >>= 5;
			test &= 0x07;  
			test1 = bb;
			test1 <<= 3;
			test1 &= 0x38; 
			green = test|test1;			 //ȡ��ɫ��ֵ��
			green >>= k;			         //��ɫ����
			green &= 0x3f;
	 
	 /*====== ��������ɫ=====*/	  
			dd = blue;		   			 
			dd &= 0x001f;					 //������ɫ	 -> Сͷ����

			tt = green;
			tt <<= 5;
			tt &= 0x07e0;
			dd = dd|tt;					 //������ɫ	 -> Сͷ����

			tt = red;
			tt <<= 11;
			tt &= 0xf800;
			dd = dd|tt;					 //���Ϻ�ɫ	 -> Сͷ����
				   
			return dd;	
}


/*=======ǳ��ǳ��Ч��======*/
void Shdow(void)
{
	int k, i;
	unsigned int dd;

	LCD_Clear(0xffff);
	/*====�𽥱��====*/
	for(k = 1; k < 7; k++)	//display 7 times and modify color in every time
	{
		address_set(0,0,239,319);
		for(i = 0; i < 76800; i++)	 //display one time
		{
			dd = modify_liu(girl_1[i*2],girl_1[i*2+1],k);
			LCD_WriteRAM(dd);				
		}
		Delay(0xaffff);
	}
}

/*=====�Ŵ���ʾ====*/
void big_liu(void)
{
	int i, t = 0, k = 0;
	unsigned int dd;
	LCD_Clear(0xffff);

	for(i=19200; i<57600;i++)
	{
		
		if(i%320>=80 && i%320<240)
		{	
			if(t >= 319)
			{
				t = 0;
				k += 2;
			}
			address_set(k,t,k,319);
			dd=(0x00|girl_1[i*2+1])<<8;
			dd = dd|girl_1[i*2];	                 //��8λ�ϲ���16λ�ġ�
			LCD_WriteRAM(dd);
			LCD_WriteRAM(dd);

			address_set(k+1,t,k+1,319);
			LCD_WriteRAM(dd);
			LCD_WriteRAM(dd);
			t += 2;

		}
				
	} 
//	Delay(0xaffff);
//	Delay(0xaffff);
//	Delay(0x5ffff);
}


/*====��С��ʾ====*/
void small_liu(void)
{
	int i;
	unsigned int dd;
	LCD_Clear(0xffff);
	address_set(0,0,119,159);
	for(i = 0; i < 38400; i++)
	{
		if(i%160 == 0)
		i += 160;
		dd=(0x00|girl_1[i*4+1])<<8;
		dd = dd|girl_1[i*4];	                 //��8λ�ϲ���16λ�ġ�
		LCD_WriteRAM(dd);	
	}

	address_set(0,160,119,319);
	for(i = 0; i < 38400; i++)
	{
		if(i%160 == 0)
		i += 160;
		dd=(0x00|girl_1[i*4+1])<<8;
		dd = dd|girl_1[i*4];	                 //��8λ�ϲ���16λ�ġ�
		LCD_WriteRAM(dd);	
	}
	address_set(120,0,239,159);
	for(i = 0; i < 38400; i++)
	{
		if(i%160 == 0)
		i += 160;
		dd=(0x00|girl_1[i*4+1])<<8;
		dd = dd|girl_1[i*4];	                 //��8λ�ϲ���16λ�ġ�
		LCD_WriteRAM(dd);	
	}
	address_set(120,160,239,319);
	for(i = 0; i < 38400; i++)
	{
		if(i%160 == 0)
		i += 160;
		dd=(0x00|girl_1[i*4+1])<<8;
		dd = dd|girl_1[i*4];	                 //��8λ�ϲ���16λ�ġ�
		LCD_WriteRAM(dd);	
	}	
//	Delay(0xaffff);
//	Delay(0xaffff);
//	Delay(0x5ffff);	
}
