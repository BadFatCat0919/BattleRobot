///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���ߵ��Բ˵���-��������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __KEY_H
#define __KEY_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*���ð���������ƽ*/
#define KEY_PRESS   0
#define KEY_RELEASE ��KEY_PRESS
/*���ð���ռ��IO��*/
#define KEY_OK 		PAin(12)
#define KEY_BACK 	PBin(0)
#define KEY_UP 		PBin(14)
#define KEY_DOWN 	PBin(12)
#define KEY_LEFT 	PAin(8)
#define KEY_RIGHT	PBin(1)
#define KEY_USER	PBin(7)
#define BLUETOOTH PAin(5)
/*��������ʱ�䣨ms��*/
#define KEY_FILTER  1
/*���ð�����ֵ*/
#define __KEY_OK 		1
#define __KEY_BACK 	2
#define __KEY_UP 		3
#define __KEY_DOWN 	4
#define __KEY_LEFT 	5
#define __KEY_RIGHT 6
#define __KEY_USER  7
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void    KEY_Init(void);       //������ʼ��
void    KEY_Scan_USART(void); //ɨ���USER������������ͨ�����ڷ���
uint8_t KEY_Scan(void);       //ɨ���USER���������������ؼ�ֵ
uint8_t KEY_USER_Scan(uint16_t HoldTime);  //ɨ���û��Զ��尴��
uint8_t KEY_OK_Scan(void);    //ɨ��OK��
uint8_t KEY_BACK_Scan(void);  //ɨ��BACK��
uint8_t KEY_UP_Scan(void);    //ɨ��UP��
uint8_t KEY_DOWN_Scan(void);  //ɨ��DOWN��
uint8_t KEY_LEFT_Scan(void);  //ɨ��LEFT��
uint8_t KEY_RIGHT_Scan(void); //ɨ��RIGHT��
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
