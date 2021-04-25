///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板-OLED驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "oled.h"
#include "oledfont.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
 uint32_t oled_pow( uint8_t m, uint8_t n);                          //仅内部使用的函数，放在c文件中声明
/********************************************************************************
  功能：	写指令（不用理解）
  参数：	dat   指令内容
         cmd   写指令/写数据
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_WR_Byte( uint8_t dat, uint8_t cmd)
{
  uint8_t i;
  if(cmd)
    OLED_DC=1;
  else
    OLED_DC=0;
  for(i=0;i<8;i++)
  {
    OLED_DO=0;
    if(dat&0x80)
       OLED_D1=1;
    else
       OLED_D1=0;
    OLED_DO=1;
    dat<<=1;
  }
  OLED_DC=1;
}
/********************************************************************************
  功能：	设置光标
  参数：	x		横坐标
        y	 纵坐标
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_Set_Pos(unsigned char x, unsigned char y)
{
  OLED_WR_Byte(0xb0+y,OLED_CMD);
  OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
  OLED_WR_Byte((x&0x0f)|0x01,OLED_CMD);
}
/********************************************************************************
  功能：	打开OLED
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_Display_On(void)
{
  OLED_WR_Byte(0X8D,OLED_CMD);
  OLED_WR_Byte(0X14,OLED_CMD);
  OLED_WR_Byte(0XAF,OLED_CMD);
}
/********************************************************************************
  功能：	关闭OLED
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_Display_Off(void)
{
  OLED_WR_Byte(0X8D,OLED_CMD);
  OLED_WR_Byte(0X10,OLED_CMD);
  OLED_WR_Byte(0XAE,OLED_CMD);
}
/********************************************************************************
  功能：	清屏
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_Clear(void)
{
   uint8_t i,n;
  for(i=0;i<8;i++)
  {
    OLED_WR_Byte (0xb0+i,OLED_CMD);
    OLED_WR_Byte (0x02,OLED_CMD);
    OLED_WR_Byte (0x10,OLED_CMD);
    for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA);
  }
}
/********************************************************************************
  功能：	显示字符
  参数：	x			横坐标
        y	    纵坐标
        char  需要显示的字符
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_ShowChar( uint8_t x, uint8_t y, uint8_t chr)
{
    unsigned char c=0,i=0;
    c=chr-' ';
    if(x>Max_Column-1){x=0;y=y+2;}
    if(SIZE == 16)
    {
      OLED_Set_Pos(x,y);
      for(i=0;i<8;i++)
        OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
      OLED_Set_Pos(x,y+1);
      for(i=0;i<8;i++)
        OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
    }
    else
    {
      OLED_Set_Pos(x,y+1);
      for(i=0;i<6;i++)
        OLED_WR_Byte(F6x8[c][i],OLED_DATA);
    }
}
/********************************************************************************
  功能：	乘方运算
  参数：	m		底数
         n   指数
  返回：	运算结果
  备注：	内部函数
*********************************************************************************/
 uint32_t oled_pow( uint8_t m, uint8_t n)
{
   uint32_t result=1;
  while(n--)result*=m;
  return result;
}
/********************************************************************************
  功能：	显示数字
  参数：	x			横坐标
        y			纵坐标
        num		需要显示的数字
        len		数字长度
        size	显示的尺寸（12/16）
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_ShowNum( uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size)
{
   uint8_t t,temp;
   uint8_t enshow=0;
  for(t=0;t<len;t++)
  {
    temp=(num/oled_pow(10,len-t-1))%10;
    if(enshow==0&&t<(len-1))
    {
      if(temp==0)
      {
        OLED_ShowChar(x+(size/2)*t,y,' ');
        continue;
      }else enshow=1;
    }
     OLED_ShowChar(x+(size/2)*t,y,temp+'0');
  }
}
/********************************************************************************
  功能：	显示字符串
  参数：	x			横坐标
        y			纵坐标
        chr   需要显示的字符串
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_ShowString( uint8_t x, uint8_t y, uint8_t *chr)
{
  unsigned char j=0;
  while (chr[j]!='\0')
  {		OLED_ShowChar(x,y,chr[j]);
      x+=8;
    if(x>120){x=0;y+=2;}
      j++;
  }
}
/********************************************************************************
  功能：	显示头文件"oledfont.h"中Chinese[][32]数组里对应序号的汉字
  参数：	x			横坐标
        y			纵坐标
        no		需要显示的字汉字序号
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_ShowChinese( uint8_t x, uint8_t y, uint8_t no)
{
   uint8_t t,adder=0;
  OLED_Set_Pos(x,y);
    for(t=0;t<16;t++)
    {
        OLED_WR_Byte(Chinese[2*no][t],OLED_DATA);
        adder+=1;
     }
    OLED_Set_Pos(x,y+1);
    for(t=0;t<16;t++)
      {
        OLED_WR_Byte(Chinese[2*no+1][t],OLED_DATA);
        adder+=1;
      }
}
/********************************************************************************
  功能：	居中显示头文件"oledfont.h"中Chinese[][32]数组里对应序号的一段文字
  参数：	line		显示的行序号
        start		显示汉字起始序号
        end			显示汉字终止序号
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_ShowText( uint8_t line, uint8_t start, uint8_t end)
{
   uint8_t i;
  for(i=start;i<=end;i++)
    OLED_ShowChinese((i-start)*16+(128-(end-start+1)*16)/2,line,i);
}
/********************************************************************************
  功能：	显示缓存数组对应的图像
  参数：	buff 宽度为1024的图像数组
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_Show(u8 buff[])
{
	uint8_t x,y;
	
	for(y=0;y<8;y++)
	{
    OLED_WR_Byte (0xb0+y,OLED_CMD);
    OLED_WR_Byte (0x00,OLED_CMD);
    OLED_WR_Byte (0x10,OLED_CMD);
		
		for(x=0;x<128;x++)
			OLED_WR_Byte(buff[x+y*128],OLED_DATA);
	}	 
}
/********************************************************************************
  功能：	清屏并显示LOGO
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_ShowLogo()
{
	uint8_t x,y;
	
  OLED_Clear();
	
	for(y=0;y<8;y++)
	{
    OLED_WR_Byte (0xb0+y,OLED_CMD);
    OLED_WR_Byte (0x00,OLED_CMD);
    OLED_WR_Byte (0x10,OLED_CMD);
		
		for(x=0;x<128;x++)
			OLED_WR_Byte(LOGO_505_Tech[x+y*128],OLED_DATA);
	}	 
	
}
/********************************************************************************
  功能：	OLED初始化
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
void OLED_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	
  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP; 
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_7;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_13;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  GPIO_SetBits(GPIOA,GPIO_Pin_7);
  GPIO_SetBits(GPIOB,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_13);

  OLED_RES=1;
  delay_ms(100);
  OLED_RES=0;
  delay_ms(100);
  OLED_RES=1;

  OLED_WR_Byte(0xAE,OLED_CMD);
  OLED_WR_Byte(0x00,OLED_CMD);
  OLED_WR_Byte(0x10,OLED_CMD);
  OLED_WR_Byte(0x40,OLED_CMD);
  OLED_WR_Byte(0x81,OLED_CMD);
  OLED_WR_Byte(0xCF,OLED_CMD);
  OLED_WR_Byte(0xA1,OLED_CMD);
  OLED_WR_Byte(0xC0,OLED_CMD);//如果OLED上下颠倒，改为OLED_WR_Byte(0xC8,OLED_CMD);
  OLED_WR_Byte(0xA6,OLED_CMD);
  OLED_WR_Byte(0xA8,OLED_CMD);
  OLED_WR_Byte(0x3f,OLED_CMD);
  OLED_WR_Byte(0xD3,OLED_CMD);
  OLED_WR_Byte(0x00,OLED_CMD);
  OLED_WR_Byte(0xd5,OLED_CMD);
  OLED_WR_Byte(0x80,OLED_CMD);
  OLED_WR_Byte(0xD9,OLED_CMD);
  OLED_WR_Byte(0xF1,OLED_CMD);
  OLED_WR_Byte(0xDA,OLED_CMD);
  OLED_WR_Byte(0x12,OLED_CMD);
  OLED_WR_Byte(0xDB,OLED_CMD);
  OLED_WR_Byte(0x40,OLED_CMD);
  OLED_WR_Byte(0x20,OLED_CMD);
  OLED_WR_Byte(0x02,OLED_CMD);
  OLED_WR_Byte(0x8D,OLED_CMD);
  OLED_WR_Byte(0x14,OLED_CMD);
  OLED_WR_Byte(0xA4,OLED_CMD);
  OLED_WR_Byte(0xA6,OLED_CMD);
  OLED_WR_Byte(0xAF,OLED_CMD);
  OLED_WR_Byte(0xAF,OLED_CMD);

  OLED_Clear();
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
