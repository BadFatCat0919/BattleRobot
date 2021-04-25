///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-����2��3����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V2.2.0.190718_Alpha
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "usart.h"
#include "menu.h"
#include "led.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint8_t         UART4_Res; 
U16_TO_U8_DATA  USART3_Buf[10];
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
  ���ܣ�	����3��ʼ��
  ������	bound ������
  ���أ�	��
  ��ע��	��ADC��չ��ͨ��
*********************************************************************************/
void USART3_ADCandUNO_Init(u32 bound)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel						        = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority			    = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd					        = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.USART_BaudRate						= bound;
    USART_InitStructure.USART_WordLength					= USART_WordLength_8b;
    USART_InitStructure.USART_StopBits						= USART_StopBits_1;
    USART_InitStructure.USART_Parity						  = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode							  = USART_Mode_Tx|USART_Mode_Rx;
    USART_Init(USART3, &USART_InitStructure);

    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
		
    USART_Cmd(USART3, ENABLE);
}
/********************************************************************************
  ���ܣ�	����4��ʼ��
  ������	bound ������
  ���أ�	��
  ��ע��	��˵���ͨ��
*********************************************************************************/
void UART4_Menu_Init(u32 bound)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel						       = UART4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.USART_BaudRate						= bound;
    USART_InitStructure.USART_WordLength					= USART_WordLength_8b;
    USART_InitStructure.USART_StopBits						= USART_StopBits_1;
    USART_InitStructure.USART_Parity						  = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode                = USART_Mode_Tx|USART_Mode_Rx;
    USART_Init(UART4, &USART_InitStructure);

    USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
    USART_Cmd(UART4, ENABLE);
}
/********************************************************************************
  ���ܣ�	����3�жϷ�����
  ������	��
  ���أ�	��
  ��ע��	��ADC��չ��ͨ��
*********************************************************************************/
void USART3_IRQHandler(void)
{
	static uint8_t Res,res_flag=0,i=0;
	
	if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)     //�����ж�
	{
			Res = USART_ReceiveData(USART3);                       //��ȡ���յ�������
			if(res_flag == 0)
			{
				if(Res == 0xfe)
					res_flag=1;
			}   
			else if(res_flag == 1)
			{
				if(Res == 0xfd)
					res_flag=2;
			}   
			else if(res_flag == 2)
			{
				USART3_Buf[i/2].u8[i%2]=Res;
				if(++i == 20)
				{
					i=0;
					res_flag=0;
				}
			}
	}
}
/********************************************************************************
  ���ܣ�	����4�жϷ�����
  ������	��
  ���أ�	��
  ��ע��	��˵���ͨ��
*********************************************************************************/
void UART4_IRQHandler(void)
{
	static uint8_t HoldFlag=0,LastRes;
	
	if (USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)     //�����ж�
	{
			LastRes = UART4_Res;
		
			UART4_Res =USART_ReceiveData(UART4);
		
			if(LastRes == UART4_Res)
				HoldFlag=1;
			else
				HoldFlag=0;
			
			if(!HoldFlag)
			{
				SOLGUI_InputKey(UART4_Res);												//��ֵ����
//				BEEP_USING_FLAG=1;
//				BEEP=BEEP_ON;
				LED_ShowWhite();
			}
	}
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
