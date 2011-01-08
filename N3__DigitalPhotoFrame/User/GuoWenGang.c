/********************************************************************************
* 
* @file    ./N3__DigitalPhotoFrame/User/GuoWenGang.c 
* @author  国文刚
* @version 0.1
* @date    07/01/2011
*
*******************************************************************************/

extern void address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
extern const unsigned char girl_1[];
extern void LCD_WriteRAM(unsigned int val);


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
		for(k=0; k < (25 - i)*3200; k++)		 
		{
			dd=(0x00|girl_1[k*2 + 1])<<8;
	        dd=dd|girl_1[k*2];  	
	        LCD_WriteRAM(dd);
	   	}
	}
}
