///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-�ӿ�����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __PINCONFIG_H__
#define __PINCONFIG_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "timer.h"
#include "adc.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*PWM���*/
#define MotorL_P	TIM1->CCR2	//������ת
#define MotorL_N	TIM1->CCR1	//������ת
#define MotorR_P	TIM1->CCR3	//�ҵ����ת
#define MotorR_N	TIM1->CCR4	//�ҵ����ת
#define MotorJ_P	TIM8->CCR4	//��̨�����ת
#define MotorJ_N	TIM8->CCR3	//��̨�����ת

//#define MotorL_P	TIM1->CCR1	//������ת
//#define MotorL_N	TIM1->CCR2	//������ת
//#define MotorR_P	TIM1->CCR4	//�ҵ����ת
//#define MotorR_N	TIM1->CCR3	//�ҵ����ת
//#define MotorJ_P	TIM8->CCR3	//��̨�����ת
//#define MotorJ_N	TIM8->CCR4	//��̨�����ת

#define Fan     	TIM2->CCR1	//��������
/*������*/	
#define EncoderL	TIM4->CNT	//�������
#define EncoderR	TIM3->CNT	//�ұ�����
/*��̨װ�ú���*/
#define	IR_JUMP		ADC_F0		//��̨����
/*������*/
#define	IR_FL		ADC_F1		//ǰ-�����
#define	IR_FML		ADC_F3		//ǰ-��ƫ�����
#define	IR_FMR		ADC_F4		//ǰ-��ƫ�Һ���
#define	IR_FR		ADC_F6		//ǰ-�Һ���
#define	IR_BL		ADC_R4		//��-�����
#define	IR_BM		ADC_R5		//��-�к���
#define	IR_BR		ADC_R3		//��-�Һ���
#define	IR_LF		ADC_L5		//��-ǰ����
#define	IR_LM		ADC_L6		//��-�к���
#define	IR_LB		ADC_L7		//��-�����
#define	IR_RF		ADC_R0		//��-ǰ����
#define	IR_RM		ADC_R1		//��-�к���
#define	IR_RB		ADC_R2		//��-�����
#define	IR_TF		ADC_L1		//��-ǰ����
#define	WAVE_BL		(4095-ADC_L3)		//��������
#define	WAVE_BR		(4095-ADC_L2)		//���ҳ�����
/*��λ�Ҷ�*/	
#define	GRAY_FL		ADC_F2		//ǰ��Ҷ�
#define	GRAY_FR		1500//ADC_F5		//ǰ�һҶ�
#define	GRAY_BL		ADC_R7		//����Ҷ�
#define	GRAY_BR		ADC_R6		//���һҶ�
/*̨�߼������*/
#define OS_L		ADC_L4		//(4095-ADC_L9)			//������
#define	OS_R		ADC_F7		//(4095-ADC_F7)			//�ҹ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
