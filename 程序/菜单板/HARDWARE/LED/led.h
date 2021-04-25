///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���ߵ��Բ˵���-LED����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __LED_H__
#define __LED_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*����LED������ƽ*/
#define LED_USER_ON         1
#define LED_RGB_ON          0
#define BLUETOOTH_ON        1
#define LED_USER_OFF        !LED_USER_ON
#define LED_RGB_OFF         !LED_RGB_ON
#define BLUETOOTH_OFF       !BLUETOOTH_ON
/*����LEDռ��IO��*/
#define LED_R        				PBout(3)
#define LED_G        				PAout(3)
#define LED_B        				PAout(15)
#define LED_USER     				PAout(11)
#define BLUETOOTH_EN				PAout(4)
/*����LEDRGB���ز���*/
#define LED_R_ON()					{LED_R=LED_RGB_ON;}
#define LED_R_OFF()					{LED_R=LED_RGB_OFF;}
#define LED_G_ON()					{LED_G=LED_RGB_ON;}
#define LED_G_OFF()					{LED_G=LED_RGB_OFF;}
#define LED_B_ON()					{LED_B=LED_RGB_ON;}
#define LED_B_OFF()					{LED_B=LED_RGB_OFF;}
#define LED_RGB_ALLOFF()		{LED_R_OFF();LED_G_OFF();LED_B_OFF();}
/*����LED��ʾ��Ӧ��ɫ����*/
#define LED_ShowRed()				{LED_RGB_ALLOFF();LED_R_ON();}
#define LED_ShowGreen()			{LED_RGB_ALLOFF();LED_G_ON();}
#define LED_ShowBlue()			{LED_RGB_ALLOFF();LED_B_ON();}
#define LED_ShowYellow()		{LED_RGB_ALLOFF();LED_R_ON();LED_G_ON();}
#define LED_ShowPurple()		{LED_RGB_ALLOFF();LED_R_ON();LED_B_ON();}
#define LED_ShowLightblue()	{LED_RGB_ALLOFF();LED_G_ON();LED_B_ON();}
#define LED_ShowWhite()			{LED_RGB_ALLOFF();LED_R_ON();LED_G_ON();LED_B_ON();}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void LED_Init(void);                  //LED��ʼ��
void LED_User_Flash( uint16_t time);   //LED1��˸
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
