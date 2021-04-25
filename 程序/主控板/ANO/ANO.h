#ifndef __UNOSEND_H
#define __UNOSEND_H

#include "stm32f10x.h"

void usart1_send_char(u8 c);
void usart1_niming_report(u8 fun,u8*data,u8 len);
void mpu6050_send_data(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz);
void send_date_u16(int first,int second,int third);
void Send_date_float(float first,float second,float third);
void usart2_niming_report(u8*data);
void Send_PID(float PID_P,float PID_I,float PID_D);
void I_send_data(short lvboqian,short lvbohou,short My_Angle);

#endif
