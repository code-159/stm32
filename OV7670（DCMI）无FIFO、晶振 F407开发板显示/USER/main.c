#include "main.h"
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ��  
	KEY_Init();					//������ʼ�� 
 	usmart_dev.init(84);		//��ʼ��USMART
 	POINT_COLOR=RED;//��������Ϊ��ɫ
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"OV7670 TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2019/1/15");  		
	while(OV7670_Init())//��ʼ��OV7670
	{
		LCD_ShowString(30,130,240,16,16,"OV7670 ERR");
		delay_ms(200);
	    LCD_Fill(30,130,239,170,WHITE);
		delay_ms(200);
	}
	LCD_ShowString(30,130,200,16,16,"OV7670 OK"); 
	LCD_ShowNum(30,150,lcddev.id,16,16);
	printf("HELLO \r\n");					//����NRF24L01�������໥ͨ�Ų���������
	delay_ms(500);	
	OV7670_Window_Set(12,176,240,320);//OV7670�����������
	My_DCMI_Init();			//DCMI����
	DCMI_DMA_Init((u32)&LCD->LCD_RAM,10,DMA_MemoryDataSize_HalfWord,DMA_MemoryInc_Disable);//DCMI DMA����  
	DCMI_Start();//��������	
 	while(1)
	{		
		//��Ϊһֱ�ڴ������ݣ�WHILE(1)���ڷ��ˣ�����������DCMI�жϴ���������
	}
}

