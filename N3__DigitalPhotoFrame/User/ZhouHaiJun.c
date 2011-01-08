/********************************************************************************
* 
* @file    ./N3__DigitalPhotoFrame/User/ZhouHaiJun.c 
* @author  周海军
* @version 0.1
* @date    07/01/2011
*
*******************************************************************************/

#include "lcd.h"
#include "stm32f10x_usart.h"
#include "BaiMing.h"
#include "GuoWenGang.h"
#include "time.h"
#include "stdlib.h"

#define ESC 27

extern const unsigned char home_picture[];
extern void WindowBlinds(void);
extern void LCD_WriteRAM(unsigned int val);
extern void address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
extern void SystemInit (void);
extern void LED_Light(u32 i);
extern u8 Read_Ads7846(void);
extern void delay_ms(u16 nms);
extern void delay_us(u32 Nus);
void RandPicture(void);
extern const unsigned char girl_1[];
extern const unsigned char girl_2[];
extern unsigned char _it1;
extern unsigned int Xs,Ys;
extern unsigned int X,Y;

void Delay(vu32 Time);

int count = 0;
int flag = 0;

unsigned char TxBuf[10]  = " \r\n";
unsigned char TxBuf1[54] = " **************************************************\r\n";
unsigned char TxBuf2[54] = " *                                                *\r\n";
unsigned char TxBuf3[50] = "\r\n Please input your choice :\r\n ";
unsigned char TxBuf4[54] = " *     Welcome to our digital photo world ^_^     *\r\n";
unsigned char TxBuf5[50] = "\r\n Press '1' to last photo\r\n ";
unsigned char TxBuf6[50] = "\r\n Press '2' to next photo\r\n ";
//unsigned char TxBuf7[50] = "\r\n Press '3' to show special effect\r\n ";
unsigned char TxBuf8[50] = "\r\n Press ESC to back to meun\r\n ";



/*******************************************************************************
* Author		 : 周海军
* Date           : 07/01/2011
* Function Name  : Show_home_picture
* Description    : void Show_home_picture(void).
* Input          : - home_picture: The array data of picture named home_picture.
* Output         : None
* Return         : None
*******************************************************************************/
void Show_home_picture(void)
{
	u32 i, dd;
	address_set(0,0,239,319);
	for(i = 0; i < 153608/2; i++)
	{
		dd=(0x00|home_picture[i*2 + 1])<<8;
		dd=dd|home_picture[i*2];
		LCD_WriteRAM(dd);	
	}		
}

/*******************************************************************************
* Author		 : 周海军
* Date           : 07/01/2011
* Function Name  : ShowPicture
* Description    : void ShowPicture(void).
* Input          : - girl_1: The array data of picture named girl_1.
* Output         : None
* Return         : None
*******************************************************************************/
void ShowPicture(void)
{
	u32 i, dd;
	address_set(0,0,239,319);
	for(i = 0; i < 153608/2; i++)
	{
		dd=(0x00|girl_1[i*2 + 1])<<8;
		dd=dd|girl_1[i*2];
		LCD_WriteRAM(dd);	
	}	
}

/*******************************************************************************
* Author		 : 周海军
* Date           : 07/01/2011
* Function Name  : ShowPicture1
* Description    : void ShowPicture1(void).
* Input          : - navy_image: The array data of picture named navy_image.
* Output         : None
* Return         : None
*******************************************************************************/
void ShowPicture1(void)
{
	u32 i, dd;
	address_set(0,0,239,319);
	for(i = 0; i < 153608/2; i++)
	{
		dd=(0x00|girl_2[i*2 + 1])<<8;
		dd=dd|girl_2[i*2];
		LCD_WriteRAM(dd);	
	}	
}

