#include "SOLGUI_Type.h"
#include "SOLGUI_Config.h"
#include "SOLGUI_Hardware.h"

//*******************【屏幕驱动头文件】*******************

//##########################【需要用户实现的部分】############################

void SOLGUI_Hardware_Init(void)
{
//=========【用户硬件初始化移植处】=======

//========================================
}

void SOLGUI_Hardware_FillScreen(u8 GRAM[SCREEN_X_WIDTH][SCREEN_Y_PAGE])
{
//=========【用户硬件屏幕填充函数移植处】=======
	uint8_t x,y;
	uint16_t waittime=0;
	#define USARTX UART4
	for(y=0;y<SCREEN_Y_PAGE;y++)
	{
		USART_SendData(USARTX,y+1+100);
		waittime=0;
		while((USARTX->SR&0X40)==0)
		{if(waittime++==1000)break;}
		
		USART_SendData(USARTX,y+1+180);
		waittime=0;
		while((USARTX->SR&0X40)==0)
		{if(waittime++==1000)break;}
		
		for(x=0;x<SCREEN_X_WIDTH;x++)
		{
			USART_SendData(USARTX,GRAM[x][y]);
			waittime=0;
			while((USARTX->SR&0X40)==0)
			{if(waittime++==1000)break;}
		}
	}	   
//========================================
}

void SOLGUI_Hardware_ClearScreen(void)
{
//=========【用户硬件清屏函数移植处】=======
//========================================	
}



