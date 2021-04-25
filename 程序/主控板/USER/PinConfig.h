///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-接口配置
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __PINCONFIG_H__
#define __PINCONFIG_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "timer.h"
#include "adc.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*PWM输出*/
#define MotorL_P	TIM1->CCR2	//左电机正转
#define MotorL_N	TIM1->CCR1	//左电机反转
#define MotorR_P	TIM1->CCR3	//右电机正转
#define MotorR_N	TIM1->CCR4	//右电机反转
#define MotorJ_P	TIM8->CCR4	//跳台电机正转
#define MotorJ_N	TIM8->CCR3	//跳台电机反转

//#define MotorL_P	TIM1->CCR1	//左电机正转
//#define MotorL_N	TIM1->CCR2	//左电机反转
//#define MotorR_P	TIM1->CCR4	//右电机正转
//#define MotorR_N	TIM1->CCR3	//右电机反转
//#define MotorJ_P	TIM8->CCR3	//跳台电机正转
//#define MotorJ_N	TIM8->CCR4	//跳台电机反转

#define Fan     	TIM2->CCR1	//涵道风扇
/*编码器*/	
#define EncoderL	TIM4->CNT	//左编码器
#define EncoderR	TIM3->CNT	//右编码器
/*跳台装置红外*/
#define	IR_JUMP		ADC_F0		//跳台红外
/*测距红外*/
#define	IR_FL		ADC_F1		//前-左红外
#define	IR_FML		ADC_F3		//前-中偏左红外
#define	IR_FMR		ADC_F4		//前-中偏右红外
#define	IR_FR		ADC_F6		//前-右红外
#define	IR_BL		ADC_R4		//后-左红外
#define	IR_BM		ADC_R5		//后-中红外
#define	IR_BR		ADC_R3		//后-右红外
#define	IR_LF		ADC_L5		//左-前红外
#define	IR_LM		ADC_L6		//左-中红外
#define	IR_LB		ADC_L7		//左-后红外
#define	IR_RF		ADC_R0		//右-前红外
#define	IR_RM		ADC_R1		//右-中红外
#define	IR_RB		ADC_R2		//右-后红外
#define	IR_TF		ADC_L1		//顶-前红外
#define	WAVE_BL		(4095-ADC_L3)		//后左超声波
#define	WAVE_BR		(4095-ADC_L2)		//后右超声波
/*定位灰度*/	
#define	GRAY_FL		ADC_F2		//前左灰度
#define	GRAY_FR		1500//ADC_F5		//前右灰度
#define	GRAY_BL		ADC_R7		//后左灰度
#define	GRAY_BR		ADC_R6		//后右灰度
/*台边检测光电门*/
#define OS_L		ADC_L4		//(4095-ADC_L9)			//左光电门
#define	OS_R		ADC_F7		//(4095-ADC_F7)			//右光电门
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
