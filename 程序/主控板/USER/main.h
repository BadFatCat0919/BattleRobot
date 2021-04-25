///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-����ͷ�ļ�
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __MAIN_H__
#define __MAIN_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "control.h"
#include "data.h"
#include "delay.h"
#include "ANO.h"
#include "usart.h"
#include "timer.h"
#include "led.h"
#include "beep.h"
#include "adc.h"
#include "key.h"
#include "bluetooth.h"
#include "PinConfig.h"
#include <string.h> 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�˲���if
#define IF(STATE,program)\
if(STATE){delay_ms(10);if(STATE){program}}
//�ɴ���delay
#define delay_while(TIME,STATE)\
{static uint16_t temp=TIME;while(STATE&&temp>0){temp--;delay_ms(1);}}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#define __KEY_OK 	1
#define __KEY_BACK 	2
#define __KEY_UP 	3
#define __KEY_DOWN 	4
#define __KEY_LEFT 	5
#define __KEY_RIGHT 6
///////////////////////////////////////////////////////////////////-=505-Tech=-///
typedef union{
	uint16_t u16;
	uint8_t  u8[2];
}U16_TO_U8_DATA;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern U16_TO_U8_DATA  USART3_Buf[10];
extern uint8_t CarRunEN;
extern uint16_t TestFan;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
