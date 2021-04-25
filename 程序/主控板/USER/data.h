///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-���ݴ���
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __DATA_H
#define __DATA_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "main.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*����������¼��־λ*/
#define PROGRAM_REFRESH_FLAG		DATA[0]
#define PROGRAM_REFRESH_PASSWORD	1894			//������λ����
/*����������ֵ*/
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
/*������ģʽ����*/
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
/*�������ݴ洢��flashҳ�漰���ݿ��*/
#define DATA_PAGE                	ADDR_FLASH_PAGE_125
#define DATA_LENGTH              	64
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern uint16_t DATA[DATA_LENGTH];
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint8_t Judge_Program_FirstRun(void);	//�жϳ����ǲ���������¼���һ������
void DATA_Load(void);									//��������
void DATA_Save(void);									//�洢����
void DATA_Default(void);							//��������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
