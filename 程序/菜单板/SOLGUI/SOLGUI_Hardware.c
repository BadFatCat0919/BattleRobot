#include "SOLGUI_Type.h"
#include "SOLGUI_Config.h"
#include "SOLGUI_Hardware.h"

//*******************����Ļ����ͷ�ļ���*******************
#include "oled.h"
#include "delay.h"
#include "usart.h"
//##########################����Ҫ�û�ʵ�ֵĲ��֡�############################

void SOLGUI_Hardware_Init(void)
{
//=========���û�Ӳ����ʼ����ֲ����=======

//========================================
}

void OLED_Show(u8* buff);
void SOLGUI_Hardware_FillScreen(u8 GRAM[SCREEN_X_WIDTH][SCREEN_Y_PAGE])
{
//=========���û�Ӳ����Ļ��亯����ֲ����=======
	uint8_t x,y;
	
	for(y=0;y<SCREEN_Y_PAGE;y++)
	{
		OLED_WR_Byte (0xb0+y,OLED_CMD); //����ҳ��ַ��0~7��
    OLED_WR_Byte (0x00,OLED_CMD);   //������ʾλ�á��е͵�ַ
    OLED_WR_Byte (0x10,OLED_CMD);   //������ʾλ�á��иߵ�ַ

		for(x=0;x<SCREEN_X_WIDTH;x++)
			OLED_WR_Byte(GRAM[x][y],OLED_DATA);
	}	
//========================================
}

void SOLGUI_Hardware_ClearScreen(void)
{
//=========���û�Ӳ������������ֲ����=======
//	uint8_t x,y;
//	
//	for(y=0;y<SCREEN_Y_PAGE;y++)
//	{
//		OLED_WR_Byte (0xb0+y,OLED_CMD); //����ҳ��ַ��0~7��
//    OLED_WR_Byte (0x00,OLED_CMD);   //������ʾλ�á��е͵�ַ
//    OLED_WR_Byte (0x10,OLED_CMD);   //������ʾλ�á��иߵ�ַ

//		for(x=0;x<SCREEN_X_WIDTH;x++)
//			OLED_WR_Byte(0,OLED_DATA);
//	}	  
//========================================	
}



