/********************************************************************************
* 
* @file    ./N3__DigitalPhotoFrame/User/BaiMing.c 
* @author  °×Ã÷
* @version 0.1
* @date    07/01/2011
*
*******************************************************************************/


#include "lcd.h"

extern void address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
extern const unsigned char home_picture[];
extern void LCD_WriteRAM(unsigned int val);
extern void Delay(vu32 Time);


/*******************************************************************************
* Author		 : °×Ã÷
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
	LCD_Clear(Yellow);
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
