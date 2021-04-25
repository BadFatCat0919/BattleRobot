///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板-按键驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __KEY_H
#define __KEY_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置按键触发电平*/
#define KEY_PRESS   0
#define KEY_RELEASE ！KEY_PRESS
/*设置按键占用IO口*/
#define KEY_OK 		PAin(12)
#define KEY_BACK 	PBin(0)
#define KEY_UP 		PBin(14)
#define KEY_DOWN 	PBin(12)
#define KEY_LEFT 	PAin(8)
#define KEY_RIGHT	PBin(1)
#define KEY_USER	PBin(7)
#define BLUETOOTH PAin(5)
/*设置消抖时间（ms）*/
#define KEY_FILTER  1
/*设置按键键值*/
#define __KEY_OK 		1
#define __KEY_BACK 	2
#define __KEY_UP 		3
#define __KEY_DOWN 	4
#define __KEY_LEFT 	5
#define __KEY_RIGHT 6
#define __KEY_USER  7
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void    KEY_Init(void);       //按键初始化
void    KEY_Scan_USART(void); //扫描除USER外六个按键并通过串口发送
uint8_t KEY_Scan(void);       //扫描除USER外六个按键并返回键值
uint8_t KEY_USER_Scan(uint16_t HoldTime);  //扫描用户自定义按键
uint8_t KEY_OK_Scan(void);    //扫描OK键
uint8_t KEY_BACK_Scan(void);  //扫描BACK键
uint8_t KEY_UP_Scan(void);    //扫描UP键
uint8_t KEY_DOWN_Scan(void);  //扫描DOWN键
uint8_t KEY_LEFT_Scan(void);  //扫描LEFT键
uint8_t KEY_RIGHT_Scan(void); //扫描RIGHT键
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
