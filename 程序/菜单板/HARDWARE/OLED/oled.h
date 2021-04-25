///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���ߵ��Բ˵���-OLED����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __OLED_H
#define __OLED_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "stdlib.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*����OLED��ز���*/
#define SIZE        16
#define XLevelL     0x00
#define XLevelH     0x10
#define Max_Column  128
#define Max_Row     64
#define	Brightness  0xFF
#define X_WIDTH     128
#define Y_WIDTH     64
#define OLED_CMD    0
#define OLED_DATA   1
/*����OLEDռ��IO��*/
//D0(SCLK):
#define OLED_DO  PBout(13)
//D1(SDIN/MOSI):
#define OLED_D1  PBout(11)
//RES(RST):
#define OLED_RES PBout(10)
//DC:
#define OLED_DC	 PAout(7)
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void OLED_WR_Byte( uint8_t dat, uint8_t cmd);                  //дָ��
void OLED_Set_Pos(unsigned char x, unsigned char y);           //���ù��
void OLED_Display_On(void);                                    //��OLED
void OLED_Display_Off(void);                                   //�ر�OLED
void OLED_Clear(void);                                         //����
void OLED_ShowChar( uint8_t x, uint8_t y, uint8_t chr);        //��ʾ�ַ�
void OLED_ShowNum( uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size); //��ʾ����
void OLED_ShowString( uint8_t x, uint8_t y,  uint8_t *p);      //��ʾ�ַ���
void OLED_ShowChinese( uint8_t x, uint8_t y, uint8_t no);      //��ʾ����
void OLED_ShowText( uint8_t line, uint8_t start, uint8_t end); //������ʾһ������
void OLED_Show(u8 buff[]);                                     //��ʾ���������Ӧ��ͼ��
void OLED_ShowLogo(void);                                      //��������ʾLOGO
void OLED_Init(void);                                          //OLED��ʼ��
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
