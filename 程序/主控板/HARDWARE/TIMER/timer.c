///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-��ʱ������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "timer.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
  ���ܣ�	PWM��ʼ��
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void PWM_Init(void)
{
	TIM1_PWM_Init();
	TIM2_PWM_Init();
	TIM8_PWM_Init();
}
/********************************************************************************
  ���ܣ�	��������ʼ��
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void Encoder_Init(void)
{
	TIM3_Encoder_Init();
	TIM4_Encoder_Init();
}
/********************************************************************************
  ���ܣ�	��ʱ���жϳ�ʼ��
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void TIMInterrupt_Init(void)
{
  TIM6_Interrupt_Init();
//  TIM7_Interrupt_Init();
}
/********************************************************************************
  ���ܣ�	TIM1��ʼ��
  ������	��
  ���أ�	��
  ��ע��	����1KHzPWM����������˶����
        PWMƵ��=72000000/(Period+1)/(Prescaler+1)=1kHz
        CH1  PA8
        CH2  PA9
        CH3  PA10
        CH4  PA11
*********************************************************************************/
void TIM1_PWM_Init(void)
{
  GPIO_InitTypeDef         GPIO_InitStructure;
  TIM_OCInitTypeDef        TIM_OCInitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
  TIM_BDTRInitTypeDef      TIM_BDTRInitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOA, ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Period        = 1021-1;
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 70-1;
  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

  TIM_OCStructInit(&TIM_OCInitStructure);
  TIM_OCInitStructure.TIM_OCMode       = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState  = TIM_OutputState_Enable;
  TIM_OC1Init(TIM1, &TIM_OCInitStructure);
  TIM_OC2Init(TIM1, &TIM_OCInitStructure);
  TIM_OC3Init(TIM1, &TIM_OCInitStructure);
  TIM_OC4Init(TIM1, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
  TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
  TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
  TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);

  TIM_BDTRStructInit(&TIM_BDTRInitStructure);
  TIM_BDTRConfig(TIM1,&TIM_BDTRInitStructure);

  TIM_ARRPreloadConfig(TIM1, ENABLE);
  TIM_CtrlPWMOutputs(TIM1,ENABLE);
  TIM_Cmd(TIM1, ENABLE);
}
/********************************************************************************
  ���ܣ�	TIM2��ʼ��
  ������	��
  ���أ�	��
  ��ע��	����5HzPWM��������ƺ�������
        PWMƵ��=72000000/(Period+1)/(Prescaler+1)=100Hz
        CH1  PA15
*********************************************************************************/
void TIM2_PWM_Init(void)
{
  GPIO_InitTypeDef         GPIO_InitStructure;
  TIM_OCInitTypeDef        TIM_OCInitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);
	
  GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_3;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInitStructure.TIM_Period 				= 1000-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler     = 1440-1;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
  TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode 			= TIM_OCMode_PWM2;
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity 	= TIM_OCPolarity_Low;
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);

	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

  TIM_SetCounter(TIM2,0);

  TIM_Cmd(TIM2, ENABLE);
}
/********************************************************************************
  ���ܣ�	TIM3������ģʽ��ʼ��
  ������	��
  ���أ�	��
  ��ע��	���ڶ�ȡ������
        ���Ų�����ӳ�󣬱�����ģʽ�½�ͨ��1��ͨ��2����
        CH1  PB4
        CH2  PB5
*********************************************************************************/
void TIM3_Encoder_Init(void)
{
  GPIO_InitTypeDef        GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef	TIM_TimeBaseInitStructure;
  TIM_ICInitTypeDef		    TIM_ICInitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
	
  GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4|GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Period        = 65535-1;
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 1-1;
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising ,TIM_ICPolarity_Rising);
	
  TIM_ICStructInit(&TIM_ICInitStructure);
  TIM_ICInitStructure.TIM_ICFilter = 10;
  TIM_ICInit(TIM3, &TIM_ICInitStructure);

  TIM_SetCounter(TIM3,0);

  TIM_Cmd(TIM3, ENABLE);
}
/********************************************************************************
  ���ܣ�	TIM4������ģʽ��ʼ��
  ������	��
  ���أ�	��
  ��ע��	���ڶ�ȡ������
        ������ģʽ�½�ͨ��1��ͨ��2����
        CH1  PB6
        CH2  PB7
*********************************************************************************/
void TIM4_Encoder_Init(void)
{
  GPIO_InitTypeDef        GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  TIM_ICInitTypeDef       TIM_ICInitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Period        = 65535-1;
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 1-1;
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);

  TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising ,TIM_ICPolarity_Rising);
	
  TIM_ICStructInit(&TIM_ICInitStructure);
  TIM_ICInitStructure.TIM_ICFilter = 10;
  TIM_ICInit(TIM4, &TIM_ICInitStructure);

  TIM_SetCounter(TIM4,0);

  TIM_Cmd(TIM4, ENABLE);
}
/********************************************************************************
  ���ܣ�	TIM6��ʱ�жϳ�ʼ��
  ������	��
  ���أ�	��
  ��ע��	Ƶ��=72000000/(Period+1)/(Prescaler+1)=100Hz -> 10ms
*********************************************************************************/
void TIM6_Interrupt_Init(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  NVIC_InitTypeDef        NVIC_InitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 7200-1;
  TIM_TimeBaseInitStructure.TIM_Period        = 100-1;
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);

  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);

  NVIC_InitStructure.NVIC_IRQChannel                   = TIM6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  TIM_Cmd(TIM6, ENABLE);
}
/********************************************************************************
  ���ܣ�	TIM7��ʱ�жϳ�ʼ��
  ������	��
  ���أ�	��
  ��ע��	Ƶ��=72000000/(Period+1)/(Prescaler+1)=100Hz -> 10ms
*********************************************************************************/
void TIM7_Interrupt_Init(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  NVIC_InitTypeDef        NVIC_InitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 7200-1;
  TIM_TimeBaseInitStructure.TIM_Period        = 100-1;
  TIM_TimeBaseInit(TIM7, &TIM_TimeBaseInitStructure);

  TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);

  NVIC_InitStructure.NVIC_IRQChannel                   = TIM7_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  TIM_Cmd(TIM7, ENABLE);
}
/********************************************************************************
  ���ܣ�	TIM8��ʼ��
  ������	��
  ���أ�	��
  ��ע��	����1KHzPWM�����������̨���
        PWMƵ��=72000000/(Period+1)/(Prescaler+1)=1kHz
        CH3  PC8
        CH4  PC9
*********************************************************************************/
void TIM8_PWM_Init(void)
{
  GPIO_InitTypeDef        GPIO_InitStructure;
  TIM_OCInitTypeDef       TIM_OCInitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  TIM_BDTRInitTypeDef		  TIM_BDTRInitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8|RCC_APB2Periph_GPIOC, ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8|GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Period        = 103-1;
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 35-1;
  TIM_TimeBaseInit(TIM8, &TIM_TimeBaseInitStructure);

  TIM_OCStructInit(&TIM_OCInitStructure);
  TIM_OCInitStructure.TIM_OCMode       = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState  = TIM_OutputState_Enable;
  TIM_OC3Init(TIM8, &TIM_OCInitStructure);
  TIM_OC4Init(TIM8, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);
  TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);

  TIM_BDTRStructInit(&TIM_BDTRInitStructure);
  TIM_BDTRConfig(TIM8,&TIM_BDTRInitStructure);

  TIM_ARRPreloadConfig(TIM8, ENABLE);
  TIM_CtrlPWMOutputs(TIM8,ENABLE);
  TIM_Cmd(TIM8, ENABLE);
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
