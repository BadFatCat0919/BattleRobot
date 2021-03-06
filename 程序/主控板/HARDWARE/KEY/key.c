///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-按键驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "key.h"
#include "beep.h"
/********************************************************************************
  功能：	按键初始化
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
void KEY_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;                     //建立初始化结构体
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);     //打开GPIO时钟

  GPIO_StructInit(&GPIO_InitStructure);                    //为初始化结构体赋缺省值
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9;    //设置初始化引脚编号;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;            //设置IO模式为上拉输入
  GPIO_Init(GPIOB, &GPIO_InitStructure);							     //读取初始化结构体的值
}
/********************************************************************************
  功能：	扫描按键
  参数：	无
  返回：	键值
  备注：	消抖时间可通过KEY_FILTER更改
*********************************************************************************/
uint8_t KEY_Scan(void)
{
  uint8_t value=0;                                          //设置键值缺省为0
  
  if ( KEY_L == KEY_PRESS || KEY_R == KEY_PRESS )
  {
    delay_ms(KEY_FILTER);                                   //消抖
	BEEP_USING_FLAG=1;
    BEEP=BEEP_ON;
    if      (KEY_L 	== KEY_PRESS)value = __KEY_L;      		//判断键值
    else if (KEY_R 	== KEY_PRESS)value = __KEY_R;
  
	while( KEY_L == KEY_PRESS || KEY_R == KEY_PRESS );		//等待按键释放
  }
    BEEP=BEEP_OFF;
	BEEP_USING_FLAG=0;
  
  return value;                                             //返回键值
}
/********************************************************************************
  功能：	扫描左键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_L_Scan(void)
{
  if(KEY_L == KEY_PRESS)                                   	//判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_L == KEY_PRESS)
    {
      while(KEY_L == KEY_PRESS);                           	//等待按键释放
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  功能：	扫描右键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_R_Scan(void)
{
  if(KEY_R == KEY_PRESS)                                   	//判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_R == KEY_PRESS)
    {
      while(KEY_R == KEY_PRESS);                           	//等待按键释放
      return 1;
    }
  }
  
  return 0;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
