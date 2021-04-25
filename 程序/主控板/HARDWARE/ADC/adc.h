///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-ADC驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __ADC_H
#define __ADC_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "PinConfig.h"
#include "data.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern  uint16_t ADC_BUFF[16];      //ADC读数缓存
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*映射ADC缓存数组元素与26路ADC通道*/
#define	ADC_F0	ADC_BUFF[0]		//PC0
#define	ADC_F1	ADC_BUFF[1]		//PC1
#define	ADC_F2	ADC_BUFF[2]		//PC2
#define	ADC_F3	ADC_BUFF[3]		//PC3
#define	ADC_F4	ADC_BUFF[4]		//PA0
#define	ADC_F5	ADC_BUFF[5]		//PA1
#define	ADC_F6	ADC_BUFF[6]		//PA2
#define	ADC_F7	ADC_BUFF[7]		//PA3
#define	ADC_R0	ADC_BUFF[8]		//PA4
#define	ADC_R1	ADC_BUFF[9]		//PA5
#define	ADC_R2	ADC_BUFF[10]	//PA6
#define	ADC_R3	ADC_BUFF[11]	//PA7
#define	ADC_R4	ADC_BUFF[12]	//PC4
#define	ADC_R5	ADC_BUFF[13]	//PC5
#define	ADC_R6	ADC_BUFF[14]	//PB0
#define	ADC_R7	ADC_BUFF[15]	//PB1
#define	ADC_L0	USART3_Buf[0].u16
#define	ADC_L1	USART3_Buf[1].u16
#define	ADC_L2	USART3_Buf[2].u16
#define	ADC_L3	USART3_Buf[3].u16
#define	ADC_L4	USART3_Buf[4].u16
#define	ADC_L5	USART3_Buf[5].u16
#define	ADC_L6	USART3_Buf[6].u16
#define	ADC_L7	USART3_Buf[7].u16
#define	ADC_L8  USART3_Buf[8].u16
#define	ADC_L9  USART3_Buf[9].u16
/*将各传感器的模拟量转换为数字量*/
#define	IR_JUMP_Judge	 (	IR_JUMP	>	IR_JUMP_TH	)
#define	IR_FL_Judge		 (	IR_FL	>	IR_FL_TH	)
#define	IR_FML_Judge	 (	IR_FML	>	IR_FML_TH	)
#define	IR_FMR_Judge	 (	IR_FMR	>	IR_FMR_TH	)
#define	IR_FR_Judge		 (	IR_FR	>	IR_FR_TH	)
#define	IR_BL_Judge		 (	IR_BL	>	IR_BL_TH	)
#define	IR_BM_Judge		 (	IR_BM	>	IR_BM_TH	)
#define	IR_BR_Judge		 (	IR_BR	>	IR_BR_TH	)
#define	IR_LF_Judge		 (	IR_LF	>	IR_LF_TH	)
#define	IR_LM_Judge		 (	IR_LM	>	IR_LM_TH	)
#define	IR_LB_Judge		 (	IR_LB	>	IR_LB_TH	)
#define	IR_RF_Judge		 (	IR_RF	>	IR_RF_TH	)
#define	IR_RM_Judge		 (	IR_RM	>	IR_RM_TH	)
#define	IR_RB_Judge		 (	IR_RB	>	IR_RB_TH	)


#define	IR_JUMP_JudgeBT	 	(	IR_JUMP	>	2000)
#define	IR_FL_JudgeBT		 (	IR_FL	>	2000)
#define	IR_FML_JudgeBT	 	(	IR_FML	>	2000)
#define	IR_FMR_JudgeBT	 	(	IR_FMR	>	2000)
#define	IR_FR_JudgeBT		 (	IR_FR	>	2000)
#define	IR_BL_JudgeBT		 (	IR_BL	>	2000)
#define	IR_BM_JudgeBT		 (	IR_BM	>	2000)
#define	IR_BR_JudgeBT		 (	IR_BR	>	2000)
#define	IR_LF_JudgeBT		 (	IR_LF	>	2000)
#define	IR_LM_JudgeBT		 (	IR_LM	>	2000)
#define	IR_LB_JudgeBT		 (	IR_LB	>	2000)
#define	IR_RF_JudgeBT		 (	IR_RF	>	2000)
#define	IR_RM_JudgeBT		 (	IR_RM	>	2000)
#define	IR_RB_JudgeBT		 (	IR_RB	>	2000)


#define	IR_FL_JudgeFall	 (	IR_FL	>	IR_JUDGE_TH	)
#define	IR_FML_JudgeFall (	IR_FML	>	IR_JUDGE_TH	)
#define	IR_FMR_JudgeFall (	IR_FMR	>	IR_JUDGE_TH	)
#define	IR_FR_JudgeFall	 (	IR_FR	>	IR_JUDGE_TH	)
#define	IR_BL_JudgeFall	 (	IR_BL	>	IR_JUDGE_TH	)
#define	IR_BM_JudgeFall	 (	IR_BM	>	IR_JUDGE_TH	)
#define	IR_BR_JudgeFall	 (	IR_BR	>	IR_JUDGE_TH	)
#define	IR_LF_JudgeFall	 (	IR_LF	>	IR_JUDGE_TH	)
#define	IR_LM_JudgeFall	 (	IR_LM	>	IR_JUDGE_TH	)
#define	IR_LB_JudgeFall	 (	IR_LB	>	IR_JUDGE_TH	)
#define	IR_RF_JudgeFall	 (	IR_RF	>	IR_JUDGE_TH	)
#define	IR_RM_JudgeFall	 (	IR_RM	>	IR_JUDGE_TH	)
#define	IR_RB_JudgeFall	 (	IR_RB	>	IR_JUDGE_TH	)
                         
#define	IR_TF_Judge		 (	IR_TF	>	IR_TF_TH	)
#define	WAVE_BL_Judge    (	WAVE_BL	>	WAVE_BL_TH	)
#define	WAVE_BR_Judge    (	WAVE_BR	>	WAVE_BR_TH	)
#define GRAY_FL_Judge	 (	GRAY_FL	>	GRAY_FL_TH	)
#define GRAY_FR_Judge	 (	GRAY_FR	>	GRAY_FR_TH	)
#define GRAY_BL_Judge	 (	GRAY_BL	>	GRAY_BL_TH	)
#define GRAY_BR_Judge	 (	GRAY_BR	>	GRAY_BR_TH	)
#define	OS_L_Judge		 (	OS_L	>	OS_L_TH		)
#define	OS_R_Judge		 (	OS_R	>	OS_R_TH		)
#define IR_ALL_Judge	 (IR_FL_Judge||IR_FR_Judge||IR_BL_Judge||IR_BM_Judge||IR_BR_Judge||IR_LF_Judge||IR_LM_Judge||IR_LB_Judge||IR_RF_Judge||IR_RM_Judge||IR_RB_Judge)
#define IR_BALL_Judge	 (IR_BL_JudgeFall&&IR_BM_JudgeFall&&IR_BR_JudgeFall)
#define IR_RALL_Judge	 (IR_RF_JudgeFall&&IR_RM_JudgeFall&&IR_RB_JudgeFall)
#define IR_LALL_Judge	 (IR_LF_JudgeFall&&IR_LM_JudgeFall&&IR_LB_JudgeFall)
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void ADC1_Init(void);           //ADC初始化
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
