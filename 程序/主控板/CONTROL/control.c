///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-控制算法
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
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
    功能：	TIM6定时中断服务函数
    参数：	无
    返回：	无
    备注：	包含所有控制算法，10ms运行一次，使用前请确保TIM6已初始化
*********************************************************************************/
void TIM6_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)     //检查TIM6更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);         //清除TIM6更新中断标志
//====================涵道风扇控制=======================//
		Fan=TestFan;
//===================编码器数值读取======================//
		Read_Encoder();
//=====================蜂鸣器控制========================//
		if(!UART4_Res)
		{
			if (!BEEP_USING_FLAG)
				BEEP=BEEP_OFF;
		}
	}
}
/********************************************************************************
    功能：	TIM7定时中断服务函数
    参数：	无
    返回：	无
    备注：	100ms运行一次，使用前请确保TIM7已初始化
*********************************************************************************/
void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)     //检查TIM7更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM7, TIM_IT_Update);         //清除TIM7更新中断标志
		
		
	}
}
/********************************************************************************
    功能：	读编码器值
    参数： 无
    返回：	无
    备注：	control.c内部函数
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
    功能：	限幅
    参数：
            Value       需要限幅的变量地址
            Range	      限制幅度
    返回：	无
    备注：	control.c内部函数
*********************************************************************************/
void Limiting(int16_t* Value,int16_t Range)
{
    if(*Value >  Range)*Value =  Range;
    if(*Value < -Range)*Value = -Range;
}
/********************************************************************************
    功能：	更新PWM到电机上
    参数： pwml   左电机PWM值
					pwmr   右电机PWM值
    返回：	无
    备注：	control.c内部函数
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
