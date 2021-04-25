///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板-串口驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "usart.h"
#include "led.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint8_t  USART1_Buf[USART1_MAX_LEN];
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
	功能：	串口1初始化
	参数：	bound 波特率
	返回：	无
	备注：	无
*********************************************************************************/
void USART1_Init(uint32_t bound)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);
  
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin	= GPIO_Pin_9;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin	= GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel						= USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority 			= 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd 					= ENABLE;	
	NVIC_Init(&NVIC_InitStructure);

	USART_StructInit(&USART_InitStructure);
	USART_InitStructure.USART_BaudRate						= bound;
	USART_InitStructure.USART_WordLength					= USART_WordLength_8b;
	USART_InitStructure.USART_StopBits						= USART_StopBits_1;
	USART_InitStructure.USART_Parity						= USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl			= USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode							= USART_Mode_Tx|USART_Mode_Rx;
	USART_Init(USART1, &USART_InitStructure);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

	USART_Cmd(USART1, ENABLE);

}
/********************************************************************************
	功能：	串口1接收中断
	参数：	无
	返回：	无
	备注：	接收菜单数据
*********************************************************************************/
void USART1_IRQHandler(void)
{
	u8 Res;
	static u8 Row=0,Check=0;
	static u16 i=0;
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		Res=USART_ReceiveData(USART1);
		
		if(Check!=0)
		{
			if( Res-180==Check )
			{
				Row=Check-1;
				Check=0;
				i=0;
			}
			else
			{
				Check=0;
				USART1_Buf[Row*128+i++]=Check+100;
				if(i>=128)i=0;
				USART1_Buf[Row*128+i++]=Res;
				if(i>=128)i=0;
			}
		}
		else
		{
			if( ( (Res-100>=1)&&(Res-100<=8) ) )
			{
				Check=Res-100;
				
				LED_User_Flash(1);
			}
			else
			{
				USART1_Buf[Row*128+i++]=Res;
				if(i>=128)i=0;
			}
		}
	}
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
