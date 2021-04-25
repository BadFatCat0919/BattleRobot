///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板-LED驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "led.h"
/********************************************************************************
  功能：	LED初始化
  参数：	无
  返回：	无
  备注：	初始化后LED默认关闭
*********************************************************************************/
void LED_Init()
{
  GPIO_InitTypeDef  GPIO_InitStructure;										//建立初始化结构体
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
                                                          //打开GPIO时钟
  GPIO_StructInit(&GPIO_InitStructure);                   //为初始化结构体赋缺省值
  GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP;       //设置IO模式为推挽输出
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_11|GPIO_Pin_15;
  GPIO_Init(GPIOA, &GPIO_InitStructure);							    //读取初始化结构体的值
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_3;             //设置初始化引脚编号
  GPIO_Init(GPIOB, &GPIO_InitStructure);							    //读取初始化结构体的值
  
	LED_USER=LED_USER_ON;
  LED_R = LED_RGB_OFF;                                     //IO初始化完成后关闭LED
  LED_G = LED_RGB_OFF;                                     //IO初始化完成后关闭LED
  LED_B = LED_RGB_OFF;                                     //IO初始化完成后关闭LED
	BLUETOOTH_EN=BLUETOOTH_OFF;
}
/********************************************************************************
	功能：	LED_User闪烁
	参数：	time	闪烁频率（本函数运行多少次时改变LED_User开关状态）
	返回：	无
	备注：	无
*********************************************************************************/
void LED_User_Flash( uint16_t time)
{
	  static int temp;
	  if(time==0)
	  	LED_USER=LED_USER_OFF;
	  else
	  	if(++temp==time)
				LED_USER=!LED_USER,temp=0;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
