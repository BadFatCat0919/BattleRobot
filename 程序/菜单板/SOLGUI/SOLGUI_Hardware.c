#include "SOLGUI_Type.h"
#include "SOLGUI_Config.h"
#include "SOLGUI_Hardware.h"

//*******************【屏幕驱动头文件】*******************
#include "oled.h"
#include "delay.h"
#include "usart.h"
//##########################【需要用户实现的部分】############################

void SOLGUI_Hardware_Init(void)
{
//=========【用户硬件初始化移植处】=======

//========================================
}

void OLED_Show(u8* buff);
void SOLGUI_Hardware_FillScreen(u8 GRAM[SCREEN_X_WIDTH][SCREEN_Y_PAGE])
{
//=========【用户硬件屏幕填充函数移植处】=======
	uint8_t x,y;
	
	for(y=0;y<SCREEN_Y_PAGE;y++)
	{
		OLED_WR_Byte (0xb0+y,OLED_CMD); //设置页地址（0~7）
    OLED_WR_Byte (0x00,OLED_CMD);   //设置显示位置—列低地址
    OLED_WR_Byte (0x10,OLED_CMD);   //设置显示位置—列高地址

		for(x=0;x<SCREEN_X_WIDTH;x++)
			OLED_WR_Byte(GRAM[x][y],OLED_DATA);
	}	
//========================================
}

void SOLGUI_Hardware_ClearScreen(void)
{
//=========【用户硬件清屏函数移植处】=======
//	uint8_t x,y;
//	
//	for(y=0;y<SCREEN_Y_PAGE;y++)
//	{
//		OLED_WR_Byte (0xb0+y,OLED_CMD); //设置页地址（0~7）
//    OLED_WR_Byte (0x00,OLED_CMD);   //设置显示位置—列低地址
//    OLED_WR_Byte (0x10,OLED_CMD);   //设置显示位置—列高地址

//		for(x=0;x<SCREEN_X_WIDTH;x++)
//			OLED_WR_Byte(0,OLED_DATA);
//	}	  
//========================================	
}



