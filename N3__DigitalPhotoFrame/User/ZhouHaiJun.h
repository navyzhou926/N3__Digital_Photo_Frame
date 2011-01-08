/********************************************************************************
* 
* @file    ./N3__DigitalPhotoFrame/User/ZhouHaiJun.h 
* @author  ÖÜº£¾ü
* @version 0.1
* @date    07/01/2011
*
*******************************************************************************/

#ifndef __ZHOUHAIJUN_H
#define __ZHOUHAIJUN_H

extern void Show_home_picture(void);
extern void ShowPicture(void);
extern void ShowPicture1(void);
extern void ShowSpecialEffect(void);
extern void perform(void); 
extern void GPIO_Configuration(void);
extern void USART1_Config(void);
extern void USART_PrintWelcomeMeun(void);
extern void touch(void);

extern unsigned char TxBuf[10];
extern unsigned char TxBuf1[54];
extern unsigned char TxBuf2[54];
extern unsigned char TxBuf3[50];
extern unsigned char TxBuf4[54];
extern unsigned char TxBuf5[50];
extern unsigned char TxBuf6[50];
extern unsigned char TxBuf7[50];
extern unsigned char TxBuf8[50];



#endif /* __ZHOUHAIJUN_H */

/******************* (C) COPYRIGHT 2011 ZHOUHAIJUN *****END OF FILE****/
