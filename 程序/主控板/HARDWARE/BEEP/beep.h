///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-有源蜂鸣器驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __BEEP_H__
#define __BEEP_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置蜂鸣器触发电平*/
#define BEEP_ON         1
#define BEEP_OFF        !BEEP_ON
/*设置蜂鸣器占用IO口*/
#define BEEP            PCout(6)
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern uint8_t BEEP_USING_FLAG;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void BEEP_Init(void);                  //蜂鸣器初始化
void BEEP_Hint(uint16_t times);        //蜂鸣器短促蜂鸣数次
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
