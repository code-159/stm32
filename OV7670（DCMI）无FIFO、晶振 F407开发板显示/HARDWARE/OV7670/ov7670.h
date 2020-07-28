#ifndef _OV7670_H
#define _OV7670_H
#include "sys.h"
#include "sccb.h"
#define OV7670_PWDN  	PGout(9)			//POWER DOWN�����ź� 
#define OV7670_RST  	PGout(15)			//��λ�����ź� 
////////////////////////////////////////////////////////////////////////////////// 
#define OV7670_MID				0X7FA2    
#define OV7670_PID				0X7673
													  					 
#define OV7670_DATA   GPIO_ReadInputData(GPIOC,0x00FF) 					//��������˿�
//GPIOC->IDR&0x00FF 
/////////////////////////////////////////


void MCLK_ON(void);
void MCLK_OFF(void);
u8   OV7670_Init(void);		  	   		 
void OV7670_Light_Mode(u8 mode);
void OV7670_Color_Saturation(u8 sat);
void OV7670_Brightness(u8 bright);
void OV7670_Contrast(u8 contrast);
void OV7670_Special_Effects(u8 eft);
void OV7670_Window_Set(u16 sx,u16 sy,u16 width,u16 height);
void set_cif(void);

#endif





















