/********************************************************************************
* 
* @file    ./N3__DigitalPhotoFrame/User/BaiMing.c 
* @author  白明
* @version 0.1
* @date    07/01/2011
*
*******************************************************************************/


#include "lcd.h"

extern void address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
extern const unsigned char home_picture[];
extern void LCD_WriteRAM(unsigned int val);
extern void ili9320_PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor);
extern void Delay(vu32 Time);


/*******************************************************************************
* Author		 : 白明
* Date           : 07/01/2011
* Function Name  : ShowSpecialEffect
* Description    : void ShowSpecialEffect(void).
* Input          : - home_picture: The array data of picture named home_picture.
* Output         : None
* Return         : None
*******************************************************************************/
void ShowSpecialEffect(void)
{
	int i,c,d,x,y,r,z;
	unsigned int dd;	  
	c = 0;x = 0;
	y = 0;r = 0;z = 0;
	LCD_Clear(Red);
	for(d = 0;d < 120; d++)
	{
		address_set(120+c, 0, 120 + c, 319);
		for(i = 0; i < 320; i++)
		{
			x = (120 + d)*640 + 2*i + 1;
			r = (120 + d)*640 + 2*i;
			dd = (0x00|home_picture[x])<<8;             
			dd = dd|home_picture[r];                                                                                                                                                                                                                                			
			LCD_WriteRAM(dd);				
		}				  
		address_set(119-c, 0, 119-c, 319);
		for(i = 0;i < 320;i++)
		{
			y = (120-d)*640 + 2*i + 1;
			z = (120-d)*640 + 2*i;
			dd = (0x00|home_picture[y])<<8;             
			dd = dd|home_picture[z];                                                                                                                                                                                                                                			   
			LCD_WriteRAM(dd);					          
		}	
		Delay(0x8fff);		
		c++;
	}
}

void ShowString(char table[])
{
	int i;
	for(i = 0; i < 25; i++)
	{
		ili9320_PutChar(60 + 8*i, 112, *(table+i), 0x3000, 0xF7DE);	
	}	
}

void CenterOut(void)
{
	unsigned int i = 0, j = 0, k = 1, p = 0;
	unsigned int g , h, dd, a, b, c, d;				
	g = 7; h = 8;
	LCD_Clear(0xffff);
	for(p = 0; p < 8; p++)
	{
		c = 15*p; 
		d = 20*p;					
		for(a = 0; a < 15; a++)
		{	
			address_set(120 - c - a,140 - d,120 - c - a,180 + d);	//一行			
			i = ((120 - c - a)*320 + 20*g)*2;						 //起始位置
			j = 40*k;
			for(b = 0; b < j; b++)
			{
				dd = (0x00|home_picture[i+b*2 + 1])<<8;
			    dd = dd|home_picture[i+b*2];
			    LCD_WriteRAM(dd);
			}	
		}
		if(p != 0)
		{				
			for(a = 0; a < 30*(k-1); a++)
			{	
				address_set(120 - c + a,160 + d,120 - c + a,180 + d);	//一列
				i = ((15*(g+1) + a)*320 + 20*h)*2;						//开始位置
				j = 20;													 //一行20个
				for(b = 0; b < j; b++)									 
				{
					dd = (0x00|home_picture[i+b*2 + 1])<<8;
			    	dd = dd|home_picture[i+b*2];
			    	LCD_WriteRAM(dd);
				}
			}
		}			
		for(a = 0; a < 15; a++)
		{
			address_set(120 + c + a,140 - d,120 + c +a,180 + d);	 //一行
			i = ((120 + c + a)*320 + 20*g)*2;
			j = 40*k;
			for(b = 0; b < j; b++)
			{
				dd = (0x00|home_picture[i+b*2 + 1])<<8;
			   	dd = dd|home_picture[i+b*2];
			   	LCD_WriteRAM(dd);
			}	
		}		
		if(p !=0 )			  
		{
			for(a = 0; a < 30*(k-1); a++)
			{	 
				address_set(120 - c + a,140 - d,120 - c + a,180 - d);	   //一列
				i = ((15*(g+1)+a)*320 + 20*g)*2;
				j = 20;
				for(b = 0; b < j; b++)
			{
				dd = (0x00|home_picture[i+b*2 + 1])<<8;
			   	dd = dd|home_picture[i+b*2];
			   	LCD_WriteRAM(dd);
			}
		}
	}		
	Delay(0x1ffff);				
	g--;
	k++;
	h++;			 
	}
}


