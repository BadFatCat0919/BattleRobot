///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-有源蜂鸣器驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "beep.h"
#include "delay.h"
uint8_t BEEP_USING_FLAG=0;
/********************************************************************************
  功能：	蜂鸣器初始化
  参数：	无
  返回：	无
  备注：	初始化后蜂鸣器默认关闭
*********************************************************************************/
void BEEP_Init()
{
  GPIO_InitTypeDef  GPIO_InitStructure;										//建立初始化结构体
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   //打开GPIO时钟
	
  GPIO_StructInit(&GPIO_InitStructure);                   //为初始化结构体赋缺省值
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_6;             //设置初始化引脚编号
  GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP;       //设置IO模式为推挽输出
  GPIO_Init(GPIOC, &GPIO_InitStructure);							    //读取初始化结构体的值
  
  BEEP = BEEP_OFF;                                        //IO初始化完成后关闭蜂鸣器
}
/********************************************************************************
	功能：	蜂鸣器短促蜂鸣数次
	参数：	times	蜂鸣次数
	返回：	无
	备注：	无
*********************************************************************************/
void BEEP_Hint(uint16_t times)
{
	BEEP_USING_FLAG=1;
	while(times--)
	{
		BEEP = BEEP_ON;
		delay_ms(100);
		BEEP = BEEP_OFF;
		delay_ms(100);
	}
	BEEP_USING_FLAG=0;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
