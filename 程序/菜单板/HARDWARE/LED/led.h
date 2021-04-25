///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板-LED驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __LED_H__
#define __LED_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置LED触发电平*/
#define LED_USER_ON         1
#define LED_RGB_ON          0
#define BLUETOOTH_ON        1
#define LED_USER_OFF        !LED_USER_ON
#define LED_RGB_OFF         !LED_RGB_ON
#define BLUETOOTH_OFF       !BLUETOOTH_ON
/*设置LED占用IO口*/
#define LED_R        				PBout(3)
#define LED_G        				PAout(3)
#define LED_B        				PAout(15)
#define LED_USER     				PAout(11)
#define BLUETOOTH_EN				PAout(4)
/*定义LEDRGB开关操作*/
#define LED_R_ON()					{LED_R=LED_RGB_ON;}
#define LED_R_OFF()					{LED_R=LED_RGB_OFF;}
#define LED_G_ON()					{LED_G=LED_RGB_ON;}
#define LED_G_OFF()					{LED_G=LED_RGB_OFF;}
#define LED_B_ON()					{LED_B=LED_RGB_ON;}
#define LED_B_OFF()					{LED_B=LED_RGB_OFF;}
#define LED_RGB_ALLOFF()		{LED_R_OFF();LED_G_OFF();LED_B_OFF();}
/*定义LED显示对应颜色操作*/
#define LED_ShowRed()				{LED_RGB_ALLOFF();LED_R_ON();}
#define LED_ShowGreen()			{LED_RGB_ALLOFF();LED_G_ON();}
#define LED_ShowBlue()			{LED_RGB_ALLOFF();LED_B_ON();}
#define LED_ShowYellow()		{LED_RGB_ALLOFF();LED_R_ON();LED_G_ON();}
#define LED_ShowPurple()		{LED_RGB_ALLOFF();LED_R_ON();LED_B_ON();}
#define LED_ShowLightblue()	{LED_RGB_ALLOFF();LED_G_ON();LED_B_ON();}
#define LED_ShowWhite()			{LED_RGB_ALLOFF();LED_R_ON();LED_G_ON();LED_B_ON();}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void LED_Init(void);                  //LED初始化
void LED_User_Flash( uint16_t time);   //LED1闪烁
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