/*******************************************************************************
* Author		 : 周海军
* Date           : 07/01/2011
* Function Name  : USART_PrintWelcomeMeun
* Description    : void USART_PrintWelcomeMeun(void).
* Input          : - TxBuf: The data printed to upper computer. 
*                  - TxBuf1-8: The data printed to upper computer.
* Output         : None
* Return         : None
*******************************************************************************/
void USART_PrintWelcomeMeun(void)
{
	u32 i;
	for( i = 0; TxBuf[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf1[i] != '\0'; i++)
	{
		USART_SendData(USART1 , TxBuf1[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf2[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf2[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf4[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf4[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf2[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf2[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf2[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf2[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf1[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf1[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf5[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf5[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf6[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf6[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
//	for( i = 0; TxBuf7[i] != '\0'; i++) 
//	{
//		USART_SendData(USART1 , TxBuf7[i]);
//		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
//	}
	for( i = 0; TxBuf8[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf8[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
	}
	for( i = 0; TxBuf3[i] != '\0'; i++) 
	{
		USART_SendData(USART1 , TxBuf3[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);	
	}
}

/*******************************************************************************
* Function Name  : USART1_Config
* Description    : void USART1_Config(void).
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART1_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
    USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1, &USART_InitStructure); 
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
	USART_Cmd(USART1, ENABLE);
}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : void GPIO_Configuration(void).
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 |RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
    RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
    RCC_APB2Periph_GPIOE, ENABLE);					 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	         
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);		   

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	        
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
	GPIO_Init(GPIOA, &GPIO_InitStructure);		       
}

/*******************************************************************************
* Function Name  : Delay
* Description    : Delay(vu32 Time)
* Input          : - Time: Delayed time;
* Output         : None
* Return         : None
*******************************************************************************/
void Delay(vu32 Time)
{
	for(; Time != 0; Time--);
}


/*******************************************************************************
* Author		 : 周海军
* Date           : 07/01/2011
* Function Name  : touch
* Description    : void touch(void).
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void touch(void)
{
  	unsigned char a = 0;  						   
	if(_it1 == 1)
	{
		delay_ms(10);
		a = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);
		if(a == 0)
		{
			while(a == 0)
			{
				delay_us(10);
				Read_Ads7846();
				Xs = X; Ys = Y;
				a = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);
				_it1 = 0;
				RandPicture();
		//		count++;
		//		if (count == 5)
		//			count = 1;
				flag = 1;	
				break;
			}	 
		}
		else
		{
			_it1 = 0;
		}	
	}				
}

/*******************************************************************************
* Author		 : 周海军
* Date           : 08/01/2011
* Function Name  : RandPicture
* Description    : void RandPicture(void).
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RandPicture(void)
{
	count = rand()%5 + 1;	
}

/*******************************************************************************
* Author		 : 周海军
* Date           : 07/01/2011
* Function Name  : perform
* Description    : void perform(void).
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void perform(void)
{	
	char RX_data = 0;
	int RX_status = 0;
	count = 0;	
	
	GPIO_Configuration();
	USART1_Config();
	Show_home_picture();
	USART_PrintWelcomeMeun();
	while (1)									  
	{
		RX_status = USART_GetFlagStatus(USART1, USART_FLAG_RXNE);		
		if(RX_status == SET) 
		{
			RX_data = USART_ReceiveData(USART1);
			USART_SendData(USART1 , RX_data);
			USART_SendData(USART1 , '\r');
			flag = 1;
			switch (RX_data)
			{
				case '1':
				{
					count++;
					if(count == 6) 
						count = 1;										
					break;	
				}
				case '2':
				{
					count--;
					if(count == 0) 
						count = 5;					
					break;
				}
				case ESC:
				{
				 	RX_data = 0;
					count = 0;					
					break;
				}
				default :
				{
					break;
				}
			}				
        }
		touch();

		switch (count)
		{
			case 0: 
			{
				if (flag == 1)
				{
					LED_Light(5);
					USART_PrintWelcomeMeun();
					Show_home_picture();
					flag = 0; 	
				}				
				break;	
			}			
			case 1:	
			{
				if (flag == 1)
				{
					LED_Light(1);
					ShowPicture();
					flag = 0; 	
				}  
				break;	
			}
			case 2:
			{
				if (flag == 1)
				{
					LED_Light(2);
					ShowPicture1();
					flag = 0; 	
				}  			
				break;	
			} 
			case 3: 
			{
 				if (flag == 1)
				{
					LED_Light(3);
					ShowSpecialEffect();
					flag = 0; 	
				} 
				break;	
			}
			case 4: 
			{
 				if (flag == 1)
				{
					LED_Light(4);
					WindowBlinds();
					flag = 0; 	
				} 
				break;	
			}
			case 5: 
			{
 				if (flag == 1)
				{
					LED_Light(6);
					DisplayDownUp();
					flag = 0; 	
				} 
				break;	
			}			
			default : break;
		}		
	}
}
