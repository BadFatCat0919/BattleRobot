///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-数据处理
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __DATA_H
#define __DATA_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "main.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*程序重新烧录标志位*/
#define PROGRAM_REFRESH_FLAG		DATA[0]
#define PROGRAM_REFRESH_PASSWORD	1894			//任意四位数字
/*各传感器阈值*/
#define	IR_JUMP_TH					DATA[1]	
#define	IR_FL_TH					DATA[2]	
#define	IR_FML_TH					DATA[3]	
#define	IR_FMR_TH					DATA[4]	
#define	IR_FR_TH					DATA[5]	
#define	IR_BL_TH					DATA[6]	
#define	IR_BM_TH					DATA[7]	
#define	IR_BR_TH					DATA[8]	
#define	IR_LF_TH					DATA[9]	
#define	IR_LM_TH					DATA[10]
#define	IR_LB_TH					DATA[11]
#define	IR_RF_TH					DATA[12]
#define	IR_RM_TH					DATA[13]
#define	IR_RB_TH					DATA[14]
#define	IR_TF_TH					DATA[15]
#define	WAVE_BL_TH					DATA[16]
#define	WAVE_BR_TH					DATA[17]
#define	GRAY_FL_TH					DATA[18]
#define	GRAY_FR_TH					DATA[19]
#define GRAY_BL_TH					DATA[20]
#define GRAY_BR_TH                  DATA[21]
#define OS_L_TH						DATA[22]
#define	OS_R_TH						DATA[23]
#define	IR_ALL_TH					DATA[24]
#define	IR_JUDGE_TH					DATA[29]
#define DefaultTH					2500
/*推棋子模式参数*/
#define WaitTimeFM					DATA[30]
#define WaitTimeFL					DATA[31]
#define WaitTimeLF					DATA[32]
#define WaitTimeLM					DATA[33]
#define WaitTimeLB					DATA[34]
#define WaitTimeBL					DATA[35]
#define WaitTimeBM					DATA[36]
#define WaitTimeBR					WaitTimeBL
#define WaitTimeRB					WaitTimeLB
#define WaitTimeRM					WaitTimeLM
#define WaitTimeRF					WaitTimeLF
#define WaitTimeFR					WaitTimeFL
#define TurnSpeedFL					DATA[37]
#define TurnSpeedLF					DATA[38]
#define TurnSpeedLM					DATA[39]
#define TurnSpeedLB					DATA[40]
#define TurnSpeedBL					DATA[41]
#define TurnSpeedBM					DATA[42]
#define TurnSpeedBR					TurnSpeedBL
#define TurnSpeedRB					TurnSpeedLB
#define TurnSpeedRM					TurnSpeedLM
#define TurnSpeedRF					TurnSpeedLF
#define TurnSpeedFR					TurnSpeedFL
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置数据存储的flash页面及数据宽度*/
#define DATA_PAGE                	ADDR_FLASH_PAGE_125
#define DATA_LENGTH              	64
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern uint16_t DATA[DATA_LENGTH];
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint8_t Judge_Program_FirstRun(void);	//判断程序是不是重新烧录后第一次运行
void DATA_Load(void);									//加载数据
void DATA_Save(void);									//存储数据
void DATA_Default(void);							//重置数据
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
