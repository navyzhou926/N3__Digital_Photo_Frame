/********************************************************************************
* 
* @file    ./N3__DigitalPhotoFrame/User/GuoWenGang.c 
* @author  国文刚
* @version 0.1
* @date    07/01/2011
*
*******************************************************************************/

#include "lcd.h"
#include "stdlib.h"

extern void address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
extern const unsigned char girl_1[];
extern void LCD_WriteRAM(unsigned int val);
extern void Delay(vu32 Time);
extern void LCD_DrawCircle1(u8 Xpos, u16 Ypos, u16 Radius,u16 fill);
extern const unsigned char girl_2[];

/*******************************************************************************
* Author		 : 国文刚
* Date           : 07/01/2011
* Function Name  : DisplayDownUp
* Description    : void DisplayDownUp(void).
* Input          : - girl_1: The array data of picture named home_picture.
* Output         : None
* Return         : None
*******************************************************************************/
void DisplayDownUp(void)
{
	unsigned int dd,i;
	int k;
	for(i = 24; i>0; i--)
    {	
		address_set((i-1)*10, 0, 239, 319);   //设置坐标   
		for(k = 0; k < (25 - i)*3200; k++)		 
		{
			dd = (0x00|girl_1[k*2 + 1])<<8;
	        dd = dd|girl_1[k*2];  	
	        LCD_WriteRAM(dd);
	   	}
	}
}
/*
void ShowCircle(void)
{
	int fill1, fill2;
	int m, i;
	for(m = 1; m < 5; m++)
	{
		if((m&1) == 1) 
		{
		   fill1 = Black;
		   fill2 = White;
		}
		if((m&1) == 0)
		{
		   fill2 = Black;
		   fill1 = White;
		}
		for(i = 1; i < 10; i++)
        { 
	    	LCD_DrawCircle1(120, 160, i, fill1);   
	    }
	    for(i = 10; i < 50; i++)
	    {
	    	LCD_DrawCircle1(120, 160, i, fill2);
	    }
	    for(i = 50; i < 160; i++)
        {
	    	LCD_DrawCircle1(120, 160, i, fill1);
	    }
	}	
}	 */


void ShowSpecial2(void)
{
	unsigned int  dd,i,m;
	int k ,l;
	u16 fill3;
//	u16 fill1,fill2	
//	unsigned int color[] = {White,Black,Grey,Blue,Blue2,Red,Magenta,Green,Cyan,Yellow };
	int color[10] = {0xFFFF,0x0000,0xF7DE,0x001F,0x051F,0xF800,0xF81F,0x07E0,0x7FFF,0xFFE0};
	
	address_set(0,0,239,319);
	for(i = 0; i < 76800; i++)
    {
		dd=(0x00|girl_1[i*2 + 1])<<8;
		dd=dd|girl_1[i*2];  	
	    LCD_WriteRAM(dd);
	}

	   for(k = 1; k < 7; k++)
	   {
		 for(i = 1; i < 120 ; i++)
		 {
//		 	if(i > 0 && i <= 10)  {fill1 = White; fill2 = Black;}
//			if(i > 10 && i <= 40) {fill1 = Black; fill2 = White;}
//			if(i > 40 && i <= 50) {fill1 = White; fill2 = Black;}
//			if(i > 50 && i <= 80) {fill1 = Black; fill2 = White;}
//			if(i > 80 && i <= 90) {fill1 = White; fill2 = Black;}
//			if(i > 90 && i <= 120){fill1 = Black; fill2 = White;}

		 	if(i == 1)  {fill3 = rand()%10;}
			if(i == 11) {fill3 = rand()%10;}
			if(i == 41) {fill3 = rand()%10;}
			if(i ==51) {fill3 = rand()%10;}
			if(i == 81) {fill3 = rand()%10;}
			if(i == 91){fill3 = rand()%10;}
//			if(k & 1 == 1)  
//				fill3 = fill1;
//			else  
//				fill3 = fill2;
			LCD_DrawCircle1(120, 160, i, color[fill3]);
		 }
	}
		 
	 for(l = 1; l <= 16; l++)
	 {
	// 	for(i=0; i < 20; i++)
	//	{
			for(k = 1; k <= 12; k++)
			{
				if((k&1) == 0)
				{
					address_set((k-1)*20, 0, k*20, l*20);
		//			fill1 = Black ;
		//			fill1 = color[rand()%10];
		//			fill2 = Green ;
		//			fill2 = color[rand()%10];
				}
				if((k&1) == 1)
				{											 
					address_set((k-1)*20, (320-l*20), k*20, 320);
		//			fill1 = color[rand()%10];
		//			fill2 = color[rand()%10];
				}
				fill3 = color[rand()%10];
				for(m = 0; m < 20*l*20; m++)  
				{
			//		if((l&1) == 1)
			//		{
			//			fill3 = fill1;
			//		}
			//		if((l&1) == 0)
			//		{
			//			fill3 = fill2;
			//		}					
					LCD_WriteRAM(fill3);	   
				}
			}
		//}
	 }
	for(i = 24; i > 0; i--)
    {	
		address_set((i-1)*10, 0, 239, 319);   //设置坐标   
		for(k=0; k < (25-i)*3200; k++)		 
		{
			dd=(0x00|girl_1[k*2 + 1])<<8;
	        dd=dd|girl_1[k*2];  	
	        LCD_WriteRAM(dd);
	   	}
	}
}


void DisplayCorner(void)
{
	int i, l, k;
	int dd;
	for(i=0 ; i<10; i++)				  //横纵标10等分
	{
	 	address_set((9-i)*24,(9-i)*32,239,319);	  //设置每次写入坐标
		for(k = 0; k < (i+1)*24; k++ )		   //刷新次数
		{
			for(l = k*320; l < k*320+(i+1)*32; l++ )   //纵向扫描次数
			{
				dd=(0x00|girl_2[l*2+1])<<8;
	            dd=dd|girl_2[l*2];  	
	            LCD_WriteRAM(dd);	
			}
		}
		Delay(0xffff);	   //延时
		Delay(0xffff);	 
	 }		 
}
