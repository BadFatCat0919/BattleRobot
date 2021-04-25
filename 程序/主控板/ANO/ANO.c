#include "ANO.h"
#include "stm32f10x.h"

//串口1发送1个字符 
//c:要发送的字符
void usart1_send_char(u8 c)
{
	while((USART3->SR&0X40)==0);//等待上一次发送完毕   
	USART3->DR=c;   	
} 
//传送数据给匿名四轴上位机软件(V2.6版本)
//fun:功能字. 0XA0~0XAF
//data:数据缓存区,最多28字节!!
//len:data区有效数据个数
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//最多28字节数据 
	send_buf[len+3]=0;	//校验数置零
	send_buf[0]=0X88;	//帧头
	send_buf[1]=fun;	//功能字
	send_buf[2]=len;	//数据长度
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//复制数据
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//计算校验和	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//发送数据到串口1 
}

//调节PID参数时使用
void usart2_niming_report(u8*data)
{
	u8 send_buf[32];
	u8 i;
	send_buf[0]=0X88;
	send_buf[1]=0XAC;
	send_buf[2]=0X1C;
	send_buf[3]=0XAD;
	for(i=0;i<6;i++)send_buf[4+i]=data[i];
	for(i=0;i<12;i++)send_buf[10+i]=0;
	send_buf[22]=0x00;
	for(i=0;i<23;i++)send_buf[23]+=send_buf[i];
	for(i=0;i<24;i++)usart1_send_char(send_buf[i]);
}

//发送加速度传感器数据和陀螺仪数据
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
void mpu6050_send_data(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz)
{
	u8 tbuf[12]; 
	tbuf[0]=(aacx>>8)&0XFF;
	tbuf[1]=aacx&0XFF;
	tbuf[2]=(aacy>>8)&0XFF;
	tbuf[3]=aacy&0XFF;
	tbuf[4]=(aacz>>8)&0XFF;
	tbuf[5]=aacz&0XFF; 
	tbuf[6]=(gyrox>>8)&0XFF;
	tbuf[7]=gyrox&0XFF;
	tbuf[8]=(gyroy>>8)&0XFF;
	tbuf[9]=gyroy&0XFF;
	tbuf[10]=(gyroz>>8)&0XFF;
	tbuf[11]=gyroz&0XFF;
	usart1_niming_report(0XA1,tbuf,12);//自定义帧,0XA1
}	


//发送short型数据给上位机
void I_send_data(short lvboqian,short lvbohou,short My_Angle)
{
	u8 tbuf[6]; 
	tbuf[0]=(lvboqian>>8)&0XFF;
	tbuf[1]=lvboqian&0XFF;
	tbuf[2]=(lvbohou>>8)&0XFF;
	tbuf[3]=lvbohou&0XFF;
	tbuf[4]=(My_Angle>>8)&0XFF;
	tbuf[5]=My_Angle&0XFF;
	usart1_niming_report(0XA1,tbuf,6);
}	


//发送int型数据给上位机
void send_date_u16(int first,int second,int third)
{
	 	u8 tbuf[12]; 
	  tbuf[0]=(first>>24)&0XFF;
	  tbuf[1]=(first>>16)&0XFF;
	  tbuf[2]=(first>>8)&0XFF;
	  tbuf[3]=first&0XFF;
	  
	  tbuf[4]=(second>>24)&0XFF;
	  tbuf[5]=(second>>16)&0XFF;
	  tbuf[6]=(second>>8)&0XFF;
	  tbuf[7]=second&0XFF;
	
		tbuf[8]=(third>>24)&0XFF;
	  tbuf[9]=(third>>16)&0XFF;
	  tbuf[10]=(third>>8)&0XFF;
	  tbuf[11]=third&0XFF;
	
	  usart1_niming_report(0XA1,tbuf,12);
}

//发送float型数给上位机
void Send_date_float(float first,float second,float third)
{
	u8 tbuf[12]; 
	union B_F
 {
	 char Byte[4];
	 float f;
 } fl;
	fl.f=first;
  tbuf[0]=fl.Byte[3];
  tbuf[1]=fl.Byte[2];
  tbuf[2]=fl.Byte[1];
  tbuf[3]=fl.Byte[0];
  fl.f=second;
  tbuf[4]=fl.Byte[3];
  tbuf[5]=fl.Byte[2];
  tbuf[6]=fl.Byte[1];
  tbuf[7]=fl.Byte[0];
  fl.f=third;
  tbuf[8]=fl.Byte[3];
  tbuf[9]=fl.Byte[2];
  tbuf[10]=fl.Byte[1];
  tbuf[11]=fl.Byte[0]; 
  usart1_niming_report(0XA1,tbuf,12);
}


//发送PID参数给上位机

void Send_PID(float PID_P,float PID_I,float PID_D)
{
	u8 tbuf[6]; 
	union B_F
 {
	 char Byte[2];
	 unsigned short f;
 } fl;
  fl.f=PID_P*1000;
  tbuf[0]=fl.Byte[1];
  tbuf[1]=fl.Byte[0];
  fl.f=PID_I*1000;
  tbuf[2]=fl.Byte[1];
  tbuf[3]=fl.Byte[0];
  fl.f=PID_D*1000;
  tbuf[4]=fl.Byte[1];
  tbuf[5]=fl.Byte[0];
  usart2_niming_report(tbuf);
}

