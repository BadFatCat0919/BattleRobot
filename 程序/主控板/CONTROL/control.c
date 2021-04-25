///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-�����㷨
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "control.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
int16_t SpeedL=0,SpeedR=0;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void Limiting(int16_t* Value,int16_t Range);
void Set_PWM(int16_t pwml,int16_t pwmr);
void Read_Encoder(void);
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
    ���ܣ�	TIM6��ʱ�жϷ�����
    ������	��
    ���أ�	��
    ��ע��	�������п����㷨��10ms����һ�Σ�ʹ��ǰ��ȷ��TIM6�ѳ�ʼ��
*********************************************************************************/
void TIM6_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)     //���TIM6�����жϷ������
	{
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);         //���TIM6�����жϱ�־
//====================�������ȿ���=======================//
		Fan=TestFan;
//===================��������ֵ��ȡ======================//
		Read_Encoder();
//=====================����������========================//
		if(!UART4_Res)
		{
			if (!BEEP_USING_FLAG)
				BEEP=BEEP_OFF;
		}
	}
}
/********************************************************************************
    ���ܣ�	TIM7��ʱ�жϷ�����
    ������	��
    ���أ�	��
    ��ע��	100ms����һ�Σ�ʹ��ǰ��ȷ��TIM7�ѳ�ʼ��
*********************************************************************************/
void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)     //���TIM7�����жϷ������
	{
		TIM_ClearITPendingBit(TIM7, TIM_IT_Update);         //���TIM7�����жϱ�־
		
		
	}
}
/********************************************************************************
    ���ܣ�	��������ֵ
    ������ ��
    ���أ�	��
    ��ע��	control.c�ڲ�����
*********************************************************************************/
void Read_Encoder(void)
{
	if(EncoderL<32768)
		SpeedL=EncoderL;
	else
		SpeedL=EncoderL-65535;
	
	if(EncoderR<32768)
		SpeedR=EncoderR;
	else
		SpeedR=EncoderR-65535;
	
//	SpeedL=-SpeedL;	
//	SpeedR=-SpeedR;	
	
	EncoderL=0;
	EncoderR=0;
}
/********************************************************************************
    ���ܣ�	�޷�
    ������
            Value       ��Ҫ�޷��ı�����ַ
            Range	      ���Ʒ���
    ���أ�	��
    ��ע��	control.c�ڲ�����
*********************************************************************************/
void Limiting(int16_t* Value,int16_t Range)
{
    if(*Value >  Range)*Value =  Range;
    if(*Value < -Range)*Value = -Range;
}
/********************************************************************************
    ���ܣ�	����PWM�������
    ������ pwml   ����PWMֵ
					pwmr   �ҵ��PWMֵ
    ���أ�	��
    ��ע��	control.c�ڲ�����
*********************************************************************************/
void Set_PWM(int16_t pwml,int16_t pwmr)
{
//	#define S 0
//	#define P 1
//	#define N 2
//	static uint8_t ForwordFlagL=S,ForwordFlagR=S;
	if(pwml>0)
	{
//		if(ForwordFlagL==N)
//		{
//			MotorL_P=0;
//			MotorL_N=0;
//			ForwordFlagL=S;
//			return;
//		}
//		ForwordFlagL=P;
		MotorL_P=pwml;
		MotorL_N=0;
	}
	else if(pwml<0)
	{
//		if(ForwordFlagL==P)
//		{
//			MotorL_P=0;
//			MotorL_N=0;
//			ForwordFlagL=S;
//			return;
//		}
//		ForwordFlagL=N;
		MotorL_P=0;
		MotorL_N=-pwml;
	}
	else
	{
//		ForwordFlagL=S;
		MotorL_P=0;
		MotorL_N=0;
	}
	
	if(pwmr>0)
	{
//		if(ForwordFlagR==N)
//		{
//			MotorL_P=0;
//			MotorL_N=0;
//			ForwordFlagR=S;
//			return;
//		}
//		ForwordFlagR=P;
		MotorR_P=pwmr;
		MotorR_N=0;
	}
	else if(pwml<0)
	{
//		if(ForwordFlagR==P)
//		{
//			MotorL_P=0;
//			MotorL_N=0;
//			ForwordFlagR=S;
//			return;
//		}
//		ForwordFlagR=N;
		MotorR_P=0;
		MotorR_N=-pwmr;
	}
	else
	{
//		ForwordFlagR=S;
		MotorR_P=0;
		MotorR_N=0;
	}
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
