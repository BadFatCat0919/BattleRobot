///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-LED����
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
#define LED_RGB_ON          	0
#define LED_RGB_OFF         	!LED_RGB_ON
/*����LEDռ��IO��*/
#define LED_R        			PCout(15)
#define LED_G        			PCout(14)
#define LED_B        			PCout(13)
/*����LEDRGB���ز���*/
#define LED_R_ON()				{LED_R=LED_RGB_ON;}
#define LED_R_OFF()				{LED_R=LED_RGB_OFF;}
#define LED_G_ON()				{LED_G=LED_RGB_ON;}
#define LED_G_OFF()				{LED_G=LED_RGB_OFF;}
#define LED_B_ON()				{LED_B=LED_RGB_ON;}
#define LED_B_OFF()				{LED_B=LED_RGB_OFF;}
#define LED_RGB_ALLON()			{LED_R_ON();LED_G_ON();LED_B_ON();}
#define LED_RGB_ALLOFF()		{LED_R_OFF();LED_G_OFF();LED_B_OFF();}
/*����LED��ʾ��Ӧ��ɫ����*/
#define LED_ShowRed()			{LED_RGB_ALLOFF();LED_R_ON();}
#define LED_ShowGreen()			{LED_RGB_ALLOFF();LED_G_ON();}
#define LED_ShowBlue()			{LED_RGB_ALLOFF();LED_B_ON();}
#define LED_ShowYellow()		{LED_RGB_ALLOFF();LED_R_ON();LED_G_ON();}
#define LED_ShowPurple()		{LED_RGB_ALLOFF();LED_R_ON();LED_B_ON();}
#define LED_ShowLightblue()		{LED_RGB_ALLOFF();LED_G_ON();LED_B_ON();}
#define LED_ShowWhite()			{LED_R_ON();LED_G_ON();LED_B_ON();}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void LED_Init(void);							//LED��ʼ��
void LED_R_Flash( uint16_t time);	//LED_R��˸
void LED_G_Flash( uint16_t time);	//LED_G��˸
void LED_B_Flash( uint16_t time);	//LED_B��˸
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
