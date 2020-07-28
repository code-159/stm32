#include "main.h"
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化  
	KEY_Init();					//按键初始化 
 	usmart_dev.init(84);		//初始化USMART
 	POINT_COLOR=RED;//设置字体为红色
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"OV7670 TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2019/1/15");  		
	while(OV7670_Init())//初始化OV7670
	{
		LCD_ShowString(30,130,240,16,16,"OV7670 ERR");
		delay_ms(200);
	    LCD_Fill(30,130,239,170,WHITE);
		delay_ms(200);
	}
	LCD_ShowString(30,130,200,16,16,"OV7670 OK"); 
	LCD_ShowNum(30,150,lcddev.id,16,16);
	printf("HELLO \r\n");					//用于NRF24L01串口先相互通信才正常连接
	delay_ms(500);	
	OV7670_Window_Set(12,176,240,320);//OV7670设置输出窗口
	My_DCMI_Init();			//DCMI配置
	DCMI_DMA_Init((u32)&LCD->LCD_RAM,10,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Disable);//DCMI DMA配置  
	DCMI_Start();//启动传输	
 	while(1)
	{		
		//因为一直在传输数据，WHILE(1)等于废了，处理函数都在DCMI中断处理函数里面
	}
}

