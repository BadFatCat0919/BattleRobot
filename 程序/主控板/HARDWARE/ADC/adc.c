///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-ADC驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0.1.190719_Beta
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "adc.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint16_t ADC_BUFF[16];
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
  功能：	ADC初始化
  参数：	无
  返回：	无
  备注：	利用DMA读取
*********************************************************************************/
void  ADC1_Init(void)
{ 	
	ADC_InitTypeDef  ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef  DMA_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC|RCC_APB2Periph_ADC1, ENABLE);
 	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
							  
	GPIO_StructInit(&GPIO_InitStructure); 			 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	

	ADC_StructInit(&ADC_InitStructure);
	ADC_InitStructure.ADC_Mode               = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode       = ENABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv   = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign          = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel       = 16;
	ADC_Init(ADC1, &ADC_InitStructure);

	ADC_RegularChannelConfig(ADC1,ADC_Channel_9,	1,	ADC_SampleTime_239Cycles5);	//PB1
	ADC_RegularChannelConfig(ADC1,ADC_Channel_8,	2,	ADC_SampleTime_239Cycles5);	//PB0
	ADC_RegularChannelConfig(ADC1,ADC_Channel_15,	3,	ADC_SampleTime_239Cycles5);	//PC5
	ADC_RegularChannelConfig(ADC1,ADC_Channel_14,	4,	ADC_SampleTime_239Cycles5);	//PC4
	ADC_RegularChannelConfig(ADC1,ADC_Channel_7,	5,	ADC_SampleTime_239Cycles5);	//PA7
	ADC_RegularChannelConfig(ADC1,ADC_Channel_6,	6,	ADC_SampleTime_239Cycles5);	//PA6
	ADC_RegularChannelConfig(ADC1,ADC_Channel_5,	7,	ADC_SampleTime_239Cycles5);	//PA5
	ADC_RegularChannelConfig(ADC1,ADC_Channel_4,	8,	ADC_SampleTime_239Cycles5);	//PA4
	ADC_RegularChannelConfig(ADC1,ADC_Channel_3,	9,	ADC_SampleTime_239Cycles5);	//PA3
	ADC_RegularChannelConfig(ADC1,ADC_Channel_2,	10,	ADC_SampleTime_239Cycles5);	//PA2
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,	11,	ADC_SampleTime_239Cycles5);	//PA1
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,	12,	ADC_SampleTime_239Cycles5);	//PA0
	ADC_RegularChannelConfig(ADC1,ADC_Channel_13,	13,	ADC_SampleTime_239Cycles5);	//PC3
	ADC_RegularChannelConfig(ADC1,ADC_Channel_12,	14,	ADC_SampleTime_239Cycles5);	//PC2
	ADC_RegularChannelConfig(ADC1,ADC_Channel_11,	15,	ADC_SampleTime_239Cycles5);	//PC1
	ADC_RegularChannelConfig(ADC1,ADC_Channel_10,	16,	ADC_SampleTime_239Cycles5);	//PC0

	ADC_DMACmd(ADC1,ENABLE);
	ADC_Cmd(ADC1, ENABLE);

	ADC_ResetCalibration(ADC1); 
	while(ADC_GetResetCalibrationStatus(ADC1));

	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));

	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
  DMA_StructInit(&DMA_InitStructure);
	DMA_InitStructure.DMA_PeripheralBaseAddr = ( uint32_t)&ADC1->DR; 
	DMA_InitStructure.DMA_MemoryBaseAddr     = ( uint32_t)ADC_BUFF;
	DMA_InitStructure.DMA_DIR                = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize         = 16;
	DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode               = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority           = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M                = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);

	DMA_Cmd(DMA1_Channel1, ENABLE);
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
