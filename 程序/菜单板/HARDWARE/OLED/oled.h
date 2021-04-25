///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板-OLED驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __OLED_H
#define __OLED_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "stdlib.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置OLED相关参数*/
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
/*设置OLED占用IO口*/
//D0(SCLK):
#define OLED_DO  PBout(13)
//D1(SDIN/MOSI):
#define OLED_D1  PBout(11)
//RES(RST):
#define OLED_RES PBout(10)
//DC:
#define OLED_DC	 PAout(7)
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void OLED_WR_Byte( uint8_t dat, uint8_t cmd);                  //写指令
void OLED_Set_Pos(unsigned char x, unsigned char y);           //设置光标
void OLED_Display_On(void);                                    //打开OLED
void OLED_Display_Off(void);                                   //关闭OLED
void OLED_Clear(void);                                         //清屏
void OLED_ShowChar( uint8_t x, uint8_t y, uint8_t chr);        //显示字符
void OLED_ShowNum( uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size); //显示数字
void OLED_ShowString( uint8_t x, uint8_t y,  uint8_t *p);      //显示字符串
void OLED_ShowChinese( uint8_t x, uint8_t y, uint8_t no);      //显示汉字
void OLED_ShowText( uint8_t line, uint8_t start, uint8_t end); //居中显示一段文字
void OLED_Show(u8 buff[]);                                     //显示缓存数组对应的图像
void OLED_ShowLogo(void);                                      //清屏并显示LOGO
void OLED_Init(void);                                          //OLED初始化
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
